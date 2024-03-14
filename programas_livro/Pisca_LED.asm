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
