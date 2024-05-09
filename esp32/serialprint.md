# Comunicação Serial 

A comunicação serial é um processo fundamental no desenvolvimento de projetos com Arduino e ESP32, utilizado para enviar e receber dados entre o microcontrolador e o computador ou outros dispositivos. É uma ferramenta essencial para depuração, configuração e operação remota de sistemas embarcados.  Os dados são transferidos bit a bit digitalmente na forma de bits de um dispositivo para outro. Comunicações seriais são classíficadas quanto ao sincronimos entre síncronas (presença do clock) ou assíncronas (sem clock de referência).

## Comunicações Assíncronas: UART - Universal Asynchronous Receiver/Transmitter (UART) 

![image](https://github.com/mchavesferreira/mcr/assets/63993080/0863b2cf-8b89-437b-bdcd-02d2f85ea9fb)
Como dois dispositivos se comunicam através do UART

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

O módulo ESP32 fornece três portas universais de receptores e transmissores assíncronos (UART), como UART0, UART1 e UART2, que funcionam no nível TTL de 3,3 V. Essas três interfaces seriais são suportadas por hardware. Cada um deles expõe 4 pinos: RX, TX, RTS e CTS. No entanto, o Arduino IDE usa apenas pinos RX e TX.


    - Serial0 (UART0): Geralmente usado para comunicação USB-to-Serial e programação, conectado à porta USB do ESP32.
    - Serial1 (UART1) e Serial2 (UART2): Disponíveis para uso geral, não conectadas por padrão para permitir comunicação livre com periféricos externos.

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

    

