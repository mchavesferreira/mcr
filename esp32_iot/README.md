<h1>Aplicações de Internet das coisas com ESP32</h1>
<BR>4° Bimestre/MCR/Prof. Marcos Chaves
<BR>
	<P>07/Outubro/2022
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
  
  
  ### Criando comunicação para IOT
  
 ## Acess-Point com programação em blocos
 
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
  WiFi.begin("Isaweb_1","julia3103");
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

   <P><P>
Referências:
<BR>https://mundoprojetado.com.br/criar-access-point-com-nodemcu/
<BR>https://randomnerdtutorials.com/esp32-web-server-arduino-ide/
<br> https://randomnerdtutorials.com/esp32-access-point-ap-web-server/
<br> https://circuits4you.com/2016/12/16/esp8266-web-server-html/
