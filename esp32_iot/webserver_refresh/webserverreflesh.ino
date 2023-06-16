#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "SUA_REDE_WIFI";
const char* password = "SENHA_REDE_WIFI";

const int pinoSensor = 26;

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Conecta-se à rede WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando à rede WiFi...");
  }

  Serial.println("Conectado à rede WiFi");

  // Rota para servir o arquivo HTML
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, [](const String& var) {
      if (var == "STATUS") {
        // Verifica o estado do pino 26
        int status = digitalRead(pinoSensor);
        return String(status);
      }
      return String();
    });
  });

  // Inicia o servidor
  server.begin();
  
  // Configura o pino do sensor como entrada
  pinMode(pinoSensor, INPUT);
}

void loop() {
  // Coloque aqui o código do loop principal, se necessário
}
