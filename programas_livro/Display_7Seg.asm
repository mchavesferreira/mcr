//------------------------------------------------------------------------------------- //
//		AVR e Arduino: T�cnicas de Projeto, 2a ed. - 2012.								//	
//------------------------------------------------------------------------------------- //
//=====================================================================================	//
//		ESCREVENDO EM UM DISPLAY DE 7 SEGMENTOS ANODO COMUM 							//           
//	Toda vez que um bot�o � pressionado o valor do Display muda(0->F)					//
//	mantendo-se o bot�o pressionado o incremento � autom�tico 							//        
//====================================================================================	//

.equ BOTAO    = PB0		//BOTAO � o substituto de PB0 na programa��o      
.equ DISPLAY  = PORTD	//PORTD � onde est� conectado o Display (seg a = LSB)
.def AUX      = R16;	//R16 tem agora o nome de AUX 

//------------------------------------------------------------------------------------
.ORG 0x000				

Inicializacoes:

	LDI  AUX,0b11111110	//carrega AUX com o valor 0xFE (1 sa�da, 0 entrada)
	OUT  DDRB,AUX    	//configura PORTB, PB0 entrada e PB1 .. PB7 sa�das 
	LDI  AUX,0xFF	    
	OUT  PORTB,AUX  	//habilita o pull-up do PB0 (demais pinos em 1)
	OUT  DDRD, AUX    	//PORTD como sa�da
	OUT  PORTD,AUX   	//desliga o display

	/*Para utilizar os pinos PD0 e PD1 como I/O gen�rico no Arduino � necess�rio 
	desabilitar as fun��es TXD e RXD desses pinos*/

	STS UCSR0B,R1		//carrega o valor 0x00 (default de R1) em USCR0B, como ele esta na SRAM, usa-se STS

//------------------------------------------------------------------------------------
Principal:
		
	SBIC PINB,BOTAO 	//verifica se o bot�o foi pressionado, sen�o
	RJMP Principal		//volta e fica preso no la�o Principal	 
    
	CPI  AUX,0x0F   	//compara se valor � m�ximo
	BRNE Incr       	//se n�o for igual, incrementa; sen�o, zera valor
	LDI  AUX,0x00
	RJMP Decod

Incr:	
	INC  AUX

Decod:	
	RCALL Decodifica	//chama sub-rotina de decodifica��o
	RCALL Atraso      	//incremento autom�tico do display se o bot�o ficar pressionado
	RJMP  Principal   	//volta ler bot�o

//------------------------------------------------------------------------------------
//SUB-ROTINA de atraso - Aprox. 0,2 s � 16 MHz
//------------------------------------------------------------------------------------
Atraso:        
	LDI   R19,16 		//repete os la�os abaixo 16 vezes
volta:
	DEC   R17	    	//decrementa R17
	BRNE  volta    		//enquanto R17 > 0 fica decrementando R17
	DEC   R18      		//decrementa R18
	BRNE  volta	    	//enquanto R18 > 0 volta a decrementar R17
	DEC   R19      		//decrementa R19, come�a com 0x02
	BRNE  volta
	RET
//------------------------------------------------------------------------------------
//SUB-ROTINA que decodifica um valor de 0 -> 15 para o display 
//------------------------------------------------------------------------------------
Decodifica:
 
	LDI  ZH,HIGH(Tabela<<1)	//carrega o endere�o da tabela no registrador Z, de 16 bits (trabalha como um ponteiro)
	LDI  ZL,LOW(Tabela<<1) 	//deslocando a esquerda todos os bits, pois o bit 0 � para a sele��o do byte alto ou baixo no end. de mem�ria
	ADD  ZL,AUX 	   		//soma posi��o de mem�ria correspondente ao nr. a apresentar na parte baixa do endere�o
	BRCC le_tab           	//se houve Carry, incrementa parte alta do endere�o, sen�o l� diretamente a mem�ria
	INC  ZH    
      
le_tab:		
	LPM  R0,Z            	//l� valor em R0
	OUT  DISPLAY,R0   		//mostra no display
	RET
//------------------------------------------------------------------------------------
//	Tabela p/ decodificar o display: como cada endere�o da mem�ria flash � de 16 bits, 
//	acessa-se a parte baixa e alta na decodifica��o
//------------------------------------------------------------------------------------
Tabela: .dw 0x7940, 0x3024, 0x1219, 0x7802, 0x1800, 0x0308, 0x2146, 0x0E06
//             1 0     3 2     5 4     7 6     9 8     B A     D C     F E  
//====================================================================================


