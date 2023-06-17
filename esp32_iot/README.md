# ESP32 IOT

 
## Aplicações de Internet das Coisas com ESP32
- [Webserver](#Webserver)
- [Criando comunicação para IOT](#Criando-comunicação-para-IOT)
	- [Acess-Point](#Acess-Point)
	- [Oled](#display-oled)
- [Residencial e IOT](#Residencial-e-IOT)
- [Thingspeak](#Residencial-e-IOT)
- [MQTT](#MQTT)
- [Integração com Alexa](#Integração-com-Alexa)
- [Explorando recursos da comunicação WIFI](#Explorando-recursos-com-a-comunicação-WIFI)
- [Frameworks](#Frameworks)
- [FreeRtos](#FreeRtos)
- [Cloud para desenvolvimento](#Cloud-para-desenvolvimento)
- [ESP32-Cam](#ESP32-Cam)
- Dashboard

https://www.youtube.com/watch?v=KndZoTMCRsA
Aveiro Tech City Living Lab

	
## Webserver
<BR>01- Criando um web server para controle e exibição de dados (Dashboard)<BR>
	
 <BR> <img src=imagens/webserver.png>
	
<BR>Um servidor Web é um programa que usa HTTP (Hypertext Transfer Protocol) para servir os arquivos que formam páginas da Web aos usuários, em resposta às suas solicitações (métodos GET ou POST), que são encaminhadas pelos clientes HTTP de seus computadores ou smartphones.
<BR>Para implementar uma pagina web no Esp32, existem duas maneiras de fazer: 
	<BR><b>-Web Server</b> - o servidor web primeiro se conectar ao seu roteador WiFi; ou
	<BR><b>-Acess Point</b> - tornar o Esp32 como ponto de acesso.
<BR>A ideia do Access Point (AP) é criar um ponto de acesso, uma rede WiFi, com nome e senha personalizadas para podermos criar uma rede local e comunicar com o ESP32. 
<BR>O access point é uma opção em locais onde não existe uma rede WiFi para conectar o ESP32, ou então existe, mas ela é instável ou inacessível.

O Esp32 disponiliza 4 modos diferentes de Wifi:

Modo estação:  utilizado para conectar o Esp32 à uma rede WiFi existente. 

Modo SOFTAP (acess point): Este é o modo utilizado para criar apenas o ponto de acesso. Por padrão, o IP do NodeMcu será 192.168.4.1. 

Modo STATIONAP: Neste modo o Esp32 é capaz de trabalhar no modo de estação e no modo SOFTAP.

Modo nulo: Este modo coloca o WiFi do Esp32 em um estado de baixo consumo, como se o módulo do WiFi ficasse desligado.

<P><b>Criando paginas html</B></p>
Todos os servidores web possuem uma página web a ser atendida. Primeiro faça uma página web usando HTML e teste-a no seu computador.
Você pode testar uma pagina web em seu navegador, utilizando bloco de notas para escrever o código HTML. Salve como index.htm e abra em seu browser.
	
	
```ruby
	<HTML>
	<HEAD>
		<TITLE>Minha primeira pagina web</TITLE>
	</HEAD>
<BODY>
	<CENTER>
		<B>Olá mundo.... </B>
	</CENTER>	
</BODY>
</HTML>
```

<a href=https://www.w3schools.com/htmL/default.asp>Guia de elementos html</a>. A w3schools disponiliza um vasto tutorial de formatação de elementos em Html e outras formatações para criação de paginas html.



<P><P>
  <b>Exemplo Modo Estação</b><BR>
 <img src=imagens/station.png>
  <BR><a href=https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/webserver/webserver.ino>Codigo .ino estação</a>

<P><P>
  <b>Exemplo Acess-Point Wifi</b><BR>
  <img src=imagens/acesspoint.png>
  <BR><a href=https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/acess_point/acess_point.ino>Codigo .ino acess point</a>
  <BR><a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot/acesshtml>Codigo .ino e pagina web em index.h</a>

### Webserver com atualização sem recarga da pagina
  <img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/webserverajax/montagem.png><BR>
  <img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/webserverajax/circuito1.jpg><BR>
 Este exemplo mostra em um pagina web o valor de status ou leitura de pinos do Esp32 sem recarga da pagina.<P>
 <img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/webserverajax/status.jpg><BR>
<BR>Salve os arquivos: webserver2.ino e index.h em uma pasta. Modifique senha e login de wifi.<BR>


   <BR><a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot/webserverajax>Codigo webAjax </a> <BR>

<BR>
 ```ruby
   <html>
      <h1>GPIO 32:<span id="ADCValue"></span></h1><br>
      <h1>GPIO 33:<span id="gpio1"></span></h1><br>
      <h1>GPIO 34:<span id="gpio2"></span></h1><br>
      <h1>Status:<span id="textoserial"></span></h1>
    </html>

```
<BR>
 O valores são substituidos nos "ID" a cada intervalo de tempo, buscando a String de uma url no próprio microcontrolador.
 
## Criando comunicação para IOT
  
### Código de Acess-Point gerado com a programação em blocos
 <br><img src=imagens/blocos.jpg><BR>
<a href=easycoding.tn target=_blank>Easycoding.tn</a><br><BR>
 ```javascript
 /////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <WiFi.h>

IPAddress staticIP69_196(192,168,15,196);
IPAddress gateway69_196(192,168,15,1);
IPAddress subnet69_196(255,255,255,0);

void setup()
{
Serial.begin(9600);

  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
  WiFi.begin("redewifi","senha");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  WiFi.config(staticIP69_196, gateway69_196, subnet69_196);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));

}


void loop()
{

    client.println("bom dia");

}
 
 
 ```


## Residencial e IOT
Automação Residencial com ESP32 – Controle sua Casa pela Web (Usina info)
https://www.usinainfo.com.br/blog/automacao-residencial-com-esp32-controle-sua-casa-pela-web/


	  	  
## Thingspeak
<BR>Enviando dados para nuvem utilizando Thingspeak
<BR><a href=https://thingspeak.com/ target=_blank border=0><img src=imagens/thingspeak.png>Thingspeak</a>
<BR>
<BR><a href=https://wokwi.com/projects/364642003805651969>Exemplo online</a><BR>
	
	
## MQTT
<BR>Comunicação de dados IOT utilizando protocolo MQTT
Saiba mais:  https://www.gta.ufrj.br/ensino/eel878/redes1-2019-1/vf/mqtt/

Utilizando um broker MQTT publico
	  http://www.hivemq.com/demos/websocket-client/
   <P><P>
 
## Protocolo MQTT para IOT
aula <BR>  http://smartcampus.ctd.ifsp.edu.br/blog/index.php?IDselecionado=48

Aplicativo: Dash MQTT  
https://play.google.com/store/apps/details?id=net.routix.mqttdash

Exemplo utilizando broker MQTT Público:  http://www.hivemq.com/demos/websocket-client/<BR>
Configure os campos:<BR>
host:  broker.hivemq.com<BR>
username: mchavesferreira<BR>
password: Embar2022<BR>
topic: movel/acelerax<BR>

Exemplo Wokwi, com tópico em IFSP/led<BR>

https://wokwi.com/projects/347942096378790483
	   
### Exemplo ESP32, mqtt e dashboard node-red
	   
<BR>https://wokwi.com/projects/365211000246545409
<BR>
<BR>https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/node_red1.json
<BR>https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/node_red_estudo.json
	   
<BR><BR>
## Integração com Alexa

ESP32 integração com Alexa. Utilizando a biblioteca Espalexa para acionar GPIOs com nomes reconhecidos pela echo-dot.
<BR>Fonte: https://mjrobot.org/2020/12/31/home-automation-with-alexa/<BR>
<br>Código fonte de integração com a alexa corrigido: <a href=https://github.com/mchavesferreira/mcr/blob/main/dicas%20de%20projetos/alexa_casa.ino>Alexa controlando luzes</a><br> 

## Frameworks

Utilizando frameworks (pacotes de programas) prontos para iniciar uma automação com poucas ou nenhuma linha de códigos. Alguns frameworks permitem a gravação através do navegador Chrome.<BR>
1 - OpenMQTTGateway v1.0.0 - https://docs.openmqttgateway.com/upload/web-install.html<BR>
2 - ESP Easy’s https://espeasy.readthedocs.io/en/latest/index.html<BR>
3 - ESP Web Tools https://esphome.github.io/esp-web-tools/ <BR>
4 - Tasmota https://tasmota.github.io/docs/<BR>
5 - <a href=https://esphome.io/ target=_blank>ESPHome</a> 	
   
## Explorando recursos com a comunicação WIFI
<BR><BR>  https://www.espressif.com/en/news/espressif-announces-%E2%80%A8esp32-s2-secure-wi-fi-mcu
<BR><BR>
-O que é Wifi  Direct<BR>
https://www.digitaltrends.com/computing/what-is-wi-fi-direct/
<BR><BR>
-Aplicação prática com ESP-NOW<BR>
https://www.youtube.com/watch?v=6NsBN42B80Q<BR>
<BR><BR>
-ESP32 Mesh Desenvolvimento do framework<BR>
https://www.youtube.com/watch?v=8JaK2W0avr0<BR>
<BR><BR>

## FreeRtos

Blink com FreeRtos
<A href=https://github.com/PacktPublishing/Internet-of-Things-Projects-with-ESP32/blob/master/Chapter01/blinking/main/blinking.c>source code</a>
<BR><BR>
	
## Cloud para desenvolvimento
### Blynk
<BR>https://blynk.io/
<BR>O Blynk foi desenvolvido para ser utilizado em projetos IoT, com ele conseguimoscomunicar através do celular com nossa placa ESP-32 e controlá-la via Wi-fi ouBluetooth.<BR>

### IFTT
<BR>https://ifttt.com/
<BR>
### Tago IO
<BR>https://tago.io/<BR>
	
### Arduino IoT Cloud
<BR>https://cloud.arduino.cc/<BR>
	
## ESP32-Cam
Este dispositivo para prototipação de aplicações, que além dos recursos de WIFI e Bluetooth presente em módulos do Esp32, inclui uma câmera de 2Mp. Suporta câmeras OV2640 e OV7670
<BR>Pinos do módulo ESP32-Cam
<img src=https://github.com/mchavesferreira/mcr/blob/main/esp32cam/ESP32-CAM-pinout-mischianti.jpg>
<P>
<BR>Conexão utilizando um adaptador USB-TTL para gravação do firmware:
<BR><img src=https://github.com/mchavesferreira/mcr/blob/main/esp32cam/esp32-cam-upload-sketch-connection-schema-5v.jpg>
	
	
##  Estudo de redes ESP32-WiFi-Sniffer
O chip WiFi no ESP32 pode ser alternado para o chamado “modo promíscuo”, que permite monitorar pacotes WiFi sem se conectar à própria rede. Em particular, podemos ver os endereços MAC dos dispositivos próximos:
https://github.com/ESP-EOS/ESP32-WiFi-Sniffer
https://hackmag.com/security/esp32-sniffer/
	
	
Referências:
<BR>Curso IOT aplicações em automação com esp32
https://mjrobot.org/2017/09/26/iot-feito-facil-brincando-com-o-esp32-no-arduino-ide/
<BR>https://mundoprojetado.com.br/criar-access-point-com-nodemcu/
<BR>https://randomnerdtutorials.com/esp32-web-server-arduino-ide/
<br> https://randomnerdtutorials.com/esp32-access-point-ap-web-server/
<br> https://circuits4you.com/2016/12/16/esp8266-web-server-html/
