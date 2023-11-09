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
    String html = "<html><head><style>body { background-color: #f0f0f0; text-align: center; } h1 { color: #3333cc; }</style></head><body><h1>Poema de Camões</h1><p style='font-size: 18px;'>Amor é fogo que arde sem se ver;<br>É ferida que dói e não se sente;<br>É um contentamento descontente;<br>É dor que desatina sem doer;<br>É um não querer mais que bem querer;<br>É solitário andar por entre a gente;<br>É nunca contentar-se de contente;<br>É cuidar que se ganha em se perder.<br>É querer estar preso por vontade;<br>É servir a quem vence, o vencedor;<br>É ter com quem nos mata lealdade.<br>Mas como causar pode seu favor<br>Nos corações humanos amizade,<br>Se tão contrário a si é o mesmo Amor?</p></body></html>";
    request->send(200, "text/html", html);
  });

  // Inicia o servidor
  server.begin();
}

void loop() {
  // O loop pode ser vazio
}
