# Microcontroladores

 
## Utilizando ESP32, Arduino IDE e simulador Wokwi para aprendizado da programação de sistemas embarcados e dispositivos IOT.



## Aulas
- [Arduino Referências](#Referências-Arduino)
- [Pinout Esp32](#pinout-esp32)
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
- [Servidor Web](#servidor-web)
- [IOT, Protocolo MQTT e Alexa](#IOT-Protocolo-MQTT-Alexa)
- [Exemplos de projetos](#Exemplos-de-projetos)
- [Projetos Bimestrais](#projetos-bimestrais)
	- [Terceiro Bimestre](#terceiro-bimestre)
	- [Quarto Bimestre](#quarto-bimestre)




## Referências Arduino
<center>  <a href=https://www.arduino.cc/reference/pt/>Arduino Referência de Linguagem C</a> </center><BR>

## Pinout ESP32
<br><a href=https://microcontrollerslab.com/wp-content/uploads/2019/02/ESP32-pinout-mapping.png target=_blank><img src=https://microcontrollerslab.com/wp-content/uploads/2019/02/ESP32-pinout-mapping.png>ESP32 pinout<a/>
<BR><a href=https://randomnerdtutorials.com/esp32-pinout-reference-gpios/>Configuração I/O</a> para cada pino.
<BR>Como verificar o ID do chip<a href=https://wokwi.com/projects/340959007153848914> Chip ID</a><BR>  

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

# Frameworks:
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

## Projetos Bimestrais
	
### Terceiro Bimestre
Projetos baseado em uma maquina de lavar
  <BR><i>Aula 15/09</i>
  <BR><B>Trabalho para Bimestre 3: (Etapa 1 15/9 horário de aula, Etapa 2: 23/9 Suap)</b><BR>
   <BR> Utilizando o projeto inicial a seguir, crie uma máquina personalizada (não será considerado máquina de lavar) atenda os seguintes critérios:<BR>
   <BR> -  apresente no mínimo 05 perguntas entre (sim x não) ou ajustes de valores (exemplo tempo);
   <BR> - ajustes de pelo menos 02  valores inteiros;
   <BR> - utilize pelo menos 03 leds como saídas;
   <BR> - nesta primeira entrega do projeto(horário da aula 15/9), as perguntas e possíveis respostas poderão ser na porta serial; (2,0 pontos)
   <BR> - na segunda etapa as perguntas e respostas devem utilizar display e botões (exemplos para botões: + - 1 2 3 Y N enter) (2,0 pontos)
   <BR> - enviar o link da primeira fase no email: mchavesferreira@gmail.com
   <BR> - segunda fase enviar o link na área trabalhos (suap), cada integrante da dupla deve postar.
  <BR> - As duplas não podem ter trabalhos "clones", criatividade e dificuldades serão pontuados
   <BR> - A utilização de PWM e entrada analógica será considerada como maior pontuação.
   <BR>  <BR>Link de exemplo inicial: https://wokwi.com/projects/342835850626728530
<BR>
     <BR></b>Orientações</B> para o código. Utilize switch()/case  para estruturar seu projeto;
  <BR>A utilização de funções deixam o código limpo e facilmente comprensível
    <br>Variáveis que serão utlizadas em funções diferentes devem ser globais. Variáveis locais são sempre recomendadas para economia de memória RAM.
    

### projeto avaliação
	  
<P><a href=https://github.com/mchavesferreira/mcr/tree/main/trabalho>Trabalho</a> <B>Revisão da prova bimestre 3</b>
	  
Atividade para o dia 11/08/2022.

Acesse o seguinte projeto com este <a href=https://wokwi.com/projects/339673145686360659>link</a>.

<img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/imagens/leds_painel.png> <P>

Crie uma conta no simulador wokwi para salvar as seguintes atividades. <P>
Explore o código que utliza máquina de estados para a mudança através da lógica de fluxo switch-case. <BR> Faça as seguintes modificações:

<b>Atividade 11_08a:</b> Modifique o esquema elétrico e o programa para que ele tenha 10 leds alterando em sequência a cada vez que o botão for pressionado e solto.

<b>Atividade 11_08b:</b> Modifique programa para que os leds pisquem em sequência a cada 1 segundo.


  
<BR>  


###  Quarto Bimestre
Projetos para o quarto bimestre

## Requisitos
- Utilizar ESP32 (Pode pegar do colega de outra turma para apresentar o trabalho prático, podendo ser em protoboard). Montagem prática e simulação
- Trabalho em dupla.
- Programação com envio de dados na nuvem (Thingspeak e ou MQTT/Dashboard)
- Leitura de um sensor ou simulado
- Utilizar maquina de estados de processo (switch/case) ou uma sequência de compararações(if/else)
- Apresentar dado local em display
- Relizar leitura analógica
- gerar um repositorio no github, com detalhes, código fonte e fotos. Enviar link para o email do professor.
- Prazo Trabalho prático: 01/12/2022 (Peso do trabalho na nota final: 60%)
<BR>

<BR>Peso da prova escrita:  30%  (24/11/2022)
<BR>Participação e desenvolvimento em aula: 10% (caderno, código em sala...)
<BR><B>Compartilhem </b>seu repositório com o professor, adicionando-o como colaborador(login:mchavesferreira) se seu repostório ter o status de Privado.
<BR>Escreva um texto breve explicando seu projeto, faça upload de fotos, e coloque o nome dos autores.Escreva um texto breve explicando seu projeto, faça upload de fotos, e coloque o nome dos autores. Crie um arquivo README.md na pasta.
<br><img src=imagens/colaborador.png>
<BR>

