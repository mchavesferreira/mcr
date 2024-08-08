# Projeto Pasteurização

Elabore um programa para o ESP32 com os seguintes requisitos.


## Problema:

Desenvolva um sistema de controle para um processo de pasteurização de leite em um laticínio usando um ESP32. O processo de pasteurização envolve as seguintes etapas:

    Aquecimento Inicial: O leite é aquecido até 63°C.

    Manutenção da Temperatura: O leite é mantido a 63°C por 30 minutos.

    Resfriamento Inicial: O leite é resfriado rapidamente até 4°C.

    Manutenção da Refrigeração: O leite é mantido a 4°C até que o operador o retire.

##  Requisitos:

    Um botão de start inicia o processo de pasteurização. (botões normalmente aberto)

    A cada etapa, a temperatura deve ser mantida dentro de uma faixa específica.

    Ao final do processo, um alarme soa indicando que o leite está pronto.

    Sensores de temperatura monitoram continuamente a temperatura do leite. Utilizar entrada analógica analogRead() e a conversão de valores. Vide exemplo:  https://wokwi.com/projects/340963795998343762


## Conversão Direta do Valor RAW para Temperatura

Quando utilizamos um microcontrolador como o ESP32 para ler valores de sensores analógicos, a leitura direta do valor RAW (valor bruto) do ADC (Conversor Analógico-Digital) pode ser convertida diretamente para a unidade de medida desejada. Neste caso, vamos converter o valor bruto lido (que varia de 0 a 4095) diretamente para uma faixa de temperatura de 0°C a 100°C.
Conceito

O valor lido pelo ADC do ESP32, que varia de 0 a 4095, corresponde a um intervalo de tensão de 0V a 3.3V. Queremos mapear esses valores para uma faixa de temperatura de 0°C a 100°C.

A relação é linear, então podemos usar uma regra de três simples para converter o valor RAW diretamente para a temperatura desejada.
Fórmula

A fórmula para converter o valor bruto (RAW) lido do ADC para uma temperatura em °C é:

<img src=img/formula.png>


Exemplo de Código

Aqui está um exemplo de código para o ESP32 que realiza essa conversão:

´´´ java
const int potPin = 34; // Pino ao qual o sensor está conectado

void setup() {
    Serial.begin(115200);
}

void loop() {
    int potValue = analogRead(potPin);               // Lê o valor analógico do sensor
    float temperature = (potValue / 4095.0) * 100;   // Converte o valor RAW para temperatura em °C

    Serial.print("Leitura RAW: ");
    Serial.print(potValue);
    Serial.print(" - Temperatura: ");
    Serial.print(temperature);
    Serial.println(" °C");

    delay(1000); // Aguarda 1 segundo antes da próxima leitura
}

´´´




##  Tarefa:

    Crie um diagrama de máquina de estados que descreva cada etapa do processo de pasteurização.
