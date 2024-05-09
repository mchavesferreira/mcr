# Comunicação Serial 

A comunicação serial é um processo fundamental no desenvolvimento de projetos com Arduino e ESP32, utilizado para enviar e receber dados entre o microcontrolador e o computador ou outros dispositivos. É uma ferramenta essencial para depuração, configuração e operação remota de sistemas embarcados.  Os dados são transferidos bit a bit digitalmente na forma de bits de um dispositivo para outro. Comunicações seriais são classíficadas quanto ao sincronimos entre síncronas (presença do clock) ou assíncronas (sem clock de referência).

## Comunicações Assíncronas: UART - Universal Asynchronous Receiver/Transmitter (UART) 

![image](https://github.com/mchavesferreira/mcr/assets/63993080/0863b2cf-8b89-437b-bdcd-02d2f85ea9fb)

Como dois dispositivos se comunicam através do UART

### Funções dos Pinos RX e TX

TX (Transmitir): O pino TX é utilizado para enviar dados do ESP32 para outro dispositivo. Isso pode incluir o envio de comandos para um módulo GSM, coordenadas para um dispositivo GPS, ou simplesmente para comunicação de dados para um computador ou outro microcontrolador. No ESP32, diferentes pinos podem ser configurados como TX para as diferentes UARTs disponíveis.

RX (Receber): O pino RX é usado para receber dados de outros dispositivos. Isso permite ao ESP32 receber informações, como dados de sensores, respostas de comandos AT de um módulo Wi-Fi ou GSM, ou comandos de um computador. Assim como os pinos TX, os pinos RX podem ser configurados para diferentes UARTs no ESP32.

Ao conectar o ESP32 a outros dispositivos, certifique-se de que os níveis de tensão dos pinos RX e TX sejam compatíveis, e lembre-se de conectar o TX do ESP32 ao RX do dispositivo receptor e vice-versa. Utilizar resistores de pull-up ou pull-down pode ser necessário para estabilizar os níveis lógicos em ambientes com ruído elétrico ou longas distâncias de transmissão.

### Comunicações Síncronas: SPI, I2C

![Serial communication](https://github.com/mchavesferreira/mcr/assets/63993080/b245763b-464d-436d-8484-f270fb7e2549)

A comunicação serial geralmente é usada para:

### Depuração: 
Permite ao desenvolvedor enviar dados do microcontrolador para um terminal no computador, facilitando a verificação de variáveis, o estado do programa e a ocorrência de erros.
### Comunicação entre Dispositivos:
Microcontroladores podem trocar informações entre si ou com outros dispositivos que suportem comunicação serial, como GPS, módulos GSM, sensores e outros.
### Controle Remoto: 
Receber comandos de um computador ou outro controlador para alterar parâmetros de operação, iniciar ou parar funções, etc.


Por padrão, apenas UART0 e UART2 podem ser usados. Para usar o UART1, temos que redefinir os pinos porque os pinos padrão do UART1, como GPIO9 e GPIO10, estão conectados internamente à memória flash SPI.


## Sistema Simplex, Half-duplex ou Full-duplex

![code-156](https://github.com/mchavesferreira/mcr/assets/63993080/a6eadc7d-5897-4169-a5ff-44eb3c93c9eb)

A comunicação entre dois dispositivos UART pode ser simplex, full-duplex ou half-duplex. A comunicação simplex é um tipo de comunicação unidirecional em que o sinal se move de um UART para outro. Ele não permite que o UART receptor envie sinais de volta. Um full-duplex ocorre quando ambos os dispositivos podem transmitir e receber comunicações ao mesmo tempo. Half-duplex é quando os dispositivos se revezam para transmitir e receber.

## Portas Seriais 

O módulo ESP32 fornece três portas universais de receptores e transmissores assíncronos (UART), como UART0, UART1 e UART2, que funcionam no nível TTL de 3,3 V. Essas três interfaces seriais são suportadas por hardware. Cada um deles expõe 4 pinos: RX, TX, RTS 
### Serial0 (UART0): 
Geralmente usado para comunicação USB-to-Serial e programação, conectado à porta USB do ESP32.
### Serial1 (UART1) e Serial2 (UART2):
Disponíveis para uso geral, não conectadas por padrão para permitir comunicação livre com periféricos externos.

## Baud Rate

| Baud Rate (bps) | Uso Comum                     |
|-----------------|-------------------------------|
| 300             | Modems antigos, comunicação lenta|
| 1200            | Comunicação lenta, sistemas legados|
| 2400            | Comunicação básica de dados   |
| 4800            | GPS, dados em baixa velocidade|
| 9600            | Padrão para muitos dispositivos, incluindo GPS|
| 19200           | Comunicação em melhor velocidade|
| 38400           | Uso geral, mais rápido        |
| 57600           | Comunicação de alta velocidade|
| 115200          | Padrão de alta velocidade para microcontroladores|
| 230400          | Comunicação muito rápida      |
| 460800          | Comunicação muito rápida      |
| 921600          | Comunicação extremamente rápida|
| 1000000         | Máxima taxa para aplicações específicas|

## Paridade 

| Termo | Significado                          |
|-------|--------------------------------------|
| 8     | 8 bits de dados por pacote           |
| N     | No Parity (Sem bit de paridade)      |
| 1     | 1 Stop Bit (Um bit de parada)        |

    8 bits de dados: Cada pacote de dados enviado contém 8 bits de informações.
    No Parity: Não é adicionado um bit de paridade aos dados. O bit de paridade é usado para checagem de erros; a ausência dele significa que essa checagem não ocorrerá.
    1 Stop Bit: Após os bits de dados e o bit de paridade, um bit de parada é adicionado para sinalizar o final do pacote de dados.

## Exemplo comunicação ASCII

Vamos considerar o envio da mensagem "IFSP" usando a codificação ASCII através de uma conexão serial.

Mensagem e Codificação ASCII

Cada caractere em ASCII é representado por um byte (8 bits). A mensagem "IFSP" consiste nos seguintes caracteres e seus correspondentes códigos ASCII em hexadecimal:

    I = 0x49
    F = 0x46
    S = 0x53
    P = 0x50

### Transmissão Serial com Configuração SERIAL_8N1

Com a configuração SERIAL_8N1 (8 bits de dados, sem paridade, 1 bit de parada), cada caractere enviado precisará de:

    8 bits para o dado
    0 bits de paridade
    1 bit de parada

Isso totaliza 9 bits por caractere.

### Cálculo do Tempo de Transmissão

O tempo de transmissão de cada caractere depende da taxa de baud_rate escolhida. O baud_rate define quantos bits são transmitidos por segundo. Por exemplo, se escolhermos uma taxa de baud_rate de 9600 bps (bits por segundo), podemos calcular o tempo necessário para transmitir a mensagem "IFSP".
Cálculo:

Tempo por caractere=Total de bits por caractereBaud rateTempo por caractere=Baud rateTotal de bits por caractere​

Tempo por caractere=9 bits9600 bits/segundo≈0,0009375 segundos por caractereTempo por caractere=9600 bits/segundo9 bits​≈0,0009375 segundos por caractere

Tempo total para "IFSP"=4 caracteres×0,0009375 segundos/caractere=0,00375 segundosTempo total para "IFSP"=4 caracteres×0,0009375 segundos/caractere=0,00375 segundos

## Função Serial.begin()

A função Serial.begin() é usada para inicializar a porta serial0 com uma taxa de transmissão específica (baud rate), configurando a velocidade na qual os dados são enviados e recebidos através da porta serial. Esta função é essencial para estabelecer a comunicação entre o microcontrolador e o computador ou outro dispositivo serial.

### Sintaxe
 ```ruby 
Serial.begin(baud_rate);
 ```
- baud_rate: A velocidade de transmissão em bits por segundo (bps). Exemplos comuns incluem 9600, 115200, etc.

#### Exemplo de Uso:

 ```ruby 
void setup() {
    // Inicia a comunicação serial a 115200 bps
    Serial.begin(115200);
}

void loop() {
    // Envia "Hello World" seguido de uma nova linha a cada segundo
    Serial.println("Hello World");
    delay(1000);
}

 ```

## Serial1.begin() e Serial2.begin()

Para utilizar as portas Serial1 e Serial2 no ESP32, você pode configurá-las da seguinte maneira:


 ```ruby
#include <HardwareSerial.h>

void setup() {
    // Inicializa Serial1 com 9600 bps
    Serial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);  // Especifique os pinos RX e TX apropriados

    // Inicializa Serial2 com 115200 bps
    Serial2.begin(115200, SERIAL_8N1, RX2_PIN, TX2_PIN); // Especifique os pinos RX2 e TX2 apropriados
}

void loop() {
    // Se houver dados disponíveis na Serial1, leia e envie para Serial2
    if (Serial1.available()) {
        int inByte = Serial1.read();
        Serial2.write(inByte);
    }

    // Similarmente, leia de Serial2 e escreva para Serial1
    if (Serial2.available()) {
        int inByte = Serial2.read();
        Serial1.write(inByte);
    }
}


 ```

A biblioteca HardwareSerial.h é uma parte fundamental do framework Arduino, usada para facilitar a comunicação serial através das portas de hardware disponíveis nos microcontroladores. 


   - baud_rate: Define a taxa de transmissão em bits por segundo.
   - config: Configurações de bits de dados, paridade e bits de parada. Por exemplo, SERIAL_8N1 indica 8 bits de dados, sem paridade, 1 bit de parada.
   - RX_PIN, TX_PIN: Os números dos pinos para receber (RX) e transmitir (TX) dados. No ESP32, esses pinos são flexíveis e podem ser definidos pelo usuário, facilitando a integração com outros módulos e sensores.

    

