# Microcontroladores

 
## Utilizando ESP32, Arduino IDE e simulador Wokwi para aprendizado da programação de sistemas embarcados e dispositivos IOT.



## Aulas
- [Apostila ESP32](#Apostila-ESP32)
- [Arduino Referências](#Referências-Arduino)
- [Pinout Esp32](#pinout-esp32)
- [Arquitetura Esp32](#arquitetura-esp32)
- [Simulador Online](#simulador-wokwi)
- [Funções principais](#Funçoes-principais)
- [Variáveis e Operadores](#variaveis-operadores)
- [GPIOs, leitura e escrita em pinos digitais](#gpio-digital)
- [Tabelas e vetores](#tabelas-vetores)
- [PWM](#pwm)
- [Comunicação Serial](#Comunicação-serial)
- [Display](#Display)
	- [LCD 16x2](#lcd-16x2)
	- [Oled](#display-oled)
- [Interrupções e Funções de tempo](#tempo)
	- [millis()](#função-millis)
	- [Interrupção Externa](#Interrupção-externa)
- [Acesso GET POST](#Acesso-GET-POST)
- [Servidor Web](#servidor-web)
- [IOT, Protocolo MQTT e Alexa](#IOT-Protocolo-MQTT-Alexa)
- [Exemplos de projetos](#Exemplos-de-projetos)
- [Cloud para desenvolvimento] (#Cloud-para-desenvolvimento)
- [Livros]



## Apostila ESP32
<BR> <a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/ESP32.docx>Apostila</a> em desenvolvimento

<BR> <a href=https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf>Datasheet ESP32</a>

## Referências Arduino
<center>  <a href=https://www.arduino.cc/reference/pt/>Arduino Referência de Linguagem C</a> </center><BR>

## Pinout ESP32
<br><a href=https://microcontrollerslab.com/wp-content/uploads/2019/02/ESP32-pinout-mapping.png target=_blank><img src=https://microcontrollerslab.com/wp-content/uploads/2019/02/ESP32-pinout-mapping.png>ESP32 pinout<a/>
<BR><a href=https://randomnerdtutorials.com/esp32-pinout-reference-gpios/>Configuração I/O</a> para cada pino.
<BR>Como verificar o ID do chip<a href=https://wokwi.com/projects/340959007153848914> Chip ID</a><BR>  

# Sensores internos

Os pinos SENSOR_VP e SENSOR_VN são pinos analógicos dedicados para a interface de entrada do sensor Hall interno no microcontrolador ESP32.

# Pinos RTC_GPIO <br><br>
<BR>Os pinos RTC_GPIO no ESP32 são pinos de entrada/saída que são capazes de operar tanto em modo RTC (Real Time Clock) quanto em modo digital normal. Esses pinos são conectados ao subsistema RTC do chip ESP32 e podem ser usados para uma variedade de funções relacionadas a relógios e temporizadores.
<br><br>
O subsistema RTC no ESP32 é responsável por manter um relógio em tempo real com alta precisão, mesmo quando o chip está em modo de baixo consumo de energia ou em modo de hibernação. Os pinos RTC_GPIO podem ser usados para acionar interrupções de baixo consumo de energia no subsistema RTC, permitindo que o chip acorde em momentos específicos para executar tarefas agendadas.
<br><br>
Além disso, os pinos RTC_GPIO também podem ser usados para funções de entrada/saída de uso geral no modo digital normal, como outros pinos de entrada/saída do ESP32. Eles suportam diferentes níveis de sinal, incluindo níveis TTL e CMOS, e podem ser configurados como entrada ou saída de acordo com as necessidades do projeto.
<br><br>
Em resumo, os pinos RTC_GPIO são úteis para aplicações que envolvem temporizadores, relógios e baixo consumo de energia. Eles permitem que o ESP32 acorde em momentos específicos para executar tarefas agendadas, o que é útil em aplicações de IoT, por exemplo, onde o dispositivo precisa permanecer em modo de baixo consumo de energia na maior parte do tempo para economizar energia.
<br><br>	
## Arquitetura Esp32	<BR><BR>
	<BR> - Mapeamento da memória (pagina 7) <a href=https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf>m<BR>emory</a>
	<BR> -
	<bR> -
	
## Simulador Wokwi

Simulador <a href=https://wokwi.com/projects/new/esp32>ESP32 Online</a>
<BR>
Teclas de atalho e tutorial para o <a href=https://docs.wokwi.com/pt-BR/guides/diagram-editor> Simulador Wokwi</a>
 

	
## Funçoes principais
<details><summary>Conheça as principais funções em wiring disponíveis na IDE Arduino (clique)</summary>
	
<BR><B>Funções</b>
<bR>Para controlar a placa Arduino e realizar computações.
<BR><b>Entradas e Saídas Digitais</b>
<BR>digitalRead()
<BR>digitalWrite()
<BR>pinMode() 
<BR>
  <BR><B>Entradas e Saídas Analógicas</b>
<BR>analogRead()
<BR>analogReference()
<BR>analogWrite() 
<BR>
<BR><B>Funções Temporizadoras</b>
<BR>delay()
<BR>delayMicroseconds()
<BR>micros()
<BR>millis()
<BR>
  
<BR><B>Comunicação</b>
<BR>Serial
<BR>Stream 
<BR>
<BR><B>Variáveis</b>
<BR>
<BR>Tipos de dados e constantes da linguagem Arduino.
<BR><B>Constantes</b>
<BR>HIGH | LOW
<BR>INPUT | OUTPUT | INPUT_PULLUP
<BR>LED_BUILTIN
<BR>true | false
<BR>Constantes de Ponto Flutuante
<BR>Constantes Inteiras
 <BR> 
<BR><B>Tipos de Dados</b>
<BR>bool
<BR>boolean
<BR>byte
<BR>char
<BR>double
<BR>float
<BR>int
<BR>long
<BR>short
<BR>size_t
<BR>string
<BR>String()
<BR>unsigned char
<BR>unsigned int
<BR>unsigned long
<BR>vetor
<BR>void
<BR>word 
<BR><BR> 

</details>


	
## variaveis operadores
  <BR>Variáveis e Operadores</b><BR>  

 <BR>- Uso de HEX, DEC, BIN e OCT  <a href=https://wokwi.com/projects/340328764284076626>print()  </a>



## GPIO Digital
Uso de Variáveis, #define e funções próprias para I/0 Arduino
<BR>GPIOs, leitura e escrita em pinos digitais. Simulação: <a href=https://wokwi.com/projects/339670467067511378>digitalRead() e digitalWrite()</a>


## Tabelas Vetores
<P>Uso de <B>Vetores</B> ou tabelas para organização de variáveis
<BR>01: <a href=https://wokwi.com/projects/341561728616628819> Mapeamento de pinos ESP32</a>

## PWM
<P>PWM - Simulando saída analógica
<BR>02: <a href=https://wokwi.com/projects/341562296506516051>LED RGB e uso de analog_write() para PWM</a>
<P>Função Debounce e uso de condição de fluxo IF
<BR>03: <a href=https://wokwi.com/projects/341562149868405330>Alternando cores em LEDS</a>
<P>PWM e leitura analógia alterando RGB
<BR><a href=https://wokwi.com/projects/341599671301440083>PWM-Analog</a><P>


<P><a href=http://www.cdme.im-uff.mat.br/matrix/matrix-html/matrix_color_cube/matrix_color_cube_br.html>Tabela de cores RGB</a>
<P> 	
	
## Leitura analógica
<bR>02: ADC - Leitura analógica, conversão de valores com funções e a função mapeamento. Simulação: <a href=https://wokwi.com/projects/340963795998343762> analogRead()</a>

## Comunicação Serial
Imprimindo e lendo na porta serial (UART)<BR>
  
<details><summary>Codigo Serial</summary>
<p>

```ruby
   Serial.begin(115200);
   Serial.println("Please enter your name:");
   while (!Serial.available()); // Wait for input
   String name = Serial.readStringUntil('\n');
   Serial.print("Hello, ");
   Serial.print(name);
```

</p>
</details>

  
<BR>Simulação: <a href=https://wokwi.com/projects/341561853822894674>Comunicando através da entrada serial</a>
<P>Exemplos aplicando porta serial e PWM
<BR>05: <a href=https://wokwi.com/projects/341698810319209042>Leitura de cores utilizando serial</a>.<span size=-2> Autores: Vinicius Viana e  Luis H. Estareli</span>.

## Display
 
<BR>Displays LCD, Oled, comunicação I2C
### LCD 16x2
  <BR>01 -<a href=https://wokwi.com/projects/342202939017790036> Exemplo LCD 16x2 paralelo</a>
  <BR>02 -<a href=https://wokwi.com/projects/342199886273315410> Exemplo LCD 16x2 I2C</a>
  
### Display Oled   
  <BR>03 -<a href=https://wokwi.com/projects/342195248670179922> Exemplo Oled U8g2lib</a>
  <BR>04 -<a href=https://wokwi.com/projects/342195418005766739> Exemplo Adafruit_SSD1306</a>
  <Br> <img src=https://github.com/mchavesferreira/mcr/blob/main/imagens/oled.png width=400 height=225><BR>
<details><summary>Exemplo Oled</summary>
<p>

```ruby  
*/
#include <U8g2lib.h>
#include <Wire.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  u8g2.begin();
}

void loop() {
  u8g2.clearBuffer();	// limpa memoria interna
  u8g2.setFont(u8g2_font_ncenB08_tr);	// escolha da fonte
  u8g2.drawStr(15, 10, "IFSP Catanduva");	// escrevendo na memoria interna
  u8g2.sendBuffer(); // transferindo da memoria interna para display
  delay(1000);
}  
```
</p>
</details> 
	  
## Tempo
	  
### Interrupção e funções de tempo
  ### função millis
  <br>05 -<a href=https://wokwi.com/projects/342203041946010194> Exemplo função tempo millis()</a>
	  
### Interrupção externa
  <br>06 -<a href=https://wokwi.com/projects/342203713958445651> Exemplo função Interrupção()</a>
<BR>  
 <br><a href=https://wokwi.com/projects/342234932555285074>bomba</a>
  


## Acesso GET POST

<BR>Exemplo de aplicação com métodos de acesso URL para uplink ou downlink de informações (payload)
	





## Servidor Web
<P><a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot>Esp32 como servidor de pagina</a><B> Introdução a internet das coisas </b>

<a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot><img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/imagens/webserver.png width=50% border=0></a>


## Exemplos de projetos

Está faltando imaginação!!! 
	
Busque na Internet exemplos para aplicar os conhecimentos sobre a programação com microcontroladores.
	
Se o projeto for bem documentado, é possível inscrevê-lo em feira de ciências, realizá-lo como trabalho de conclusão de curso (TCC), apresentá-lo em congressos, revistas e eventos ciêntíficos, ou até criar um produto e registá-lo como uma patente.
A seguir apresentamos links de eventos e revistas ciêntíficas para colaborar com sua idéia.
- CONICT  
	
    -- Trabalhos apresentados em formato online (<a href=https://www.youtube.com/channel/UC4hDqSkORN1rHfyrIIMu9SA/videos>canal youtube</a>)
	
    -- Artigos Conict (<a href=http://ocs.ifsp.edu.br/index.php/conict> Anais </a>)
 
- FECCIF- Feira Estadual de Ciência e Cultura do IFSP (http://feccip.com.br> Pagina</a>)

Outros:
- Seleção de projetos <a href=https://github.com/mchavesferreira/mcr/blob/81e149b137445a6df07bdaa17b2f0c46f31eff36/dicas%20de%20projetos/Dicas%20para%20projetos.pdf> Dicas de projetos.pdf</a>

	- <a href=https://embarcados.com.br> Embarcados </a> Site de uma comunidade sobre sistemas embarcados
	- 
## IOT, Protocolo MQTT, Alexa

Uso do protocolo MQTT para envio de mensagens entre dispositivos de internet das coisas (IOT). 


## Residencial e IOT
Automação Residencial com ESP32 – Controle sua Casa pela Web (Usina info)
https://www.usinainfo.com.br/blog/automacao-residencial-com-esp32-controle-sua-casa-pela-web/

## Curso IOT aplicações em automação com esp32
https://mjrobot.org/2017/09/26/iot-feito-facil-brincando-com-o-esp32-no-arduino-ide/

### Integração com Alexa

ESP32 integração com Alexa. Utilizando a biblioteca Espalexa para acionar GPIOs com nomes reconhecidos pela echo-dot.
<BR>Fonte: https://mjrobot.org/2020/12/31/home-automation-with-alexa/<BR>
<br>Código fonte de integração com a alexa corrigido: <a href=https://github.com/mchavesferreira/mcr/blob/main/dicas%20de%20projetos/alexa_casa.ino>Alexa controlando luzes</a><br> 

## Protocolo MQTT para IOT
aula <BR>  http://smartcampus.ctd.ifsp.edu.br/blog/index.php?IDselecionado=48

Aplicativo: Dash MQTT  
https://play.google.com/store/apps/details?id=net.routix.mqttdash

MQTT Público:  http://www.hivemq.com/demos/websocket-client/<BR>
host:  broker.hivemq.com<BR>
username: mchavesferreira<BR>
password: Embar2022<BR>
topic: movel/acelerax<BR>

Exemplo Wokwi, com tópico em IFSP/led

https://wokwi.com/projects/347942096378790483


##  Estudo de redes ESP32-WiFi-Sniffer
O chip WiFi no ESP32 pode ser alternado para o chamado “modo promíscuo”, que permite monitorar pacotes WiFi sem se conectar à própria rede. Em particular, podemos ver os endereços MAC dos dispositivos próximos:
https://github.com/ESP-EOS/ESP32-WiFi-Sniffer

https://hackmag.com/security/esp32-sniffer/

## Frameworks:

Utilizando frameworks (pacotes de programas) prontos para iniciar uma automação com poucas ou nenhuma linha de códigos. Alguns frameworks permitem a gravação através do navegador Chrome.<BR>
1 - OpenMQTTGateway v1.0.0 - https://docs.openmqttgateway.com/upload/web-install.html<BR>
2 - ESP Easy’s https://espeasy.readthedocs.io/en/latest/index.html<BR>
3 - ESP Web Tools https://esphome.github.io/esp-web-tools/ <BR>
4 - Tasmota https://tasmota.github.io/docs/<BR>


# Linguagens e programação
## Programando através de blocos
### Easycondig

Aprenda a programar o ESP32 para IOT através de videos tutoriais organizado em 3 partes (Stand-alone, Local-Network e Internet)
http://easycoding.tn/index.php/esp32/  (Videos tutoriais)

http://www.easycoding.tn/esp32/demos/code/  (ambiente de programação)

Exemplo XML com código fonte para websever: https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/easycoding_xml.xml

### codeskool

https://ide.codeskool.cc/

### mpyblockly
Programação visual em micropython para ESP32
https://mpyblockly.github.io/mpyblockly/

Brincando com Esp32
https://mjrobot.org/2017/09/26/iot-feito-facil-brincando-com-o-esp32-no-arduino-ide/
	
## FreeRtos

Blink com FreeRtos
<A href=https://github.com/PacktPublishing/Internet-of-Things-Projects-with-ESP32/blob/master/Chapter01/blinking/main/blinking.c>source code</a>
<BR><BR>
## Cloud para desenvolvimento
<BR>#Blynk
<BR>https://blynk.io/
<BR>O Blynk foi desenvolvido para ser utilizado em projetos IoT, com ele conseguimoscomunicar através do celular com nossa placa ESP-32 e controlá-la via Wi-fi ouBluetooth.

<BR>#IFTT
https://ifttt.com/

<BR>#Tago IO
https://tago.io/
	
<BR>#Arduino IoT Cloud
https://cloud.arduino.cc/
	
	
<BR>## Livros e codigo fonte
<BR> 
<img src=https://static.packt-cdn.com/products/9781789956870/cover/smaller> Internet of Things Projects with ESP32, <BR><BR>
https://download.packt.com/free-ebook/9781789956870,<BR><BR> source code: https://github.com/PacktPublishing/Internet-of-Things-Projects-with-ESP32 <BR><BR>
https://github.com/PacktPublishing/Developing-IoT-Projects-with-ESP32-2nd-edition<BR>
https://github.com/PacktPublishing/Internet-of-Things-with-ESP32<BR>
https://github.com/PacktPublishing/Advanced-ESP32	<BR>
Características para ESP32<BR><BR>
  https://www.espressif.com/en/news/espressif-announces-%E2%80%A8esp32-s2-secure-wi-fi-mcu
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
   
Livros e Codigos fontes<Br><BR>
https://github.com/PacktPublishing/Advanced-ESP32
	
	
	
	