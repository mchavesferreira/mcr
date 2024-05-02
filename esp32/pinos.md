Pinos de Entradas e Saídas para ESP32

Referência de Pinagem do ESP32: Quais pinos GPIO você deve usar?

O chip ESP32 vem com 48 pinos com múltiplas funções. Nem todos os pinos são expostos em todas as placas de desenvolvimento ESP32, e alguns pinos não podem ser usados.

Há muitas questões sobre como usar os GPIOs do ESP32. Quais pinos você deve usar? Quais pinos você deve evitar usar em seus projetos? Este post tem como objetivo ser um guia de referência simples e fácil de seguir para os GPIOs do ESP32.

A figura abaixo ilustra a pinagem do ESP-WROOM-32. Você pode usá-la como referência se estiver usando um chip ESP32 avulso para construir uma placa personalizada:


Nota: nem todos os GPIOs são acessíveis em todas as placas de desenvolvimento, mas cada GPIO específico funciona da mesma maneira, independentemente da placa de desenvolvimento que você está usando. Se você está apenas começando com o ESP32, recomendamos a leitura do nosso guia: Introdução à Placa de Desenvolvimento ESP32.




| GPIO | Entrada    | Saída | Observações                                                           |
|------|------------|-------|-----------------------------------------------------------------------|
| 0    | com pull-up| OK    | emite sinal PWM na inicialização, deve ser LOW para entrar no modo de gravação |
| 1    | pino TX    | OK    | saída de debug na inicialização                                       |
| 2    | OK         | OK    | conectado ao LED onboard, deve ser deixado flutuando ou LOW para entrar no modo de gravação |
| 3    | OK         | pino RX| HIGH na inicialização                                                 |
| 4    | OK         | OK    |                                                                       |
| 5    | OK         | OK    | emite sinal PWM na inicialização, pino de configuração                |
| 6    | x          | x     | conectado ao flash SPI integrado                                      |
| 7    | x          | x     | conectado ao flash SPI integrado                                      |
| 8    | x          | x     | conectado ao flash SPI integrado                                      |
| 9    | x          | x     | conectado ao flash SPI integrado                                      |
| 10   | x          | x     | conectado ao flash SPI integrado                                      |
| 11   | x          | x     | conectado ao flash SPI integrado                                      |
| 12   | OK         | OK    | a inicialização falha se estiver puxado para HIGH, pino de configuração|
| 13   | OK         | OK    |                                                                       |
| 14   | OK         | OK    | emite sinal PWM na inicialização                                      |
| 15   | OK         | OK    | emite sinal PWM na inicialização, pino de configuração                |
| 16   | OK         | OK    |                                                                       |
| 17   | OK         | OK    |                                                                       |
| 18   | OK         | OK    |                                                                       |
| 19   | OK         | OK    |                                                                       |
| 21   | OK         | OK    |                                                                       |
| 22   | OK         | OK    |                                                                       |
| 23   | OK         | OK    |                                                                       |
| 25   | OK         | OK    |                                                                       |
| 26   | OK         | OK    |                                                                       |
| 27   | OK         | OK    |                                                                       |
| 32   | OK         | OK    |                                                                       |
| 33   | OK         | OK    |                                                                       |
| 34   | OK         |       | apenas entrada                                                        |
| 35   | OK         |       | apenas entrada                                                        |
| 36   | OK         |       | apenas entrada                                                        |
| 39   | OK         |       | apenas entrada                                                        |


