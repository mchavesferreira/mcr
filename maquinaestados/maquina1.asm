.include "m328pdef.inc"

.equ LED_PIN,  PB0       ; pino de saída para o LED
.equ RELAY_PIN, PB1      ; pino de saída para o relê
.equ BUTTON_PIN, PD2     ; pino de entrada para o botão
.equ SENSOR_PIN, PC0     ; pino de entrada para o sensor analógico
.equ LCD_RS_PIN, PD4     ; pino de controle RS do display LCD
.equ LCD_EN_PIN, PD5     ; pino de controle EN do display LCD
.equ LCD_D4_PIN, PD6     ; pino de dados D4 do display LCD
.equ LCD_D5_PIN, PD7     ; pino de dados D5 do display LCD
.equ LCD_D6_PIN, PB2     ; pino de dados D6 do display LCD
.equ LCD_D7_PIN, PB3     ; pino de dados D7 do display LCD

; Definir estados do sistema
.equ IDLE_STATE, 0
.equ BUTTON_PRESSED_STATE, 1
.equ SENSOR_TRIGGERED_STATE, 2

.def button_state = r16   ; registrador para armazenar o estado do botão
.def sensor_value = r17   ; registrador para armazenar o valor do sensor
.def current_state = r18  ; registrador para armazenar o estado atual da máquina de estados

.org 0x0000               ; endereço de início do programa

reset:
    ldi r16, 0xFF        ; inicializa o registrador R16 com o valor 0xFF
    out DDRB, r16        ; configura todos os pinos do PORTB como saída
    clr button_state     ; limpa o registrador button_state
    clr sensor_value     ; limpa o registrador sensor_value
    clr current_state    ; limpa o registrador current_state

    ; Inicializa o display LCD
    ldi r16, (1<<LCD_D4_PIN)|(1<<LCD_D5_PIN)|(1<<LCD_D6_PIN)|(1<<LCD_D7_PIN)
    out DDRB, r16
    ldi r16, (1<<LCD_EN_PIN)|(1<<LCD_RS_PIN)
    out DDRD, r16
    call lcd_init

main_loop:
    call check_button    ; verifica o estado do botão
    call read_sensor     ; lê o valor do sensor
    call update_state    ; atualiza o estado da máquina de estados
    call update_outputs  ; atualiza as saídas do sistema
    rjmp main_loop

check_button:
    sbis PIND, BUTTON_PIN ; verifica se o botão foi pressionado
    rjmp button_not_pressed
    mov button_state, BUTTON_PRESSED_STATE ; atualiza o estado do botão
    rjmp button_done
button_not_pressed:
    clr button_state ; limpa o estado do botão
button_done:
    ret

read_sensor:
    lds sensor_value, ADC ; lê o valor do conversor analógico-digital
    ret

update_state:
    ; máquina de estados para o sistema de automação
    ; transições de estado baseadas nas entradas e saídas do sistema
    cpi current_state, IDLE_STATE
    breq idle_state
    c
