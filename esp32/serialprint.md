# Comunicação Serial

A comunicação serial é um processo fundamental no desenvolvimento de projetos com Arduino e ESP32, utilizado para enviar e receber dados entre o microcontrolador e o computador ou outros dispositivos. É uma ferramenta essencial para depuração, configuração e operação remota de sistemas embarcados.
Uso da Comunicação Serial

![Serial communication](https://github.com/mchavesferreira/mcr/assets/63993080/b245763b-464d-436d-8484-f270fb7e2549)


No contexto do Arduino e do ESP32, a comunicação serial geralmente é usada para:

### Depuração: 
Permite ao desenvolvedor enviar dados do microcontrolador para um terminal no computador, facilitando a verificação de variáveis, o estado do programa e a ocorrência de erros.
### Comunicação entre Dispositivos:
Microcontroladores podem trocar informações entre si ou com outros dispositivos que suportem comunicação serial, como GPS, módulos GSM, sensores e outros.
### Controle Remoto: 
Receber comandos de um computador ou outro controlador para alterar parâmetros de operação, iniciar ou parar funções, etc.

## Função Serial.begin()

A função Serial.begin() é usada para inicializar a porta serial com uma taxa de transmissão específica (baud rate), configurando a velocidade na qual os dados são enviados e recebidos através da porta serial. Esta função é essencial para estabelecer a comunicação entre o microcontrolador e o computador ou outro dispositivo serial.

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
