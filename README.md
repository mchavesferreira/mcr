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
