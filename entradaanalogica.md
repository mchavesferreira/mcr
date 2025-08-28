
	
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

 
## Comunicação Serial

```ruby
 void setup() {
  Serial.begin(115200);

 
}

void loop() {

  Serial.println("Oi seja bem vindo");
  delay(1000);
}
```


https://wokwi.com/projects/401871586327571457

Imprimindo e lendo na porta serial (UART)<BR>

Faça a leitura de um pino analogico

https://wokwi.com/projects/440535005748564993

  
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
