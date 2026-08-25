/*
 * Cria uma rede wifi com esp32
 */
// Carregar biblioteca Wifi
#include <WiFi.h>
#include <WebServer.h>

#include "index.h" //O conteúdo da nossa página da web em HTML

//SSID and Password of your WiFi router
const char* ssid = "poemas";
const char* password = "123456789";


// IP Address details
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// configurar porta para webserver 80
WebServer server(80);

//===============================================================
// Esta rotina é executada quando você abre o IP dela no navegador.
//===============================================================
void handleRoot() {
 String pagina = MAIN_page_html; //variavel com conteudo html
 server.send(200, "text/html", pagina); //Enviar web page
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  
//  WiFi.softAP(ssid, password);     //Cria a rede wifi com senha
  WiFi.softAP(ssid);

//  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.println("");
 
  //Se a conexão for bem-sucedida, exiba o endereço IP no monitor serial.
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Endereço IP atribuído ao seu ESP
 
  server.on("/", handleRoot);      //Qual rotina tratar no local raiz

  server.begin();                  //Iniciar servidor
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Atender às solicitações dos clientes
}
