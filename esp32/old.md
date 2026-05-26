## ID do chip

No ESP32, o "ID do chip" (Chip ID) refere-se a um identificador único atribuído ao chip. Esse ID pode ser usado para várias finalidades, incluindo a diferenciação entre múltiplos dispositivos na mesma rede ou para fins de segurança e autenticação.

O ID do chip no ESP32 é tipicamente derivado do endereço MAC do dispositivo, que é único para cada chip. Isso significa que cada ESP32 tem um ID do chip que pode ser considerado único, ajudando a evitar colisões e conflitos em sistemas onde múltiplos dispositivos precisam ser identificados de forma inequívoca.

Para obter o ID do chip em um programa, os desenvolvedores geralmente usam funções específicas da API do ESP-IDF ou do ambiente de desenvolvimento que estão utilizando, como o Arduino. Por exemplo, no ambiente Arduino, você pode usar a função ESP.getEfuseMac() para obter o ID do chip, que retorna o endereço MAC do dispositivo, e então processá-lo conforme necessário para seu uso específico.

Esse ID é especialmente útil em aplicações de Internet das Coisas (IoT), onde a identificação única de cada dispositivo é crucial para a comunicação e controle de rede.

<BR>Como verificar o ID do chip<a href=https://wokwi.com/projects/340959007153848914> Chip ID</a><BR>  

## Video Espressif ESP32-P4 REVERSE ENGINEERING

https://www.youtube.com/watch?v=-Nu0tjDCbbM



## Memória ESP32 


Mapeamento da memória (pagina 7) <a href=https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf>memory</a>

### Memória Volátil no ESP32

o ESP32, assim como em outros microcontroladores, a memória volátil é a memória que perde seu conteúdo quando o dispositivo é desligado. A memória volátil mais comum no ESP32 é a SRAM (Static Random Access Memory), que armazena variáveis e dados temporários durante a execução de programas.

<img src=https://raw.githubusercontent.com/mchavesferreira/mcr/refs/heads/main/esp32/imagens/memoria.jpg>

No ESP32, a memória volátil é representada pela SRAM, que está dividida em diferentes blocos:

SRAM1: Usada para armazenar dados e instruções do programa em execução.

SRAM2: Usada para operações de alta velocidade e pode ser mapeada tanto para a memória de dados quanto para a memória de instrução.

RTC FAST RAM: Uma pequena porção de SRAM acessível durante os modos de baixo consumo, como o modo deep sleep.

A memória volátil é essencial para o armazenamento temporário de variáveis e dados que mudam durante a execução de um programa.

## Memória Dinâmica vs. Memória Estática

A memória volátil pode ser utilizada de duas formas: dinâmica e estática.

##  Memória Estática (Static Memory)

A memória estática se refere a uma maneira de alocar memória que ocorre em tempo de compilação. No caso do ESP32, quando declaramos uma variável global ou local dentro de uma função sem utilizar alocação dinâmica, essa memória é estática. A principal característica da memória estática é que o tamanho e a alocação são definidos antes do programa ser executado, e ela permanece alocada até o final do programa.

###  Características da memória estática:

Alocada durante o tempo de compilação.

O espaço reservado não muda durante a execução do programa.

Mais eficiente em termos de performance, pois a alocação/desalocação não ocorre durante a execução.

Usada para variáveis globais e variáveis locais fixas.

Exemplo em C:

```ruby
int contador = 0;  // Variável estática, sempre disponível na memória.
```
##  Memória Dinâmica (Dynamic Memory)

A memória dinâmica, por outro lado, é alocada em tempo de execução usando funções como malloc, calloc ou realloc. No ESP32, o uso de memória dinâmica pode ser importante em aplicações que precisam lidar com dados de tamanho variável ou que têm necessidades de memória que mudam durante a execução.

### Características da memória dinâmica:

Alocada em tempo de execução.

O espaço reservado pode mudar dinamicamente durante o programa.

Menos eficiente em termos de performance, pois a alocação e desalocação ocorrem enquanto o programa está sendo executado.

Requer que o desenvolvedor libere a memória manualmente com free().

Exemplo em C:

```ruby

int *buffer;
buffer = (int *)malloc(10 * sizeof(int));  // Alocação dinâmica de um buffer de 10 inteiros.
if (buffer != NULL) {
    // Uso da memória alocada dinamicamente
}
free(buffer);  // Liberação da memória.
```

### Diferenças principais

#### Memória Estática:

A alocação é fixa e conhecida em tempo de compilação.

Usa menos recursos computacionais durante a execução.

Mais previsível em termos de uso de memória.

####  Memória Dinâmica:

Alocada durante a execução, permite maior flexibilidade.

Pode consumir mais recursos durante a execução devido à necessidade de gerenciamento da memória.

Requer cuidado com vazamentos de memória, onde a memória alocada não é liberada corretamente.

## Memória não volátil

<img src=https://raw.githubusercontent.com/mchavesferreira/mcr/refs/heads/main/esp32/imagens/memorianaovolatil.jpg>


## Linguagens e programação
<BR>Programando através de blocos
### Easycondig

Aprenda a programar o ESP32 para IOT através de videos tutoriais organizado em 3 partes (Stand-alone, Local-Network e Internet)
http://easycoding.tn/index.php/esp32/  (Videos tutoriais)

http://www.easycoding.tn/esp32/demos/code/  (ambiente de programação)

Exemplo XML com código fonte para websever: https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/easycoding_xml.xml

### codeskool

https://ide.codeskool.cc/

### mpyblockly
Programação visual em micropython para ESP32
https://mpyblockly.github.io/mpyblockly/

Brincando com Esp32
https://mjrobot.org/2017/09/26/iot-feito-facil-brincando-com-o-esp32-no-arduino-ide/
	
### Comunicando com google excel
Unleash the Power of ChatGPTs Code Interpreter: Crafting a Dynamic ESP32 Data Logger with DHT22 and Google Sheets
https://robu.in/unleash-the-power-of-chatgpts-code-interpreter-crafting-a-dynamic-esp32-data-logger-with-dht22-and-google-sheets/
	
## Livros e referencias
<BR> 
<img src=https://static.packt-cdn.com/products/9781789956870/cover/smaller> Internet of Things Projects with ESP32, <BR><BR>
https://download.packt.com/free-ebook/9781789956870,<BR><BR> source code: https://github.com/PacktPublishing/Internet-of-Things-Projects-with-ESP32 <BR><BR>
https://github.com/PacktPublishing/Developing-IoT-Projects-with-ESP32-2nd-edition<BR>
https://github.com/PacktPublishing/Internet-of-Things-with-ESP32<BR>
https://github.com/PacktPublishing/Advanced-ESP32	<BR>
https://lastminuteengineers.com/getting-started-with-esp32/
https://lastminuteengineers.com/electronics/esp32-projects/  Tutorial e Projetos com ESP32	<BR>
	
Características para ESP32<BR><BR>

  https://www.espressif.com/en/news/espressif-announces-%E2%80%A8esp32-s2-secure-wi-fi-mcu
<BR><BR> 
Livros e Codigos fontes<Br><BR>
https://github.com/PacktPublishing/Advanced-ESP32


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
