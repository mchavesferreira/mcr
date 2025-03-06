
# Microcontroladores 

# Atmega328P 

## Utilizando Atmega328P para a compreensão e funcionamento de microprocessadores e microcontroladores em geral utilizando a linguagem Assembly.

## Aulas Turma 2025
### 1° Bimestre
- 20/02  - Introdução a Disciplina, Histórico sobre microprocessadores
- 27/02 -  Arquitetura de funcionamento de um microprocessador genérico

Exemplos de circuitos básicos em um microprocessador:

https://circuitverse.org/simulator/51702

https://github.com/viniciusNoleto/Electronic_Components_Example-LOGISIM-CIRC/tree/main

- 06/03 -  Arquitetura AVR Atmega 328P, [Mapeamento de Memória](#Mapeamento-de-memória)

Slide: https://github.com/mchavesferreira/mcr/blob/main/arquitetura.pdf

- 13/03 -  Primeiras instruções assembly para Atmega328P. 
- 20/03 -  [Programa Pisca Led](#Programa-Pisca-Led), [Programa Reservatorio](#Programa-Reservatorio)
- 27/03 -  Simulador Wowki, Display 7 segmentos 
- 03/04 -  Projeto microcontrolado Assembly
- 10/04 -  Trabalho em Grupo
- 17/04 -  Avaliação Escrita
- 
### 2° Bimestre
- 08/05 - Introdução ao ESP32
- 15/05 - Programação Alto Nível, C
- 22/05 -

-
-   
- 



#  Arquitetura de funcionamento de um microprocessador genérico




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


![processador](https://github.com/user-attachments/assets/cd0111e0-3362-433f-9e02-2d62215ecf9f)


### Arquitetura de von Neumann:

- A memória armazena tanto as instruções quanto os dados.
- O microprocessador executa as instruções sequencialmente.
- As operações são realizadas na ULA usando os registradores internos.

### Reservas de Endereço para Vetores de Interrupção e Bootloader

Muitos microprocessadores reservam os primeiros endereços de memória (por exemplo, de 0000H a 00FFH) para vetores de interrupção, tabelas de inicialização e rotinas do sistema.

Um vetor de interrupção contém endereços de sub-rotinas que devem ser executadas quando eventos específicos ocorrem, como interrupções de hardware.

Algumas arquiteturas, especialmente as inspiradas nos primeiros microprocessadores como o Intel 8080, Zilog Z80 e 6502, seguem a convenção de reservar os primeiros endereços para registradores mapeados na memória ou para o sistema operacional.

O código do usuário é normalmente carregado a partir de 0100H para evitar sobrescrever esses dados do sistema.
 
## Mapeamento-de-memória
 
Instruções principais para a movimentação de bytes na memória do Atmega328
<center><img src=imagens/movimentacao_bits_bytes.png></center>
 
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

## Programa Pisca Led

Programa Pisca Led
<center><a href=https://wokwi.com/projects/341066839950885460><img src=https://github.com/mchavesferreira/mcr/blob/main/imagens/pisca.png  width=300 height=300 border=0></a></center>

 ```ruby  
; Pisca LED on PB5(Arduino Uno pin 13)
#define __SFR_OFFSET 0

#include "avr/io.h"  

.global main   ; obrigatorio simulador

.ORG 0x000
main:
  LDI R16,0b11111111		//carrega R16 com o valor 0xFF
	OUT DDRB,R16

principal:
  sbi   PORTB, 5 ; Seta o pino da porta   
  call  ATRASO
  cbi   PORTB, 5   ; Clear(0) o pino da porta   
  call  ATRASO
  rjmp principal

ATRASO:
	LDI R19,80	
volta:		
	DEC  R17			//decrementa R17, comeÁa com 0x00
	BRNE volta 			//enquanto R17 > 0 fica decrementando R17
	DEC  R18			//decrementa R18, comeÁa com 0x00
	BRNE volta			//enquanto R18 > 0 volta decrementar R18
	DEC  R19			//decrementa R19
	BRNE volta
  ret
; Exemplo Pisca Led Avr Projetos

```


### Pisca Led com biblioteca

<details><summary>Código Exemplo Pisca Led com utilização de biblioteca para delay</summary>
<p>

```ruby  
*/
//--------------------------------------------------------------------------- //
//		Fonte: AVR e Arduino: Técnicas de Projeto, 2a ed. - 2012.					  //	
//--------------------------------------------------------------------------- //

.equ LED   = PB5  		//LED é o substituto de PB5 na programação 

.ORG 0x000				//endereço de início de escrita do código 
rjmp INICIO
.include "lib328Pv03.inc"
INICIO:
	LDI R16,0xFF		//carrega R16 com o valor 0xFF
	OUT DDRB,R16		//configura todos os pinos do PORTB como saída

PRINCIPAL:
      SBI PORTB, LED		//coloca o pino PB5 em 5V
      ldi delay_time, 2 	; Carrega delay_time com
      rcall delay_seconds	; Chama rotina de atraso
	 CBI PORTB, LED 	//coloca o pino PB5 em 0V
	 RCALL ATRASO		//chama a sub-rotina de atraso
	 RJMP PRINCIPAL 	//volta para PRINCIPAL
```
</p>
</details> 

Biblioteca: <a href=https://raw.githubusercontent.com/mchavesferreira/mcr/main/programas_livro/lib328Pv03.inc>lib328Pv03.inc</a>

### Programa-Reservatorio

Exemplo de um programa para controle de reservatório.

<BR>Defina pinos de entrada e saída. As entradas com push button aterradas e  pull up ativos. O Programa aguarda “Start” ser pressionado, que liga a  Valvula 1 até que sensor cheio seja acionado. O misturador é acionado  por2 segundos. Esvazia-se o tanque até o sensor vazio ser acionado, retornando ao estado inicial. Considere clock 16Mhz.
<br><BR>Solução:
<br>Para que servem e quais são os registradores de I/O de um AVR Atmega?  Os registradores de IO  funcionam para configurar, ler e escrever cada  pino das portas  do microcontrolador, cada bit representa um pino:  DDRx  quando em 0=entrada e 1=saída. PINx para a leitura do pino quando este é  definido com entrada; PORTx escreve na saída se o pino é definido como  saída ou ativa pull-up se o pino é definido como entrada.
	<Br>
<details><summary>Ilustração da Solução (clique)</summary>
<p>
<br><img src=imagens/oprojeto.jpg>
<br><img src=imagens/configuracaopinos.jpg>
<br><img src=imagens/inicio.jpg>
<br><img src=imagens/principal.jpg>
<br><img src=imagens/encher.jpg>
<br><img src=imagens/misturar.jpg>
<br><img src=imagens/esvaziar.jpg>
<br><img src=imagens/atraso.jpg>
</p>
</details>

<details><summary>Código Solução Controle Reservatório</summary>
<p>

```ruby 
//--------------------------------------------------------------------------- //
// EXEMPLO 					  //	
//--------------------------------------------------------------------------- //

.ORG 0x000				

INICIO:
     LDI R19, 0b00000111	//carrega R19 
     OUT DDRB,R19		//configura todos os pinos
     LDI R19, 0b00111000
     OUT PORTB, R19
; aguarda botao start
PRINCIPAL:      
     SBIC PINB,5		
     RJMP Principal
     RJMP ENCHER

; Liga válvula aguarda sensor cheio
ENCHER:
    SBI PORTB,0
    SBIC PINB,3
    RJMP ENCHER
    RJMP MISTURAR

; desliga V1, liga misturador por 2 seg. 
MISTURAR:
    CBI PORTB,0
    SBI PORTB,2
    RCALL ATRASO 
    RCALL ATRASO 
    CBI PORTB, 2
    RJMP ESVAZIAR

; Liga válvula 2 aguarda sensor vazio
ESVAZIAR:
    SBI PORTB,1
    SBIC PINB,4
    RJMP ESVAZIAR
    CBI PORTB,1
    RJMP PRINCIPAL
; .  .    .   .    .    .    .    .   .     .   
; rotina de atraso 1 segundo. 
ATRASO:	
      LDI R19,80	
volta:		
      DEC  R17	
      BRNE volta
      DEC  R18	
      BRNE volta
      DEC  R19
      BRNE volta
      RET
```
</details>

Simulação:  https://wokwi.com/projects/394247093827346433

![image](https://github.com/mchavesferreira/mcr/assets/63993080/fee83e1b-24d9-4df6-bfa0-f8256ef35413)


<h1>Trabalho em Grupo</h1>

-Modifique o projeto de simulação anterior para atender este projeto. Envie este link no SUAP Trabalho 1. Utilizando wokwi, SALVE O PROJETO COM LOCK.

-Elabore um exemplo de programação utilizando AVR Atmega 328P em assembly para automação de processos da seguinte figura: 

-Ao ligar a máquina, aguarda-se pressionar o botão1. Então a válvula V4 é fechada (High) e V1 é acionada por 4 segundos.

-A válvula V2 é acionada até que o sensor nível1 seja acionado.

-A válvula V3 é acionada por 2 segundos.

-O misturador M1 é acionado por 3 segundos.

-A válvula V4 é acionada por 2 segundo para esvaziar parcialmente o tanque.

-A válvula V2 é acionada por 5 segundos para diluir novamente a solução.

-O misturador é acionado por  4 segundos. Em seguida o tanque é esvaziado totalmente, abrindo-se a válvula V4 até o sensor nível 0 seja acionado.

-Volta-se ao estado inicial, desligando saídas.




## Programação em Alto Nível, C

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

## Utilizando Macros

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


## Lendo Botão

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

## Referências Arduino
<BR>  <a href=https://www.arduino.cc/reference/pt/>Arduino Referência de Linguagem Wiring</a> <BR>
<BR>
### Pisca Led
<BR><a href=https://wokwi.com/projects/344891652101374548>Pisca led em Arduino</a>	
<BR><BR>	
## GPIO Entradas e saídas
	
<BR>Utilizando  pinos como entrada
<BR>Atividade 1: Edite o circuito anterior "Pisca Led", acrescentando ao circuito um botão "push button" entre o pino 7 e GND<BR>
<BR>Copie o código a seguir, modificando-o para este exemplo.
	
```java
#define LED 2
#define botao 14

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
<BR> Atividade 2: Acrescente mais dois leds. Modifique o programa anterior, 
	para que estes dois leds permaneçam desligados quando o botão não está pressionado, 
	e alternem entre si, quando o botão está pressionado.<BR>
<BR>
	<BR>
Materiais:
<BR>https://edisciplinas.usp.br/pluginfile.php/3252633/mod_resource/content/1/Guia_Arduino_Iniciante_Multilogica_Shop.pdf

<BR>https://www.if.ufrgs.br/public/tapf/rodrigues_v25_n4.pdf

<BR>https://edisciplinas.usp.br/pluginfile.php/3252633/mod_resource/content/1/Guia_Arduino_Iniciante_Multilogica_Shop.pdf



## Simulador Wokwi e Atmel Studio

Atmel Studio:<a href=http://studio.download.atmel.com/7.0.2389/as-installer-7.0.2389-full.exe>Atmel Studio 7.0</a><BR>
  
Gravador para firmware .hex utilizando bootloader Arduino: <a href=https://github.com/mchavesferreira/smie/blob/main/hexloader.zip>Hexloader</a>
  
Referências:
[1] Atmega 328P 8-bit AVR Microcontroller with 32K Bytes In-System Programmable Flash - Datasheet
	
[2] <a href=https://github.com/mchavesferreira/mcr/blob/main/dicas%20de%20projetos/Dicas%20para%20projetos.pdf>Dicas de projeto</a>

