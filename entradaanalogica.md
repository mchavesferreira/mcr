
	  
# Display, comunicação serial, conversor AD

<BR><BR><B>Uso de millis() no lugar de delays()</b>


##Display Oled   
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


## Comunicação Serial

### Imprimindo texto na porta serial
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

## lendo resposta na porta serial

<details><summary>Codigo Serial</summary>
<p>

```ruby
   Serial.begin(115200);
   Serial.println("Qual é o seu nome? :");
   while (!Serial.available()); // Wait for input
   String name = Serial.readStringUntil('\n');
   Serial.print("Ola, ");
   Serial.print(name);
```

</p>
</details>

<BR>Simulação: <a href=https://wokwi.com/projects/341561853822894674>Lendo resposta na porta serial</a>

## Conversor Anaógico Digital
<BR></BR><b></b>Aula prática uma entrada analógica</b>

<BR><img src=esp32/adcesp32.png width=300 height=300><BR>

### Lend um canal AD 
```ruby
int valoranalogico = 0;
void setup() {
  Serial.begin(115200);
  delay(1000); 
}

void loop() {
  // Lendo o valor de tensao analogica de um potenciomentro
  valoranalogico = analogRead(34);

  Serial.println(valoranalogico);

  delay(500);
}
```
https://wokwi.com/projects/440535005748564993

<BR></BR>
##  Comparações (if/else/>/<=)

```ruby
// variavel para armazenar o valor AD
int valoranalogico = 0;
void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Lê o valor analogico sem conversao 0-4095
  valoranalogico = analogRead(34);
  // compara valor analogico
  if(valoranalogico<1000){ Serial.print ("Estou calma.."); }
  if(valoranalogico>=1000 && valoranalogico<2000){  Serial.print ("estressando.."); }
  if(valoranalogico>=2000){ Serial.print ("ESTRESSADA.."); }
  Serial.println(valoranalogico);
  delay(500);
}

```

## Convertendo valor AD em tensão Volts

Utilize a equação de regra de 3 para converter o valor AD ou valor RAW para o seu equivalente em tensão (volts)

```ruby
  // Leitura ad 0-4095
  valoranalogico  = analogRead(34);
  Tensao= (3.3*valoranalogico)/4095;
  Serial.println(Tensao);
```
  
<BR>Utilize o seguinte <a href=https://wokwi.com/projects/340963795998343762>exemplo</a> de leitura analógica, onde um potênciometro ligado a uma das entradas AD(conversor analógico-digital), realiza a conversão em valor binário e utiizando uma função converte o valor em Volts.


<BR>



# Construindo uma maquina (projeto 3° Bimestre)
	
<BR><BR>Exemplos de projetos de máquinas (estados). Vamos modificar estes projetos exemplos sem uso de delay().  
>>>> https://wokwi.com/projects/375842607540556801

## Exemplos de anos anteriores

<BR><BR>Máquina de macarrão:
<BR><BR>https://wokwi.com/projects/343824918481207891

<BR><BR>Maquina de bolos:
<BR><BR>https://wokwi.com/projects/343896310503440979


<BR><BR>Máquina de sorvete:
<BR><BR>https://wokwi.com/projects/343353681787224660 
<BR><BR> https://wokwi.com/projects/343718518644015698
<BR><BR>
## Tempo

<BR><B>Utilizando a IDE Arduino</B>
<BR><img src=https://www.lojamundi.com.br/imagens/produtos/Raspberry-Pi-Cabo-mini-USB.webp width=200 height=200>
<BR> <a href=https://www.blogdarobotica.com/2021/08/24/como-programar-a-placa-esp32-no-arduino-ide>Como gravar o esp32 com Arduino</a>
<hr>
