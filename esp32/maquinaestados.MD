# Máquina de estados

Comparação Lado a Lado
Abordagem	Vantagens	Desvantagens
if	Simples de entender para pequenas lógicas	Pode se tornar complexo e difícil de manter para lógicas mais complicadas
switch/case	Melhor organização e clareza em lógicas complexas	Pode ser um pouco mais difícil de entender inicialmente para iniciantes

A máquina de estados com switch/case é mais organizada e escalável para lógicas de controle de processos mais complexos. A abordagem com if é mais direta, mas pode rapidamente se tornar difícil de gerenciar à medida que a complexidade do processo aumenta.

Para ilustrar o uso de máquina de estados na programação de um ESP32, vamos comparar lado a lado as abordagens utilizando if e switch/case. O exemplo envolve o controle de uma esteira rolante, onde:

    1- Ao pressionar o botão de start, a esteira liga.
    2- A esteira permanece ligada até que um objeto alcance o sensor 1.
    3- Quando o sensor 1 é acionado, uma válvula V1 é ativada por 2 segundos.
    4- A esteira é religada e continua até alcançar o sensor 2.
    5- Ao atingir o sensor 2, uma válvula V2 é ativada por 3 segundos.
    6- A esteira é religada e continua até o sensor 3.
    7- Quando o sensor 3 é acionado, o processo é finalizado e volta ao início.

Abordagem Utilizando if




Abordagem Utilizando switch/case




