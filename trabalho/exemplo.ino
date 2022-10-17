void setup() { pinMode(32, OUTPUT);  digitalWrite(24, LOW); 
               pinMode(24, INPUT_PULLUP); }
int estado=0;  unsigned long millisTarefa1 = millis();
void loop()
{  switch(estado) 
    {
    case 0: if(!digitalRead(32)) {estado=1; } break;
    case 1:  if((millis() - millisTarefa1) > 3000)
             {
             millisTarefa1 = millis();
             estado=2; } break;
    case 2:  digitalWrite(24, HIGH);  delay(3000); digitalWrite(24, LOW);
             estado=0; break;
    }
} 
    
  
//
// estrategia 1:  
digitalWrite(24, HIGH); 
void loop()
{  
if((millis() - millisTarefa1) > 30000){ digitalWrite(24, LOW); }
if(!digitalRead(32)) { digitalWrite(24, LOW); }  
}
// estrategia 2:
digitalWrite(24, HIGH); 
void loop()
{  delay(30000);       digitalWrite(24, LOW);
if(!digitalRead(32)) { digitalWrite(24, LOW); }
}
    
