/*
 * VOLTAMETRICO - MODO DE CALIBRACAO V4
 *
 * OBJETIVO
 * -------
 * Calibrar novamente a cadeia completa após alterações de resistores:
 *
 *   DAC RAW -> estágio analógico -> tensão real na carga
 *   corrente conhecida pela dummy cell -> TIA -> condicionamento -> ADS1115
 *
 * Nesta versão NÃO existe pré-calibração do DAC.
 * O comando é feito diretamente em RAW (0...4095).
 *
 * ALTERAÇÕES DE HARDWARE INFORMADAS
 * ---------------------------------
 * R15 / RTIA base = 10 MΩ
 * C2              = 100 pF
 * R25             = 1 kΩ
 *
 * Ganhos adicionais em paralelo com R15:
 * GPIO12 -> 15 kΩ
 * GPIO11 -> 150 kΩ
 * GPIO10 -> 2 MΩ
 *
 * Lógica opto + ADG444:
 * ESP HIGH -> opto conduz -> IN do ADG444 = LOW -> chave FECHADA
 * ESP LOW  -> opto desliga -> pull-up -> IN do ADG444 = HIGH -> chave ABERTA
 *
 * ADS1115:
 * Para esta etapa de calibração é usado GAIN_TWOTHIRDS (±6,144 V)
 * para permitir medir sinais entre 0 e ~5 V sem saturar em 4,096 V.
 * Resolução: 187,5 uV/bit.
 *
 * MQTT
 * ----
 * comando: ic/potenciostato/calibracao/comando
 * leitura: ic/potenciostato/calibracao/leitura
 * status:  ic/potenciostato/calibracao/status
 *
 * Comando:
 * {"cmd":"SET_RAW","dac_raw":2048,"gain":0}
 */

#include <Wire.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <Adafruit_ADS1X15.h>
#include <Adafruit_MCP4725.h>

// ============================================================
// REDE / MQTT
// ============================================================

const char* ssid          = "Isaweb_1";
const char* wifi_password = "julia3103"; 
const char* mqtt_server   = "rpiot.com.br";
const int   mqtt_port     = 1883;
const char* mqtt_user     = "rpiotlora";
const char* mqtt_password = "rp234aA42c";

const char* client_id = "voltametrico-calibracao-v4";

const char* topic_cmd     = "ic/potenciostato/calibracao/comando";
const char* topic_leitura = "ic/potenciostato/calibracao/leitura";
const char* topic_status  = "ic/potenciostato/calibracao/status";

WiFiClient espClient;
PubSubClient client(espClient);

// ============================================================
// HARDWARE
// ============================================================

#define SDA_INST 8
#define SCL_INST 9

#define PIN_GANHO1 12   // 15 kΩ
#define PIN_GANHO2 11   // 150 kΩ
#define PIN_GANHO3 10   // 2 MΩ

Adafruit_ADS1115 adc;
Adafruit_MCP4725 dac;

// ============================================================
// CONSTANTES ANALÓGICAS
// ============================================================

const float VDAC_SUPPLY = 5.000f;

// TIA alterado
const float R_BASE = 10000000.0f;  // 10 MΩ
const float R_G1   =    15000.0f;  // 15 kΩ
const float R_G2   =   150000.0f;  // 150 kΩ
const float R_G3   =  2000000.0f;  // 2 MΩ

// ADS1115 GAIN_TWOTHIRDS => 187,5 uV / bit
const float ADC_LSB_V = 0.0001875f;

// Média para reduzir a flutuação durante a calibração
const uint8_t ADC_SAMPLES = 32;

float current_RTIA = R_BASE;
int gainIndex = 0;
uint16_t dacRaw = 2048;

unsigned long lastPublish = 0;
const unsigned long publishInterval = 500;

// ============================================================
// UTILIDADES
// ============================================================

float paralelo(float r1, float r2) {
  return 1.0f / ((1.0f / r1) + (1.0f / r2));
}

int clampInt(int value, int minValue, int maxValue) {
  if (value < minValue) return minValue;
  if (value > maxValue) return maxValue;
  return value;
}

// ============================================================
// GANHO DO TIA
// ============================================================

void allGainSwitchesOff() {
  // LOW no ESP -> opto OFF -> pull-up -> ADG444 HIGH -> chave aberta
  digitalWrite(PIN_GANHO1, LOW);
  digitalWrite(PIN_GANHO2, LOW);
  digitalWrite(PIN_GANHO3, LOW);
}

void setGainDiscrete(int gain) {

  allGainSwitchesOff();
  delayMicroseconds(20);

  gainIndex = 0;
  current_RTIA = R_BASE;

  switch (gain) {

    case 1:
      digitalWrite(PIN_GANHO1, HIGH);
      gainIndex = 1;
      current_RTIA = paralelo(R_BASE, R_G1);
      break;

    case 2:
      digitalWrite(PIN_GANHO2, HIGH);
      gainIndex = 2;
      current_RTIA = paralelo(R_BASE, R_G2);
      break;

    case 3:
      digitalWrite(PIN_GANHO3, HIGH);
      gainIndex = 3;
      current_RTIA = paralelo(R_BASE, R_G3);
      break;

    case 0:
    default:
      gainIndex = 0;
      current_RTIA = R_BASE;
      break;
  }

  Serial.print("[GAIN] indice=");
  Serial.print(gainIndex);
  Serial.print("  RTIA=");
  Serial.print(current_RTIA, 2);
  Serial.println(" ohm");
}

// ============================================================
// DAC RAW
// ============================================================

void setDACRaw(int code) {

  code = clampInt(code, 0, 4095);

  dacRaw = (uint16_t)code;
  dac.setVoltage(dacRaw, false);

  float vdac = ((float)dacRaw / 4095.0f) * VDAC_SUPPLY;

  Serial.print("[DAC] RAW=");
  Serial.print(dacRaw);
  Serial.print("  V_pino_DAC_teorico=");
  Serial.print(vdac, 6);
  Serial.println(" V");
}

// ============================================================
// LEITURA ESTATÍSTICA DO ADS1115
// ============================================================

void readADCStats(
  int16_t &lastRaw,
  float &meanRaw,
  int16_t &minRaw,
  int16_t &maxRaw,
  float &stdRaw,
  float &meanV
) {

  int32_t sum = 0;
  double sumSq = 0.0;

  minRaw = 32767;
  maxRaw = -32768;
  lastRaw = 0;

  for (uint8_t k = 0; k < ADC_SAMPLES; k++) {

    int16_t raw = adc.readADC_SingleEnded(0);

    lastRaw = raw;

    sum += raw;
    sumSq += (double)raw * (double)raw;

    if (raw < minRaw) minRaw = raw;
    if (raw > maxRaw) maxRaw = raw;
  }

  meanRaw = (float)sum / (float)ADC_SAMPLES;

  double meanSq = sumSq / (double)ADC_SAMPLES;
  double variance =
      meanSq - ((double)meanRaw * (double)meanRaw);

  if (variance < 0.0) variance = 0.0;

  stdRaw = sqrt(variance);
  meanV = meanRaw * ADC_LSB_V;
}

// ============================================================
// TELEMETRIA
// ============================================================

void publishReading() {

  int16_t adcLastRaw;
  float adcMeanRaw;
  int16_t adcMinRaw;
  int16_t adcMaxRaw;
  float adcStdRaw;
  float adcMeanV;

  readADCStats(
    adcLastRaw,
    adcMeanRaw,
    adcMinRaw,
    adcMaxRaw,
    adcStdRaw,
    adcMeanV
  );

  StaticJsonDocument<512> doc;

  doc["dac_raw"]       = dacRaw;
  doc["dac_v_theory"]  =
      ((float)dacRaw / 4095.0f) * VDAC_SUPPLY;

  doc["adc_raw"]       = (int)lroundf(adcMeanRaw);
  doc["adc_raw_mean"]  = adcMeanRaw;
  doc["adc_raw_last"]  = adcLastRaw;
  doc["adc_raw_min"]   = adcMinRaw;
  doc["adc_raw_max"]   = adcMaxRaw;
  doc["adc_raw_std"]   = adcStdRaw;
  doc["adc_v"]         = adcMeanV;
  doc["adc_samples"]   = ADC_SAMPLES;
  doc["adc_lsb_uv"]    = ADC_LSB_V * 1e6f;

  doc["gain"]          = gainIndex;
  doc["rtia_ohm"]      = current_RTIA;

  char payload[512];
  serializeJson(doc, payload);

  client.publish(topic_leitura, payload);

  Serial.print("[LEITURA] ");
  Serial.println(payload);
}

// ============================================================
// MQTT
// ============================================================

void mqttCallback(char* topic, byte* payload, unsigned int length) {

  char msg[512];

  if (length >= sizeof(msg))
    length = sizeof(msg) - 1;

  memcpy(msg, payload, length);
  msg[length] = '\0';

  Serial.print("[MQTT RX] ");
  Serial.println(msg);

  StaticJsonDocument<512> doc;

  DeserializationError error =
      deserializeJson(doc, msg);

  if (error) {
    client.publish(topic_status, "erro_json");
    return;
  }

  const char* cmd = doc["cmd"] | "";

  if (strcmp(cmd, "SET_RAW") == 0) {

    int code = doc["dac_raw"] | (int)dacRaw;
    int gain = doc["gain"]    | gainIndex;

    if (code < 0 || code > 4095) {
      client.publish(topic_status, "erro_dac_raw");
      return;
    }

    if (gain < 0 || gain > 3) {
      client.publish(topic_status, "erro_gain");
      return;
    }

    setGainDiscrete(gain);
    setDACRaw(code);

    client.publish(topic_status, "calibracao_ativa");
    publishReading();
    return;
  }

  if (strcmp(cmd, "READ") == 0) {
    publishReading();
    return;
  }

  if (strcmp(cmd, "DAC_ZERO") == 0) {
    setDACRaw(0);
    client.publish(topic_status, "dac_raw_0");
    publishReading();
    return;
  }

  if (strcmp(cmd, "DAC_MID") == 0) {
    setDACRaw(2048);
    client.publish(topic_status, "dac_raw_2048");
    publishReading();
    return;
  }

  if (strcmp(cmd, "DAC_MAX") == 0) {
    setDACRaw(4095);
    client.publish(topic_status, "dac_raw_4095");
    publishReading();
    return;
  }

  client.publish(topic_status, "erro_comando");
}

// ============================================================
// REDE
// ============================================================

void setup_wifi() {

  WiFi.setSleep(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, wifi_password);

  Serial.print("[WIFI] Conectando");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("[WIFI] IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect_mqtt() {

  while (!client.connected()) {

    Serial.print("[MQTT] Conectando... ");

    if (
      client.connect(
        client_id,
        mqtt_user,
        mqtt_password
      )
    ) {

      Serial.println("OK");
      client.subscribe(topic_cmd);
      client.publish(topic_status, "calibracao_pronta");

    } else {

      Serial.print("falha rc=");
      Serial.println(client.state());
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
  Serial.println("==========================================");
  Serial.println(" VOLTAMETRICO - CALIBRACAO V4");
  Serial.println(" DAC em RAW 0...4095");
  Serial.println(" RTIA base = 10 Mohm");
  Serial.println(" ADS1115 = GAIN_TWOTHIRDS");
  Serial.println("==========================================");

  pinMode(PIN_GANHO1, OUTPUT);
  pinMode(PIN_GANHO2, OUTPUT);
  pinMode(PIN_GANHO3, OUTPUT);

  allGainSwitchesOff();

  Wire.begin(SDA_INST, SCL_INST, 400000);

  if (!adc.begin(0x48, &Wire)) {
    Serial.println("[ERRO FATAL] ADS1115 nao encontrado em 0x48");
    while (true) delay(1000);
  }

  adc.setGain(GAIN_TWOTHIRDS);
  adc.setDataRate(RATE_ADS1115_860SPS);

  if (!dac.begin(0x60, &Wire)) {
    Serial.println("[ERRO FATAL] MCP4725 nao encontrado em 0x60");
    while (true) delay(1000);
  }

  setGainDiscrete(0);
  setDACRaw(2048);

  setup_wifi();

  client.setBufferSize(768);
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(mqttCallback);

  Serial.println("[BOOT] Calibracao V4 pronta.");
}

// ============================================================
// LOOP
// ============================================================

void loop() {

  if (!client.connected())
    reconnect_mqtt();

  client.loop();

  if (millis() - lastPublish >= publishInterval) {
    lastPublish = millis();
    publishReading();
  }
}