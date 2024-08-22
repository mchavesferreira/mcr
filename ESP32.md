# Microcontroladores


## Aulas
22/08  - Displays LCD e Oled

08/08 -  <a href=esp32/maquinaestadopasteurizacao.md> Projeto Pasteurização </a>

25/07 - <a href=esp32/maquinaestados.MD> Maquina de estados (abordagem if e switch/case) </a>

27/06 - Aula prática com ESP32

25/04 - Introdução ao ESP32 (Conhecendo  Referências Arduino e Simulador wokwi)

02/05 - Explorando GPIO Entradas e saídas (Pinout ESP32, GPIO Digital)

09/05  - Comunicação Serial:  https://github.com/mchavesferreira/mcr/blob/main/esp32/serialprint.md

16/05 e 23/5  - PWM:  https://github.com/mchavesferreira/mcr/blob/main/esp32/pwm.md

06/06  - Diplay Oled : https://github.com/mchavesferreira/mcr/blob/main/esp32/displayoled.md

## Simulador Wokwi

Simulador <a href=https://wokwi.com/projects/new/esp32>ESP32 Online</a>
<BR>
Teclas de atalho e tutorial para o <a href=https://docs.wokwi.com/pt-BR/guides/diagram-editor> Simulador Wokwi</a>
 
## Referências Arduino

<center>  <a href=https://www.arduino.cc/reference/pt/ target=_blank>Arduino Referência de Linguagem C</a> </center><BR>


## Pinout ESP32

<img src=https://microcontrollerslab.com/wp-content/uploads/2019/02/ESP32-pinout-mapping.png>ESP32 pinout>

<br><a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/pinos.md> Conheça sobre a configuração de pinos </a>

## GPIO Digital

### Função digitalWrite()

Definição:
A função digitalWrite() é usada para escrever um valor HIGH (alto) ou LOW (baixo) em um pino digital configurado como saída. Isso é fundamental para controlar dispositivos externos como LEDs, relés, e outros componentes digitais.

### Função digitalRead()

Definição:
A função digitalRead() é usada para ler o estado de um pino digital configurado como entrada. Isso permite detectar se um pino está recebendo um sinal HIGH ou LOW, que é útil para ler o estado de botões, sensores digitais, e outros dispositivos de entrada.

### pinMode()

A função pinMode() é essencial no desenvolvimento de projetos com microcontroladores, como o ESP32, ao usar a IDE do Arduino. Ela é usada para configurar um pino específico como entrada (INPUT), saída (OUTPUT), ou outros modos especiais como entrada com pull-up interno (INPUT_PULLUP). Essa função determina como o pino especificado se comportará, seja lendo sinais de sensores, botões e outros dispositivos, ou controlando LEDs, relés, e outros atuadores.

#### Configurando um pino como saída:

 ```ruby  
#define LED_PIN 2  // Define o número do pino para um LED

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configura o pino do LED como saída
}

 ```

#### Configurando um pino como entrada com pull-up:

 ```ruby  
#define BUTTON_PIN 0  // Define o número do pino para um botão

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Configura o pino do botão como entrada com pull-up
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // Lê o estado do botão
  if (buttonState == LOW) {  // Verifica se o botão está sendo pressionado
    // Ação a ser realizada quando o botão está pressionado
  }
}

 ```


<BR>GPIOs, leitura e escrita em pinos digitais. Simulação: <a href=https://wokwi.com/projects/339670467067511378>digitalRead() e digitalWrite()</a>



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



## Apostila ESP32
<BR> <a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/ESP32.docx>Apostila</a> em desenvolvimento

<BR> <a href=https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf>Datasheet ESP32</a>





## ID do chip

No ESP32, o "ID do chip" (Chip ID) refere-se a um identificador único atribuído ao chip. Esse ID pode ser usado para várias finalidades, incluindo a diferenciação entre múltiplos dispositivos na mesma rede ou para fins de segurança e autenticação.

O ID do chip no ESP32 é tipicamente derivado do endereço MAC do dispositivo, que é único para cada chip. Isso significa que cada ESP32 tem um ID do chip que pode ser considerado único, ajudando a evitar colisões e conflitos em sistemas onde múltiplos dispositivos precisam ser identificados de forma inequívoca.

Para obter o ID do chip em um programa, os desenvolvedores geralmente usam funções específicas da API do ESP-IDF ou do ambiente de desenvolvimento que estão utilizando, como o Arduino. Por exemplo, no ambiente Arduino, você pode usar a função ESP.getEfuseMac() para obter o ID do chip, que retorna o endereço MAC do dispositivo, e então processá-lo conforme necessário para seu uso específico.

Esse ID é especialmente útil em aplicações de Internet das Coisas (IoT), onde a identificação única de cada dispositivo é crucial para a comunicação e controle de rede.

<BR>Como verificar o ID do chip<a href=https://wokwi.com/projects/340959007153848914> Chip ID</a><BR>  


## Arquitetura Esp32	<BR><BR>


Mapeamento da memória (pagina 7) <a href=https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf>memory</a>
	
	
## Aula prática ESP32

Comunicação  Serial

https://wokwi.com/projects/401871586327571457

Pisca Led

https://wokwi.com/projects/339670467067511378

![esp32-led-wiring-diagram](https://github.com/mchavesferreira/mcr/assets/63993080/e9eb1095-144c-46ec-96a2-2628b59b60e2)


	
## variaveis operadores

Uso de Variáveis, #define e funções próprias para I/0 Arduino

  <BR>Variáveis e Operadores</b><BR>  

 <BR>- Uso de HEX, DEC, BIN e OCT  <a href=https://wokwi.com/projects/340328764284076626>print()  </a>



## Tabelas Vetores
<P>Uso de <B>Vetores</B> ou tabelas para organização de variáveis
<BR>01: <a href=https://wokwi.com/projects/341561728616628819> Mapeamento de pinos ESP32</a>


	
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

### Oled
 
-<a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/displayoled.md> Display Oled</a>

	  
### Interrupção externa
  <br>06 -<a href=https://wokwi.com/projects/342203713958445651> Exemplo função Interrupção()</a>
<BR>  
 <br><a href=https://wokwi.com/projects/342234932555285074>Uso de interrupção</a>
  


## ESP32 IOT

<a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot><img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/imagens/webserver.png width=50% border=0><BR>Saiba mais...</a><BR>
<B> Introdução a internet das coisas </b>: Esp32 como servidor de pagina, protocolo mqtt, uso de frameworks, cloud e outros recursos para aplicações com Internet das Coisas (IOT) através do ESP32.

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
	
### Comunicando com google excel
Unleash the Power of ChatGPTs Code Interpreter: Crafting a Dynamic ESP32 Data Logger with DHT22 and Google Sheets
https://robu.in/unleash-the-power-of-chatgpts-code-interpreter-crafting-a-dynamic-esp32-data-logger-with-dht22-and-google-sheets/
	
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
	
