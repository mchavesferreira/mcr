# Microcontroladores 
 

<BR>1° Bimestre/2026 <h1>- <a href=https://github.com/mchavesferreira/mcr/blob/main/mcr.md> Aulas Atmega 328P</a></h1>, linguagens: C e Assembly


<B><h1>- <a href=https://github.com/mchavesferreira/mcr/tree/main/esp32> Aulas ESP32 </A></h1>

3° Bimestre/2026

Prova: 22/09/2026

Trabalho Projeto:  22/09/2026 

Peso Bimestre: Prova (50%) + Trabalho montado (50%) 

# Especificações do projeto 3

#### Máquina microcontrolada com ESP32, interface web e prototipagem em protoboard (PROJETO FÍSICO)


Trabalho individual ou em dupla. Cada integrante deverá postar o trabalho no SUAP e informar o nome da dupla. A entrega deverá conter o link da simulação no Wokwi, os arquivos `.ino` e `index.h` e um pequeno texto explicando o funcionamento.

Crie uma máquina personalizada controlada por ESP32 e montada em protoboard. Não serão consideradas máquinas de lavar ou sorveterias. O projeto deverá atender aos seguintes critérios:

* página web com, no mínimo, três perguntas ou escolhas; **(1,5 ponto)**
* ajuste de pelo menos um valor inteiro, como quantidade, tempo ou velocidade; **(0,5 ponto)**
* pelo menos dois LEDs como saídas digitais; **(0,5 ponto)**
* pelo menos uma saída PWM; **(0,5 ponto)**
* perguntas, escolhas e etapas apresentadas no display OLED; **(1,0 ponto)**
* botões virtuais para realizar as escolhas, reiniciar o processo e iniciar uma nova operação; **(1,0 ponto)**
* atualização da página por AJAX, sem recarregamento, mostrando as escolhas e o estado atual; **(1,5 ponto)**
* código organizado como máquina de estados, utilizando `switch/case`, funções e `millis()`; **(1,5 ponto)**
* criatividade, originalidade, complexidade e qualidade da montagem; **(2,0 pontos)**

Os botões da página substituem os botões físicos. O OLED, os LEDs, a saída PWM e os demais atuadores deverão fazer parte da montagem. A comunicação poderá utilizar `XMLHttpRequest` e rotas HTTP com respostas em `text/plain`, sem necessidade de JSON.

As duplas não poderão apresentar trabalhos clones. Todos os integrantes deverão postar o link e os arquivos no SUAP. Em caso de erro, a entrega poderá ser enviada por e-mail.

Exemplo inicial: https://wokwi.com/projects/466317204103476225

**Peso do bimestre:** Prova (50%) + Trabalho montado (50%) 


<BR><h1>Sugestão de lista de compras para montagem de projetos com ESP32</h1>
<BR>
<BR>-Esp32  Devkit Esp32-recomendado S3 com conector usb - Tipo C
<BR><img src=imagens/ESP32_tipoC.png width=200 height=200>
<BR>https://produto.mercadolivre.com.br/MLB-3456778444-esp32-doit-devkit-esp32-wroom-32-30-pinos-tipo-c-_JM

<BR>-Display Oled 0.96 I2c Branco/amarelo ou Azul 
<BR><img src=imagens/display_oled.png width=200 height=200>
<BR>https://produto.mercadolivre.com.br/MLB-2844134920-display-oled-branco-096-i2c-arduino-pic-_JM
<BR>
<BR>-Cabo Wire Jumper 20cm 40 Fios Fêmea-macho Protoboard 
<BR><img src=imagens/jumpers_machofemea.png width=200 height=200>
<BR>https://produto.mercadolivre.com.br/MLB-1884942498-cabo-wire-jumper-20cm-40-fios-fmea-macho-protoboard-arduino-_JM
<BR>
<BR>-Jumper Macho X Macho 65pcs Fio Arduino 
<BR><img src=imagens/jumpers_machomacho.png  width=200 height=200>
<BR>https://produto.mercadolivre.com.br/MLB-1944458631-jumper-macho-x-macho-65pcs-fio-arduino-para-mega-e-uno-_JM
<BR>
<BR>-Protoboard 830 Furos
<BR><img src=imagens/protoboard.png  width=200 height=200>
<BR>https://produto.mercadolivre.com.br/MLB-1934614556-protoboard-830-furos-breadboard-830-pontos-_JM

<BR>
<BR>-Minimo 5 Leds, resistores, botões Push-buttons
<BR><img src=imagens/leds_resistor.png  width=200 height=200>
<BR>

## Simuladores

https://velxio.dev/example/esp32c3-http-server



ChatGPT: https://chatgpt.com/g/g-TFvuISQH5-professor-dos-embarcados
