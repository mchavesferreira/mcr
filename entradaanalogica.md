
	  
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

# Princípio da entrada analógica no ESP32

A entrada analógica do ESP32 permite medir uma tensão elétrica variável e convertê-la em um valor numérico que pode ser utilizado pelo programa.

Essa conversão é realizada por um **conversor analógico-digital**, denominado **ADC** — *Analog-to-Digital Converter*.

## Funcionamento básico

O ADC recebe uma tensão aplicada a um pino analógico e a transforma em um número inteiro.

Nos ESP32, a resolução normalmente utilizada é de **12 bits**. Isso significa que o conversor pode representar a tensão por meio de:

[
2^{12} = 4096
]

valores diferentes.

Assim, o resultado da leitura varia de:

```text
0 a 4095
```

De forma simplificada:

|             Tensão aplicada | Valor digital aproximado |
| --------------------------: | -----------------------: |
|                         0 V |                        0 |
|  Metade da faixa de medição |                     2048 |
| Máximo da faixa configurada |                     4095 |

A conversão pode ser representada aproximadamente por:

<img width="612" height="272" alt="image" src="https://github.com/user-attachments/assets/c4d37990-42da-4d25-9ab3-d6aae0e081e2" />




| Característica                              | ESP32-WROOM-32                                      | ESP32-S3                                   |
| ------------------------------------------- | --------------------------------------------------- | ------------------------------------------ |
| Resolução usual do ADC                      | 12 bits: 0 a 4095                                   | 12 bits: 0 a 4095                          |
| Faixa de pinos do ADC1                      | GPIO32 a GPIO39                                     | GPIO1 a GPIO10                             |
| Faixa de pinos do ADC2                      | GPIO0, 2, 4, 12–15 e 25–27                          | GPIO11 a GPIO20                            |
| **Pinos preferenciais**                     | **GPIO32, 33, 34, 35, 36 e 39**                     | **GPIO4, 5, 6, 7, 8, 9 e 10**              |
| **Melhores escolhas gerais**                | **GPIO34, 35, 36 e 39**                             | **GPIO4, 5, 6 e 7**                        |
| Pinos somente de entrada                    | GPIO34, 35, 36 e 39                                 | Não há equivalentes somente de entrada     |
| Pinos a evitar                              | GPIO0, 2, 12 e 15 por participarem da inicialização | GPIO3 por ser pino de inicialização        |
| Pinos a evitar com USB                      | Não se aplica à USB nativa                          | GPIO19 e GPIO20                            |
| Uso com Wi-Fi                               | Preferir obrigatoriamente o ADC1                    | Preferir o ADC1 para simplificar o projeto |
| Tensão máxima no GPIO                       | 3,3 V                                               | 3,3 V                                      |
| **Entrada analógica principal recomendada** | **GPIO34**                                          | **GPIO4**                                  |


<BR><img src=esp32/adcesp32.png width=300 height=300><BR>
<br><img src=esp32/imagens/pinout_esp32s3.jpg width=300 height=300><BR>
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




