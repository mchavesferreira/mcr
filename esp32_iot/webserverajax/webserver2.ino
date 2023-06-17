/*
 * ESP32 AJAX Demo
 * Updates and Gets data from webpage without page refresh
 * https://circuits4you.com
 * Adaptação: Marcos Chaves jun/2023
 */
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>



#include "index.h"  //Web page header file

// Vetor para armazenar as frases
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

 int i=0;

//Enter your SSID and PASSWORD
const char* ssid = "Isaweb_1";
const char* password = "julia3103";

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
 
void handleADC() {
 int a = analogRead(32);
 String adcValue = String(a);
 server.send(200, "text/plane", adcValue); //Envia valor ADC pino 32 para a requisição cliente ajax 
}

void handlegpio1() {
 int b = analogRead(33);   // le o valor analógico no pino 33
 String adcValue = String(b);
 server.send(200, "text/plane", adcValue); 
}

void handlegpio2() {
 int c = analogRead(34);  // le o valor analógico no pino 34
 String adcValue = String(c);  
 server.send(200, "text/plane", adcValue); 
}

void handlemsgoled() {
 String s = frases[i]; //le o indice i no vetor frase i e salva na string s
 server.send(200, "text/html", s); //envia para webpage
  i++;
 if(i>=10)i=0;
}

//===============================================================
// Setup
//===============================================================

void setup(void){
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

/*
//ESP32 As access point  descomentar para criar uma acess point
  WiFi.mode(WIFI_AP); //Access Point mode
  WiFi.softAP(ssid, password);
*/
//ESP32 connects to your wifi -----------------------------------
  WiFi.mode(WIFI_STA); //Connectto your wifi
  WiFi.begin(ssid, password);

  Serial.println("Connecting to ");
  Serial.print(ssid);

  //Wait for WiFi to connect
  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
    }
    
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Cponectado em SSID: ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
//----------------------------------------------------------------
 
  server.on("/", handleRoot);      //pagina inicial principal
  server.on("/readADC", handleADC);//busca a funcao handle especifica para url requisitada
  server.on("/readgpio1", handlegpio1);
  server.on("/readgpio2", handlegpio2);
  server.on("/msgoled", handlemsgoled);
  server.begin();                  //inicia webserver
  Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void loop(void){
  server.handleClient();
  delay(1);
}


//  funcooes


