Exemplo de Prova

Especifique entradas e saídas  acionando devidamente pull up para entradas 
Considere a utilização da biblioteca utilizada em sala de aula para o display 16x2, e tempos de atraso. Para cada etapa, o display informará a situação sendo executada por mensagens;  (2,0)
Utilize o display para ajustar o tempo de resfriamento TR1 através dos botões “+” “-“ e confirmação “Enter”. Após a confirmação dos tempos para os dois ingredientes, a máquina inicia o processo; (2,0)
Ao pressionar o botão de START, a esteira M1 e a lâmpada é acionada,  e o cilindro C1 avança, até que a peça passe pelo sensor S1; 
O cilindro então recua, a peça se desloca até o sensor S2; 
A esteira M1 é desligada e inicia o processo de resfriamento durante TR1 segundos através de um temporizador; 
Após o tempo de resfriamento,  a esteira M1 é novamente ligada. A esteira permanece ligada até a peça passar por S3, desligando a esteira e finalizando o ciclo e dando condição para um novo ciclo, desligando a lâmpada;
Repete-se o processo até que o número de peças resfriadas seja igual a 6.
Considere a utilização da comunicação Serial para informar cada etapa sendo executada.
Considere a utilização da função millis() para contagem de tempo
Utilize maquina de estados para organizar a execução

<img src=projetoesteira.png>
