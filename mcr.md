
# Microcontroladores


# Atmega328P 

## Utilizando Atmega328P para a compreensão e funcionamento de microprocessadores e microcontroladores em geral

## Aulas Turma 2026

## 1° Bimestre
- 10/02  - Apresentação da disciplina, forma de avaliação, datas das avaliações. Aula expositiva sobre Histórico dos microprocessadores e microcontroladores.
- 24/02 - Conceitos de microcontroladores, diferenças entre microcontrolador e microprocessador, arquiteturas Havard e Von Neumman
- 03/03 - Modelo básico de um programa em C, diretivas, macros e definições, como utilizar o ambiente de desenvolvimento.
- 10/03 - Programação em alto nível utilizando C para AVR, estrutura básica de programa. Estruturas de Condicionais e repetição. Blocos de declarações (If, for, while, switch).
- 17/03 - Registradores do ATmega328P, portas digitais, DDRx, PORTx e PINx. Manipulação de bits e controle de GPIO.
- 24/03 - Código BCD. Utilizando display de 7 segmentos em linguagem C com AVR LibC para o microcontrolador Atmega328P.
- 31/03 - Avaliação 1. Conteúdos anteriores: Arquitetura, memória, registradores, programação C para AVR Atmega 328P, registradores de I/O. Display de segmentos.
- 07/04 - Apresentação de Trabalho T1 - Relatório e Projeto microcontrolado 

#  Arquitetura de funcionamento de um microprocessador genérico

![processador](https://github.com/user-attachments/assets/cd0111e0-3362-433f-9e02-2d62215ecf9f)


Exemplos de circuitos básicos em um microprocessador:

https://circuitverse.org/simulator/51702

https://github.com/viniciusNoleto/Electronic_Components_Example-LOGISIM-CIRC/tree/main



Slide: https://github.com/mchavesferreira/mcr/blob/main/arquitetura.pdf









        ORG 0H        ; Início do programa na memória (Endereço 256)
        LDA #17         ; Carrega o valor 17 no registrador A
        LDB #9          ; Carrega o valor 9 no registrador B
        ADD A, B        ; Soma A + B e armazena em A
        STA 300H        ; Armazena o conteúdo de A na memória 300H
        HLT             ; Finaliza o programa

; Definição de memória e registradores:
- LDA #XX   -> Carrega o valor imediato XX no registrador A
- LDB #XX   -> Carrega o valor imediato XX no registrador B
- ADD A, B  -> Soma os valores dos registradores A e B e armazena em A
- STA XXXH  -> Armazena o conteúdo de A no endereço de memória XXXH
- HLT       -> Finaliza a execução do programa

O programa na memória flash seria equivalente a seguinte tabela de exportação do código Assembly convertido para hexadecimal e binário, considerando que cada instrução ocupará 16 bits (2 bytes). São estes os valores armazenados na memória de programa ROM(ou Flash em versões recentes):

### Tabela de Exportação do Código Assembly

| Endereço | Instrução  | Hexadecimal  | Binário                |
|----------|-----------|--------------|------------------------|
| 0x0000   | ORG 0H    | 0000         | 00000000 00000000      |
| 0x0002   | LDA 17    | 3A11         | 00111010 00010001      |
| 0x0004   | LDB 9     | 0609         | 00000110 00001001      |
| 0x0006   | ADD A, B  | 8000         | 10000000 00000000      |
| 0x0008   | STA 300H  | 3203         | 00110010 00000011      |
| 0x000A   | HL        | 7600         | 01110110 00000000      |



### Arquitetura de von Neumann:

- A memória armazena tanto as instruções quanto os dados.
- O microprocessador executa as instruções sequencialmente.
- As operações são realizadas na ULA usando os registradores internos.

### Arquitetura Havard:



 

 
## Configuração de pinos

<center><img src=imagens/pinout_atmega328P.png></center>

## Atmega 328p

https://youtu.be/q9hdLVaBdvM?si=qtBKph2J_WjbxWr6&t=30  Video Laser fibra

## Pinos Arduino UNO
![tabela_arduino](https://github.com/mchavesferreira/mcr/assets/63993080/315726ac-c35e-4365-84e5-910684880c2a)

| Nome do Pino (Porta) | Descrição no Arduino | Funções Principais          |
|----------------------|----------------------|-----------------------------|
| PC0                  | A0                   | ADC0, PCINT8                |
| PC1                  | A1                   | ADC1, PCINT9                |
| PC2                  | A2                   | ADC2, PCINT10               |
| PC3                  | A3                   | ADC3, PCINT11               |
| PC4                  | A4 (SDA)             | ADC4, PCINT12, SDA (TWI)    |
| PC5                  | A5 (SCL)             | ADC5, PCINT13, SCL (TWI)    |
| PD0                  | 0 (RX)               | RXD, PCINT16                |
| PD1                  | 1 (TX)               | TXD, PCINT17                |
| PD2                  | 2                    | INT0, PCINT18               |
| PD3                  | 3 (PWM)              | OC2B, INT1, PCINT19         |
| PD4                  | 4                    | XCK, T0, PCINT20            |
| PD5                  | 5 (PWM)              | OC0B, T1, PCINT21           |
| PD6                  | 6 (PWM)              | AIN0, OC0A, PCINT22         |
| PD7                  | 7                    | AIN1, PCINT23               |
| PB0                  | 8                    | ICP1, CLKO, PCINT0          |
| PB1                  | 9 (PWM)              | OC1A, PCINT1                |
| PB2                  | 10 (PWM, SS)         | OC1B, SS, PCINT2            |
| PB3                  | 11 (PWM, MOSI)       | MOSI, OC2A, PCINT3          |
| PB4                  | 12 (MISO)            | MISO, PCINT4                |
| PB5                  | 13 (SCK, LED)        | SCK, PCINT5                 |



## Diagrama de blocos
O Atmel® ATmega328P é um microcontrolador CMOS de 8 bits de baixa potência baseado na arquitetura RISC aprimorada AVR®. Ao executar instruções poderosas em um único ciclo de clock, o ATmega328P atinge taxas de transferência de aproximadamente 1MIPS por MHz, permitindo otimizar consumo de energia versus a velocidade de processamento.[1]
<center><img src=imagens/diagrama_blocos.png></center

O núcleo AVR® combina um rico conjunto de instruções com 32 registradores de trabalho de uso geral(GPR). Todos os 32 registradores são conectados diretamente à unidade lógica aritmética (ULA), permitindo que dois registradores independentes sejam acessados em uma única instrução executada em um ciclo de clock. A arquitetura resultante é mais eficiente em termos de código, ao mesmo tempo em que alcança rendimentos até dez vezes mais rápidos do que os microcontroladores CISC convencionais.
O Atmel® ATmega328P fornece os seguintes recursos: 32K bytes de flash programável no sistema com recursos de leitura durante a gravação, 1K bytes EEPROM, 2K bytes SRAM, 23 linhas de E/S de uso geral, 32 registradores de trabalho de uso geral, três temporizadores flexíveis /Contadores com modos de comparação, interrupções internas e externas, um USART programável serial, uma interface serial de 2 fios orientada a byte, uma porta serial SPI, um ADC de 6 canais e 10 bits (8 canais em pacotes TQFP e QFN/MLF) , um temporizador de watchdog programável com oscilador interno e cinco modos de economia de energia selecionáveis por software. O modo ocioso para a CPU enquanto permite que a SRAM, Temporizador/Contadores, USART, interface serial de 2 fios, porta SPI e sistema de interrupção continuem funcionando. O modo de desligamento salva o conteúdo do registro, mas congela o oscilador, desabilitando todas as outras funções do chip até a próxima interrupção ou reinicialização do hardware. No modo de economia de energia, o temporizador assíncrono continua a funcionar, permitindo que o usuário mantenha uma base de temporizador enquanto o restante do dispositivo está dormindo. O modo de redução de ruído ADC para a CPU e todos os módulos de E/S, exceto temporizador assíncrono e ADC, para minimizar o ruído de comutação durante as conversões ADC. No modo de espera, o oscilador de cristal/ressonador está funcionando enquanto o restante do dispositivo está dormindo. Isto permite um arranque muito rápido combinado com um baixo consumo de energia.[1]


Core CPU
A principal função do núcleo da CPU (core CPU) é garantir a execução correta do programa. A CPU deve, portanto, ser capaz de acessar memórias, realizar cálculos, controlar periféricos e lidar com interrupções.

<center><img src=imagens/core_cpu.png></center
Diagrama de Blocos da Arquitetura AVR

Para maximizar o desempenho e o paralelismo, o AVR usa uma arquitetura harvard – com memórias e barramentos separados para programa e dados. As instruções na memória do programa são executadas com um pipelining de nível único. Enquanto uma instrução está sendo executada, a próxima instrução é pré-buscada na memória do programa. Este conceito permite que as instruções sejam executadas em cada ciclo de clock. A memória do programa é uma memória flash reprogramável no sistema.[1]

## Sistemas de clock

Principais sistemas de clock do AVR® e sua distribuição. Todos os clock não precisam estar ativos em um determinado momento. Para reduzir o consumo de energia, os relógios dos módulos que não estão sendo usados podem ser interrompidos usando diferentes modos de suspensão, conforme descrito na Seção "Modes Sleep Gerenciamento de energia e modos de suspensão". 

Para maximizar o desempenho e o paralelismo, o AVR usa uma arquitetura harvard – com memórias e barramentos separados para programa e dados. As instruções na memória do programa são executadas com um pipelining de nível único. Enquanto uma instrução está sendo executada, a próxima instrução é pré-buscada na memória do programa. Este conceito permite que as instruções sejam executadas em cada ciclo de clock. A memória do programa é uma memória flash reprogramável no sistema.[1]

## Sistema de Reset

<center><img src=https:imagens/sistema_reset.png>Lógica Reset</center>

Durante o reset, todos os registradores de E/S são ajustados para seus valores iniciais, e o programa inicia a execução a partir do vetor de reset. Para o Atmel® ATmega328P, a instrução colocada no vetor de reset deve ser uma instrução RJMP – salto relativo – para a rotina de manipulação de reset. Se o programa nunca habilita uma fonte de interrupção, os vetores de interrupção não são usados e o código de programa regular pode ocupar nesses locais. Este também é o caso se o vetor de reset estiver na seção de aplicação enquanto os vetores de interrupção estiverem na seção de inicialização. As portas de E/S do AVR® são imediatamente redefinidas para seu estado inicial quando uma fonte de redefinição fica ativa. Isso não requer que nenhuma fonte de relógio esteja em execução. Após todas as fontes de reset ficarem inativas, um contador de atraso é invocado, estendendo o reset interno. Isso permite que a potência atinja um nível estável antes do início da operação normal. O tempo limite do contador de atraso é definido pelo usuário através dos fusíveis SUT e CKSEL. 


# Programação em Alto Nível, C

Este primeiro exemplo de programa com um pisca Led

Código para o primeiro programa
```java

#define F_CPU 16000000UL // Clock frequency, needed to delay functions
#include <avr/io.h> // Register definitions
#include <util/delay.h> // Delay functions

int main(){
  DDRB |= (1<<PB5); // Define PORTB5 as an output
  while(1){ // Infinite loop
  PORTB |= (1<<PB5); // Turn led on
  _delay_ms(1000); // Wait 1 second
   PORTB &= ~(1<<PB5); // Turn led off
  _delay_ms(1000); // Wait another second
  }
return 0;
}
```
<br><a href=https://wokwi.com/projects/363128065545249793>Pisca Led em C</a>

## Pisca LED  Utilizando Macros em C

Conhecendo o recurso de Macros do compilador para simplificar o código

```java
#define F_CPU 16000000UL	//define a frequencia do microcontrolador 16MHz (necessario para usar as rotinas de atraso)
#include <avr/io.h> 	    //definiçoeses do componente especificado
#include <util/delay.h>		//biblioteca para o uso das rotinas de _delay_ms() e _delay_us()

//Definicoeses de macros - empregadas para o trabalho com os bits de uma variavel ou registrador

#define	set_bit(Y,bit_x) (Y|=(1<<bit_x))	//ativa o bit x da variavel Y (coloca em 1)
#define	clr_bit(Y,bit_x) (Y&=~(1<<bit_x))	//limpa o bit x da variavel Y (coloca em 0) 
#define tst_bit(Y,bit_x) (Y&(1<<bit_x))  	//testa o bit x da variavel Y (retorna 0 ou 1)
#define cpl_bit(Y,bit_x) (Y^=(1<<bit_x))	//troca o estado do bit x da variavel Y (complementa)

#define LED PB5				//LED � o substituto de PB5 na programacao     	

//--------------------------------------------------------------------------------------
int main( )
{
    DDRB = 0xFF;			//configura todos os pinos do PORTB como saidas
	
	while(1)				//laco infinito
    {
        set_bit(PORTB,LED);	//liga LED
		_delay_ms(200);		//atraso de 200 ms
		clr_bit(PORTB,LED);	//desliga LED
		_delay_ms(200);		//atraso de 200 ms
    }
}

```


## Lendo Botão com macros

```java

//=====================================================================================	//
//    LIGANDO E DESLIGANDO UM LED QUANDO UM BOTaO e PRESSIONADO							//
//===================================================================================== //
#define F_CPU 16000000UL	/*define a frequ�ncia do microcontrolador 16MHz (necess�rio
							para usar as rotinas de atraso)*/
#include <avr/io.h> 	    //definicoes do componente especificado
#include <util/delay.h>		//biblioteca para as rotinas de _delay_ms() e delay_us()

//Definicoes de macros - para o trabalho com os bits de uma variavel

#define set_bit(Y,bit_x)(Y|=(1<<bit_x))		//ativa o bit x da variavel Y (coloca em 1)
#define clr_bit(Y,bit_x)(Y&=~(1<<bit_x))	//limpa o bit x da variavel Y (coloca em 0) 
#define cpl_bit(Y,bit_x)(Y^=(1<<bit_x))		//troca o estado do bit x da variavel Y 
#define tst_bit(Y,bit_x)(Y&(1<<bit_x))  	//testa o bit x da variavel Y (retorna 0 ou 1)

#define LED   PD2   //LED e o substituto de PD2 na programacao 
#define BOTAO PD7   //BOTAO e o substituto de PD7 na programacao     	
//-------------------------------------------------------------------------------------
int main()
{
	DDRD = 0b00000100;	//configura o PORTD, PD2 saida, os demais pinos entradas
	PORTD= 0b11111111;	/*habilita o pull-up para o botao e apaga o LED (todas as 
						entradas com pull-ups habilitados)*/
	
	while(1)								//laco infinito
	{
		if(!tst_bit(PIND,BOTAO))			//se o botao for pressionado executa o if
		{					
			while(!tst_bit(PIND,BOTAO));	//fica preso ate soltar o botao

			_delay_ms(10);					//atraso de 10 ms para eliminar o ruido do botao

			if(tst_bit(PORTD,LED))			//se o LED estiver apagado, liga o LED
				clr_bit(PORTD,LED);			
			else							//se nao apaga o LED
				set_bit(PORTD,LED);	

			//o comando cpl_bit(PORTD,LED) pode substituir este laco if-else
		
		}//if do botao pressionado
	
	}//laco infinito
}
```

# Programação com IDE Arduino

## Referências
<BR>  <a href=https://www.arduino.cc/reference/pt/>Arduino Referência de Linguagem Wiring</a> <BR>
<BR>

## Referências Arduino

<center>  <a href=https://www.arduino.cc/reference/pt/ target=_blank>Arduino Referência de Linguagem C</a> </center><BR>

## Funçoes principais

<details><summary>Conheça as principais funções em wiring disponíveis na IDE Arduino (clique)</summary>
	
<BR><B>Funções</b>
<bR>Para controlar a placa Arduino e realizar computações.
<BR><b>Entradas e Saídas Digitais</b>
<BR>digitalRead()
<BR>digitalWrite()
<BR>pinMode() 
<BR>
  <BR><B>Entradas e Saídas Analógicas</b>
<BR>analogRead()
<BR>analogReference()
<BR>analogWrite() 
<BR>
<BR><B>Funções Temporizadoras</b>
<BR>delay()
<BR>delayMicroseconds()
<BR>micros()
<BR>millis()
<BR>
  
<BR><B>Comunicação</b>
<BR>Serial
<BR>Stream 
<BR>
<BR><B>Variáveis</b>
<BR>
<BR>Tipos de dados e constantes da linguagem Arduino.
<BR><B>Constantes</b>
<BR>HIGH | LOW
<BR>INPUT | OUTPUT | INPUT_PULLUP
<BR>LED_BUILTIN
<BR>true | false
<BR>Constantes de Ponto Flutuante
<BR>Constantes Inteiras
 <BR> 
<BR><B>Tipos de Dados</b>
<BR>bool
<BR>boolean
<BR>byte
<BR>char
<BR>double
<BR>float
<BR>int
<BR>long
<BR>short
<BR>size_t
<BR>string
<BR>String()
<BR>unsigned char
<BR>unsigned int
<BR>unsigned long
<BR>vetor
<BR>void
<BR>word 
<BR><BR> 

</details>

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


### Pisca Led Arduino


```java
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}


```
Clique para abrir o exemplo de pisca led em Arduino no simulador wokwi


<BR><a href=https://wokwi.com/projects/344891652101374548>Pisca led em Arduino</a>	

<BR><BR>	

#### 22/05 TAREFA: 
Crie uma conta no Wokwi e altere este exemplo para um semaforo. Salve o exemplo para a próxima aula.

# Aula 29/05

#### Configurando um pino como entrada com pull-up:

Utilizando a função digitalRead();

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


<BR><B>Atividade 1</b>: Monte o circuito "Pisca Led", agora acrescentando ao circuito um botão "push button" entre o pino 7 e GND<BR>
<BR>Copie o código a seguir, modificando-o para este exemplo.
	
```java
#define LED 13
#define botao 7

int tempo=100;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(botao, INPUT_PULLUP); // definir botao de entrada
}

void loop() {
  // altera o valor da variavel se pressionado
  if(digitalRead(botao)) {tempo=500;} else  {tempo=100; } 
  
  digitalWrite(LED, HIGH);
  delay(tempo);
  digitalWrite(LED, LOW);
  delay(tempo);
}

```
#### Circuito de simulação para o pisca led Botão https://wokwi.com/projects/432285716099971073

<BR><b> Atividade 2:</b> Acrescente mais dois leds. Modifique o programa anterior, 
	para que estes dois leds permaneçam desligados quando o botão não está pressionado, 
	e alternem entre si, quando o botão está pressionado.<BR>
<BR>

### Programa para debounce de botão

```java
int main()
{

						entradas com pull-ups habilitados)*/
	while(1)								//laco infinito
	{
                //////// pisca led
                contador++;
                _delay_ms(1);		
                if(contador>500) {  contador=0; cpl_bit(PORTD,LEDPISCA);   }
                //////// pisca led

		if(!tst_bit(PIND,BOTAO))			//se o botao for pressionado executa o if
		{					
			while(!tst_bit(PIND,BOTAO));	//fica preso ate soltar o botao
			_delay_ms(10);					//atraso de 10 ms para eliminar o ruido do botao
			if(tst_bit(PORTD,LED))			//se o LED estiver apagado, liga o LED
				clr_bit(PORTD,LED);			
			else							//se nao apaga o LED
				set_bit(PORTD,LED);	
			//o comando cpl_bit(PORTD,LED) pode substituir este laco if-else	
		}//if do botao pressionado
	}//laco infinito
}
```





## Maquina de estados


### Maquina de estados 

![image](https://github.com/mchavesferreira/smc/assets/63993080/3765f170-1abe-4377-89a2-41d980c8b771)

### Switch-case

A estrutura switch-case é uma técnica eficaz para implementar máquinas de estados em programação de microcontroladores, facilitando o controle de fluxo do programa com base nos valores de uma variável. Aqui está um exemplo simplificado utilizando em uma função:
```java
// Exemplo de máquina de estados usando switch-case
void stateMachineExample(int state) {
    switch(state) {
        case 1:
            // Ação para o estado 1
            break;
        case 2:
            // Ação para o estado 2
            break;
        // Adicione mais estados conforme necessário
        default:
            // Ação padrão se nenhum estado anterior corresponder
            break;
    }
}
```
Este exemplo demonstra a base de uma máquina de estados, onde state determina o fluxo de execução. Cada case representa um estado único, permitindo ações específicas para cada um, e o default oferece uma ação padrão para estados não especificados. Esta abordagem organiza logicamente o código, tornando-o mais legível e fácil de manter.

Compreendendo a mudança de fluxo por meio da chamada de switch-case em um programa principal:

https://wokwi.com/projects/358828863218714625


### Código completo para maquina de estados

```java

//=====================================================================================	//
//		Marquina de estados  e controle de fluxos   							//

//=====================================================================================	//

#define F_CPU 16000000UL	//define a frequencia do microcontrolador - 16MHz

#include <avr/io.h> 	    //defini��es do componente especificado
#include <util/delay.h>		//biblioteca para o uso das rotinas de _delay_ms e _delay_us()
#include <avr/pgmspace.h>   //para o uso do PROGMEM, grava��o de dados na mem�ria flash

//Definicoeses de macros para o trabalho com bits

#define	set_bit(y,bit)	(y|=(1<<bit))	//coloca em 1 o bit x da vari�vel Y
#define	clr_bit(y,bit)	(y&=~(1<<bit))	//coloca em 0 o bit x da vari�vel Y
#define cpl_bit(y,bit) 	(y^=(1<<bit))	//troca o estado l�gico do bit x da vari�vel Y
#define tst_bit(y,bit) 	(y&(1<<bit))	//retorna 0 ou 1 conforme leitura do bit


// variaveis
unsigned int tempo=0;
unsigned char  estado=0;	//declara variavel global

///  funcoes da maquina de lavar

//descricao dos pinos I/O
// ENTRADAS
#define botao1 PC0 // botao mais
#define botao2 PC1 // botao menos
#define botao3 PC2 // botao ENTER / STOP processo


//SAIDAS
#define LED1 PB4 // motor agitacao
#define LED2 PB3 // valvula de entrada agua
#define LED3 PB2 // bomba saida tanque




void etapa0(){
	       set_bit(PORTB,2);
	     	if(!tst_bit(PINC,0)) {  clr_bit(PORTB,2);  estado=1; tempo=2000; } //if botao+
		 	 
}


void etapa1(){
	      set_bit(PORTB,3);

		 	  if(!tempo) { clr_bit(PORTB,3);   estado=2; tempo=2000; }   //muda de estado 
			 _delay_ms(1);  // atraso
			 tempo--;    // decrementa tempo
}

void etapa2(){

        set_bit(PORTB,4);
		 	  if(!tempo) {  clr_bit(PORTB,4);   estado=0; tempo=2000; }   //muda de estado 
			  _delay_ms(1);  // atraso
			   tempo--;    // decrementa tempo
}

//--------------------------------------------------------------------------------------
int main()
{	
 	//declaracao da vari�vel para armazenagem dos digitos

	DDRB = 0b00111111;			//PORT B saida
	PORTB= 0;		        	//inicia desligado
	DDRC = 0b00000000;			//PORT C entrada
  PORTC= 0b11111111;          //PULL UP portC
	DDRD = 0xFF;				//PORTD como sa�da (display)
	PORTD= 0xFF;				//desliga o display
	UCSR0B = 0x00;				//PD0 e PD1 como I/O gen�rico, para uso no Arduino


	
	tempo=1000;   // varial de contagem de tempo
	while(1) 					//laco infinito
	{
		
		switch(estado)
		{  //estado inicial
		    case 0:  etapa0();        break; 
				case 1:  etapa1();        break; 
				case 2:  etapa2();        break; 

		}

		
	}// fim do while
	
} // fim do main
//======================================================================================

```
# Aula 12/06

# Semaforo com ESP32

![semaforo_esp32](https://github.com/user-attachments/assets/36976ead-06ea-4dfa-a741-c1806ce6f3d1)

Acesse este exemplo agora implementado com ESP32 https://wokwi.com/projects/401870196210377729

<BR>

## Maquina de estados com ESP32

https://wokwi.com/projects/433518731827009537

<details><summary>Código máquina de estados com ESP32</summary>
	
```java	
#define LED1 2
#define LED2 4
#define LED3 5
#define botao 14

int tempo=1000;
int estado=0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(botao, INPUT_PULLUP); // definir botao de entrada
  Serial.begin(115200);
  Serial.println("Bem Vindo Jhon");
    delay(3000);
}
/*
// utilizando funcoes para os cases
void etapa0(){
	       digitalWrite(LED1, HIGH);
	     	if(!digitalRead(botao)) 
           {  digitalWrite(LED1, LOW); 
               estado=1; 
               tempo=2000; } //if botao+		 	 
}

void etapa1(){
	     digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(1);  // atraso
			 tempo--;    // decrementa tempo
       if(!tempo) {   tempo=2000;
                      estado=2;  }
}
*/

void loop() {

switch (estado) {
  case 0:
      Serial.println("Estado=0");
      digitalWrite(LED1, HIGH);
      if(!digitalRead(botao)) {   // verifica se botao pressionado
           tempo=2000;  // carrega variavel tempo
           estado=1; }   // muda de estado
    break;
  case 1:    
     digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(1);  // atraso
			 tempo--;    // decrementa variavel tempo
       if(!tempo) {  // compara se tempo=0 
                      tempo=2000; // carrega variavel tempo
                      estado=2;  }  // muda de estado
    break;
  case 2:
    Serial.println("Estado=2");
     digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(1);  // atraso
			 tempo--;    // decrementa tempo
       if(!tempo) {   tempo=2000;
                      estado=3;  }
    break;  
  case 3:
    Serial.println("Estado=3");
     digitalWrite(LED3, LOW);
      delay(1);  // atraso
			 tempo--;    // decrementa tempo
       if(!tempo) {   tempo=2000;
                      estado=0;  }
    break;  
 
}  // fim do switch

 //
     
}
```
</details>

### Atividade

#### Exemplo de um programa para controle de reservatório com ESP32

Defina pinos de entrada e saída. As entradas com push button aterradas e pull up ativos. O Programa aguarda “Start” ser pressionado, que liga a Valvula 1 até que sensor cheio seja acionado. O misturador é acionado por2 segundos. Esvazia-se o tanque até o sensor vazio ser acionado, retornando ao estado inicial.. 

![image](https://github.com/mchavesferreira/mcr/assets/63993080/fee83e1b-24d9-4df6-bfa0-f8256ef35413)

# Trabalho 2
## Monte o projeto de reservatório com ESP32 utilizando maquina de estados para o mesmo projeto aplicado na prova do bimestre anterior

<a href=provacodigoparte2.pdf>Avaliação P1</a>


# Avaliação P1

Utilize o código exemplo para realizar o projeto 2 utilizando a programação em máquina de estados em um Esp32  e Arduino IDE.

## Configuração Inicial

* Inicie definindo as entradas com **pull-up interno ativado**.
* Configure os pinos correspondentes às **saídas**.
* Utilize os GPIO do ESP32  para especificar todos os pinos de **entrada e saída (I/O)**, conforme a tabela apresentada a seguir:

|     |      ||| |     |    |    |
| ------ | ---------- | --- | --- | --- | -------- | ------- | ----- |
| Vsaida | Misturador | V3  | V2  | V1  | S. Vazio | S. Max. | START |

## Descrição da Sequência de Operação

* Ao pressionar o botão **START**, a seguinte sequência ocorrerá:

1. A **válvula de saída** será acionada para manter o recipiente fechado, enquanto a **válvula V1** (saída) será aberta por **5 segundos**. *
2. Em seguida, a **válvula V2** será ligada por **3 segundos**.
3. Logo após, o **misturador** será ativado por **2 segundos**, com o objetivo de **homogeneizar a mistura**. 
4. Após esse período, a **válvula V3** será aberta e permanecerá acionada até que o **sensor de nível máximo** detecte a presença de líquido.
5. Quando o nível máximo for atingido, o **misturador** será novamente ativado por **2 segundos**. 
6. Por fim, a **válvula de saída** será desligada.
7. O sistema continuará monitorando até que o **sensor de nível mínimo (vazio)** seja acionado, retornando então ao estado inicial. 

**OBS:** Válvulas V1, V2 e V3 são NF(normalmente fechadas); Válvula de saída NA(normalmente aberta);

<img src=imagens/bimestre2projeto2.png><BR><BR>





## Videos tutoriais

Playlist:  https://www.youtube.com/watch?v=uMod3r2ZOJU&list=PLO-6CbqPG8oUPetj7I6bLNCjS7Rk9Supv

### Video Aula Arquitetura Von Neumman 
 
https://www.youtube.com/watch?v=uMod3r2ZOJU&list=PLO-6CbqPG8oUPetj7I6bLNCjS7Rk9Supv

### Video Aula: Arquitetura AVR

https://www.youtube.com/watch?v=KVz5ry-89n8&list=PLO-6CbqPG8oUPetj7I6bLNCjS7Rk9Supv

### Canal Professor Rodrigo Rech

Curso de AVR Básico #01 - Introdução
https://www.youtube.com/watch?v=wiM6_4IC_4o&list=PLMdNWywlSE5QPsEeT_cXisUT366NS3U8R




- 
<BR><h1>Sugestão de lista de compras para montagem de projetos com ESP32</h1>
<BR>
<BR>-Esp32  Devkit Esp32-wroom-32 - 30 Pinos - Tipo C
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




# Referências

<BR>https://www.if.ufrgs.br/public/tapf/rodrigues_v25_n4.pdf





