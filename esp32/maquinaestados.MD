# Máquina de estados


A máquina de estados com switch/case é mais organizada e escalável para lógicas de controle de processos mais complexos. A abordagem com if é mais direta, mas pode rapidamente se tornar difícil de gerenciar à medida que a complexidade do processo aumenta.

Para ilustrar o uso de máquina de estados na programação de um ESP32, vamos comparar lado a lado as abordagens utilizando if e switch/case. O exemplo envolve o controle de uma esteira rolante, onde:

1- Ao pressionar o botão de start, a esteira liga.

2- A esteira permanece ligada até que um objeto alcance o sensor 1.

3- Quando o sensor 1 é acionado, uma válvula V1 é ativada por 2 segundos.

4- A esteira é religada e continua até alcançar o sensor 2.

5- Ao atingir o sensor 2, uma válvula V2 é ativada por 3 segundos.

6- A esteira é religada e continua até o sensor 3.

7- Quando o sensor 3 é acionado, o processo é finalizado e volta ao início.

<img src=https://github.com/mchavesferreira/mcr/blob/main/esp32/imagens/exemplo_maquia.png> 


## Abordagem Utilizando if

 ```ruby  
#define LED1 2
#define LED2 4
#define LED3 5
#define botao 14

int tempo=1000;
int estado=0;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(botao, INPUT_PULLUP); // definir botao de entrada
  Serial.begin(115200);
  Serial.println("Inicio setup");
    delay(3000);
}

void loop() {

switch (estado) {
  case 0:
      Serial.println("Estado=0");
      digitalWrite(LED1, HIGH);
      if(!digitalRead(botao)) { estado=1; }
    break;
  case 1:
    Serial.println("Estado=1");
     digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(2000);
      estado=2;
    break;
  case 2:
    Serial.println("Estado=2");
     digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(2000);
      estado=3;
    break;  
  case 3:
    Serial.println("Estado=3");
     digitalWrite(LED3, LOW);
     estado=0;
     delay(2000);
    break;  
 
}  // fim do switch

 //
     
}


 ```


## Abordagem Utilizando switch/case

 ```ruby  


 ```


Verifique sobre requisitos de pino

https://github.com/mchavesferreira/mcr/blob/main/esp32/pinos.md



