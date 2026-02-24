
## Mapeamento-de-memória
 
Instruções principais para a movimentação de bytes na memória do Atmega328
<center><img src=imagens/movimentacao_bits_bytes.png></center>


# Programas em ASSEMBLY

## Programa Pisca Led

Aula 10/04/2025


 ```ruby  
//--------------------------------------------------------------------------- //
//		AVR e Arduino: T�cnicas de Projeto, 2a ed. - 2012.					  //	
//--------------------------------------------------------------------------- //

.equ LED   = PB5  		//LED � o substituto de PB5 na programa��o 

.ORG 0x000				//endere�o de in�cio de escrita do c�digo 

INICIO:
	LDI R16,0xFF		//carrega R16 com o valor 0xFF
	OUT DDRB,R16		//configura todos os pinos do PORTB como sa�da

PRINCIPAL:
     SBI PORTB, LED		//coloca o pino PB5 em 5V
	 RCALL ATRASO		//chama a sub-rotina de atraso
	 CBI PORTB, LED 	//coloca o pino PB5 em 0V
	 RCALL ATRASO		//chama a sub-rotina de atraso
	 RJMP PRINCIPAL 	//volta para PRINCIPAL


ATRASO:					//atraso de aprox. 200ms
	LDI R19,16	
 volta:		
	DEC  R17			//decrementa R17, come�a com 0x00
	BRNE volta 			//enquanto R17 > 0 fica decrementando R17
	DEC  R18			//decrementa R18, come�a com 0x00
	BRNE volta			//enquanto R18 > 0 volta decrementar R18
	DEC  R19			//decrementa R19
	BRNE volta			//enquanto R19 > 0 vai para volta
	RET	
//---------------------------------------------------------------------------
 ```

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


## Simulador Wokwi e Atmel Studio

Atmel Studio:<a href=http://studio.download.atmel.com/7.0.2389/as-installer-7.0.2389-full.exe>Atmel Studio 7.0</a><BR>
  
Gravador para firmware .hex utilizando bootloader Arduino: <a href=https://github.com/mchavesferreira/smie/blob/main/hexloader.zip>Hexloader</a>


