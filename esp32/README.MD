# Esp32  

- [Apostila ESP32](#Apostila-ESP32)
- [Arduino Referências](#Referências-Arduino)
- [Pinout Esp32](#pinout-esp32)
- [Arquitetura Esp32](#arquitetura-esp32)
- [Simulador Online](#simulador-wokwi)
- [Funções principais](#Funçoes-principais)
- [Variáveis e Operadores](#variaveis-operadores)
- [GPIOs, leitura e escrita em pinos digitais](#gpio-digital) 
- [Comunicação Serial](#Comunicação-serial) (19/5)
- [PWM](#pwm) (26/5)
- [millis()](#função-millis)
- [Display](#Display) (02/6)
	- [LCD 16x2](#lcd-16x2)
	- [Oled](#display-oled) (tarefa suap)
- [Interrupção Externa](#Interrupção-externa) (09/6)
- [Exemplo de projeto](#Exemplo-de-projeto) (16/6)
- Avaliação (23/6)
- Entrega de projetos (30/6)
- [ESP32 IOT](#ESP32-IOT) (3°Bimestre)
 - leitura analógica
- [Livros](#Livros-e-referencias)


# Referências Arduino

<center>  <a href=https://www.arduino.cc/reference/pt/ target=_blank>Arduino Referência de Linguagem C</a> </center><BR>

<BR><B>Programar ESP32 com IDE Arduino</B>

<BR><img src=https://www.lojamundi.com.br/imagens/produtos/Raspberry-Pi-Cabo-mini-USB.webp width=200 height=200>
<BR> <a href=https://www.blogdarobotica.com/2021/08/24/como-programar-a-placa-esp32-no-arduino-ide>Como gravar o esp32 com Arduino</a>
<hr>

# variaveis e operadores

Uso de Variáveis, #define e funções próprias para I/0 Arduino

https://docs.arduino.cc/language-reference/pt/#vari%C3%A1veis

https://github.com/mchavesferreira/mcr/blob/main/esp32/variaveis.md

# Pinout ESP32

<img src=https://microcontrollerslab.com/wp-content/uploads/2019/02/ESP32-pinout-mapping.png>

<br><a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/pinos.md> Conheça sobre a configuração de pinos </a>

# GPIO Digital

### Função digitalWrite()

Definição:
A função digitalWrite() é usada para escrever um valor HIGH (alto) ou LOW (baixo) em um pino digital configurado como saída. Isso é fundamental para controlar dispositivos externos como LEDs, relés, e outros componentes digitais.

### Função digitalRead()

Definição:
A função digitalRead() é usada para ler o estado de um pino digital configurado como entrada. Isso permite detectar se um pino está recebendo um sinal HIGH ou LOW, que é útil para ler o estado de botões, sensores digitais, e outros dispositivos de entrada.

### pinMode()

A função pinMode() é essencial no desenvolvimento de projetos com microcontroladores, como o ESP32, ao usar a IDE do Arduino. Ela é usada para configurar um pino específico como entrada (INPUT), saída (OUTPUT), ou outros modos especiais como entrada com pull-up interno (INPUT_PULLUP). Essa função determina como o pino especificado se comportará, seja lendo sinais de sensores, botões e outros dispositivos, ou controlando LEDs, relés, e outros atuadores.

#### Configurando um pino como saída:

 ```ruby  
#define LED_PIN 2  // Define o número do pino para um LED

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configura o pino do LED como saída
}

 ```

#### Configurando um pino como entrada com pull-up:

 ```ruby  
#define BUTTON_PIN 0  // Define o número do pino para um botão

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Configura o pino do botão como entrada com pull-up
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // Lê o estado do botão
  if (buttonState == LOW) {  // Verifica se o botão está sendo pressionado
    // Ação a ser realizada quando o botão está pressionado
  }
}

 ```


<BR>GPIOs, leitura e escrita em pinos digitais. Simulação: <a href=https://wokwi.com/projects/339670467067511378>digitalRead() e digitalWrite()</a>


# Arquitetura

<img src=https://raw.githubusercontent.com/mchavesferreira/mcr/refs/heads/main/esp32/imagens/arquitetura_esp32.png>

	
## Exemplos práticos


### Pisca Led

https://wokwi.com/projects/339670467067511378


<img src=imagens/piscaled.jpg width=300 height=300>

#### Pisca-led RGB onboard Esp32S3

https://www.phippselectronics.com/esp32-s3-devkitc-1-blink-onboard-rgb-led/?srsltid=AfmBOoof7fWzIlkYRgw8T0ClmNdsBDHrAUJHE5bU1oa9FyKTfL4wS_5w

## Aula 12/05

### Maquina de estados (revisão)

https://wokwi.com/projects/366330976086070273

## Aula 19/05

# Comunicação Serial

Imprimindo e lendo na porta serial (UART)<BR>

https://github.com/mchavesferreira/mcr/blob/main/esp32/serialprint.md
  
<details><summary>Codigo Serial</summary>
<p>

```ruby
void setup() {
// Inicializa a comunicação serial UART do ESP32
// na velocidade de 115200 bits por segundo.
// Essa comunicação será usada com o Monitor Serial da IDE Arduino.
Serial.begin(115200);


// Envia a mensagem para o Monitor Serial
// utilizando println(), que imprime o texto
// e pula automaticamente para a próxima linha.
Serial.println("Qual é o seu nome? :");


// Aguarda até que algum dado seja digitado
// no Monitor Serial.
// Serial.available() retorna a quantidade de bytes
// disponíveis no buffer serial.
// Enquanto for zero, o programa fica parado neste loop.
while (!Serial.available());


// Lê os caracteres recebidos pela serial
// até encontrar o caractere '\n' (ENTER).
// O texto recebido será armazenado
// na variável String chamada "name".
String name = Serial.readStringUntil('\n');


// Envia o texto "Ola, " para o Monitor Serial
// sem quebra de linha.
Serial.print("Ola, ");


// Exibe o conteúdo armazenado na variável "name",
// ou seja, o nome digitado pelo usuário.
Serial.print(name);
}

void loop() {
}

```

</p>
</details>

  
<BR>Simulação: <a href=https://wokwi.com/projects/341561853822894674>Comunicando através da entrada serial</a>

<P>Exemplos aplicando porta serial e PWM
<BR>05: <a href=https://wokwi.com/projects/341698810319209042>Leitura de cores utilizando serial</a>.<span size=-2> Autores: Vinicius Viana e  Luis H. Estareli</span>.



## Aula 26/05

# PWM

Gerando sinais analógicos através PWM

https://github.com/mchavesferreira/mcr/blob/main/esp32/pwm.md

# Função millis()

A função `millis()` no Arduino é uma ferramenta poderosa para realizar temporizações sem bloquear a execução do programa. Diferente da função `delay()`, que pausa a execução de todo o código por um período especificado, `millis()` permite que o Arduino continue processando outras tarefas enquanto monitora o tempo.

### Como Funciona

A função `millis()` retorna o número de milissegundos que se passaram desde que o Arduino foi ligado ou reiniciado. Utilizando essa função, é possível implementar temporizações em seu código sem impedir o funcionamento de outras partes do programa.

### Exemplo Prático

Imagine que você quer fazer um LED piscar a cada segundo sem interromper a execução de outras funcionalidades. Isso pode ser feito com `millis()` da seguinte forma:

```ruby
const int pinoLed = 13; // Pino onde o LED está conectado
unsigned long tempoAnterior = 0; // Armazena o último momento em que o LED foi alterado
const long intervalo = 1000; // Intervalo desejado de 1 segundo (1000 milissegundos)

void setup() {
  pinMode(pinoLed, OUTPUT); // Define o pino do LED como saída
}

void loop() {
  unsigned long tempoAtual = millis(); // Captura o tempo atual

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual; // Atualiza o tempo anterior

    // Altera o estado do LED
    int estadoLed = digitalRead(pinoLed);
    digitalWrite(pinoLed, !estadoLed); // Inverte o estado do LED
  }
}

```
<a href=https://raw.githubusercontent.com/mchavesferreira/mcr/refs/heads/main/esp32/imagens/figura_millis.png> millis() versus delay()</a> - Diferenças sobre o uso

## Exemplo de maquina de estados com millis()

Tarefa Suap: Acrescente mais uma transição com botão e torne o brilho do led com controle pwm.

https://wokwi.com/projects/465046164881436673

## Aula 02/06

# Display
 
<BR>Displays LCD, Oled, comunicação I2C
### LCD 16x2
  <BR>01 -<a href=https://wokwi.com/projects/342202939017790036> Exemplo LCD 16x2 paralelo</a>
  <BR>02 -<a href=https://wokwi.com/projects/342199886273315410> Exemplo LCD 16x2 I2C</a>

### Oled
 
-<a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/displayoled.md> Display Oled</a>

Para ESP32 S3, os pinos alteram para o display I2C: GPIO 8 (SDA) GPIO 9 (SCL)

### Tarefa SUAP: 

#### Cronometro Oled

Utilize o exemplo disponivel em wokwi

https://wokwi.com/projects/342195248670179922

e a explicação sobre display Oleds para criar um cronometro. Acrescente ao display um botão para iniciar a contagem do tempo e um botão para resetar. Formato 00:00:00 (hora: minuto:segundo)

Lembre-se: crie tres variáveis e coloque as regras sobe o incremento das variaveis hora, minuto e segundos.
Utilize millis() no lugar de delay()


## aula 09/6

# Interrupção externa

## Função `attachInterrupt()`

A função `attachInterrupt()` é utilizada para associar uma interrupção externa a um pino do microcontrolador. Com ela, o ESP32 passa a monitorar uma mudança elétrica nesse pino e, quando a condição definida acontece, uma função escolhida pelo programador é executada automaticamente.

Sua estrutura geral é:

```cpp
attachInterrupt(pino, funcao, modo);
```

O primeiro parâmetro indica o pino que será monitorado. O segundo parâmetro indica qual função será chamada quando a interrupção ocorrer. Essa função pode receber qualquer nome válido em C/C++, como `funcao_ISR`, `contadorPulso`, `leituraSensor` ou outro nome escolhido pelo programador. O terceiro parâmetro define o tipo de mudança no sinal que irá disparar a interrupção.

No exemplo do odômetro de bicicleta, a interrupção pode ser usada para contar os pulsos gerados por um sensor magnético. Cada vez que o ímã preso ao aro da roda passa próximo ao sensor, ocorre uma mudança no sinal elétrico. Essa mudança pode ser detectada pelo ESP32 por meio da função `attachInterrupt()`, permitindo contar giros ou frações de giro da roda sem precisar verificar continuamente o sensor dentro do `loop()`.

### Modos de disparo da interrupção

| Modo      | Quando a interrupção ocorre                                                       | Exemplo de uso                                                                   |
| --------- | --------------------------------------------------------------------------------- | -------------------------------------------------------------------------------- |
| `RISING`  | Quando o sinal muda de nível baixo para nível alto                                | Detectar a chegada de um pulso positivo                                          |
| `FALLING` | Quando o sinal muda de nível alto para nível baixo                                | Detectar o fim de um pulso ou acionamento com pull-up                            |
| `CHANGE`  | Quando o sinal muda de estado, tanto de baixo para alto quanto de alto para baixo | Detectar qualquer mudança no sinal                                               |
| `LOW`     | Enquanto o pino permanece em nível baixo                                          | Usos específicos em que o nível baixo deve manter a interrupção ativa            |
| `HIGH`    | Enquanto o pino permanece em nível alto                                           | Disponível apenas em algumas placas, não é o modo mais comum em exemplos básicos |

Para sensores digitais, botões e aplicações como contagem de pulsos, os modos mais usados são `RISING`, `FALLING` e `CHANGE`. A escolha depende do comportamento elétrico do sensor e do momento em que se deseja registrar o evento.

<img src=imagens/bicicletaodometro.png>

No exemplo a seguir, a cada mudança de borda de descida para o pino GPIO_BOTAO, a rotina funcao_ISR é chamada.

```java
  pinMode(GPIO_BOTAO, INPUT_PULLUP);
  attachInterrupt(GPIO_BOTAO, funcao_ISR, RISING);
```

 <br><a href=https://wokwi.com/projects/439860789263905793> Exemplo função de Interrupção AttachInterrupt </a>

  ## Biblioteca `ezButton`

A biblioteca `ezButton.h` facilita a leitura de botões no ESP32, pois organiza a verificação do acionamento e ajuda a tratar o efeito de *debounce*, evitando que um único toque seja interpretado como vários comandos. Com ela, o botão é criado como um objeto, por exemplo `ezButton button1(2);`, indicando que o botão está ligado ao pino GPIO 2. Dentro do `loop()`, é necessário chamar `button1.loop()` continuamente para que a biblioteca atualize o estado do botão e permita verificar eventos como pressionamento ou liberação.

```cpp
#include <ezButton.h>

// Cria um objeto chamado button1 associado ao pino GPIO 2
ezButton button1(2);

void setup() {
  Serial.begin(9600);

  // Define o tempo de debounce em milissegundos
  // Ajuda a evitar leituras falsas causadas pelo repique mecânico do botão
  button1.setDebounceTime(50);
}

void loop() {
  // Atualiza internamente o estado do botão
  // Essa função deve ser chamada sempre dentro do loop()
  button1.loop();

  // Verifica se o botão foi pressionado
  if (button1.isPressed()) {
    Serial.println("Botao pressionado");
  }

  // Verifica se o botão foi solto
  if (button1.isReleased()) {
    Serial.println("Botao solto");
  }
}
```


## aula 16/6

# Exemplo de projeto 
 

Exemplo básico de um projeto com display Oled, 3 botões de seleção, uso de máquina de estados.

<a href=https://wokwi.com/projects/466317204103476225>Máquina de Sorvete</a>

Este projeto permite praticar uma aplicação interativa com ESP32, simulando uma máquina de sorvete automatizada. O aluno aprende o uso de **máquina de estados**, em que cada etapa representa uma escolha, como número de bolas, sabor, cobertura e recipiente. Também exercita a **leitura de botões**, o uso do **display OLED** para mensagens e o acionamento de **LEDs** para representar válvulas, motores ou outras cargas. A partir desse exemplo, o aluno pode criar novos projetos, como vending machine, dosador de líquidos, esteira seletora ou painel de controle didático, etc...


<img src=imagens/maquinasorverteprojeto1.png>


<BR><BR>


# Referências

## Apostila ESP32
<BR> <a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/ESP32.docx>Apostila</a> em desenvolvimento

<BR> <a href=https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf>Datasheet ESP32</a>


https://docs.espressif.com/projects/esp-hardware-design-guidelines/en/latest/esp32/schematic-checklist.html#flash-and-psram

https://docs.espressif.com/projects/esp-hardware-design-guidelines/en/latest/esp32/_images/esp32-sche-core.png


	
	
	
	
