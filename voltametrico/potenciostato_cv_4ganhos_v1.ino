/*
 * POTENCIOSTATO DIDÁTICO - VOLTAMETRIA CÍCLICA V1
 * ESP32-S3 + MCP4725 + ADS1115 + ADG444
 *
 * Recursos:
 * - 4 faixas de transimpedância calibradas experimentalmente
 * - Voltametria cíclica não bloqueante
 * - MQTT para Node-RED Dashboard 2.0
 * - Média/estatística do ADS1115
 * - Verificação de faixa validada e saturação
 * - Registro de ciclo, segmento, ponto e tempo
 * - Comandos START / STOP / ZERO / READ
 *
 * TÓPICOS MQTT:
 *   ic/potenciostato/comando
 *   ic/potenciostato/leitura
 *   ic/potenciostato/status
 *
 * IMPORTANTE:
 * As equações abaixo são calibrações experimentais da cadeia completa
 * (TIA + condicionamento + entrada do ADS1115) e devem ser refinadas
 * quando uma nova calibração metrológica for realizada.
 */

#include <Wire.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Adafruit_ADS1X15.h>
#include <Adafruit_MCP4725.h>

// ============================================================
// REDE / MQTT - PREENCHER
// ============================================================

const char* WIFI_SSID = "Isaweb_1";
const char* WIFI_PASS = "xxxx";

const char* MQTT_HOST = "rpiot.com.br";
const uint16_t MQTT_PORT = 1883;
const char* MQTT_USER = "rpiotlora";
const char* MQTT_PASS = "xxxx";

const char* MQTT_CLIENT_ID = "voltametrico-cv-v1";

const char* TOPIC_CMD     = "ic/potenciostato/comando";
const char* TOPIC_READING = "ic/potenciostato/leitura";
const char* TOPIC_STATUS  = "ic/potenciostato/status";

WiFiClient wifiClient;
PubSubClient mqtt(wifiClient);

// ============================================================
// HARDWARE
// ============================================================

#define SDA_INST 8
#define SCL_INST 9

// Optoacopladores: ESP HIGH -> opto conduz -> ADG444 IN LOW -> chave fecha
#define PIN_GANHO1 12   // 15 kΩ
#define PIN_GANHO2 11   // 150 kΩ
#define PIN_GANHO3 10   // 2 MΩ

Adafruit_ADS1115 adc;
Adafruit_MCP4725 dac;

// ============================================================
// DAC - CALIBRAÇÃO TENSÃO APLICADA
// ============================================================
//
// Melhor ajuste experimental disponível:
//   Vcarga[V] = DAC_A * RAW + DAC_B
//
// Logo:
//   RAW = (Vdesejada[V] - DAC_B) / DAC_A
//
// Coeficientes derivados da calibração do estágio de aplicação.
// Se uma nova calibração for realizada, alterar apenas estes dois.
//
const float DAC_A = 0.001328635f;   // V / count
const float DAC_B = -2.500750f;     // V

// ============================================================
// ADS1115
// ============================================================
//
// GAIN_TWOTHIRDS => faixa nominal ±6,144 V e 187,5 uV/bit.
// O ADS1115 continua limitado eletricamente aos seus trilhos de alimentação.
//
const float ADC_LSB_V = 0.0001875f;

// Correção adicional do próprio ADC (deixe 1 e 0 até nova calibração específica):
const float ADC_CAL_A = 1.0f;
const float ADC_CAL_B = 0.0f;

// ============================================================
// TRANSIMPEDÂNCIAS NOMINAIS
// ============================================================

const float R_BASE = 10000000.0f;   // 10 MΩ
const float R_G1   =    15000.0f;
const float R_G2   =   150000.0f;
const float R_G3   =  2000000.0f;

// ============================================================
// CALIBRAÇÃO DE CORRENTE
// I[nA] = A[gain] * Vads[V] + B[gain]
// ============================================================
//
// Ganho 0: melhor resultado com carga de 14,1004 MΩ, janela restrita.
// Ganhos 1, 2 e 3: carga de 9,426 MΩ.
//
const float CURRENT_A[4] = {
  -43.2972f,    // G0
  -69464.57f,   // G1
  -6950.04f,    // G2
  -613.001f     // G3
};

const float CURRENT_B[4] = {
  106.9020f,    // G0
  171958.74f,   // G1
  17204.02f,    // G2
  1517.193f     // G3
};

// Faixas de tensão na célula validadas experimentalmente (mV)
const int GAIN_VMIN_MV[4] = {-859, -1272, -2499, -2499};
const int GAIN_VMAX_MV[4] = {1137,  2935,  2938,  2939};

// Janela preferencial da entrada ADS para o ganho 0
const float G0_ADS_MIN_V = 0.50f;
const float G0_ADS_MAX_V = 4.10f;

// Janela genérica conservadora para demais ganhos
const float ADS_MIN_V = 0.20f;
const float ADS_MAX_V = 4.80f;

// ============================================================
// ESTRUTURAS / ESTADO
// ============================================================

enum RunState {
  STATE_IDLE,
  STATE_QUIET,
  STATE_RUNNING,
  STATE_ABORTED
};

RunState runState = STATE_IDLE;

struct CVConfig {
  int vStart_mV;
  int vVertex1_mV;
  int vVertex2_mV;
  int vEnd_mV;

  int step_mV;
  int cycles;

  float scanRate_mV_s;
  uint32_t quietTime_ms;
  uint32_t minPointInterval_ms;
  uint32_t settle_ms;

  uint8_t gain;
  uint8_t adcSamples;

  char runId[48];
};

CVConfig cfg;

int activeGain = 0;
float activeRTIA = R_BASE;

int currentPotential_mV = 0;
int segmentTarget_mV = 0;
int segmentDirection = 1;
int segmentId = 0;
int cycleIndex = 1;

uint32_t sampleIndex = 0;
uint32_t runStartMs = 0;
uint32_t quietStartMs = 0;
uint32_t pointSetAtMs = 0;
uint32_t nextPointDueMs = 0;
uint32_t pointPeriodMs = 100;

bool samplePending = false;

// ============================================================
// FUNÇÕES AUXILIARES
// ============================================================

float parallelR(float r1, float r2) {
  return 1.0f / ((1.0f / r1) + (1.0f / r2));
}

int clampInt(int v, int lo, int hi) {
  if (v < lo) return lo;
  if (v > hi) return hi;
  return v;
}

const char* stateText(RunState s) {
  switch (s) {
    case STATE_IDLE:    return "idle";
    case STATE_QUIET:   return "quiet";
    case STATE_RUNNING: return "running";
    case STATE_ABORTED: return "aborted";
    default:            return "unknown";
  }
}

const char* segmentText(int s) {
  switch (s) {
    case 0: return "start_to_vertex1";
    case 1: return "vertex1_to_vertex2";
    case 2: return "vertex2_to_vertex1";
    case 3: return "vertex1_to_end";
    default:return "unknown";
  }
}

// ============================================================
// GANHO
// ============================================================

void allGainSwitchesOff() {
  digitalWrite(PIN_GANHO1, LOW);
  digitalWrite(PIN_GANHO2, LOW);
  digitalWrite(PIN_GANHO3, LOW);
}

void setGain(uint8_t gain) {

  allGainSwitchesOff();
  delayMicroseconds(20);

  switch (gain) {
    case 1:
      digitalWrite(PIN_GANHO1, HIGH);
      activeRTIA = parallelR(R_BASE, R_G1);
      break;

    case 2:
      digitalWrite(PIN_GANHO2, HIGH);
      activeRTIA = parallelR(R_BASE, R_G2);
      break;

    case 3:
      digitalWrite(PIN_GANHO3, HIGH);
      activeRTIA = parallelR(R_BASE, R_G3);
      break;

    case 0:
    default:
      gain = 0;
      activeRTIA = R_BASE;
      break;
  }

  activeGain = gain;

  Serial.print("[GAIN] ");
  Serial.print(activeGain);
  Serial.print(" RTIA nominal efetiva=");
  Serial.println(activeRTIA, 1);
}

// ============================================================
// DAC
// ============================================================

uint16_t potentialToDacRaw(int potential_mV) {

  float v = ((float)potential_mV) / 1000.0f;
  float raw = (v - DAC_B) / DAC_A;

  long code = lroundf(raw);

  if (code < 0) code = 0;
  if (code > 4095) code = 4095;

  return (uint16_t)code;
}

float dacRawToEstimatedPotentialV(uint16_t raw) {
  return DAC_A * (float)raw + DAC_B;
}

uint16_t applyPotential(int potential_mV) {

  uint16_t code = potentialToDacRaw(potential_mV);

  dac.setVoltage(code, false);

  currentPotential_mV = potential_mV;
  pointSetAtMs = millis();

  return code;
}

// ============================================================
// ADS1115 - ESTATÍSTICA
// ============================================================

void readADCStats(
  uint8_t samples,
  float &meanRaw,
  int16_t &minRaw,
  int16_t &maxRaw,
  float &stdRaw,
  float &meanVolts
) {

  if (samples < 1) samples = 1;
  if (samples > 64) samples = 64;

  int32_t sum = 0;
  double sumSq = 0.0;

  minRaw = 32767;
  maxRaw = -32768;

  for (uint8_t k = 0; k < samples; k++) {

    int16_t raw = adc.readADC_SingleEnded(0);

    sum += raw;
    sumSq += (double)raw * (double)raw;

    if (raw < minRaw) minRaw = raw;
    if (raw > maxRaw) maxRaw = raw;
  }

  meanRaw = (float)sum / (float)samples;

  double meanSq = sumSq / (double)samples;
  double variance =
      meanSq - ((double)meanRaw * (double)meanRaw);

  if (variance < 0.0) variance = 0.0;

  stdRaw = sqrt(variance);

  float nominalV = meanRaw * ADC_LSB_V;
  meanVolts = ADC_CAL_A * nominalV + ADC_CAL_B;
}

// ============================================================
// STATUS MQTT
// ============================================================

void publishStatus(const char* status, const char* detail = "") {

  StaticJsonDocument<384> doc;

  doc["status"] = status;
  doc["detail"] = detail;
  doc["run_id"] = cfg.runId;
  doc["state"] = stateText(runState);
  doc["gain"] = activeGain;
  doc["cycle"] = cycleIndex;
  doc["sample_index"] = sampleIndex;
  doc["point_period_ms"] = pointPeriodMs;

  char out[384];
  serializeJson(doc, out);

  mqtt.publish(TOPIC_STATUS, out);

  Serial.print("[STATUS] ");
  Serial.println(out);
}

// ============================================================
// AQUISIÇÃO / PUBLICAÇÃO
// ============================================================

void acquireAndPublish(uint16_t dacRaw) {

  float adcMeanRaw;
  int16_t adcMinRaw;
  int16_t adcMaxRaw;
  float adcStdRaw;
  float vAds;

  readADCStats(
    cfg.adcSamples,
    adcMeanRaw,
    adcMinRaw,
    adcMaxRaw,
    adcStdRaw,
    vAds
  );

  float current_nA =
      CURRENT_A[activeGain] * vAds +
      CURRENT_B[activeGain];

  float current_uA = current_nA / 1000.0f;

  float estimatedPotential_V =
      dacRawToEstimatedPotentialV(dacRaw);

  bool saturated = false;

  if (activeGain == 0) {
    saturated =
      (vAds < G0_ADS_MIN_V || vAds > G0_ADS_MAX_V);
  } else {
    saturated =
      (vAds < ADS_MIN_V || vAds > ADS_MAX_V);
  }

  bool noisy = adcStdRaw > 100.0f;

  const char* quality =
      saturated ? "saturation" :
      noisy ? "noisy" :
      "ok";

  StaticJsonDocument<768> doc;

  doc["run_id"] = cfg.runId;

  doc["sample_index"] = sampleIndex++;
  doc["elapsed_ms"] = millis() - runStartMs;

  doc["cycle"] = cycleIndex;
  doc["segment_id"] = segmentId;
  doc["segment"] = segmentText(segmentId);

  doc["potential_set_mv"] = currentPotential_mV;
  doc["potential_est_mv"] = estimatedPotential_V * 1000.0f;

  doc["dac_raw"] = dacRaw;

  doc["gain"] = activeGain;
  doc["rtia_nominal_ohm"] = activeRTIA;

  doc["adc_raw_mean"] = adcMeanRaw;
  doc["adc_raw_min"] = adcMinRaw;
  doc["adc_raw_max"] = adcMaxRaw;
  doc["adc_raw_std"] = adcStdRaw;
  doc["ads_v"] = vAds;

  doc["current_nA"] = current_nA;
  doc["current_uA"] = current_uA;

  doc["quality"] = quality;
  doc["rssi_dbm"] = WiFi.RSSI();

  char out[768];
  serializeJson(doc, out);

  mqtt.publish(TOPIC_READING, out);

  Serial.print("[DATA] ");
  Serial.println(out);
}

// ============================================================
// CV - CONTROLE DE SEGMENTOS
// ============================================================

void configureSegment(int id, int target_mV) {

  segmentId = id;
  segmentTarget_mV = target_mV;

  if (segmentTarget_mV > currentPotential_mV)
    segmentDirection = +1;
  else if (segmentTarget_mV < currentPotential_mV)
    segmentDirection = -1;
  else
    segmentDirection = 0;
}

bool reachedTarget() {

  if (segmentDirection > 0)
    return currentPotential_mV >= segmentTarget_mV;

  if (segmentDirection < 0)
    return currentPotential_mV <= segmentTarget_mV;

  return true;
}

void transitionAfterTarget() {

  // start -> vertex1
  if (segmentId == 0) {
    configureSegment(1, cfg.vVertex2_mV);
    return;
  }

  // vertex1 -> vertex2
  if (segmentId == 1) {
    configureSegment(2, cfg.vVertex1_mV);
    return;
  }

  // vertex2 -> vertex1: conclui um ciclo
  if (segmentId == 2) {

    if (cycleIndex < cfg.cycles) {
      cycleIndex++;
      configureSegment(1, cfg.vVertex2_mV);
    } else {
      configureSegment(3, cfg.vEnd_mV);
    }

    return;
  }

  // vertex1 -> end: final
  if (segmentId == 3) {

    runState = STATE_IDLE;

    // garante exatamente a tensão final
    uint16_t code = applyPotential(cfg.vEnd_mV);
    delay(2);

    publishStatus("completed", "Voltametria concluida");
    return;
  }
}

void scheduleCurrentPoint() {

  uint16_t code = applyPotential(currentPotential_mV);

  // Guarda o RAW do ponto em uma variável estática local compartilhada
  // por meio de nextPointDueMs + uma leitura posterior.
  // Para evitar nova conversão, publicamos o mesmo valor reobtido após settle.
  (void)code;

  samplePending = true;
  nextPointDueMs = pointSetAtMs + pointPeriodMs;
}

void advancePotential() {

  if (runState != STATE_RUNNING)
    return;

  if (reachedTarget()) {
    transitionAfterTarget();

    if (runState != STATE_RUNNING)
      return;
  }

  int nextPotential =
      currentPotential_mV +
      (segmentDirection * cfg.step_mV);

  // Não ultrapassa o alvo
  if (segmentDirection > 0 && nextPotential > segmentTarget_mV)
    nextPotential = segmentTarget_mV;

  if (segmentDirection < 0 && nextPotential < segmentTarget_mV)
    nextPotential = segmentTarget_mV;

  currentPotential_mV = nextPotential;

  scheduleCurrentPoint();
}

// ============================================================
// VALIDAÇÃO
// ============================================================

bool potentialInsideGainRange(int potential_mV, uint8_t gain) {
  return
    potential_mV >= GAIN_VMIN_MV[gain] &&
    potential_mV <= GAIN_VMAX_MV[gain];
}

bool validateCVConfig(String &reason) {

  if (cfg.gain > 3) {
    reason = "gain fora de 0..3";
    return false;
  }

  if (cfg.step_mV <= 0 || cfg.step_mV > 500) {
    reason = "step_mv invalido";
    return false;
  }

  if (cfg.cycles < 1 || cfg.cycles > 100) {
    reason = "cycles invalido";
    return false;
  }

  if (cfg.scanRate_mV_s <= 0.0f) {
    reason = "scan_rate invalido";
    return false;
  }

  if (cfg.adcSamples < 1 || cfg.adcSamples > 64) {
    reason = "adc_samples invalido";
    return false;
  }

  int values[4] = {
    cfg.vStart_mV,
    cfg.vVertex1_mV,
    cfg.vVertex2_mV,
    cfg.vEnd_mV
  };

  for (int i = 0; i < 4; i++) {
    if (!potentialInsideGainRange(values[i], cfg.gain)) {
      reason =
        "tensao fora da faixa experimental validada para o ganho";
      return false;
    }
  }

  return true;
}

// ============================================================
// START / STOP
// ============================================================

void startCV() {

  String reason;

  if (!validateCVConfig(reason)) {
    publishStatus("error_config", reason.c_str());
    return;
  }

  setGain(cfg.gain);

  float theoreticalPeriod =
      ((float)cfg.step_mV / cfg.scanRate_mV_s) * 1000.0f;

  uint32_t requested =
      (uint32_t)lroundf(theoreticalPeriod);

  pointPeriodMs = requested;

  if (pointPeriodMs < cfg.minPointInterval_ms)
    pointPeriodMs = cfg.minPointInterval_ms;

  // 32 amostras em 860 SPS consomem dezenas de ms;
  // manter um piso evita solicitar cadência fisicamente incompatível.
  if (pointPeriodMs < 50)
    pointPeriodMs = 50;

  sampleIndex = 0;
  cycleIndex = 1;
  segmentId = 0;

  runStartMs = millis();

  currentPotential_mV = cfg.vStart_mV;
  applyPotential(cfg.vStart_mV);

  runState = STATE_QUIET;
  quietStartMs = millis();
  samplePending = false;

  publishStatus("quiet", "Aguardando quiet time");
}

void stopCV(const char* reason) {

  runState = STATE_ABORTED;
  samplePending = false;

  publishStatus("aborted", reason);

  // retorna ao potencial final configurado, se válido
  applyPotential(cfg.vEnd_mV);

  runState = STATE_IDLE;
}

// ============================================================
// MQTT CALLBACK
// ============================================================

void mqttCallback(char* topic, byte* payload, unsigned int length) {

  char msg[1024];

  if (length >= sizeof(msg))
    length = sizeof(msg) - 1;

  memcpy(msg, payload, length);
  msg[length] = '\0';

  StaticJsonDocument<1024> doc;

  DeserializationError err =
      deserializeJson(doc, msg);

  if (err) {
    publishStatus("error_json", err.c_str());
    return;
  }

  const char* cmd = doc["cmd"] | "";

  if (strcmp(cmd, "START") == 0) {

    if (runState == STATE_RUNNING ||
        runState == STATE_QUIET) {
      publishStatus("busy", "Ensaio ja em andamento");
      return;
    }

    cfg.vStart_mV   = doc["vStart_mv"]   | -500;
    cfg.vVertex1_mV = doc["vVertex1_mv"] |  500;
    cfg.vVertex2_mV = doc["vVertex2_mv"] | -500;
    cfg.vEnd_mV     = doc["vEnd_mv"]     |    0;

    cfg.step_mV = doc["step_mv"] | 10;
    cfg.cycles  = doc["cycles"]  | 1;

    cfg.scanRate_mV_s =
      doc["scan_rate_mv_s"] | 100.0f;

    cfg.quietTime_ms =
      (uint32_t)(doc["quiet_time_ms"] | 2000);

    cfg.minPointInterval_ms =
      (uint32_t)(doc["sample_interval_ms"] | 50);

    cfg.settle_ms =
      (uint32_t)(doc["settle_ms"] | 20);

    cfg.gain =
      (uint8_t)(doc["gain"] | 2);

    cfg.adcSamples =
      (uint8_t)(doc["adc_samples"] | 16);

    const char* rid =
      doc["run_id"] | "sem-id";

    strncpy(
      cfg.runId,
      rid,
      sizeof(cfg.runId) - 1
    );

    cfg.runId[sizeof(cfg.runId) - 1] = '\0';

    startCV();
    return;
  }

  if (strcmp(cmd, "STOP") == 0) {
    stopCV("STOP recebido");
    return;
  }

  if (strcmp(cmd, "ZERO") == 0) {

    if (runState == STATE_RUNNING ||
        runState == STATE_QUIET) {
      stopCV("ZERO durante ensaio");
    }

    applyPotential(0);
    publishStatus("zero", "Potencial ajustado para 0 mV");
    return;
  }

  if (strcmp(cmd, "READ") == 0) {

    uint16_t code =
      potentialToDacRaw(currentPotential_mV);

    acquireAndPublish(code);
    return;
  }

  publishStatus("error_command", "Comando desconhecido");
}

// ============================================================
// WIFI / MQTT
// ============================================================

void setupWiFi() {

  WiFi.setSleep(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  Serial.print("[WIFI] conectando");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("[WIFI] IP=");
  Serial.println(WiFi.localIP());
}

void reconnectMQTT() {

  while (!mqtt.connected()) {

    Serial.print("[MQTT] conectando... ");

    if (
      mqtt.connect(
        MQTT_CLIENT_ID,
        MQTT_USER,
        MQTT_PASS
      )
    ) {

      Serial.println("OK");

      mqtt.subscribe(TOPIC_CMD);

      publishStatus(
        "ready",
        "Potenciostato pronto"
      );

    } else {

      Serial.print("erro=");
      Serial.println(mqtt.state());

      delay(3000);
    }
  }
}

// ============================================================
// SETUP
// ============================================================

void setup() {

  Serial.begin(115200);
  delay(500);

  Serial.println();
  Serial.println("======================================");
  Serial.println(" POTENCIOSTATO DIDATICO - CV V1");
  Serial.println(" 4 FAIXAS DE TRANSIMPEDANCIA");
  Serial.println("======================================");

  pinMode(PIN_GANHO1, OUTPUT);
  pinMode(PIN_GANHO2, OUTPUT);
  pinMode(PIN_GANHO3, OUTPUT);

  allGainSwitchesOff();

  Wire.begin(SDA_INST, SCL_INST, 400000);

  if (!adc.begin(0x48, &Wire)) {
    Serial.println("[FATAL] ADS1115 nao encontrado em 0x48");
    while (true) delay(1000);
  }

  adc.setGain(GAIN_TWOTHIRDS);
  adc.setDataRate(RATE_ADS1115_860SPS);

  if (!dac.begin(0x60, &Wire)) {
    Serial.println("[FATAL] MCP4725 nao encontrado em 0x60");
    while (true) delay(1000);
  }

  setGain(2);

  memset(&cfg, 0, sizeof(cfg));
  strncpy(cfg.runId, "boot", sizeof(cfg.runId) - 1);

  applyPotential(0);

  setupWiFi();

  mqtt.setBufferSize(1024);
  mqtt.setServer(MQTT_HOST, MQTT_PORT);
  mqtt.setCallback(mqttCallback);

  runState = STATE_IDLE;

  Serial.println("[BOOT] pronto");
}

// ============================================================
// LOOP
// ============================================================

void loop() {

  if (!mqtt.connected())
    reconnectMQTT();

  mqtt.loop();

  // ---------------- QUIET TIME ----------------
  if (runState == STATE_QUIET) {

    if (millis() - quietStartMs >= cfg.quietTime_ms) {

      runState = STATE_RUNNING;

      currentPotential_mV = cfg.vStart_mV;
      configureSegment(0, cfg.vVertex1_mV);

      scheduleCurrentPoint();

      publishStatus(
        "running",
        "Voltametria iniciada"
      );
    }
  }

  // ---------------- RUNNING ----------------
  if (runState == STATE_RUNNING) {

    // Aguarda acomodação analógica antes de ler
    if (
      samplePending &&
      millis() - pointSetAtMs >= cfg.settle_ms
    ) {

      uint16_t code =
        potentialToDacRaw(currentPotential_mV);

      acquireAndPublish(code);

      samplePending = false;
    }

    // Próximo ponto respeitando o período calculado
    if (
      !samplePending &&
      (int32_t)(millis() - nextPointDueMs) >= 0
    ) {
      advancePotential();
    }
  }
}