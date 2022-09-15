# mcr
<b>Links:</b><BR>

Simulador <a href=https://wokwi.com/projects/new/esp32>ESP32 Online</a>
<BR>
Teclas de atalho e tutorial para o <a href=https://docs.wokwi.com/pt-BR/guides/diagram-editor> Simulador Wokwi</a>

<center>  <a href=https://www.arduino.cc/reference/pt/>Arduino Referência de Linguagem C</a> </center><BR>
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

  <BR><i>Aula 15/09</i>
  <BR><B>Trabalho para Bimestre 3:</b><BR>
   <BR> Utilizando o projeto inicial a seguir, crie uma máquina personalizada atenda os seguintes critérios:<BR>
   <BR> -  apresente no mínimo 05 perguntas entre (sim x não) ou ajustes de valores (exemplo tempo)
   <BR> - ajustes de pelo menos 02  valores inteiros.
   <BR> - utilize pelo menos 03 leds como saída
   <BR> - nesta primeira entrega do projeto, as perguntas e possíveis respostas poderão ser na porta serial.(2,0 pontos)
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
    
  <BR>
Aula 08/09
<BR>Displays LCD, Oled, comunicação I2C
  <BR>Simulações:
  <BR>01 -<a href=https://wokwi.com/projects/342202939017790036> Exemplo LCD 16x2 paralelo</a>
  <BR>02 -<a href=https://wokwi.com/projects/342199886273315410> Exemplo LCD 16x2 I2C</a>
  <BR>03 -<a href=https://wokwi.com/projects/342195248670179922> Exemplo Oled U8g2lib</a>
  <BR>04 -<a href=https://wokwi.com/projects/342195418005766739> Exemplo Adafruit_SSD1306</a>
  <br>05 -<a href=https://wokwi.com/projects/342203041946010194> Exemplo função tempo millis()</a>
  <br>06 -<a href=https://wokwi.com/projects/342203713958445651> Exemplo função Interrupção()</a>
<BR>  
 <br><a href=https://wokwi.com/projects/342234932555285074>bomba</a>
  
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
Aula 01/09
<P>Uso de <B>Vetores</B> ou tabelas para organização de variáveis
<BR>01: <a href=https://wokwi.com/projects/341561728616628819>Mapeamento de pinos ESP32</a>
<P>PWM - Simulando saída analógica
<BR>02: <a href=https://wokwi.com/projects/341562296506516051>LED RGB e uso de analog_write() para PWM</a>
<P>Função Debounce e uso de condição de fluxo IF
<BR>03: <a href=https://wokwi.com/projects/341562149868405330>Alternando cores em LEDS</a>
<P>04: Imprimindo e lendo na porta serial (UART)<BR>
  
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

  
<BR> <a href=https://wokwi.com/projects/341561853822894674>Comunicando através da entrada serial</a>
<P>Exemplos aplicando porta serial e PWM
<BR>05: <a href=https://wokwi.com/projects/341698810319209042>Leitura de cores utilizando serial</a>.<span size=-2> Autores: Vinicius Viana e  Luis H. Estareli</span>.

<P><a href=http://www.cdme.im-uff.mat.br/matrix/matrix-html/matrix_color_cube/matrix_color_cube_br.html>Tabela de cores RGB</a>
<P> 

Aula 25/8<BR>
Uso de Variáveis, #define e funções próprias para I/0 Arduino<BR>
<BR>01: GPIOs, leitura e escrita em pinos digitais<a href=https://wokwi.com/projects/339670467067511378>digitalRead() e digitalWrite()</a>
<bR>02: ADC - Leitura analógica, conversão de valores com funções e a função mapeamento <a href=https://wokwi.com/projects/340963795998343762> analogRead()</a>

<br><a href=https://microcontrollerslab.com/wp-content/uploads/2019/02/ESP32-pinout-mapping.png target=_blank><img src=https://microcontrollerslab.com/wp-content/uploads/2019/02/ESP32-pinout-mapping.png>ESP32 pinout<a/>
<BR><a href=https://wokwi.com/projects/340959007153848914> Chip ID</a><BR>  
  
 <BR>Aulas 18/8<BR>
  <BR>Variáveis e Operadores</b><BR>
 <BR>- Uso de HEX, DEC, BIN e OCT  <a href=https://wokwi.com/projects/340328764284076626>print()  </a>

Atividade para o dia 11/08/2022.

Acesse o seguinte projeto com este <a href=https://wokwi.com/projects/339673145686360659>link</a>.

<img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/imagens/leds_painel.png> <P>

Crie uma conta no simulador wokwi para salvar as seguintes atividades. <P>
Explore o código que utliza máquina de estados para a mudança através da lógica de fluxo switch-case. <BR> Faça as seguintes modificações:

<b>Atividade 11_08a:</b> Modifique o esquema elétrico e o programa para que ele tenha 10 leds alterando em sequência a cada vez que o botão for pressionado e solto.

<b>Atividade 11_08b:</b> Modifique programa para que os leds pisquem em sequência a cada 1 segundo.
