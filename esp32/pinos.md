# Pinos de Entradas e Saídas para ESP32

## Referência de Pinagem do ESP32: Quais pinos GPIO você deve usar?

O chip ESP32 vem com 48 pinos com múltiplas funções. Nem todos os pinos são expostos em todas as placas de desenvolvimento ESP32, e alguns pinos não podem ser usados.

Há muitas questões sobre como usar os GPIOs do ESP32. Quais pinos você deve usar? Quais pinos você deve evitar usar em seus projetos? Este post tem como objetivo ser um guia de referência simples e fácil de seguir para os GPIOs do ESP32.

A figura abaixo ilustra a pinagem do ESP-WROOM-32. Você pode usá-la como referência se estiver usando um chip ESP32 avulso para construir uma placa personalizada:

<img src=board.png>

Nota: nem todos os GPIOs são acessíveis em todas as placas de desenvolvimento, mas cada GPIO específico funciona da mesma maneira, independentemente da placa de desenvolvimento que você está usando. Se você está apenas começando com o ESP32, recomendamos a leitura do nosso guia: Introdução à Placa de Desenvolvimento ESP32.

## Periféricos do ESP32

Os periféricos do ESP32 incluem:

    18 canais de Conversor Analógico para Digital (ADC)
    3 interfaces SPI
    3 interfaces UART
    2 interfaces I2C
    16 canais de saída PWM
    2 Conversores Digital para Analógico (DAC)
    2 interfaces I2S
    10 GPIOs com detecção capacitiva

As funcionalidades de ADC (conversor analógico para digital) e DAC (conversor digital para analógico) são atribuídas a pinos específicos estáticos. No entanto, você pode decidir quais pinos serão UART, I2C, SPI, PWM, etc – você apenas precisa atribuí-los no código. Isso é possível devido à característica de multiplexação do chip ESP32.

Embora você possa definir as propriedades dos pinos no software, existem pinos atribuídos por padrão, conforme mostrado na figura a seguir (este é um exemplo para a placa ESP32 DEVKIT V1 DOIT com 36 pinos – a localização dos pinos pode mudar dependendo do fabricante).

Além disso, existem pinos com características específicas que os tornam adequados ou não para um determinado projeto. A tabela a seguir mostra quais pinos são melhores para usar como entradas, saídas e quais exigem cautela.

Os pinos destacados em verde estão OK para usar. Os destacados em amarelo também estão OK para uso, mas é necessário prestar atenção porque eles podem ter um comportamento inesperado principalmente na inicialização. Os pinos destacados em vermelho não são recomendados para uso como entradas ou saídas

<table border="1">
  <tr>
    <th>GPIO</th>
    <th>Entrada</th>
    <th>Saída</th>
    <th>Observações</th>
  </tr>
  <tr>
    <td>0</td>
    <td>com pull-up</td>
    <td>OK</td>
    <td>emite sinal PWM na inicialização, deve ser LOW para entrar no modo de gravação</td>
  </tr>
  <tr>
    <td>1</td>
    <td style="color: red;">pino TX</td>
    <td>OK</td>
    <td>saída de debug na inicialização</td>
  </tr>
  <tr>
    <td>2</td>
    <td>OK</td>
    <td>OK</td>
    <td>conectado ao LED onboard, deve ser deixado flutuando ou LOW para entrar no modo de gravação</td>
  </tr>
  <tr>
    <td>3</td>
    <td>OK</td>
    <td style="color: red;>pino RX</td>
    <td>HIGH na inicialização</td>
  </tr>
  <tr>
    <td>4</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>5</td>
    <td>OK</td>
    <td>OK</td>
    <td>emite sinal PWM na inicialização, pino de configuração</td>
  </tr>
  <tr>
    <td>6</td>
    <td style="color: red;>x</td>
    <td style="color: red;>x</td>
    <td>conectado ao flash SPI integrado</td>
  </tr>
  <tr>
    <td>7</td>
    <td style="color: red;>x</td>
    <td style="color: red;>x</td>
    <td>conectado ao flash SPI integrado</td>
  </tr>
  <tr>
    <td>8</td>
    <td style="color: red;>x</td>
    <td style="color: red;>x</td>
    <td>conectado ao flash SPI integrado</td>
  </tr>
  <tr>
    <td>9</td>
    <td>x</td>
    <td>x</td>
    <td>conectado ao flash SPI integrado</td>
  </tr>
  <tr>
    <td>10</td>
    <td style="color: red;>x</td>
    <td style="color: red;>x</td>
    <td>conectado ao flash SPI integrado</td>
  </tr>
  <tr>
    <td>11</td>
    <td>x</td>
    <td>x</td>
    <td>conectado ao flash SPI integrado</td>
  </tr>
  <tr>
    <td>12</td>
    <td>OK</td>
    <td>OK</td>
    <td>a inicialização falha se estiver puxado para HIGH, pino de configuração</td>
  </tr>
  <tr>
    <td>13</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>14</td>
    <td>OK</td>
    <td>OK</td>
    <td>emite sinal PWM na inicialização</td>
  </tr>
  <tr>
    <td>15</td>
    <td>OK</td>
    <td>OK</td>
    <td>emite sinal PWM na inicialização, pino de configuração</td>
  </tr>
  <tr>
    <td>16</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>17</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>18</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>19</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>21</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>22</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>23</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>25</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>26</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>27</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>32</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>33</td>
    <td>OK</td>
    <td>OK</td>
    <td></td>
  </tr>
  <tr>
    <td>34</td>
    <td>OK</td>
    <td></td>
    <td>apenas entrada</td>
  </tr>
  <tr>
    <td>35</td>
    <td>OK</td>
    <td></td>
    <td>apenas entrada</td>
  </tr>
  <tr>
    <td>36</td>
    <td>OK</td>
    <td></td>
    <td>apenas entrada</td>
  </tr>
  <tr>
    <td>39</td>
    <td>OK</td>
    <td></td>
    <td>apenas entrada</td>
  </tr>
</table>


## Pinos apenas para entrada

Os GPIOs de 34 a 39 são GPIs – pinos apenas para entrada. Esses pinos não possuem resistores internos de pull-up ou pull-down. Eles não podem ser usados como saídas, então use esses pinos apenas como entradas:

    GPIO 34
    GPIO 35
    GPIO 36
    GPIO 39

## Flash SPI integrado no ESP-WROOM-32

Os GPIOs 6 a 11 são expostos em algumas placas de desenvolvimento ESP32. No entanto, esses pinos estão conectados ao flash SPI integrado no chip ESP-WROOM-32 e não são recomendados para outros usos. Portanto, não use esses pinos em seus projetos:

    GPIO 6 (SCK/CLK)
    GPIO 7 (SDO/SD0)
    GPIO 8 (SDI/SD1)
    GPIO 9 (SHD/SD2)
    GPIO 10 (SWP/SD3)
    GPIO 11 (CSC/CMD)

## GPIOs com sensores de toque capacitivos

O ESP32 possui 10 sensores internos de toque capacitivo. Eles podem detectar variações em qualquer coisa que mantenha uma carga elétrica, como a pele humana. Assim, eles podem detectar variações induzidas ao tocar os GPIOs com um dedo. Esses pinos podem ser facilmente integrados em pads capacitivos e substituir botões mecânicos. Os pinos de toque capacitivo também podem ser usados para acordar o ESP32 do modo de suspensão profunda.

Esses sensores de toque internos estão conectados a estes GPIOs:

    T0 (GPIO 4)
    T1 (GPIO 0)
    T2 (GPIO 2)
    T3 (GPIO 15)
    T4 (GPIO 13)
    T5 (GPIO 12)
    T6 (GPIO 14)
    T7 (GPIO 27)
    T8 (GPIO 33)
    T9 (GPIO 32)


## Conversor Analógico para Digital (ADC)

O ESP32 possui 18 canais de entrada ADC de 12 bits (enquanto o ESP8266 possui apenas 1 canal ADC de 10 bits). Estes são os GPIOs que podem ser usados como ADC e seus respectivos canais:

    ADC1_CH0 (GPIO 36)
    ADC1_CH1 (GPIO 37)
    ADC1_CH2 (GPIO 38)
    ADC1_CH3 (GPIO 39)
    ADC1_CH4 (GPIO 32)
    ADC1_CH5 (GPIO 33)
    ADC1_CH6 (GPIO 34)
    ADC1_CH7 (GPIO 35)
    ADC2_CH0 (GPIO 4)
    ADC2_CH1 (GPIO 0)
    ADC2_CH2 (GPIO 2)
    ADC2_CH3 (GPIO 15)
    ADC2_CH4 (GPIO 13)
    ADC2_CH5 (GPIO 12)
    ADC2_CH6 (GPIO 14)
    ADC2_CH7 (GPIO 27)
    ADC2_CH8 (GPIO 25)
    ADC2_CH9 (GPIO 26)

    Nota: Os pinos ADC2 não podem ser usados quando o Wi-Fi está em uso. Portanto, se você está utilizando Wi-Fi e está tendo problemas para obter o valor de um GPIO ADC2, você pode considerar usar um GPIO ADC1 em vez disso. Isso deve resolver seu problema.

Os canais de entrada ADC possuem uma resolução de 12 bits. Isso significa que você pode obter leituras analógicas variando de 0 a 4095, onde 0 corresponde a 0V e 4095 a 3,3V. Você também pode configurar a resolução dos seus canais no código e o intervalo do ADC.

Os pinos ADC do ESP32 não têm um comportamento linear. Provavelmente, você não conseguirá distinguir entre 0 e 0,1V ou entre 3,2 e 3,3V. Você precisa ter isso em mente ao usar os pinos ADC. Você obterá um comportamento semelhante ao mostrado na figura a seguir.

<img src=conversorad.png>
Figura: Comportamento dos pinos ADC do ESP32.


## Conversor Digital para Analógico (DAC)

Existem 2 canais DAC de 8 bits no ESP32 para converter sinais digitais em saídas de sinal de tensão analógica. Estes são os canais DAC:

    DAC1 (GPIO25)
    DAC2 (GPIO26)


## GPIOs RTC

O ESP32 possui suporte para GPIOs RTC. Os GPIOs roteados para o subsistema de baixo consumo de energia RTC podem ser usados quando o ESP32 está em modo de sono profundo. Esses GPIOs RTC podem ser usados para acordar o ESP32 do sono profundo quando o co-processador Ultra Low Power (ULP) está em funcionamento. Os seguintes GPIOs podem ser usados como uma fonte externa de despertar:

    RTC_GPIO0 (GPIO36)
    RTC_GPIO3 (GPIO39)
    RTC_GPIO4 (GPIO34)
    RTC_GPIO5 (GPIO35)
    RTC_GPIO6 (GPIO25)
    RTC_GPIO7 (GPIO26)
    RTC_GPIO8 (GPIO33)
    RTC_GPIO9 (GPIO32)
    RTC_GPIO10 (GPIO4)
    RTC_GPIO11 (GPIO0)
    RTC_GPIO12 (GPIO2)
    RTC_GPIO13 (GPIO15)
    RTC_GPIO14 (GPIO13)
    RTC_GPIO15 (GPIO12)
    RTC_GPIO16 (GPIO14)
    RTC_GPIO17 (GPIO27)

## PWM

O controlador PWM LED do ESP32 possui 16 canais independentes que podem ser configurados para gerar sinais PWM com diferentes propriedades. Todos os pinos que podem atuar como saídas podem ser usados como pinos PWM (GPIOs de 34 a 39 não podem gerar PWM).
Para configurar um sinal PWM, você precisa definir os seguintes parâmetros no código:

- Frequência do sinal;
- Ciclo de trabalho (duty cycle);
- Canal PWM;
- GPIO onde você deseja emitir o sinal.

## I2C

O ESP32 possui dois canais I2C e qualquer pino pode ser configurado como SDA ou SCL. Ao usar o ESP32 com a IDE do Arduino, os pinos I2C padrão são:

    GPIO 21 (SDA)
    GPIO 22 (SCL)

Se você quiser usar outros pinos ao utilizar a biblioteca Wire, basta chamar:
´´´code
Wire.begin(SDA, SCL);
´´´
Saiba mais sobre o protocolo de comunicação I2C com o ESP32 usando a IDE do Arduino: Comunicação I2C no ESP32 (Configurar Pinos, Interfaces de Múltiplos Barramentos e Periféricos)

## SPI

Por padrão, o mapeamento de pinos para SPI é:

| SPI  | MOSI    | MISO    | CLK    | CS   |
|------|---------|---------|--------|------|
| VSPI | GPIO 23 | GPIO 19 | GPIO 18| GPIO 5 |
| HSPI | GPIO 13 | GPIO 12 | GPIO 14| GPIO 15 |

## Interrupções

Todos os GPIOs podem ser configurados como interrupções.

## Pinos de Configuração (Strapping Pins)

"Strapping Pins" refere-se a pinos específicos em um microcontrolador ou processador que são usados para configurar o estado inicial do dispositivo quando ele é ligado ou reiniciado. Esses pinos são lidos pelo hardware no momento do boot para determinar configurações importantes, como o modo de operação do dispositivo ou outras opções de configuração essenciais.

O chip ESP32 possui os seguintes pinos de configuração:

    GPIO 0 (deve estar em LOW para entrar no modo de inicialização)
    GPIO 2 (deve estar flutuante ou em LOW durante a inicialização)
    GPIO 4
    GPIO 5 (deve estar em HIGH durante a inicialização)
    GPIO 12 (deve estar em LOW durante a inicialização)
    GPIO 15 (deve estar em HIGH durante a inicialização)

Esses pinos são usados para colocar o ESP32 em modo de bootloader ou modo de gravação (flashing). Na maioria das placas de desenvolvimento com USB/Serial embutido, você não precisa se preocupar com o estado desses pinos. A placa coloca os pinos no estado correto para gravação ou modo de inicialização. Mais informações sobre a Seleção de Modo de Boot do ESP32 podem ser encontradas aqui.

No entanto, se você tiver periféricos conectados a esses pinos, pode ter dificuldades ao tentar fazer upload de novo código, gravar o ESP32 com novo firmware ou reiniciar a placa. Se você tem periféricos conectados aos pinos de configuração e está tendo problemas para fazer upload de código ou gravar o ESP32, pode ser que esses periféricos estejam impedindo o ESP32 de entrar no modo correto. Leia a documentação de Seleção de Modo de Boot para orientá-lo na direção certa. Após reiniciar, gravar ou inicializar, esses pinos funcionam como esperado.

## Pinos em Estado Alto na Inicialização (BOOT)

Alguns GPIOs mudam seu estado para ALTO ou emitem sinais PWM ao iniciar ou reiniciar. Isso significa que, se você tiver saídas conectadas a esses GPIOs, poderá obter resultados inesperados quando o ESP32 for reiniciado ou inicializado.

    GPIO 1
    GPIO 3
    GPIO 5
    GPIO 6 a GPIO 11 (conectados à memória flash SPI integrada do ESP32 – não recomendado para uso).
    GPIO 14
    GPIO 15

## Enable (EN)

Enable (EN) é o pino de habilitação do regulador de 3.3V. Ele é puxado para cima, então conecte ao terra para desativar o regulador de 3.3V. Isso significa que você pode usar esse pino conectado a um botão de pressão para reiniciar seu ESP32, por exemplo.

##  Corrente de Consumo dos GPIOs

A corrente máxima absoluta por GPIO é de 40mA de acordo com a seção "Condições Operacionais Recomendadas" na folha de dados do ESP32.

##  Sensor de Efeito Hall Integrado no ESP32

O ESP32 também possui um sensor de efeito hall integrado que detecta mudanças no campo magnético ao seu redor.

Fonte:  
<BR><a href=https://randomnerdtutorials.com/esp32-pinout-reference-gpios/>Configuração I/O</a> para cada pino.

