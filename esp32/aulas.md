05/09 - Relógio e Cronometro

Utilize este exemplo de display OLed (https://wokwi.com/projects/342195248670179922) e a função millis() para construir um relogio 

Hora:Minuto:Segundos 

29/08  - Temporização
 - [millis()](#millis())

22/08  - Displays LCD e Oled
      - [Display](#Display)

08/08 -  <a href=esp32/maquinaestadopasteurizacao.md> Projeto Pasteurização </a>

25/07 - <a href=esp32/maquinaestados.MD> Maquina de estados (abordagem if e switch/case) </a>

27/06 - Aula prática com ESP32

25/04 - Introdução ao ESP32 (Conhecendo  Referências Arduino e Simulador wokwi)

02/05 - Explorando GPIO Entradas e saídas (Pinout ESP32, GPIO Digital)

09/05  - Comunicação Serial:  https://github.com/mchavesferreira/mcr/blob/main/esp32/serialprint.md

16/05 e 23/5  - PWM:  https://github.com/mchavesferreira/mcr/blob/main/esp32/pwm.md

06/06  - Diplay Oled : https://github.com/mchavesferreira/mcr/blob/main/esp32/displayoled.md


## Aulas


25/04 - Introdução ao ESP32 (Conhecendo  Referências Arduino e Simulador wokwi)

02/05 - Explorando GPIO Entradas e saídas (Pinout ESP32, GPIO Digital)

09/05  - Comunicação Serial:  https://github.com/mchavesferreira/mcr/blob/main/esp32/serialprint.md

25/07 - <a href=maquinaestados.MD> Maquina de estados (abordagem if e switch/case) </a>

27/06 - Aula prática com ESP32


27/07  Temporização  - [millis()](#função-millis())

07/08  - Displays LCD e Oled
      - [Display](https://github.com/mchavesferreira/mcr/blob/main/esp32/displayoled.md)

14/08 - Relógio e Cronometro

Utilize este exemplo de display OLed (https://wokwi.com/projects/342195248670179922) e a função millis() para construir um relogio 

Hora:Minuto:Segundos 


28/08  - Display, comunicação serial, conversor AD, comparação e conversão da leitura AD

https://github.com/mchavesferreira/mcr/blob/main/entradaanalogica.md

### 04/09 Interface para uma maquina com display e botões

## Projeto 3° Bimestre

### Exemplo de anos anteriores

<BR><BR>Máquina de sorvete 1:
<BR>https://wokwi.com/projects/443072496525751297

<hr>
<BR>
<BR>
ESP32_3led_1botao >>>>  https://wokwi.com/projects/366328229239357441
<BR>

## 11/09 Exemplo de prova

https://github.com/mchavesferreira/mcr/blob/main/esp32/avalia%C3%A7%C3%A3o_mcr_3bimestre%20com%20delay.doc

Simulado:  https://wokwi.com/projects/441805148851773441

resolucao:   https://github.com/mchavesferreira/mcr/blob/main/esp32/resolucaoprova3.md

## 4° Bimestre

30/10 - <a href=https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/mqtt/README.MD>Projetando IoT com Mqtt e Dashboard</A>


- Colocando em prática o projeto Mqtt e Iot, grave o controle de led via Iot

- 06/11/2025 - exemplo mqtt com mensagem em json <br>

 Iniciando projeto Iot     <a href=https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/mqtt/README.MD>Acesse </a><br>

 - Acrescente display o Oled. Planeje seu projeto Iot (<a href=https://github.com/mchavesferreira/mcr/blob/main/dicas%20de%20projetos/Dicasparaprojetos.pdf>Dicas</a>

### 13/11/2025

-Interpretando o template de código exemplo para a prova: https://github.com/mchavesferreira/mcr/blob/main/trabalho/template.pdf

-Planejamento do projeto final. Utilize exemplos de trabalhos anteriores

-https://github.com/mchavesferreira/mcr/tree/main/trabalho


# Trabalho 4° Bimestre

Maquina microntrolada Esp32 com protótipagem em protoboard e conexão mqtt ESP32


Trabalho em dupla. Postar individualmente citando a dupla. O trabalho deve ser entregue em formato digital com simulação e um pequeno texto explicando sua funcionalidade.
-Envio do codigo nesta aba do SUAP, apenas se ocorrer um erro, enviar para email, arquivos fontes e texto resumo.

Crie uma máquina personalizada (não será considerado máquina de lavar e semáforo) atenda os seguintes critérios e ponderações:

- apresente no mínimo 05 perguntas entre (sim x não) ou ajustes de valores (exemplo tempo); (2,0 pontos)
- ajustes de pelo menos 02 valores inteiros; (0,5 pontos)

- utilize pelo menos 02 leds como saídas; (0,5 pontos)

- utilize pelo menos 01 entrada analógica (1,0 pontos)

- ajuste em botões será opcional (+1,0 ponto extra se ajuste ser simultaneo Oled e botões)

- perguntas e respostas devem utilizar display Oled e botões (exemplos para botões: + - 1 2 3 Y N enter) (*opcional)

- Alterar no mínimo 3 parametros e botão iniciar e parada de emergência utilizando um app dashboard e protocolo MQTT. (3 ptos)

- As duplas não podem ter trabalhos "clones", criatividade, complexidade e dificuldades serão pontuados; (2,0)


- Enviar o link na área trabalhos (suap). TODOS INTEGRANTES de cada integrante da dupla deve postar e apenas UM enviar por email.
-
- Utilizar:


- entrada analógica

- alteração de parametros utilizando MQTT.

Link de exemplo inicial: https://wokwi.com/projects/375842607540556801 e 

topicos em mqtt
https://wokwi.com/projects/381558252547499009

Hamburgueria

https://wokwi.com/projects/413925382712666113

Orientações para o código. Utilize switch()/case para estruturar seu projeto;

A utilização de funções deixam o código limpo e facilmente compreensível

Variáveis que serão utilizadas em funções diferentes devem ser globais. Variáveis locais são sempre recomendadas para economia de memória RAM.



## Simulador Wokwi

Simulador <a href=https://wokwi.com/projects/new/esp32>ESP32 Online</a>
<BR>
Teclas de atalho e tutorial para o <a href=https://docs.wokwi.com/pt-BR/guides/diagram-editor> Simulador Wokwi</a>
