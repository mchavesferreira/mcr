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
- [ESP32 IOT](#ESP32-IOT)
- [Exemplos de projetos](#Exemplos-de-projetos)
- [Livros](#Livros-e-referencias)

<BR><BR>
<H1>Lorena, hoje 09/11/2023, </H1>agora já sabe que dispositivos na internet utilizam identificações de rede (ip, mac, ...). Vamos criar paginas para o Esp32.<BR>
Exemplos <a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot> IOT </a> <BR>
	
<BR><BR>Exemplos de projetos de máquinas (estados). Vamos modificar estes projetos exemplos sem uso de delay().  
>>>> https://wokwi.com/projects/375842607540556801


<BR><BR>Máquina de macarrão:
<BR><BR>https://wokwi.com/projects/343824918481207891

<BR><BR>Maquina de bolos:
<BR><BR>https://wokwi.com/projects/343896310503440979


<BR><BR>Máquina de sorvete:
<BR><BR>https://wokwi.com/projects/343353681787224660 
<BR><BR> https://wokwi.com/projects/343718518644015698
<BR><BR>
## Tempo
	  
### Interrupção e funções de tempo
<BR><BR><B>Uso de millis() no lugar de delays()</b>
  ### função millis
  <br>05 -<a href=https://wokwi.com/projects/342203041946010194> Exemplo função tempo millis()</a>
  
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

   
	<BR>
<BR></BR><b></b>Aula prática uma entrada analógica</b>
<BR></BR>- Leitura Analógica
<BR></BR>- Comparações (if/else/>/<=)
<BR><img src=esp32/adcesp32.png width=300 height=300><BR>
<BR>Utilize o seguinte <a href=https://wokwi.com/projects/340963795998343762>exemplo</a> de leitura analógica, onde um potênciometro ligado a uma das entradas AD(conversor analógico-digital), realiza a conversão em valor binário e utiizando uma função converte o valor em Volts.
<BR>Uma condição de comparação aciona um led. Monte e modifique o programa e circuito para 3 faixas de valores.
<br>
<BR><BR>
<img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32/qrcode_ad.jpg>

<BR>
<BR><B>Utilizando a IDE Arduino</B>
<BR><img src=https://www.lojamundi.com.br/imagens/produtos/Raspberry-Pi-Cabo-mini-USB.webp width=200 height=200>
<BR> <a href=https://www.blogdarobotica.com/2021/08/24/como-programar-a-placa-esp32-no-arduino-ide>Como gravar o esp32 com Arduino</a>
<hr>


<BR>27/7 -<BR>
## Conhecendo funções Wiring

#random()

<BR>A função random() gera números pseudoaleatórios.
<BR>https://www.arduino.cc/reference/pt/language/functions/random-numbers/random/


<BR>Exercício 1: Elabore um script que gere um número aleatório cada vez que um botão é pressionado. Imprimir na porta serial.

<BR>Exercício 2: Repita o exercício 1, porém o número aleatório deve ser apresentado em uma sequência de leds de 1 a 10. Utilize mapeamento de pinos.
<BR> https://wokwi.com/projects/341561728616628819

## Exemplo Maquina de estados

ESP32_3led_1botao >>>>  https://wokwi.com/projects/366328229239357441
<BR>
<BR>
<BR>Exemplo maquina de estados com switch-case https://wokwi.com/projects/366328860646770689

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


	  
### Interrupção externa
  <br>06 -<a href=https://wokwi.com/projects/342203713958445651> Exemplo função Interrupção()</a>
<BR>  
 <br><a href=https://wokwi.com/projects/342234932555285074>bomba</a>
  


## ESP32 IOT

<a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot><img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/imagens/webserver.png width=50% border=0><BR>Saiba mais...</a><BR>
<B> Introdução a internet das coisas </b>: Esp32 como servidor de pagina, protocolo mqtt, uso de frameworks, cloud e outros recursos para aplicações com Internet das Coisas (IOT) através do ESP32.


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
	

## Linguagens e programação
<BR>Programando através de blocos
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
	

	
## Livros e referencias
<BR> 
<img src=https://static.packt-cdn.com/products/9781789956870/cover/smaller> Internet of Things Projects with ESP32, <BR><BR>
https://download.packt.com/free-ebook/9781789956870,<BR><BR> source code: https://github.com/PacktPublishing/Internet-of-Things-Projects-with-ESP32 <BR><BR>
https://github.com/PacktPublishing/Developing-IoT-Projects-with-ESP32-2nd-edition<BR>
https://github.com/PacktPublishing/Internet-of-Things-with-ESP32<BR>
https://github.com/PacktPublishing/Advanced-ESP32	<BR>
https://lastminuteengineers.com/getting-started-with-esp32/
https://lastminuteengineers.com/electronics/esp32-projects/  Tutorial e Projetos com ESP32	<BR>
	
Características para ESP32<BR><BR>
  https://www.espressif.com/en/news/espressif-announces-%E2%80%A8esp32-s2-secure-wi-fi-mcu
<BR><BR> 
Livros e Codigos fontes<Br><BR>
https://github.com/PacktPublishing/Advanced-ESP32
	
	
	
maquina de lavar
https://wokwi.com/projects/366331470262146049
	
