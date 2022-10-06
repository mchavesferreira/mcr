<h1>Aplicações de Internet das coisas com ESP32</h1>
<BR>4° Bimestre/MCR/Prof. Marcos Chaves

<P>07/Outubro/2022
##01- Criando um web server para exibir dados
<BR>Um servidor Web é um programa que usa HTTP (Hypertext Transfer Protocol) para servir os arquivos que formam páginas da Web aos usuários, em resposta às suas solicitações (métodos GET ou POST), que são encaminhadas pelos clientes HTTP de seus computadores ou smartphones.
Para implementar uma pagina web no Esp32, existem duas maneiras de fazer: <b>Web Server</b> - o servidor web primeiro se conectar ao seu roteador WiFi; ou <b>Acess Point</b> - tornar o Esp32 como ponto de acesso.
A ideia do Access Point (AP) é criar um ponto de acesso, uma rede WiFi, com nome e senha personalizadas para podermos criar uma rede local e comunicar com o ESP32. 
O access point é uma opção em locais onde não existe uma rede WiFi para conectar o ESP32, ou então existe, mas ela é instável ou inacessível.

O Esp32 disponiliza 4 modos diferentes de Wifi:

Modo estação:  utilizado para conectar o Esp32 à uma rede WiFi existente. 

Modo SOFTAP (acess point): Este é o modo utilizado para criar apenas o ponto de acesso. Por padrão, o IP do NodeMcu será 192.168.4.1. <a href= >Exemplo Acess point</a>

Modo STATIONAP: Neste modo o Esp32 é capaz de trabalhar no modo de estação e no modo SOFTAP.

Modo nulo: Este modo coloca o WiFi do Esp32 em um estado de baixo consumo, como se o módulo do WiFi ficasse desligado.

<P><b>Criando paginas html</B></p>
Todos os servidores web possuem uma página web a ser atendida. Primeiro faça uma página web usando HTML e teste-a no seu computador.
Você pode testar uma pagina web em seu navegador, utilizando bloco de notas para escrever o código HTML. Salve como index.htm e abra em seu browser.
<code><HTML>
	<HEAD>
		<TITLE>My first web page</TITLE>
	</HEAD>
<BODY>
	<CENTER>
		<B>Hello World.... </B>
	</CENTER>	
</BODY>
</HTML>
</code>

Formatação Html

<a href=https://www.w3schools.com/htmL/default.asp>Guia de elementos html</a> para a formatação de paginas html.

<P><P>
  <b>Exemplo Web Server</b><BR>
  <img src=https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/07/esp32-we-server.jpg?resize=524%2C276&quality=100&strip=all&ssl=1>
  <BR><a href=https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/webserver/webserver.ino>Exemplo Webserver</a>

<P><P>
  <b>Exemplo Acess-Point</b><BR>
  <img src=imagens/acesspoint.png>
  <BR><a href= https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/acess_point/acess_point.ino>Exemplo acess point</a>

   <P><P>
Referências:
<BR>https://mundoprojetado.com.br/criar-access-point-com-nodemcu/
<BR>https://randomnerdtutorials.com/esp32-web-server-arduino-ide/
<br> https://randomnerdtutorials.com/esp32-access-point-ap-web-server/
<br> https://circuits4you.com/2016/12/16/esp8266-web-server-html/
