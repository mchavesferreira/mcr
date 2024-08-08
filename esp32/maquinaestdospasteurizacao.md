Controle de Processos em Automação de Laticínio

Tema:
A utilização de máquina de estados é essencial para o controle organizado e escalável de processos complexos em um laticínio. Neste exemplo, a abordagem com switch/case será comparada à abordagem utilizando if para gerenciar o processo de pasteurização de leite.

Problema:
Desenvolva um sistema de controle para um processo de pasteurização de leite em um laticínio usando um ESP32. O processo de pasteurização envolve as seguintes etapas:

    Aquecimento Inicial: O leite é aquecido até 63°C.
    Manutenção da Temperatura: O leite é mantido a 63°C por 30 minutos.
    Resfriamento Inicial: O leite é resfriado rapidamente até 4°C.
    Manutenção da Refrigeração: O leite é mantido a 4°C até que o operador o retire.

Requisitos:

    Um botão de start inicia o processo de pasteurização.
    Sensores de temperatura monitoram continuamente a temperatura do leite.
    A cada etapa, a temperatura deve ser mantida dentro de uma faixa específica.
    Ao final do processo, um alarme soa indicando que o leite está pronto.
