# Comunicação Serial 

A comunicação serial é um processo fundamental no desenvolvimento de projetos com Arduino e ESP32, utilizado para enviar e receber dados entre o microcontrolador e o computador ou outros dispositivos. É uma ferramenta essencial para depuração, configuração e operação remota de sistemas embarcados.  Os dados são transferidos bit a bit digitalmente na forma de bits de um dispositivo para outro. Comunicações seriais são classíficadas quanto ao sincronimos entre síncronas (presença do clock) ou assíncronas (sem clock de referência).

### A comunicação serial geralmente é usada para:

### Depuração: 
Permite ao desenvolvedor enviar dados do microcontrolador para um terminal no computador, facilitando a verificação de variáveis, o estado do programa e a ocorrência de erros.
### Comunicação entre Dispositivos:
Microcontroladores podem trocar informações entre si ou com outros dispositivos que suportem comunicação serial, como GPS, módulos GSM, sensores e outros.
### Controle Remoto: 
Receber comandos de um computador ou outro controlador para alterar parâmetros de operação, iniciar ou parar funções, etc.

### Funções dos Pinos RX e TX

![image](https://github.com/mchavesferreira/mcr/assets/63993080/0863b2cf-8b89-437b-bdcd-02d2f85ea9fb)

Como dois dispositivos se comunicam através do UART

TX (Transmitir): O pino TX é utilizado para enviar dados do ESP32 para outro dispositivo. Isso pode incluir o envio de comandos para um módulo GSM, coordenadas para um dispositivo GPS, ou simplesmente para comunicação de dados para um computador ou outro microcontrolador. No ESP32, diferentes pinos podem ser configurados como TX para as diferentes UARTs disponíveis.

RX (Receber): O pino RX é usado para receber dados de outros dispositivos. Isso permite ao ESP32 receber informações, como dados de sensores, respostas de comandos AT de um módulo Wi-Fi ou GSM, ou comandos de um computador. Assim como os pinos TX, os pinos RX podem ser configurados para diferentes UARTs no ESP32.

Ao conectar o ESP32 a outros dispositivos, certifique-se de que os níveis de tensão dos pinos RX e TX sejam compatíveis, e lembre-se de conectar o TX do ESP32 ao RX do dispositivo receptor e vice-versa. Utilizar resistores de pull-up ou pull-down pode ser necessário para estabilizar os níveis lógicos em ambientes com ruído elétrico ou longas distâncias de transmissão.

## Comunicações Síncronas: 

O emissor envia um sinal de clock junto com os dados: a cada transição ascendente/descendente do clock, o valor dos dados é lido pelo receptor. São exemplos de comunicação síncronas as SPI I2C.

![_clock](https://github.com/mchavesferreira/mcr/assets/63993080/5aa5f122-1154-410f-9d10-454755171f0f)

## Comunicações Assíncronas: UART - Universal Asynchronous Receiver/Transmitter (UART) 

Refere-se à sincronização remetente-destinatário. O remetente envia dados a uma determinada velocidade baseada e um protocolo de transmissão.

![taxaex](https://github.com/mchavesferreira/mcr/assets/63993080/4f5c4ccf-ba47-4c0a-bc25-67627b24303c)

## Sistema Simplex, Half-duplex ou Full-duplex

![code-156](https://github.com/mchavesferreira/mcr/assets/63993080/a6eadc7d-5897-4169-a5ff-44eb3c93c9eb)

A comunicação entre dois dispositivos UART pode ser simplex, full-duplex ou half-duplex. A comunicação simplex é um tipo de comunicação unidirecional em que o sinal se move de um UART para outro. Ele não permite que o UART receptor envie sinais de volta. Um full-duplex ocorre quando ambos os dispositivos podem transmitir e receber comunicações ao mesmo tempo. Half-duplex é quando os dispositivos se revezam para transmitir e receber.

## Portas Seriais 

O módulo ESP32 fornece três portas universais de receptores e transmissores assíncronos (UART), como UART0, UART1 e UART2, que funcionam no nível TTL de 3,3 V. Essas três interfaces seriais são suportadas por hardware. Cada um deles expõe 4 pinos: RX, TX, RTS 
### Serial0 (UART0): 
Geralmente usado para comunicação USB-to-Serial e programação, conectado à porta USB do ESP32.
### Serial1 (UART1) e Serial2 (UART2):
Disponíveis para uso geral, não conectadas por padrão para permitir comunicação livre com periféricos externos.

Por padrão, apenas UART0 e UART2 podem ser usados. Para usar o UART1, temos que redefinir os pinos porque os pinos padrão do UART1, como GPIO9 e GPIO10, estão conectados internamente à memória flash SPI.

## Baud Rate

Baud-rate refere-se à velocidade de transmissão em uma conexão de comunicação de dados. Em termos técnicos, é o número de símbolos transmitidos por segundo. Cada símbolo pode representar ou conter um ou mais bits de informação, dependendo do sistema de modulação utilizado. Na comunicação serial, como em UART (Universal Asynchronous Receiver/Transmitter), o baud-rate geralmente indica quantos bits são enviados ou recebidos por segundo. Por exemplo, um baud-rate de 9600 significa que 9600 bits são transmitidos a cada segundo.

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

## BIT de Parada

O bit de parada em comunicação serial é um aspecto importante do protocolo UART. Após cada byte de dados transmitido, um ou mais bits de parada são enviados para indicar ao receptor que o byte foi concluído. O bit de parada é essencial para separar sequências de bits contínuas e para garantir que o receptor possa sincronizar corretamente a leitura dos dados com o transmissor.

## Paridade 

A paridade é um método de verificação de erros utilizado em comunicações seriais e outras formas de transmissão de dados. O objetivo da paridade é detectar alterações acidentais nos dados que podem ocorrer durante a transmissão devido a ruídos, interferências ou falhas no hardware.

## Tamanho do Frame

O grupo de bits é transmitido/recebido em um bloco (frame) composto pelos bits de dados, bits de sincronização (bits de início e parada) e, opcionalmente, por um bit de paridade para a conferência de erro. A USART aceita várias combinações possíveis de formato de dados:

. Um bit de início.
. 5, 6, 7, 8 ou 9 bits de dados.
. Bit de paridade par, ímpar ou nenhum.
. Um ou dois bits de parada.

![frame](https://github.com/mchavesferreira/mcr/assets/63993080/c603219a-f5dd-453c-acc9-55c5771e327f)

Formato do frame da UART:

![frame2](https://github.com/mchavesferreira/mcr/assets/63993080/e6f1eae7-0888-4f18-affe-9ae5775f1b77)



| Termo | Significado                          |
|-------|--------------------------------------|
| 8     | 8 bits de dados por pacote           |
| N     | No Parity (Sem bit de paridade)      |
| 1     | 1 Stop Bit (Um bit de parada)        |

    8 bits de dados: Cada pacote de dados enviado contém 8 bits de informações.
    No Parity: Não é adicionado um bit de paridade aos dados. O bit de paridade é usado para checagem de erros; a ausência dele significa que essa checagem não ocorrerá.
    1 Stop Bit: Após os bits de dados e o bit de paridade, um bit de parada é adicionado para sinalizar o final do pacote de dados.

## Comunicação ASCII

No caso dos microcontroladores, como os da família AVR ou usando a plataforma Arduino, as funções de comunicação serial podem transmitir tanto caracteres ASCII quanto dados binários, dependendo de como são programadas. 

A tabela ASCII que se segue contém os caracteres que são comumente utilizados e podem ser transmitidos através de comunicação serial. A transmissão destes caracteres é bastante comum em contextos onde é necessário enviar comandos, texto ou dados formatados de forma legível:

<details><summary>Tabela ASCII</summary>
<p>

| Dec | Hex | Char |       Descrição       |
|-----|-----|------|-----------------------|
|  32 |  20 |      | Espaço                |
|  33 |  21 |  !   | Exclamação            |
|  34 |  22 |  "   | Aspas                 |
|  35 |  23 |  #   | Cerquilha             |
|  36 |  24 |  $   | Dólar                 |
|  37 |  25 |  %   | Percentual            |
|  38 |  26 |  &   | E comercial           |
|  39 |  27 |  '   | Aspas simples         |
|  40 |  28 |  (   | Parêntese esquerdo    |
|  41 |  29 |  )   | Parêntese direito     |
|  42 |  2A |  *   | Asterisco             |
|  43 |  2B |  +   | Mais                  |
|  44 |  2C |  ,   | Vírgula               |
|  45 |  2D |  -   | Hífen                 |
|  46 |  2E |  .   | Ponto                 |
|  47 |  2F |  /   | Barra                 |
|  48 |  30 |  0   | Zero                  |
|  49 |  31 |  1   | Um                    |
|  50 |  32 |  2   | Dois                  |
|  51 |  33 |  3   | Três                  |
|  52 |  34 |  4   | Quatro                |
|  53 |  35 |  5   | Cinco                 |
|  54 |  36 |  6   | Seis                  |
|  55 |  37 |  7   | Sete                  |
|  56 |  38 |  8   | Oito                  |
|  57 |  39 |  9   | Nove                  |
|  58 |  3A |  :   | Dois pontos           |
|  59 |  3B |  ;   | Ponto e vírgula       |
|  60 |  3C |  <   | Menor que             |
|  61 |  3D |  =   | Igual a               |
|  62 |  3E |  >   | Maior que             |
|  63 |  3F |  ?   | Interrogação          |
|  64 |  40 |  @   | Arroba                |
|  65 |  41 |  A   | A maiúsculo           |
|  66 |  42 |  B   | B maiúsculo           |
|  67 |  43 |  C   | C maiúsculo           |
|  68 |  44 |  D   | D maiúsculo           |
|  69 |  45 |  E   | E maiúsculo           |
|  70 |  46 |  F   | F maiúsculo           |
|  71 |  47 |  G   | G maiúsculo           |
|  72 |  48 |  H   | H maiúsculo           |
|  73 |  49 |  I   | I maiúsculo           |
|  74 |  4A |  J   | J maiúsculo           |
|  75 |  4B |  K   | K maiúsculo           |
|  76 |  4C |  L   | L maiúsculo           |
|  77 |  4D |  M   | M maiúsculo           |
|  78 |  4E |  N   | N maiúsculo           |
|  79 |  4F |  O   | O maiúsculo           |
|  80 |  50 |  P   | P maiúsculo           |
|  81 |  51 |  Q   | Q maiúsculo           |
|  82 |  52 |  R   | R maiúsculo           |
|  83 |  53 |  S   | S maiúsculo           |
|  84 |  54 |  T   | T maiúsculo           |
|  85 |  55 |  U   | U maiúsculo           |
|  86 |  56 |  V   | V maiúsculo           |
|  87 |  57 |  W   | W maiúsculo           |
|  88 |  58 |  X   | X maiúsculo           |
|  89 |  59 |  Y   | Y maiúsculo           |
|  90 |  5A |  Z   | Z maiúsculo           |
|  91 |  5B |  [   | Colchete esquerdo     |
|  92 |  5C |  \   | Barra invertida       |
|  93 |  5D |  ]   | Colchete direito      |
|  94 |  5E |  ^   | Circunflexo           |
|  95 |  5F |  _   | Sublinhado            |
|  96 |  60 |  `   | Crase                 |
|  97 |  61 |  a   | a minúsculo           |
|  98 |  62 |  b   | b minúsculo           |
|  99 |  63 |  c   | c minúsculo           |
| 100 |  64 |  d   | d minúsculo           |
| 101 |  65 |  e   | e minúsculo           |
| 102 |  66 |  f   | f minúsculo           |
| 103 |  67 |  g   | g minúsculo           |
| 104 |  68 |  h   | h minúsculo           |
| 105 |  69 |  i   | i minúsculo           |
| 106 |  6A |  j   | j minúsculo           |
| 107 |  6B |  k   | k minúsculo           |
| 108 |  6C |  l   | l minúsculo           |
| 109 |  6D |  m   | m minúsculo           |
| 110 |  6E |  n   | n minúsculo           |
| 111 |  6F |  o   | o minúsculo           |
| 112 |  70 |  p   | p minúsculo           |
| 113 |  71 |  q   | q minúsculo           |
| 114 |  72 |  r   | r minúsculo           |
| 115 |  73 |  s   | s minúsculo           |
| 116 |  74 |  t   | t minúsculo           |
| 117 |  75 |  u   | u minúsculo           |
| 118 |  76 |  v   | v minúsculo           |
| 119 |  77 |  w   | w minúsculo           |
| 120 |  78 |  x   | x minúsculo           |
| 121 |  79 |  y   | y minúsculo           |
| 122 |  7A |  z   | z minúsculo           |
| 123 |  7B |  {   | Chave esquerda        |
| 124 |  7C |  \|  | Barra vertical        |
| 125 |  7D |  }   | Chave direita         |
| 126 |  7E |  ~   | Tilde                 |

</details>

## Exemplo comunicação ASCII

Vamos considerar o envio da mensagem "IFSP" usando a codificação ASCII através de uma conexão serial.

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

![Captura de tela 2024-05-09 081841](https://github.com/mchavesferreira/mcr/assets/63993080/d7db9158-3bcf-4d4d-8986-cac42324635a)

Tabela de tempos para a mensagem "IFSP" com diferentes baud_rates:

| Baud Rate (bps) | Tempo por Caractere (s)    | Tempo Total para "IFSP" (s) |
|-----------------|----------------------------|-----------------------------|
| 9600            | 0.0009375                  | 0.00375                     |
| 19200           | 0.00046875                 | 0.001875                    |
| 38400           | 0.000234375                | 0.0009375                   |
| 115200          | 0.000078125                | 0.0003125                   |


## Programação com IDE-Arduino: 

### Função Serial.begin()
A função Serial.begin() é usada para inicializar a porta serial0 com uma taxa de transmissão específica (baud rate), configurando a velocidade na qual os dados são enviados e recebidos através da porta serial. Esta função é essencial para estabelecer a comunicação entre o microcontrolador e o computador ou outro dispositivo serial.

Referência:  https://www.arduino.cc/reference/pt/language/functions/communication/serial/

#### Sintaxe
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

Serial.print(): Imprime dados na porta serial em como texto ASCII (facilmente legível, diferentemente dos valores binários). Essa função pode assumir várias formas. números são impressos usando um caractere ASCII para cada dígito. 

Serial.println(): Imprime dados na porta serial como texto ASCII seguido pelo caractere de retorno de carruagem (ASCII 13, ou '\r') 

#### Prática implemente o seguinte código e confira o resultado:

 ```ruby 
    Serial.print(78, BIN);
    Serial.print("\t");

    Serial.print(78, OCT);
   Serial.print(13);

    Serial.print(78, DEC);
  Serial.print("\r");

    Serial.print(78, HEX);

    Serial.print(1.23456, 0);

    Serial.print(1.23456, 2);

    Serial.print(1.23456, 4);
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

### Função Serial.read()

A função lê dados recebidos na porta serial.

 ```ruby
int incomingByte = 0; // variável para o dado recebido

void setup() {
  Serial.begin(9600); // abre a porta serial, configura a taxa de transferência para 9600 bps
}

void loop() {
  // apenas responde quando dados são recebidos:
  if (Serial.available() > 0) {
    // lê do buffer o dado recebido:
    incomingByte = Serial.read();

    // responde com o dado recebido:
    Serial.print("Eu Recebi: ");
    Serial.println(incomingByte, DEC);
  }
}
 ```

Serial.available(): Retorna o número de bytes (caracteres) disponíveis para leitura da porta serial. 

###  Serial.readStringUntil()

Serial.readStringUntil() ê caracteres do buffer serial e os move para uma String. A função termina se o caractere terminador é encontrado, ou se ocorre time-out.


Práticas:
 1- Combine o exemplo de acionamento do Led com comunicação serial, imprimindo uma mensagem com a cor acionada:

 https://wokwi.com/projects/339670467067511378

 2 - Acionando LEDs com a comunicação serial:

Para criar um exemplo utilizando a comunicação serial no Arduino onde diferentes letras acionam diferentes LEDs, podemos escrever um código que escuta a porta serial por entradas específicas ('A', 'S', 'D') e aciona os LEDs correspondentes (LEDs conectados aos pinos 10, 9 e 8) de acordo com a entrada recebida.

<details><summary>Codigo Serial/LED</summary>
<p>
    
 ```ruby
// Definindo os pinos dos LEDs
int ledPinA = 10;  // LED para o caractere 'A'
int ledPinS = 9;   // LED para o caractere 'S'
int ledPinD = 8;   // LED para o caractere 'D'

void setup() {
  // Inicia a comunicação serial a 9600 bps
  Serial.begin(9600);
  
  // Configura os pinos dos LEDs como saída
  pinMode(ledPinA, OUTPUT);
  pinMode(ledPinS, OUTPUT);
  pinMode(ledPinD, OUTPUT);
  
  // Garante que todos os LEDs começam desligados
  digitalWrite(ledPinA, LOW);
  digitalWrite(ledPinS, LOW);
  digitalWrite(ledPinD, LOW);
}

void loop() {
  // Verifica se há dados disponíveis para ler na porta serial
  if (Serial.available() > 0) {
    // Lê o próximo caractere disponível
    char receivedChar = Serial.read();
    
    // Desliga todos os LEDs para garantir que apenas um fica aceso por vez
    digitalWrite(ledPinA, LOW);
    digitalWrite(ledPinS, LOW);
    digitalWrite(ledPinD, LOW);
    
    // Aciona o LED correspondente ao caractere recebido
    if (receivedChar == 'A') {
      digitalWrite(ledPinA, HIGH);
    } else if (receivedChar == 'S') {
      digitalWrite(ledPinS, HIGH);
    } else if (receivedChar == 'D') {
      digitalWrite(ledPinD, HIGH);
    }
  }
}
```
</details>

Exemplo:  https://wokwi.com/projects/397413115618262017

# TAREFA SUAP 09/05/2024:

Exemplo:  https://wokwi.com/projects/397413115618262017

Utilize o exemplo acima para criar o seguinte projeto com simulação ESP32, salve e envie a URL(endereço wokwi do projeto) em tarefa.

 - 4 Leds estão ligados respectivamente no pinos GPIO 21, 19, 18 e 5.
 - As 4 letras respectivamente Z, X, C e V acionam respectivamente cada um dos leds, devendo permanecer aceso o led da respectiva letra.
 - As letras estabelecem o tempo quando utilizadas na entrada serial: T <1000ms>, t <500 ms>  e U <100 ms>
 - A letra 'S' estabelece que o programa executará a sequência de pinos acionados e tempos
GPIO21, delay(300) GPIO18 delay(200) GPIO5
- A letra 'B' apaga todos os leds.
- A letra 'A' acende todos os leds.
    
3 - Imprimindo e lendo na porta serial (UART)<BR>



<details><summary>Codigo Serial</summary>
<p>

```ruby
   Serial.begin(115200);
   Serial.println("Por favor qual o seu nome:");
   while (!Serial.available()); // Wait for input
   String name = Serial.readStringUntil('\n');
   Serial.print("Olá, ");
   Serial.print(name);
```

</p>
</details>

Exemplo da comunicação serial: https://wokwi.com/projects/397406587999082497
