/*
 * ESP32 AJAX Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
 * Adaptação: Marcos Chaves jun/2023
 *
 * Acrescentado:
 * - Botão LIGAR
 * - Botão DESLIGAR
 * - Controle do GPIO 25
 */

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "index.h"

//--------------------------------------------------------------
// Configuração da saída
//--------------------------------------------------------------

#define SAIDA 25

//--------------------------------------------------------------
// Vetor para armazenar as frases
//--------------------------------------------------------------

const String frases[] PROGMEM = {
  "Você é capaz!",
  "Nunca desista!",
  "Acredite em si mesmo!",
  "Persista e conquiste!",
  "Todo esforço vale a pena!",
  "Supere seus limites!",
  "Pense positivo!",
  "Sonhe grande!",
  "Seja resiliente!",
  "Faça Acontecer!"
};

WebServer server(80);

int i = 0;

//--------------------------------------------------------------
// Wi-Fi
//--------------------------------------------------------------

const char* ssid = "";
const char* password = "";


//===============================================================
// Página principal
//===============================================================

void handleRoot() {

  String s = MAIN_page;

  server.send(200, "text/html", s);
}


//===============================================================
// Entrada analógica GPIO 32
//===============================================================

void handleADC() {

  int a = analogRead(32);

  String adcValue = String(a);

  server.send(200, "text/plain", adcValue);
}


//===============================================================
// Entrada analógica GPIO 33
//===============================================================

void handlegpio1() {

  int b = analogRead(33);

  String adcValue = String(b);

  server.send(200, "text/plain", adcValue);
}


//===============================================================
// Entrada analógica GPIO 34
//===============================================================

void handlegpio2() {

  int c = analogRead(34);

  String adcValue = String(c);

  server.send(200, "text/plain", adcValue);
}


//===============================================================
// Mensagem
//===============================================================

void handlemsgoled() {

  String s = frases[i];

  server.send(200, "text/plain", s);

  i++;

  if (i >= 10)
    i = 0;
}


//===============================================================
// LIGAR saída
//===============================================================

void handleLigar() {

  digitalWrite(SAIDA, HIGH);

  Serial.println("Saida LIGADA");

  server.send(200, "text/plain", "LIGADO");
}


//===============================================================
// DESLIGAR saída
//===============================================================

void handleDesligar() {

  digitalWrite(SAIDA, LOW);

  Serial.println("Saida DESLIGADA");

  server.send(200, "text/plain", "DESLIGADO");
}


//===============================================================
// Consultar estado da saída
//===============================================================

void handleEstado() {

  if (digitalRead(SAIDA) == HIGH) {

    server.send(200, "text/plain", "LIGADO");

  } else {

    server.send(200, "text/plain", "DESLIGADO");
  }
}


//===============================================================
// SETUP
//===============================================================

void setup(void) {

  Serial.begin(115200);

  Serial.println();
  Serial.println("Booting Sketch...");


  //-------------------------------------------------------------
  // Configura saída digital
  //-------------------------------------------------------------

  pinMode(SAIDA, OUTPUT);

  // inicia desligada
  digitalWrite(SAIDA, LOW);


  /*
  // ESP32 como Access Point
  // Descomentar para criar um Access Point

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  */


  //-------------------------------------------------------------
  // ESP32 conecta na rede Wi-Fi
  //-------------------------------------------------------------

  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid, password);

  Serial.println("Connecting to ");
  Serial.print(ssid);


  // Aguarda conexão

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {

    Serial.print(".");
  }


  //-------------------------------------------------------------
  // Mostra endereço IP
  //-------------------------------------------------------------

  Serial.println("");

  Serial.print("Conectado em SSID: ");
  Serial.println(ssid);

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());


  //-------------------------------------------------------------
  // Rotas do servidor HTTP
  //-------------------------------------------------------------

  server.on("/", handleRoot);

  server.on("/readADC", handleADC);

  server.on("/readgpio1", handlegpio1);

  server.on("/readgpio2", handlegpio2);

  server.on("/msgoled", handlemsgoled);


  // Novas rotas de controle

  server.on("/ligar", handleLigar);

  server.on("/desligar", handleDesligar);

  server.on("/estado", handleEstado);


  //-------------------------------------------------------------
  // Inicia servidor
  //-------------------------------------------------------------

  server.begin();

  Serial.println("HTTP server started");
}


//===============================================================
// LOOP
//===============================================================

void loop(void) {

  server.handleClient();

  delay(1);
}
