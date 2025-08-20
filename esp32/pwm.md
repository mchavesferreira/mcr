
 ## Continuação Porta Serial
 
 Vamos completar os conhecimentos da aula anterior:
 
 Imprimindo e lendo na porta serial (UART)<BR>


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

Exemplo com pergunta e IF:  https://wokwi.com/projects/398045854579066881



# TAREFA :

Exemplo com pergunta e IF:  https://wokwi.com/projects/398045854579066881

Utilize o exemplo com pergunta através da porta serial tratados em sala de aula e o código já solicitado na tarefa 09/05, modifique para atender aos seguintes requisitos:

Utilize o exemplo acima para criar o seguinte projeto com simulação ESP32, salve e envie a URL(endereço wokwi do projeto) em tarefa.

-Estabeleça a comunicação serial.

-4 Leds estão ligados respectivamente no pinos GPIO 21, 19, 18 e 5.

Na função loop() implemente as seguintes tarefas:

-Pergunte quantos leds deseja acender entre 1 e 4 leds?

-Pergunte o intervalo de tempo em ms (favor digitar entre 100 e 5000)?

. Receba e String e converta em inteiro ambas as respotas. Crie regras (IF) analisando se foi digitado entre 1 e 4 na primeira pergunta e entre 100 e 5000 na segunda pergunta.

. Utilize estas respostas para piscar a quantidade de leds escolhido e no intervalo de tempo respondidoA letra 'A' acende todos os leds.

Continue lendo o teclado neste loop, sendo que ao digitar a letra 'a', o programa retorna ao inicio solicitando as perguntas.

# PWM
<P>PWM - Simulando saída analógica

PWM (Pulse Width Modulation) é uma técnica de modulação utilizada para controlar a potência fornecida a dispositivos eletrônicos, variando a largura de pulso de um sinal digital de acordo com uma frequência fixa. No ESP32, o PWM é implementado de maneira eficiente utilizando o hardware interno do microcontrolador.

Sugestões de Aplicação para PWM no ESP32

## Controle de Motores:

Motores DC: Controlar a velocidade de rotação de motores DC.

Servomotores: Ajustar a posição dos servos.

##  Controle de Iluminação:

LEDs: Variar a intensidade luminosa de LEDs e fitas de LED.

Lâmpadas: Controlar a luminosidade de lâmpadas incandescentes ou halógenas.

##  Geradores de Sinais:

Audio: Gerar sons ou música simples.

Comunicação: Transmissão de sinais modulados.

##  Conversores de Potência:

Fontes de Alimentação: Controle de conversores DC-DC.

## Exemplo de um sinal PWM

![Captura de tela 2024-05-15 234655](https://github.com/mchavesferreira/mcr/assets/63993080/4e8acc44-cb38-40cf-b4f8-5a76b4ce5f42)


## Pinos disponíveis com saída PWM
![Captura de tela 2024-05-15 234802](https://github.com/mchavesferreira/mcr/assets/63993080/b953ab88-53c1-40ef-a830-76fd8ecae712)

## Arduino - Função AnalogWrite()

No ESP32, a função analogWrite() tradicionalmente usada em outras placas Arduino não é diretamente suportada pela biblioteca padrão. No entanto, podemos criar uma função similar utilizando as funções de controle PWM do ESP32 (ledcSetup(), ledcAttachPin(), ledcWrite()).

Aqui está como você pode criar uma função analogWrite() personalizada para o ESP32:

```ruby
// Mapeia os pinos PWM para os canais PWM do ESP32
int pwmChannel = 0;
int freq = 5000; // Frequência em Hz
int resolution = 8; // Resolução de 8 bits

void analogWrite(int pin, int value) {
  ledcAttachPin(pin, pwmChannel);
  ledcSetup(pwmChannel, freq, resolution);
  ledcWrite(pwmChannel, value);
}
```

### Canal PWM: 

Se precisar usar mais de um pino PWM, você deve gerenciar diferentes canais PWM.

### Frequência e Resolução:

A frequência e a resolução podem ser ajustadas conforme a aplicação. A frequência de 5000 Hz e a resolução de 8 bits são comuns para muitas aplicações de LED.

## Exemplos:

01: <a href=https://wokwi.com/projects/341562296506516051>LED RGB e uso de analog_write() para PWM</a>

### Exemplo de Código Usando analogWrite() para Controlar o Brilho de um LED

```ruby
const int ledPin = 18;  // Pino do LED

void setup() {
  // Configura o canal PWM
  //ledcSetup(pwmChannel, freq, resolution);
  // Associa o pino ao canal PWM
  //ledcAttachPin(ledPin, pwmChannel);
}

void loop() {
  // Aumenta o brilho do LED de 0 a 255
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    analogWrite(ledPin, dutyCycle);
    delay(10);
  }
  // Diminui o brilho do LED de 255 a 0
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    analogWrite(ledPin, dutyCycle);
    delay(10);
  }
}
```

<P>02 - Função Debounce e uso de condição de fluxo IF
<BR>03: <a href=https://wokwi.com/projects/341562149868405330>Alternando cores em LEDS</a>
 



<P><a href=http://www.cdme.im-uff.mat.br/matrix/matrix-html/matrix_color_cube/matrix_color_cube_br.html>Tabela de cores RGB</a>
<P> 	




Exemplo da comunicação serial: https://wokwi.com/projects/397406587999082497


# TAREFA SUAP 23/05/2024:

Exemplo:  https://wokwi.com/projects/397413115618262017

Utilize o exemplos tratados em sala de aula sobre PWM, e modifique para atender aos seguintes requisitos
Controle  LED por controle de intensidade PWM através de teclas do teclado inseridos na porta serial.

Salve com um novo nome e envie a URL(endereço wokwi do projeto) em tarefa.

 - 4 Leds estão ligados respectivamente no pinos GPIO 21, 19, 18 e 5.
 - As 4 letras respectivamente A, S, D e F aumentam a intensidade através do PWM, respectivamente cada um dos leds.
 - As letras Z, X, C e V diminuem a intensidade respectiva de cada led.
- A letra 'B' apaga todos os leds.
- A letra 'G' acende todos os leds.

## Próxima Aula 30/05/2024

<P>PWM e leitura analógia alterando RGB
 
<BR><a href=https://wokwi.com/projects/341599671301440083>PWM-Analog</a><P>
