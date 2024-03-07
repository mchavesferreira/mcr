

Primeiras instruções Assembly


| Instrução | Descrição                                               | Exemplo       | Explicação do Exemplo                                                      |
|-----------|---------------------------------------------------------|---------------|----------------------------------------------------------------------------|
| LDI       | Carrega um valor imediato em um registrador            | `LDI R16, 0xFF`| Carrega o valor hexadecimal FF no registrador R16                           |
| CLI       | Desabilita todas as interrupções                       | `CLI`         | Desabilita as interrupções globais no microcontrolador                     |
| SBI       | Seta um bit específico em um registrador de I/O        | `SBI PORTB, 1`| Seta o bit 1 do registrador PORTB, geralmente usado para ativar um pino    |
| SBIC      | Pula a próxima instrução se um bit em I/O estiver limpo| `SBIC PINB, 0`| Pula a próxima instrução se o bit 0 do registrador PINB estiver limpo      |
| SBIS      | Pula a próxima instrução se um bit em I/O estiver setado|`SBIS PINB, 0` | Pula a próxima instrução se o bit 0 do registrador PINB estiver setado     |
| OUT       | Escreve um valor de um registrador para I/O            | `OUT DDRB, R16`| Escreve o valor do R16 no DDRB, configurando direção de pino como saída    |
| IN        | Lê um valor de I/O para um registrador                 | `IN R16, PINB` | Lê o valor atual do registrador PINB para R16                              |
| RJMP      | Realiza um salto relativo                              | `RJMP +10`    | Salta 10 posições à frente no código, para executar outra parte do programa|
| RCALL     | Chama uma sub-rotina a uma distância relativa          | `RCALL +12`   | Chama uma sub-rotina que está 12 posições à frente no código               |
| DEC       | Decrementa o valor de um registrador em 1              | `DEC R16`     | Decrementa o valor no registrador R16 por 1                                |
| INC       | Incrementa o valor de um registrador em 1              | `INC R16`     | Incrementa o valor no registrador R16 por 1                                |
| BRNE      | Pula para um endereço se o resultado da última operação não for zero | `BRNE +4` | Pula 4 posições à frente se o resultado da última operação não foi zero    |
| RET       | Retorna de uma sub-rotina                              | `RET`         | Retorna para o ponto de chamada da sub-rotina                              |
