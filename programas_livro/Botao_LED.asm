//----------------------------------------------------------------------------------------- //
//		AVR e Arduino: T�cnicas de Projeto, 2a ed. - 2012.									//	
//----------------------------------------------------------------------------------------- //
//=========================================================================================	//
//      LIGANDO E DESLIGANDO UM LED QUANDO UM BOT�O � PRESSIONADO     						//
//=========================================================================================	//

//DEFINI��ES
.equ LED   = PD2  //LED � o substituto de PD2 na programa��o      
.equ BOTAO = PD7  //BOTAO � o substituto de PD7 na programa��o 
.def AUX   = R16  /*R16 tem agora o nome de AUX (nem todos os 32 registradores
					de uso geral podem ser empregados em todas as instru��es) */                             
//----------------------------------------------------------------------------------------
.ORG 0x000		//endere�o de in�cio de escrita do c�digo na mem�ria flash
                //ap�s o reset o contador do programa aponta para c�
Inicializacoes:

	LDI  AUX,0b00000100	//carrega AUX com o valor 0x04 (1 = sa�da e 0 = entrada)
	OUT  DDRD,AUX		//configura PORTD, PD2 sa�da e demais pinos entradas
	LDI  AUX,0b11111111	//habilita o pull-up para o bot�o e apaga o LED (pull-up em todas as entradas)
	OUT  PORTD,AUX

	NOP           /*sincroniza��o dos dados do PORT. Necess�rio somente para 
					uma leitura imediatamente ap�s uma escrita no PORT*/
//----------------------------------------------------------------------------------------
//LA�O PRINCIPAL
//----------------------------------------------------------------------------------------
Principal:

	SBIC  PIND,BOTAO   	//verifica se o bot�o foi pressionado, sen�o
	RJMP  Principal		//volta e fica preso no la�o Principal	 

Esp_Soltar:	

	SBIS  PIND,BOTAO  	//se o bot�o n�o foi solto, espera soltar
	RJMP  Esp_Soltar
	RCALL Atraso      	//ap�s o bot�o ser solto gasta um tempo para eliminar o ru�do proveniente do mesmo
	SBIC  PORTD,LED    	//se o LED estiver apagado, liga e vice-versa
	RJMP  Liga
	SBI   PORTD,LED   	//apaga o LED
	RJMP  Principal   	//volta ler bot�o

Liga:

	CBI   PORTD,LED   	//liga LED
	RJMP  Principal   	//volta ler bot�o

//----------------------------------------------------------------------------------------
//SUB-ROTINA DE ATRASO - Aprox. 12 ms a 16 MHz
//----------------------------------------------------------------------------------------
Atraso:

	DEC  R3			//decrementa R3, come�a com 0x00
	BRNE Atraso 	//enquanto R3 > 0 fica decrementando R3
	DEC  R2
	BRNE Atraso		//enquanto R2 > 0 volta decrementar R3
	RET
//========================================================================================

