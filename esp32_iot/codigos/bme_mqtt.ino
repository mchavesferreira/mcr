// codigo para ESP32_bme280 com envio de publish mqtt 

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>


// Definições da rede WiFi
const char* ssid = "";
const char* password = "";

const char* ssid2 = "";       // Nome da segunda rede Wi-Fi
const char* password2 = ""; // Senha da segunda rede Wi-Fi

const char* nomedevice = "esp32_M0007";

#define DEFAULT_INTERVAL  180000 // 15 min

char topicBuffer[20];

// Definições do MQTT com autenticação
const char* mqtt_server = "brokermqtt.com.br";
const char* mqtt_username = "user";
const char* mqtt_password = "senha";

WiFiClient espClient;
PubSubClient client(espClient);




/// FIM AHT

// Definir o endereço I2C do sensor (0x76 ou 0x77)
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme;  // Objeto do sensor BME280

// Função para conectar no WiFi
/*
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}
*/

// Função para esperar pela conexão WiFi com timeout (10 segundos por padrão)
bool waitForConnection(unsigned long timeout = 10000) {
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    if (millis() - startTime > timeout) {
      return false;  // Timeout alcançado
    }
    delay(500);
    Serial.print(".");  // Mostra progresso da conexão
  }
  return true;  // Conexão bem-sucedida
}

void setup_wifi() {
  delay(10);
  Serial.println();

  // Tenta conectar à primeira rede
  Serial.print("Tentando conectar a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  if (waitForConnection()) {
    Serial.println("Conectado à primeira rede!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());
    return;  // Se conectou, sai da função
  }

  // Se falhar, tenta conectar à segunda rede
  Serial.println("Falha ao conectar à primeira rede. Tentando segunda rede...");
  WiFi.begin(ssid2, password2);
  if (waitForConnection()) {
    Serial.println("Conectado à segunda rede!");
    Serial.print("Endereço IP: ");
    Serial.println(WiFi.localIP());
  } else {
    // Se nenhuma conexão for bem-sucedida
    Serial.println("Falha ao conectar em ambas as redes.");
  }
}

// Função para reconectar no MQTT se desconectar
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    // Tenta conectar usando username e password
    if (client.connect("ESP32Client", mqtt_username, mqtt_password)) {
      Serial.println("Conectado");
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

// Configuração inicial
void setup() {
   delay(5000);
  Serial.begin(115200);
      Serial.println("Setup inicial... ");
  setup_wifi();
  client.setServer(mqtt_server, 1883);

  // Inicializa o sensor BME280
  if (!bme.begin(0x76)) {  
    Serial.println("Não foi possível encontrar o sensor BME280!");
    delay(5000);
  }




  // Configura o loop de leitura
  delay(1000);
}
/*
// Função de envio dos dados para o broker MQTT
void sendToMQTT(float temperature, float humidity, float pressure) {
  char tempString[8], humString[8], pressString[8];
  
  dtostrf(temperature, 6, 2, tempString);
  dtostrf(humidity, 6, 2, humString);
  dtostrf(pressure, 6, 2, pressString);
  
  client.publish("esp32/temperature", tempString);
  client.publish("esp32/humidity", humString);
  client.publish("esp32/pressure", pressString);
}
*/

// Função para enviar dados ao MQTT em formato JSON

/*
void sendToMQTT(float temperature, float humidity, float pressure) {
  // Criação de um buffer estático para o JSON
  StaticJsonDocument<200> jsonDoc;

  // Adiciona os valores de temperatura, umidade e pressão no formato JSON
  jsonDoc["Device"] = nomedevice;
  jsonDoc["BME280"]["Temperature"] = temperature;
  jsonDoc["BME280"]["Humidity"] = humidity;
    jsonDoc["BME280"]["Pressure"] = pressure;

  // Serializa o JSON para uma string
  char jsonBuffer[512];
  serializeJson(jsonDoc, jsonBuffer);

  // Publica o JSON no tópico MQTT
    snprintf(topicBuffer, sizeof(topicBuffer), "device/%s", nomedevice);
  client.publish(topicBuffer, jsonBuffer);
    Serial.print(" send mqtt ");
}


*/
float roundToTwoDecimals(float value) {
  return round(value * 10.0) / 10.0;
}

void sendToMQTT(float temperature, float humidity, float pressure) {
  // Criação de um buffer estático para o JSON
  StaticJsonDocument<200> jsonDoc;

  // Buffers para armazenar as strings dos valores formatados
  char tempStr[8];
  char humStr[8];
  char pressStr[8];

  // Converte os valores para string com 2 casas decimais
  dtostrf(temperature, 6, 1, tempStr); // 6 é o tamanho total, 2 é o número de casas decimais
  dtostrf(humidity, 6, 1, humStr);
  dtostrf(pressure, 6, 0, pressStr);

  // Adiciona os valores de temperatura, umidade e pressão no formato JSON
  jsonDoc["Device"] = nomedevice;
  jsonDoc["BME280"]["Temperature"] = tempStr;
  jsonDoc["BME280"]["Humidity"] = humStr;
  jsonDoc["BME280"]["Pressure"] = pressStr;

  // Serializa o JSON para uma string
  char jsonBuffer[512];
  serializeJson(jsonDoc, jsonBuffer);

  // Publica o JSON no tópico MQTT
  snprintf(topicBuffer, sizeof(topicBuffer), "device/%s", nomedevice);
  client.publish(topicBuffer, jsonBuffer);
  Serial.print(" send mqtt ");
}



// Loop principal
void loop() {

  sensors_event_t humidity2;
  sensors_event_t temp;

    // Reconnect WiFi if not connected
  while (WiFi.status() != WL_CONNECTED) {
    setup_wifi();
  }

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Leitura dos valores do sensor
  float temperature = roundToTwoDecimals(bme.readTemperature());
  float humidity = roundToTwoDecimals(bme.readHumidity());
  float pressure = roundToTwoDecimals(bme.readPressure() / 100.0F); // Conversão para hPa

  // Exibe os dados no console
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  Serial.print("Umidade: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  Serial.print("Pressão: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  sendToMQTT(temperature, humidity, pressure);



  // Envia os dados ao MQTT

  // Aguarda 10 segundos para nova leitura
  delay(DEFAULT_INTERVAL);
}
