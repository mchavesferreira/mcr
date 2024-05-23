

### Display Oled  + ESP32
  <BR>03 -<a href=https://wokwi.com/projects/342195248670179922> Exemplo Oled U8g2lib</a>
  <BR>04 -<a href=https://wokwi.com/projects/342195418005766739> Exemplo Adafruit_SSD1306</a>
  <Br> <img src=https://github.com/mchavesferreira/mcr/blob/main/imagens/oled.png width=400 height=325><BR>
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


## I2C

# Protocolo I2C

O protocolo I2C (Inter-Integrated Circuit) é um protocolo de comunicação serial que permite a conexão de múltiplos dispositivos em um único barramento de dados. É amplamente utilizado em sistemas embarcados devido à sua simplicidade e eficiência na comunicação entre microcontroladores e periféricos, como sensores, displays e outros componentes integrados.

## Características Principais do I2C

1. **Barramento de Dois Fios**:
   - **SDA (Serial Data Line)**: Linha de dados.
   - **SCL (Serial Clock Line)**: Linha de clock.
   - Esses dois fios são compartilhados por todos os dispositivos conectados ao barramento.

2. **Endereçamento**:
   - Cada dispositivo no barramento possui um endereço único, geralmente de 7 bits, permitindo até 128 dispositivos (ou até 1024 com endereçamento de 10 bits).

3. **Topologia Mestre-Escravo**:
   - Um dispositivo mestre controla a comunicação, enquanto os dispositivos escravos respondem às solicitações do mestre.

![diagrama](https://github.com/mchavesferreira/mcr/assets/63993080/2f5eafa2-350e-40cc-9596-3b0ce3398b90)

4. **Comunicação Bidirecional**:
   - Permite tanto leitura quanto escrita de dados entre o mestre e os escravos.

5. **Velocidades de Operação**:
   - Standard Mode: Até 100 kbps.
   - Fast Mode: Até 400 kbps.
   - Fast Mode Plus: Até 1 Mbps.
   - High Speed Mode: Até 3.4 Mbps.

## Funcionamento Básico

1. **Início da Comunicação**:
   - O mestre inicia a comunicação gerando uma condição de START (um nível alto para baixo na linha SDA enquanto SCL está alto).
     
![start_stop](https://github.com/mchavesferreira/mcr/assets/63993080/c349b904-6a36-45e0-892b-27a4afb6e458)

2. **Endereçamento**:
   - O mestre envia o endereço do dispositivo escravo com o qual deseja comunicar-se seguido por um bit de leitura/escrita (0 para escrita e 1 para leitura).

3. **Acknowledge (ACK) e Not Acknowledge (NACK)**:
   - O escravo reconhece o recebimento do endereço enviando um bit ACK (linha SDA é puxada para baixo).
   - Se o escravo não estiver presente ou não reconhecer o endereço, ele envia um bit NACK (linha SDA permanece alta).

4. **Transferência de Dados**:
   - Dados são transferidos em bytes, com o mestre gerando o clock e determinando o ritmo da comunicação.
   - Após cada byte, o receptor deve enviar um bit ACK para confirmar a recepção correta do dado.

5. **Fim da Comunicação**:
   - A comunicação é encerrada com uma condição de STOP (um nível baixo para alto na linha SDA enquanto SCL está alto).

![pacote_i2c](https://github.com/mchavesferreira/mcr/assets/63993080/8d5a6e9d-8202-4f2b-953c-c004f3fd89d2)

## Vantagens do I2C

- **Simplicidade**: Apenas dois fios necessários para a comunicação, simplificando o design do hardware.
- **Flexibilidade**: Permite a adição de novos dispositivos ao barramento sem necessidade de muitas alterações no hardware ou software.
- **Eficiência**: Ideal para comunicação de baixa e média velocidade em curtas distâncias dentro de um dispositivo.

## Desvantagens

- **Velocidade Limitada**: Não é adequado para transferências de dados em alta velocidade.
- **Restrições de Distância**: Projetado para curtas distâncias, tipicamente dentro de um mesmo dispositivo ou módulo.

## Exemplo de Aplicação

Uma aplicação comum do I2C é a leitura de sensores. Por exemplo, um sensor de temperatura DS1307 pode ser conectado a um microcontrolador como o ATmega328P, utilizando o barramento I2C para enviar leituras de temperatura periodicamente ao microcontrolador.

Para uma implementação detalhada, consulte a documentação específica do microcontrolador e os datasheets dos dispositivos I2C utilizados. O livro "AVR e Arduino Técnicas de Projeto" contém um capítulo dedicado ao TWI (I2C) que detalha a implementação do protocolo em microcontroladores AVR, incluindo exemplos práticos e código fonte.



Referências:

https://blog.arduinoomega.com/entendo-o-protocolo-i2c/

https://www.analog.com/en/resources/technical-articles/i2c-primer-what-is-i2c-part-1.html
