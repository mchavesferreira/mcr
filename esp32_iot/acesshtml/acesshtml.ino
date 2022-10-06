/*
 * Hello world web server
 * circuits4you.com
 */
// Carregar biblioteca Wifi
#include <WiFi.h>
#include <WebServer.h>

#include "index.h" //Our HTML webpage contents

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
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void){
  Serial.begin(115200);
  
//  WiFi.begin(ssid, password);     //Connect to your WiFi router
  WiFi.softAP(ssid);

//  WiFi.softAPConfig(local_ip, gateway, subnet);
  Serial.println("");

  

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
 
  server.on("/", handleRoot);      //Which routine to handle at root location

  server.begin();                  //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void){
  server.handleClient();          //Handle client requests
}
