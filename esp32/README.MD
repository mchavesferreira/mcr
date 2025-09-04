# Curso de Microcontroladdores

# Esp32  (Técnico Integrado)


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

## 04/09 Interface para uma maquina com display e botões

# Projeto 3° Bimestre

## Exemplo de anos anteriores

<BR><BR>Máquina de sorvete 1:
<BR>https://wokwi.com/projects/343353681787224660 

<hr>
<BR>
<BR>
ESP32_3led_1botao >>>>  https://wokwi.com/projects/366328229239357441
<BR>


/10 - <a href=https://github.com/mchavesferreira/mcr/blob/main/esp32_iot/mqtt/README.MD>Projetando IoT com Mqtt e Dashboard</A>


31/10 - Colocando em prática o projeto Mqtt e Iot

/11 - Iniciando projeto Iot

 - Acrescente display o Oled. Planeje seu projeto Iot (<a href=https://github.com/mchavesferreira/mcr/blob/main/dicas%20de%20projetos/Dicasparaprojetos.pdf>Dicas</a>
/11 - Modificando Iot


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
 
## Referências Arduino

<center>  <a href=https://www.arduino.cc/reference/pt/ target=_blank>Arduino Referência de Linguagem C</a> </center><BR>

<BR><B>Utilizando a IDE Arduino</B>
<BR><img src=https://www.lojamundi.com.br/imagens/produtos/Raspberry-Pi-Cabo-mini-USB.webp width=200 height=200>
<BR> <a href=https://www.blogdarobotica.com/2021/08/24/como-programar-a-placa-esp32-no-arduino-ide>Como gravar o esp32 com Arduino</a>
<hr>


## Pinout ESP32

<img src=https://microcontrollerslab.com/wp-content/uploads/2019/02/ESP32-pinout-mapping.png>ESP32 pinout>

<br><a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/pinos.md> Conheça sobre a configuração de pinos </a>

## GPIO Digital

### Função digitalWrite()

Definição:
A função digitalWrite() é usada para escrever um valor HIGH (alto) ou LOW (baixo) em um pino digital configurado como saída. Isso é fundamental para controlar dispositivos externos como LEDs, relés, e outros componentes digitais.

### Função digitalRead()

Definição:
A função digitalRead() é usada para ler o estado de um pino digital configurado como entrada. Isso permite detectar se um pino está recebendo um sinal HIGH ou LOW, que é útil para ler o estado de botões, sensores digitais, e outros dispositivos de entrada.

### pinMode()

A função pinMode() é essencial no desenvolvimento de projetos com microcontroladores, como o ESP32, ao usar a IDE do Arduino. Ela é usada para configurar um pino específico como entrada (INPUT), saída (OUTPUT), ou outros modos especiais como entrada com pull-up interno (INPUT_PULLUP). Essa função determina como o pino especificado se comportará, seja lendo sinais de sensores, botões e outros dispositivos, ou controlando LEDs, relés, e outros atuadores.

#### Configurando um pino como saída:

 ```ruby  
#define LED_PIN 2  // Define o número do pino para um LED

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Configura o pino do LED como saída
}

 ```

#### Configurando um pino como entrada com pull-up:

 ```ruby  
#define BUTTON_PIN 0  // Define o número do pino para um botão

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Configura o pino do botão como entrada com pull-up
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);  // Lê o estado do botão
  if (buttonState == LOW) {  // Verifica se o botão está sendo pressionado
    // Ação a ser realizada quando o botão está pressionado
  }
}

 ```


<BR>GPIOs, leitura e escrita em pinos digitais. Simulação: <a href=https://wokwi.com/projects/339670467067511378>digitalRead() e digitalWrite()</a>




- [Apostila ESP32](#Apostila-ESP32)
- [Arduino Referências](#Referências-Arduino)
- [Pinout Esp32](#pinout-esp32)
- [Arquitetura Esp32](#arquitetura-esp32)
- [Simulador Online](#simulador-wokwi)
- [Funções principais](#Funçoes-principais)
- [Variáveis e Operadores](#variaveis-operadores)
- [GPIOs, leitura e escrita em pinos digitais](#gpio-digital)
- [Tabelas e vetores](#tabelas-vetores)
- [PWM](#pwm)
- [Comunicação Serial](#Comunicação-serial)
- [Display](#Display)
	- [LCD 16x2](#lcd-16x2)
	- [Oled](#display-oled)
- [Interrupções e Funções de tempo](#tempo)
	- [millis()](#função-millis)
	- [Interrupção Externa](#Interrupção-externa)
- [ESP32 IOT](#ESP32-IOT)
- [Exemplos de projetos](#Exemplos-de-projetos)
- [Livros](#Livros-e-referencias)



## Apostila ESP32
<BR> <a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/ESP32.docx>Apostila</a> em desenvolvimento

<BR> <a href=https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf>Datasheet ESP32</a>


## Arquitetura

<img src=https://raw.githubusercontent.com/mchavesferreira/mcr/refs/heads/main/esp32/imagens/arquitetura_esp32.png>

https://docs.espressif.com/projects/esp-hardware-design-guidelines/en/latest/esp32/schematic-checklist.html#flash-and-psram

https://docs.espressif.com/projects/esp-hardware-design-guidelines/en/latest/esp32/_images/esp32-sche-core.png

## ID do chip

No ESP32, o "ID do chip" (Chip ID) refere-se a um identificador único atribuído ao chip. Esse ID pode ser usado para várias finalidades, incluindo a diferenciação entre múltiplos dispositivos na mesma rede ou para fins de segurança e autenticação.

O ID do chip no ESP32 é tipicamente derivado do endereço MAC do dispositivo, que é único para cada chip. Isso significa que cada ESP32 tem um ID do chip que pode ser considerado único, ajudando a evitar colisões e conflitos em sistemas onde múltiplos dispositivos precisam ser identificados de forma inequívoca.

Para obter o ID do chip em um programa, os desenvolvedores geralmente usam funções específicas da API do ESP-IDF ou do ambiente de desenvolvimento que estão utilizando, como o Arduino. Por exemplo, no ambiente Arduino, você pode usar a função ESP.getEfuseMac() para obter o ID do chip, que retorna o endereço MAC do dispositivo, e então processá-lo conforme necessário para seu uso específico.

Esse ID é especialmente útil em aplicações de Internet das Coisas (IoT), onde a identificação única de cada dispositivo é crucial para a comunicação e controle de rede.

<BR>Como verificar o ID do chip<a href=https://wokwi.com/projects/340959007153848914> Chip ID</a><BR>  


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
	
## Exemplos práticos


Pisca Led

https://wokwi.com/projects/339670467067511378

![esp32-led-wiring-diagram](https://github.com/mchavesferreira/mcr/assets/63993080/e9eb1095-144c-46ec-96a2-2628b59b60e2)


	
## variaveis operadores

Uso de Variáveis, #define e funções próprias para I/0 Arduino

<BR>Variáveis e Operadores</b><BR>  

<BR>- Uso de HEX, DEC, BIN e OCT  <a href=https://wokwi.com/projects/340328764284076626>print()  </a>



## Tabelas Vetores
<P>Uso de <B>Vetores</B> ou tabelas para organização de variáveis
<BR>01: <a href=https://wokwi.com/projects/341561728616628819> Mapeamento de pinos ESP32</a>


	
## Leitura analógica
<bR>02: ADC - Leitura analógica, conversão de valores com funções e a função mapeamento. Simulação: <a href=https://wokwi.com/projects/340963795998343762> analogRead()</a>

## Função millis()

A função `millis()` no Arduino é uma ferramenta poderosa para realizar temporizações sem bloquear a execução do programa. Diferente da função `delay()`, que pausa a execução de todo o código por um período especificado, `millis()` permite que o Arduino continue processando outras tarefas enquanto monitora o tempo.

### Como Funciona

A função `millis()` retorna o número de milissegundos que se passaram desde que o Arduino foi ligado ou reiniciado. Utilizando essa função, é possível implementar temporizações em seu código sem impedir o funcionamento de outras partes do programa.

### Exemplo Prático

Imagine que você quer fazer um LED piscar a cada segundo sem interromper a execução de outras funcionalidades. Isso pode ser feito com `millis()` da seguinte forma:

```ruby
const int pinoLed = 13; // Pino onde o LED está conectado
unsigned long tempoAnterior = 0; // Armazena o último momento em que o LED foi alterado
const long intervalo = 1000; // Intervalo desejado de 1 segundo (1000 milissegundos)

void setup() {
  pinMode(pinoLed, OUTPUT); // Define o pino do LED como saída
}

void loop() {
  unsigned long tempoAtual = millis(); // Captura o tempo atual

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual; // Atualiza o tempo anterior

    // Altera o estado do LED
    int estadoLed = digitalRead(pinoLed);
    digitalWrite(pinoLed, !estadoLed); // Inverte o estado do LED
  }
}

```

Uso de 3 led:

https://wokwi.com/projects/411388408286145537

## Comunicação Serial

https://wokwi.com/projects/401871586327571457

Imprimindo e lendo na porta serial (UART)<BR>
  
<details><summary>Codigo Serial</summary>
<p>

```ruby
   Serial.begin(115200);
   Serial.println("Please enter your name:");
   while (!Serial.available()); // Wait for input
   String name = Serial.readStringUntil('\n');
   Serial.print("Hello, ");
   Serial.print(name);
```

</p>
</details>

  
<BR>Simulação: <a href=https://wokwi.com/projects/341561853822894674>Comunicando através da entrada serial</a>
<P>Exemplos aplicando porta serial e PWM
<BR>05: <a href=https://wokwi.com/projects/341698810319209042>Leitura de cores utilizando serial</a>.<span size=-2> Autores: Vinicius Viana e  Luis H. Estareli</span>.

## Display
 
<BR>Displays LCD, Oled, comunicação I2C
### LCD 16x2
  <BR>01 -<a href=https://wokwi.com/projects/342202939017790036> Exemplo LCD 16x2 paralelo</a>
  <BR>02 -<a href=https://wokwi.com/projects/342199886273315410> Exemplo LCD 16x2 I2C</a>

### Oled
 
-<a href=https://github.com/mchavesferreira/mcr/blob/main/esp32/displayoled.md> Display Oled</a>

	  
## Interrupção externa

  <br>06 -<a href=https://wokwi.com/projects/342203713958445651> Exemplo função Interrupção()</a>
<BR>  
 <br><a href=https://wokwi.com/projects/342234932555285074>Uso de interrupção</a>
  

# Construindo uma maquina (projeto 3° Bimestre)

<BR><BR>Exemplos de projetos de máquinas (estados). Vamos modificar estes projetos exemplos sem uso de delay().  



## Exemplos de anos anteriores

<BR><BR>Máquina de macarrão:
<BR><BR>https://wokwi.com/projects/343824918481207891

<BR><BR>Maquina de bolos:
<BR><BR>https://wokwi.com/projects/343896310503440979


<BR><BR>Máquina de sorvete 1
<BR><BR>https://wokwi.com/projects/343353681787224660 


<BR><BR>Máquina de sorvete 2

<BR><BR> https://wokwi.com/projects/343718518644015698
<BR><BR>




## ESP32 IOT

<a href=https://github.com/mchavesferreira/mcr/tree/main/esp32_iot><img src=https://raw.githubusercontent.com/mchavesferreira/mcr/main/esp32_iot/imagens/webserver.png width=50% border=0><BR>Saiba mais...</a><BR>

<B> Introdução a internet das coisas </b>: Esp32 como servidor de pagina, protocolo mqtt, uso de frameworks, cloud e outros recursos para aplicações com Internet das Coisas (IOT) através do ESP32.


## Exemplos de projetos 
	
Busque na Internet exemplos para aplicar os conhecimentos sobre a programação com microcontroladores.
	
Se o projeto for bem documentado, é possível inscrevê-lo em feira de ciências, realizá-lo como trabalho de conclusão de curso (TCC), apresentá-lo em congressos, revistas e eventos ciêntíficos, ou até criar um produto e registá-lo como uma patente.
A seguir apresentamos links de eventos e revistas ciêntíficas para colaborar com sua idéia.
- CONICT  
	
    -- Trabalhos apresentados em formato online (<a href=https://www.youtube.com/channel/UC4hDqSkORN1rHfyrIIMu9SA/videos>canal youtube</a>)
	
    -- Artigos Conict (<a href=http://ocs.ifsp.edu.br/index.php/conict> Anais </a>)
 
- FECCIF- Feira Estadual de Ciência e Cultura do IFSP (http://feccip.com.br> Pagina</a>)

Outros:
- Seleção de projetos <a href=https://github.com/mchavesferreira/mcr/blob/81e149b137445a6df07bdaa17b2f0c46f31eff36/dicas%20de%20projetos/Dicas%20para%20projetos.pdf> Dicas de projetos.pdf</a>

	- <a href=https://embarcados.com.br> Embarcados </a> Site de uma comunidade sobre sistemas embarcados
	

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
	
	
	
	
