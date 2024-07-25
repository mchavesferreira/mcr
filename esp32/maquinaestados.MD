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

https://wokwi.com/projects/404403833606235137

 ```ruby  
#define esteira 5
#define valvula1 4
#define valvula2 2
#define start 14
#define sensor1 27
#define sensor2 26
#define sensor3 25

int tempo=1000;
int etapa=1;

void setup() {
  pinMode(esteira, OUTPUT);  // led verde
  pinMode(valvula1, OUTPUT); // led amarelo
  pinMode(valvula2, OUTPUT);  // led vermelho
  pinMode(start, INPUT_PULLUP); // definir botao de entrada
  pinMode(sensor1, INPUT_PULLUP);  // define entrada, em aberto nivel alto
  pinMode(sensor2, INPUT_PULLUP);  // define entrada, em aberto nivel alto
  pinMode(sensor3, INPUT_PULLUP);  // define entrada, em aberto nivel alto
}

void loop() {

  if(etapa==1)
     { 
       if(!digitalRead(start))
         {
         digitalWrite(esteira, HIGH);
         etapa=2;
         }
     }


  if(etapa==2)
     { 
       if(!digitalRead(sensor1))
         {
         digitalWrite(esteira, LOW);
         etapa=3;
         }
     }

  if(etapa==3)
     { 
         digitalWrite(valvula1, HIGH);
         delay(2000);
         digitalWrite(valvula1, LOW);
         etapa=4;
      }

  if(etapa==4)
     { 
         digitalWrite(esteira, HIGH);
         if(!digitalRead(sensor2))
           {
           digitalWrite(esteira, LOW);
           etapa=5;
          }
      }
  
 if(etapa==5)
     { 
         digitalWrite(valvula2, HIGH);
         delay(3000);
         digitalWrite(valvula2, LOW);
         etapa=6;
      }

  if(etapa==6)
     { 
         digitalWrite(esteira, HIGH);
         if(!digitalRead(sensor3))
           {
           digitalWrite(esteira, LOW);
           etapa=1;
          }
      }

  }





 ```


## Abordagem Utilizando switch/case

https://wokwi.com/projects/404407325257579521

 ```ruby  

#define esteira 5
#define valvula1 4
#define valvula2 2
#define start 14
#define sensor1 27
#define sensor2 26
#define sensor3 25

int tempo=1000;
int etapa=1;

void setup() {
  pinMode(esteira, OUTPUT);  // led verde
  pinMode(valvula1, OUTPUT); // led amarelo
  pinMode(valvula2, OUTPUT);  // led vermelho
  pinMode(start, INPUT_PULLUP); // definir botao de entrada
  pinMode(sensor1, INPUT_PULLUP);  // define entrada, em aberto nivel alto
  pinMode(sensor2, INPUT_PULLUP);  // define entrada, em aberto nivel alto
  pinMode(sensor3, INPUT_PULLUP);  // define entrada, em aberto nivel alto

}

void loop() {

switch (etapa) {

  case 1: 
       if(!digitalRead(start))
         {
         digitalWrite(esteira, HIGH);
         etapa=2;
         }
   break;

 case 2:  
       if(!digitalRead(sensor1))
         {
         digitalWrite(esteira, LOW);
         etapa=3;
         }
 break;

 case 3: 
         digitalWrite(valvula1, HIGH);
         delay(2000);
         digitalWrite(valvula1, LOW);
         etapa=4;
  break;

 case 4: 
         digitalWrite(esteira, HIGH);
         if(!digitalRead(sensor2))
           {
           digitalWrite(esteira, LOW);
           etapa=5;
          }
   break;

 case 5: 
         digitalWrite(valvula2, HIGH);
         delay(3000);
         digitalWrite(valvula2, LOW);
         etapa=6;
   break;

 case 6: 
         digitalWrite(esteira, HIGH);
         if(!digitalRead(sensor3))
           {
           digitalWrite(esteira, LOW);
           etapa=1;
           }
  break;
  
  }  // fim switch

} // fim loop


 ```


Verifique sobre requisitos de pino

https://github.com/mchavesferreira/mcr/blob/main/esp32/pinos.md



