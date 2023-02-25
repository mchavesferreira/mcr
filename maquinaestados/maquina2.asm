.include "m328pdef.inc"  ; include file for ATmega328P

.equ STATE1 = 1
.equ STATE2 = 2
.equ STATE3 = 3

.def temp = r16   ; define a register for temporary storage

; initialization
    ldi temp, 0x00  ; clear the temporary register
    out DDRB, temp  ; set all PORTB pins as inputs
    out PORTB, temp ; disable pull-ups

; main loop
MAIN:
    ldi temp, (1<<PB0) ; set PB0 as output
    out DDRB, temp
    ldi temp, (1<<PB0) ; turn on PB0
    out PORTB, temp
    rcall DELAY_MS    ; delay for 500ms
    ldi temp, (1<<PB0) ; turn off PB0
    out PORTB, temp
    rcall DELAY_MS    ; delay for 500ms

; state machine
    lds temp, state  ; load the current state into temporary register

    ; check state and perform actions accordingly
    cpse temp, STATE1 ; if state == STATE1, go to STATE2
    rjmp STATE1_CHECK

    ldi temp, (1<<PB1) ; set PB1 as output
    out DDRB, temp
    ldi temp, (1<<PB1) ; turn on PB1
    out PORTB, temp
    ldi temp, STATE2   ; set state to STATE2
    sts state, temp   ; store the new state
    rjmp MAIN

STATE1_CHECK:
    cpse temp, STATE2 ; if state == STATE2, go to STATE3
    rjmp STATE2_CHECK
    ; perform STATE1 actions
    ldi temp, (1<<PB2) ; set PB2 as output
    out DDRB, temp
    ldi temp, (1<<PB2) ; turn on PB2
    out PORTB, temp
    rcall DELAY_MS     ; delay for 1000ms
    ldi temp, (1<<PB2) ; turn off PB2
    out PORTB, temp
    rcall DELAY_MS     ; delay for 1000ms
    ldi temp, STATE3   ; set state to STATE3
    sts state, temp   ; store the new state
    rjmp MAIN

STATE2_CHECK:
    cpse temp, STATE3 ; if state == STATE3, go to STATE1
    rjmp STATE3_CHECK
    ; perform STATE2 actions
    ldi temp, (1<<PB3) ; set PB3 as output
    out DDRB, temp
    ldi temp, (1<<PB3) ; turn on PB3
    out PORTB, temp
    rcall DELAY_MS     ; delay for 500ms
    ldi temp, (1<<PB3) ; turn off PB3
    out PORTB, temp
    rcall DELAY_MS     ; delay for 500ms
    ldi temp, STATE1   ; set state to STATE1
    sts state, temp   ; store the new state
    rjmp MAIN

STATE3_CHECK:
    ; perform STATE3 actions
    ldi temp, (1<<PB4) ; set PB4 as output
    out DDRB, temp
    ldi temp, (1<<PB4) ; turn on PB4
