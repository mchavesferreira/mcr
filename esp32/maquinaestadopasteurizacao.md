# Controle de Processos em Automação de Laticínio

Retorne em tarefa o seguinte projeto:

## Tema:

A utilização de máquina de estados é essencial para o controle organizado e escalável de processos complexos em um laticínio. Neste exemplo, a abordagem com switch/case será comparada à abordagem utilizando if para gerenciar o processo de pasteurização de leite.

## Problema:
Desenvolva um sistema de controle para um processo de pasteurização de leite em um laticínio usando um ESP32. O processo de pasteurização envolve as seguintes etapas:

Aquecimento Inicial: O leite é aquecido até 63°C.
    
Manutenção da Temperatura: O leite é mantido a 63°C por 30 segundos.
    
Resfriamento Inicial: O leite é resfriado rapidamente até 4°C.
    
Manutenção da Refrigeração: O leite é mantido a 4°C até que o operador o retire.

##  Requisitos:

Um botão de start inicia o processo de pasteurização.
    
Sensores de temperatura monitoram continuamente a temperatura do leite.
    
A cada etapa, a temperatura deve ser mantida dentro de uma faixa específica.
    
Ao final do processo, um alarme soa indicando que o leite está pronto.

## Conversão Direta do Valor RAW para Temperatura

Quando utilizamos um microcontrolador como o ESP32 para ler valores de sensores analógicos, a leitura direta do valor RAW (valor bruto) do ADC (Conversor Analógico-Digital) pode ser convertida diretamente para a unidade de medida desejada. Neste caso, vamos converter o valor bruto lido (que varia de 0 a 4095) diretamente para uma faixa de temperatura de 0°C a 100°C.

### Conceito

O valor lido pelo ADC do ESP32, que varia de 0 a 4095, corresponde a um intervalo de tensão de 0V a 3.3V. Queremos mapear esses valores para uma faixa de temperatura de 0°C a 100°C.

A relação é linear, então podemos usar uma regra de três simples para converter o valor RAW diretamente para a temperatura desejada.

### Fórmula

A fórmula para converter o valor bruto (RAW) lido do ADC para uma temperatura em °C é:

<img src=imagens/formula.png>

### Exemplo de Código

Aqui está um exemplo de código para o ESP32 que realiza essa conversão:

 ```ruby 

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


 ```

## Exemplos WOKWI

Leitura analógica:

https://wokwi.com/projects/340963795998343762

Maquina de estados switch/case:

https://wokwi.com/projects/404407325257579521


