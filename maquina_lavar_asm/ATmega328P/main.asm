;====================================================================
; Main.asm file generated by New Project wizard
;
; Created:   seg nov 9 2015
; Processor: ATmega328P
; Compiler:  AVRASM (Proteus)
;====================================================================

;====================================================================
; DEFINITIONS
;====================================================================
.equ M1 = pb5 ;PINO13
.equ SP1 = pb0 ;PINO8
;====================================================================
; VARIABLES
;====================================================================
.def caixas = r0
;====================================================================
; RESET and INTERRUPT VECTORS
;====================================================================

      ; Reset Vector
      rjmp  Start

;====================================================================
; CODE SEGMENT
;====================================================================
.include "lib328Pv02.inc"
Start:

	rcall lcd_init	; Inicializa��o do LCD (VSS=GND VDD=5V VO=GND RS=PD2 RW=GND E=PD3           D4=PD4 D5=PD5 D6=PD6 D7=PD7 A=5V K=GND) 
	rcall lcd_clear	; Chama rotina limpar o LCD e posicionar na linha 0, coluna 0
	

;;;;;;;  posiciona cursor
	ldi lcd_col,3    ;define coluna3
	rcall lcd_lin0_col ;define linha 0
    rcall BemVindo

	ldi delay_time,5			
	rcall delay_seconds

    rcall lcd_clear	; Chama rotina limpar o LCD e posicionar na linha 0, coluna 0
	

    rcall seunome
    rcall seuprontuario


Loop:
    rjmp  Loop



;;;;;;;  posiciona cursor
	ldi lcd_col,1    ;define coluna3
	rcall lcd_lin1_col ;define linha 1

    ldi lcd_caracter,'V'	  ;; carrega letra entre aspas		
	rcall lcd_write_caracter  ; chama rotina para imprimir caracter
	
     ldi lcd_caracter,'='
	 rcall lcd_write_caracter  ; chama rotina para imprimir caracter  R19 >> lcd
	







;;;  biblioteca de frases

;;;;;;;;;;;;;;;;;  escreve mensagem	letra por letra
BemVindo:
	ldi lcd_caracter,'B'	  ;; carrega letra entre aspas		
	rcall lcd_write_caracter  ; chama rotina para imprimir caracter
	ldi lcd_caracter,'E'
	rcall lcd_write_caracter
	ldi lcd_caracter,'M'
	rcall lcd_write_caracter
	ldi lcd_caracter,' '
    rcall lcd_write_caracter
	ldi lcd_caracter,'V'
	rcall lcd_write_caracter
    RET

IFSP:
	ldi lcd_caracter,'I'	  ;; carrega letra entre aspas		
	rcall lcd_write_caracter  ; chama rotina para imprimir caracter
	ldi lcd_caracter,'F'
	rcall lcd_write_caracter
	ldi lcd_caracter,'S'
	rcall lcd_write_caracter
	ldi lcd_caracter,'P'
	rcall lcd_write_caracter
	ldi lcd_caracter,64  ; = 65 no codigo ascii
	rcall lcd_write_caracter
    RET

seunome:
	ldi lcd_col,1    ;define coluna3
	rcall lcd_lin0_col ;define linha 0
	ldi lcd_caracter,'C'	  ;; carrega letra entre aspas		
	rcall lcd_write_caracter  ; chama rotina para imprimir caracter
	ldi lcd_caracter,'h'	  ;; carrega letra entre aspas		
	rcall lcd_write_caracter  ; chama rotina para imprimir caracter
	ldi lcd_caracter,'a'	  ;; carrega letra entre aspas		
	rcall lcd_write_caracter  ; chama rotina para imprimir caracter
	ldi lcd_caracter,'v'	  ;; carrega letra entre aspas		
	rcall lcd_write_caracter  ; chama rotina para imprimir caracter
	ldi lcd_caracter,'e'	  ;; carrega letra entre aspas		
	rcall lcd_write_caracter  ; chama rotina para imprimir caracter
	ldi lcd_caracter,'s'	  ;; carrega letra entre aspas		
	rcall lcd_write_caracter  ; chama rotina para imprimir caracter
    RET

 seuprontuario:
;;;;;;;  posiciona cursor
	ldi lcd_col,0    ;define coluna5
	rcall lcd_lin1_col ;define linha 1

;;;;;;;;;;;;; imprimir numero	 20  21
        ldi r16,20	; carregue o numero em um registrador		
        mov lcd_number, r16   ;;; move para o registro da biblioteca LCD
	    rcall lcd_write_number  ;; chama rotina para imprimir numero

        ldi r16,21	; carregue o numero em um registrador		
        mov lcd_number, r16   ;;; move para o registro da biblioteca LCD
	    rcall lcd_write_number  ;; chama rotina para imprimir numero


    ldi lcd_col,12    ;define coluna5
	rcall lcd_lin1_col ;define linha 1


        ldi r16,6	; carregue o numero em um registrador		
        mov lcd_number, r16   ;;; move para o registro da biblioteca LCD
	    rcall lcd_write_numberunidade  ;; chama rotina para numero apenas uma unidade
   
       RET