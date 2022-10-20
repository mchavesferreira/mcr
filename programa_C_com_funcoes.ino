LiquidCrystal lcd(22,23,5,18,19,21);// Change this for your connections (obviously) 

unsigned long millisTarefa1 = millis();
int contador=0; 
int botao=32;
int LED=24;

void setup()
{ pinMode(LED, OUTPUT);
 pinMode(botao, INPUT_PULLUP); 
 lcd.begin(20, 2); 
 lcd.clear();
 lcd.setCursor(0, 1); 
 lcd.print("Bem Vindo ");
 delay(5000);
}

int estado=0;

void loop()
{ switch(estado)
   {
   case 0: tarefa0();  break;
   case 1: tarefa1();  break;
   case 2: tarefa2(); break;
  } // fim switch
} // fim loop


void tarefa0() 
   { 
    if(!digitalRead(botao))
     {  estado=1; } 
   } 

void tarefa1()
  { 
  Serial.println("Inicia o processso");
  if((millis() - millisTarefa1) > 1000) 
      {
      millisTarefa1 = millis();
      estado=2;
      }
  }

void tarefa2()
  { 
  digitalWrite(LED, HIGH); 
  delay(tempo); 
  digitalWrite(LED, LOW); 
  delay(tempo);
  }

// gerar pwm
 analogWrite(led_red, 4095);

// lear analogico
potValue = analogRead(potPin);
