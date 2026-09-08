// Controlador de sorveteria com ESP32, OLED e botoes na pagina web

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "index.h"


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


#define LED_ROXO 12
#define LED_ROSA 13
#define LED_AMARELO 14


WebServer server(80);


// Variaveis globais

int bolas = 1;
int estado = 0;

String sabor = "-";
String cobertura = "-";
String recipiente = "-";
String mensagem = "Escolha o numero de bolas";

unsigned long tempoanterior = 0;


// Dados da rede Wi-Fi

const char* ssid = "suarede";
const char* password = "suasenha";


// Prototipos das funcoes da maquina de estados

void pergunta1();
void pergunta2();
void pergunta3();
void pergunta4();
void processo1();
void processo2();
void processo3();
void processo4();


//===============================================================
// Exibe uma mensagem no display OLED
//===============================================================

void mostraOLED(String linha1, String linha2) {

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 5);
  display.println("Sorveteria doce sabor");

  display.setCursor(0, 25);
  display.println(linha1);

  display.setCursor(0, 43);
  display.println(linha2);

  display.display();
}


//===============================================================
// Pagina principal
//===============================================================

void handleRoot() {

  String s = MAIN_page;

  server.send(200, "text/html", s);
}


//===============================================================
// Rotas utilizadas pelo AJAX para consultar o pedido
//===============================================================

void handleEstado() {
  server.send(200, "text/plain", String(estado));
}

void handleBolas() {
  server.send(200, "text/plain", String(bolas));
}

void handleSabor() {
  server.send(200, "text/plain", sabor);
}

void handleCobertura() {
  server.send(200, "text/plain", cobertura);
}

void handleRecipiente() {
  server.send(200, "text/plain", recipiente);
}

void handleMensagem() {
  server.send(200, "text/plain", mensagem);
}


//===============================================================
// Reinicia as escolhas ou o pedido em processamento
//===============================================================

void handleReiniciar() {

  bolas = 1;
  sabor = "-";
  cobertura = "-";
  recipiente = "-";

  digitalWrite(LED_ROXO, LOW);
  digitalWrite(LED_ROSA, LOW);
  digitalWrite(LED_AMARELO, LOW);

  tempoanterior = millis();
  estado = 0;
  mensagem = "Escolha o numero de bolas";

  mostraOLED("Numero de bolas:", String(bolas));

  server.send(200, "text/plain", "OK");
}


//===============================================================
// Botoes da pergunta 1 - numero de bolas
//===============================================================

void handleMais() {

  if (estado == 0 && bolas < 5) {
    bolas++;
  }

  server.send(200, "text/plain", "OK");
}


void handleMenos() {

  if (estado == 0 && bolas > 1) {
    bolas--;
  }

  server.send(200, "text/plain", "OK");
}


void handleConfirmar() {

  if (estado == 0) {
    estado = 1;
    mensagem = "Escolha o sabor";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


//===============================================================
// Botoes da pergunta 2 - sabor
//===============================================================

void handleSabor1() {

  if (estado == 1) {
    sabor = "Ovomaltine";
    estado = 2;
    mensagem = "Escolha a cobertura";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


void handleSabor2() {

  if (estado == 1) {
    sabor = "Mamao";
    estado = 2;
    mensagem = "Escolha a cobertura";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


void handleSabor3() {

  if (estado == 1) {
    sabor = "Tutti-frutti";
    estado = 2;
    mensagem = "Escolha a cobertura";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


//===============================================================
// Botoes da pergunta 3 - cobertura
//===============================================================

void handleCobertura1() {

  if (estado == 2) {
    cobertura = "Chocolate";
    estado = 3;
    mensagem = "Escolha o recipiente";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


void handleCobertura2() {

  if (estado == 2) {
    cobertura = "Chiclete";
    estado = 3;
    mensagem = "Escolha o recipiente";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


void handleCobertura3() {

  if (estado == 2) {
    cobertura = "Doce de leite";
    estado = 3;
    mensagem = "Escolha o recipiente";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


//===============================================================
// Botoes da pergunta 4 - recipiente
//===============================================================

void handleRecipiente1() {

  if (estado == 3) {
    recipiente = "Pequeno";
    estado = 4;
    tempoanterior = millis();
    mensagem = "Adicionando " + String(bolas) + " bolas";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


void handleRecipiente2() {

  if (estado == 3) {
    recipiente = "Medio";
    estado = 4;
    tempoanterior = millis();
    mensagem = "Adicionando " + String(bolas) + " bolas";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


void handleRecipiente3() {

  if (estado == 3) {
    recipiente = "Grande";
    estado = 4;
    tempoanterior = millis();
    mensagem = "Adicionando " + String(bolas) + " bolas";
      Serial.println(mensagem);

  }

  server.send(200, "text/plain", "OK");
}


//===============================================================
// SETUP
//===============================================================

void setup() {

  Serial.begin(115200);

  pinMode(LED_ROXO, OUTPUT);
  pinMode(LED_ROSA, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);

  digitalWrite(LED_ROXO, LOW);
  digitalWrite(LED_ROSA, LOW);
  digitalWrite(LED_AMARELO, LOW);


  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Falha ao iniciar o display SSD1306");
    for (;;);
  }


  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Sorveteria doce sabor");
  display.setCursor(0, 30);
  display.println("Iniciando Wi-Fi");
  display.display();


  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Conectando em ");
  Serial.println(ssid);

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.print(".");
  }


  Serial.println();
  Serial.print("Endereco IP: ");
  Serial.println(WiFi.localIP());


  // Rotas para consulta AJAX

  server.on("/", handleRoot);
  server.on("/estado", handleEstado);
  server.on("/bolas", handleBolas);
  server.on("/sabor", handleSabor);
  server.on("/cobertura", handleCobertura);
  server.on("/recipiente", handleRecipiente);
  server.on("/mensagem", handleMensagem);
  server.on("/reiniciar", handleReiniciar);


  // Rotas dos botoes da pagina

  server.on("/mais", handleMais);
  server.on("/menos", handleMenos);
  server.on("/confirmar", handleConfirmar);

  server.on("/sabor1", handleSabor1);
  server.on("/sabor2", handleSabor2);
  server.on("/sabor3", handleSabor3);

  server.on("/cobertura1", handleCobertura1);
  server.on("/cobertura2", handleCobertura2);
  server.on("/cobertura3", handleCobertura3);

  server.on("/recipiente1", handleRecipiente1);
  server.on("/recipiente2", handleRecipiente2);
  server.on("/recipiente3", handleRecipiente3);


  server.begin();

  Serial.println("Servidor HTTP iniciado");
}


//===============================================================
// LOOP
//===============================================================

void loop() {

  server.handleClient();

  switch (estado) {
    case 0: pergunta1(); break;
    case 1: pergunta2(); break;
    case 2: pergunta3(); break;
    case 3: pergunta4(); break;
    case 4: processo1(); break;
    case 5: processo2(); break;
    case 6: processo3(); break;
    case 7: processo4(); break;
  }

  delay(1);
}


//===============================================================
// PERGUNTA 1
//===============================================================

void pergunta1() {

  mensagem = "Escolha o numero de bolas: " + String(bolas);

  mostraOLED("Numero de bolas:", String(bolas));
}


//===============================================================
// PERGUNTA 2
//===============================================================

void pergunta2() {

  mensagem = "Escolha o sabor";
  mostraOLED("Escolha o sabor:", "Use a pagina web");
}


//===============================================================
// PERGUNTA 3
//===============================================================

void pergunta3() {

  mensagem = "Escolha a cobertura";
  mostraOLED("Escolha cobertura:", "Use a pagina web");
}


//===============================================================
// PERGUNTA 4
//===============================================================

void pergunta4() {

  mensagem = "Escolha o recipiente";
  mostraOLED("Escolha recipiente:", "Use a pagina web");
}


//===============================================================
// PROCESSO 1 - ADICIONA AS BOLAS
//===============================================================

void processo1() {

  mensagem = "Adicionando " + String(bolas) + " bolas";
  mostraOLED("Adicionando", String(bolas) + " bolas...");

  digitalWrite(LED_AMARELO, HIGH);

  if ((millis() - tempoanterior) > 5000) {
    Serial.println("Numero de bolas adicionadas");
    digitalWrite(LED_AMARELO, LOW);

    tempoanterior = millis();
    estado = 5;
  }
}


//===============================================================
// PROCESSO 2 - ADICIONA O SABOR
//===============================================================

void processo2() {

  mensagem = "Adicionando o sabor " + sabor;
  mostraOLED("Adicionando sabor:", sabor);

  digitalWrite(LED_ROXO, HIGH);

  if ((millis() - tempoanterior) > 5000) {
    Serial.println("Sabor selecionado..");
    digitalWrite(LED_ROXO, LOW);

    tempoanterior = millis();
    estado = 6;
  }
}


//===============================================================
// PROCESSO 3 - ADICIONA A COBERTURA
//===============================================================

void processo3() {

  mensagem = "Adicionando cobertura de " + cobertura;
  mostraOLED("Cobertura:", cobertura);

  digitalWrite(LED_ROSA, HIGH);

  if ((millis() - tempoanterior) > 5000) {
    Serial.println("Cobertura realizada");
    digitalWrite(LED_ROSA, LOW);

    tempoanterior = millis();
    estado = 7;
  }
}


//===============================================================
// PROCESSO 4 - PEDIDO PRONTO
//===============================================================

void processo4() {

  mensagem = "Pedido pronto. Bom apetite!";
  
  mostraOLED("Pedido pronto!", "Bom apetite!");

  if ((millis() - tempoanterior) > 10000) {
   Serial.println("Pedido pronto.. Reinciando para novo pedido");
    bolas = 1;
    sabor = "-";
    cobertura = "-";
    recipiente = "-";

    mensagem = "Escolha o numero de bolas";

    estado = 0;
  }
}
