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

# Duty Cycle em PWM

O **Duty Cycle**, também chamado de **ciclo de trabalho**, representa a porcentagem do tempo em que um sinal PWM permanece em nível alto (*ligado*) durante um período completo do sinal.

Em um sinal PWM (*Pulse Width Modulation*), o período é composto por dois tempos:

- **TON**: tempo em que o sinal permanece em nível alto;
- **TOFF**: tempo em que o sinal permanece em nível baixo.

O valor do Duty Cycle é calculado pela relação entre o tempo ligado e o período total do sinal.

## Fórmula do Duty Cycle

\[
Duty\ Cycle (\%) = \frac{TON}{TON + TOFF} \times 100
\]

Onde:

- **TON** = tempo em nível alto;
- **TOFF** = tempo em nível baixo.

---

# Exemplos

## Duty Cycle de 50%

Quando o sinal permanece metade do tempo ligado e metade desligado:

- TON = 5 ms
- TOFF = 5 ms

\[
\frac{5}{5+5} \times 100 = 50\%
\]

Nesse caso, a carga recebe aproximadamente metade da potência máxima.

---

## Duty Cycle de 10%

O sinal fica pouco tempo em nível alto:

- TON = 1 ms
- TOFF = 9 ms

\[
\frac{1}{1+9} \times 100 = 10\%
\]

A potência média entregue à carga será baixa.

---

## Duty Cycle de 70%

O sinal permanece ligado durante a maior parte do período:

- TON = 7 ms
- TOFF = 3 ms

\[
\frac{7}{7+3} \times 100 = 70\%
\]

A carga recebe maior potência média.

---


Ao variar o Duty Cycle, é possível controlar a potência média aplicada à carga sem alterar a tensão de alimentação.


# TAREFA SUAP :

Confira exemplo 


