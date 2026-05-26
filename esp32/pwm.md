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

<img src=imagens/pwm_exemplo.png>



## Pinos disponíveis com saída PWM
![Captura de tela 2024-05-15 234802](https://github.com/mchavesferreira/mcr/assets/63993080/b953ab88-53c1-40ef-a830-76fd8ecae712)


## Exemplos:

01: <a href=https://wokwi.com/projects/341562296506516051>LED RGB e uso de analog_write() para PWM</a>

### Exemplo de Código Usando analogWrite() para Controlar o Brilho de um LED

```ruby
const int ledPin = 18;  // Pino do LED

void setup() {
pinMode(ledPin, OUTPUT);
}

void loop() {
  // Aumenta o brilho do LED
    for (int dutyCycle = 0; dutyCycle <= 4095; dutyCycle += 100) {
    analogWrite(led_blue, dutyCycle);
    delay(50);
  }

  // Diminui o brilho do LED
  for (int dutyCycle = 4095; dutyCycle >= 0; dutyCycle -= 100) {
   analogWrite(led_blue, dutyCycle);
   delay(50);
  }
}
```

Exemplo com 3 leds RGB:  https://wokwi.com/projects/465049101568074753 

<P><a href=http://www.cdme.im-uff.mat.br/matrix/matrix-html/matrix_color_cube/matrix_color_cube_br.html>Tabela de cores RGB</a>
<P> 	



# Duty Cycle em PWM

O **Duty Cycle**, também chamado de **ciclo de trabalho**, representa a porcentagem do tempo em que um sinal PWM permanece em nível alto (*ligado*) durante um período completo do sinal.

Em um sinal PWM (*Pulse Width Modulation*), o período é composto por dois tempos:

- **TON**: tempo em que o sinal permanece em nível alto;
- **TOFF**: tempo em que o sinal permanece em nível baixo.

O valor do Duty Cycle é calculado pela relação entre o tempo ligado e o período total do sinal.

Ao variar o Duty Cycle, é possível controlar a potência média aplicada à carga sem alterar a tensão de alimentação.


## Arduino - Função AnalogWrite() (Abstração)

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

# TAREFA SUAP 




