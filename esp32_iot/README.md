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
- [Links interessantes](#Links-interessantes)

https://www.youtube.com/watch?v=KndZoTMCRsA
Aveiro Tech City Living Lab

# ESP32 em Iot

## IP

IP (Internet Protocol) é um conjunto de regras que permite o envio e recebimento de dados pela internet ou por redes locais. Ele define os endereços IP, que são identificadores numéricos atribuídos a cada dispositivo conectado a uma rede. Esses endereços permitem que os dados sejam enviados para o destino correto. Existem dois tipos principais de endereços IP: IPv4, que é composto por quatro números separados por pontos (ex: 192.168.0.1), e IPv6, que usa uma combinação maior de números e letras para suportar mais dispositivos (ex: 2001:0db8:85a3:0000:0000:8a2e:0370:7334). O IP é essencial para o roteamento de informações entre dispositivos em redes.

## MAC Adress

O MAC address (Media Access Control address) é um identificador único atribuído a dispositivos de rede, como placas de rede Wi-Fi ou Ethernet, usado para identificar cada dispositivo em uma rede local. Ele consiste em um conjunto de 48 bits, normalmente representado como seis pares de dígitos hexadecimais (ex: 00:1A:2B:3C:4D:5E). Diferente de um endereço IP, que pode mudar dependendo da rede, o MAC address é atribuído permanentemente ao hardware pelo fabricante, servindo como um identificador fixo em redes locais.

## Topologia das redes

<img src=https://raw.githubusercontent.com/mchavesferreira/mcr/refs/heads/main/esp32_iot/imagens/topologiarede.JPG>

Topologia de rede, ou arquitetura de rede, refere-se à forma como os dispositivos e conexões em uma rede estão organizados fisicamente ou logicamente. Existem diferentes tipos de topologias, como:

- Topologia em estrela: Todos os dispositivos estão conectados a um único ponto central, como um switch ou roteador.
- 
- Topologia em barramento: Todos os dispositivos compartilham uma única linha de comunicação.
- 
- Topologia em anel: Os dispositivos são conectados em uma estrutura circular, com dados circulando em uma única direção.
- 
- Topologia em malha: Cada dispositivo está conectado a vários outros, permitindo múltiplos caminhos de comunicação.
  
- Topologia ponto-a-ponto: Conecta diretamente dois dispositivos entre si.

Cada topologia tem características específicas em termos de eficiência, custo e complexidade, sendo escolhida conforme as necessidades da rede.

Rede Submarina de fibra ótica: 

https://www.submarinecablemap.com/

## DNS

O DNS (Domain Name System) é um sistema que traduz nomes de domínio legíveis por humanos (como www.exemplo.com) em endereços IP numéricos (como 192.168.1.1) que os computadores utilizam para identificar dispositivos e serviços na rede. Funciona como uma espécie de "agenda telefônica" da internet, permitindo que os usuários acessem sites e outros recursos online usando nomes amigáveis, sem precisar memorizar números IP. O DNS é essencial para o funcionamento da internet, facilitando a comunicação entre dispositivos e servidores.

Propagação DNS 

<img src=https://raw.githubusercontent.com/mchavesferreira/mcr/refs/heads/main/esp32_iot/imagens/dnspropagacao.png>

https://www.whatsmydns.net


<BR><BR> Registro traceroute Registro.br
<BR><BR> https://registro.br/tecnologia/ferramentas/traceroute/
	
## Webserver

<BR>Criando um web server para controle e exibição de dados (Dashboard)<BR>
	
 <BR> <img src=imagens/webserver.png>
	
<BR>Um servidor Web é um programa que usa HTTP (Hypertext Transfer Protocol) para servir os arquivos que formam páginas da Web aos usuários, em resposta às suas solicitações (métodos GET ou POST), que são encaminhadas pelos clientes HTTP de seus computadores ou smartphones.
<BR>Para implementar uma pagina web no Esp32, existem duas maneiras de fazer: 
	<BR><b>-Web Server</b> - o servidor web primeiro se conectar ao seu roteador WiFi; ou
	<BR><b>-Acess Point</b> - tornar o Esp32 como ponto de acesso.
<BR>A ideia do Access Point (AP) é criar um ponto de acesso, uma rede WiFi, com nome e senha personalizadas para podermos criar uma rede local e comunicar com o ESP32. 
<BR>O access point é uma opção em locais onde não existe uma rede WiFi para conectar o ESP32, ou então existe, mas ela é instável ou inacessível.

#### O Esp32 disponiliza 4 modos diferentes de Wifi:

##### Modo estação:  utilizado para conectar o Esp32 à uma rede WiFi existente. 

##### Modo SOFTAP (acess point): Este é o modo utilizado para criar apenas o ponto de acesso. Por padrão, o IP do NodeMcu será 192.168.4.1. 

##### Modo STATIONAP: Neste modo o Esp32 é capaz de trabalhar no modo de estação e no modo SOFTAP.

##### Modo nulo: Este modo coloca o WiFi do Esp32 em um estado de baixo consumo, como se o módulo do WiFi ficasse desligado.

### Paginas html

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



### Exemplos de códigos modo Estação e Acess-Point

#### Exemplo Modo Estação

 <img src=imagens/station.png>
 
  <BR><a href=https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/webserver/webserver.ino>Codigo .ino estação</a>


#### Exemplo Acess-Point Wifi

  <img src=imagens/acesspoint.png>
  
  <BR><a href=https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/acess_point/acess_point.ino>Codigo .ino acess point</a>
<p></p>
 <P>O exemplo a seguir que cria um codigo html a partir utilizando o esp32 como servidor para controlar dois leds. </P>
<a href=acess_point/exemplo_botao.html target=_blank>html de resposta</a><P></P>

  <BR><a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot/acesshtml>Codigo .ino e pagina web em index.h</a>

### Webserver com Ajax

O conceito de "web server com AJAX" em uma aplicação ESP32 refere-se à criação de uma interface web onde o ESP32 atua como servidor. Isso permite que dispositivos clientes, como navegadores, se conectem e interajam com ele via uma página web. Usando AJAX (Asynchronous JavaScript and XML), o cliente pode solicitar dados do ESP32 de maneira assíncrona, sem a necessidade de recarregar toda a página web. Essa técnica é muito útil para atualizações dinâmicas, como exibir informações de sensores em tempo real ou enviar comandos para o ESP32, mantendo a interface fluida e responsiva.

  <img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/webserverajax/montagem.png><BR>
  <img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/webserverajax/circuito1.jpg><BR>
 Este exemplo mostra em um pagina web o valor de status ou leitura de pinos do Esp32 sem recarga da pagina.<P>
 <img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/webserverajax/status.jpg><BR>
<BR>Salve os arquivos: webserver2.ino e index.h em uma pasta. Modifique senha e login de wifi.<BR>


   <BR><a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot/webserverajax>Codigo webAjax </a> <BR>


<BR>
 O valores são substituidos nos "ID" a cada intervalo de tempo, buscando a String de uma url no próprio microcontrolador.
 
# Internet das Coisas (IoT)

A Internet das Coisas (IoT) refere-se à interconexão de dispositivos físicos que podem coletar, processar e trocar dados pela internet. Esses dispositivos, que vão desde sensores, eletrodomésticos, veículos até sistemas industriais, estão equipados com software, sensores e conectividade para interagir e responder a comandos de forma autônoma. O IoT permite a automação e monitoramento de processos em tempo real, tornando possível, por exemplo, o controle remoto de dispositivos em uma casa, como luzes e termostatos, ou o monitoramento de máquinas industriais, aumentando a eficiência, segurança e conveniência.


## Residencial e IOT

O uso de IoT em uma residência com o ESP32 permite criar um ambiente automatizado e inteligente, conectando dispositivos e sensores através da rede Wi-Fi para monitoramento e controle remoto. Com o ESP32, é possível integrar iluminação, controle de temperatura, segurança, eletrodomésticos e sistemas de irrigação, tornando a casa mais eficiente e conveniente. Por exemplo, o ESP32 pode ser programado para acionar luzes automaticamente ao detectar movimento, ajustar o termostato com base em leituras de temperatura e umidade, ou enviar alertas via smartphone em caso de detecção de intrusos ou eventos inesperados, como vazamentos de água, tudo através de uma interface web ou aplicativos móveis​.

Exemplo:  Automação Residencial com ESP32 – Controle sua Casa pela Web (Usina info)

https://www.usinainfo.com.br/blog/automacao-residencial-com-esp32-controle-sua-casa-pela-web/


	  	  
## Plataformas IOT

### Thingspeak

<BR>Enviando dados para nuvem utilizando Thingspeak
<BR><a href=https://thingspeak.com/ target=_blank border=0><img src=imagens/thingspeak.png>Thingspeak</a>
<BR>
<BR><a href=https://wokwi.com/projects/364642003805651969>Exemplo online</a><BR>
	
	
## MQTT
<BR>Comunicação de dados IOT utilizando protocolo MQTT
<img src=imagens/mqtt-publish-subscribe.png><br>Mqtt.org
<img src=imagens/mqtt_mensagem.png><BR>

O MQTT (Message Queuing Telemetry Transport) é um protocolo de comunicação leve e eficiente, projetado para conectar dispositivos em redes com largura de banda limitada ou conexões instáveis, como em aplicações de Internet das Coisas (IoT). Ele utiliza o modelo de publicação/assinatura, onde os clientes podem publicar mensagens em tópicos específicos ou assinar tópicos para receber atualizações, com a intermediação de um servidor central chamado "broker". O MQTT é otimizado para minimizar o uso de recursos, sendo ideal para dispositivos com pouca capacidade de processamento e energia, como sensores e atuadores.

Saiba mais:  https://www.gta.ufrj.br/ensino/eel878/redes1-2019-1/vf/mqtt/


Broker:
Utilizando um broker MQTT publico
	  http://www.hivemq.com/demos/websocket-client/
   <P><P>
Referências:<BR>
https://wiki.foz.ifpr.edu.br/wiki/index.php/Arduino:_MQTT
https://mqtt.org/
https://embarcados.com.br/mqtt-protocolos-para-iot/
https://aws.amazon.com/pt/what-is/mqtt/
https://embarcados.com.br/mqtt-protocolos-para-iot/


 
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

# Nodered 


Node-red Oficial:  https://flows.nodered.org/

Node-red Apresentação:  http://smartcampus.ctd.ifsp.edu.br/blog/index.php?IDselecionado=50

Instalar Node-red: http://smartcampus.ctd.ifsp.edu.br/blog/index.php?IDselecionado=45

Primeiros exemplos:

## Acesse seu nodered

http://168.138.131.96:198x


### Ajude-me:  

https://chatgpt.com/g/g-TFvuISQH5-professor-dos-embarcados 


- Utilizando um DNS free
  
 http://smartcampus.ctd.ifsp.edu.br/blog/index.php?IDselecionado=30 Redirecionamento DDNS com DuckDns 

### Exemplos nodered

[flow_exemplos/README.md](https://github.com/mchavesferreira/sebe/tree/main/flow_exemplos)


Importe este primeiro fluxo:

https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/node_red_estudo.json

### Trabalhando com mysql, node-red e mqtt

Importe para o node-red o flow:

https://github.com/mchavesferreira/embarcados_freertos/blob/main/exemplo_node_red_mqtt_mysql_dht_sensor.json

Adicione os nodes faltantes:  

ui_led 

node-red-node-mysql

Crie a conexão MQTT local, e conecte ao banco de dados Mysql

A base de dados será a mesma utilizada para o projeto 1, disponível em: https://github.com/mchavesferreira/php_app

Simule a conexão utilizando o circuito tratado em aulas anteriores:  https://wokwi.com/projects/365211000246545409


### Formato JSON

<a href=https://github.com/mchavesferreira/sebe/blob/main/flow_exemplos/json.md>Saiba mais sobre o formato json</a>

Importe este exemplo para o nodered: <a href=https://github.com/mchavesferreira/sebe/blob/main/flow_exemplos/cotacao_dolar.json>Exemplo de cotação dolar</a>

Instale um plugin no navegador para facilitar a compreensão de um json: <a href=https://addons.mozilla.org/en-US/firefox/addon/json_formatter/>firefox</a>









	   
### Exemplo ESP32, mqtt e dashboard node-red
<br> Utiizando um tópico:

<BR>https://wokwi.com/projects/365211000246545409
<BR>
https://wokwi.com/projects/381558252547499009
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


#Links-interessantes


## DNS
<BR><BR> Consultar propagação DNS
<BR><BR> https://www.whatsmydns.net/

<BR><BR> Registro traceroute Registro.br
<BR><BR> https://registro.br/tecnologia/ferramentas/traceroute/

