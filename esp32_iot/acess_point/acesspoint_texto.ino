#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "MeuESP32AP";
const char* password = "senha123";

AsyncWebServer server(80);

void setup() {
  // Inicializa a Serial para depuração
  Serial.begin(115200);

  // Inicia o ponto de acesso WiFi
  WiFi.softAP(ssid, password);

  // Recupera o endereço IP do ponto de acesso
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Endereço IP do Access Point: ");
  Serial.println(IP);

  // Defina a rota para lidar com a página HTML
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body><h1>Olá, mundo!</h1></body></html>";
    request->send(200, "text/html", html);
  });

  // Inicia o servidor
  server.begin();
}

void loop() {
  // O loop pode ser vazio
}
