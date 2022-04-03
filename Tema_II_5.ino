int ox,oy;

void setup() {
  pinMode(2, OUTPUT);  //stanga
  pinMode(3, OUTPUT);  //sus
  pinMode(4, OUTPUT);  //dreapta
  pinMode(5, OUTPUT);  //jos
  pinMode(6, OUTPUT);  //mijloc
  
  digitalWrite(6,HIGH);

}

void loop() {

  delay(500);
  ox = analogRead(A0);
  oy = analogRead(A1);

  if(ox<450)
     digitalWrite(2,HIGH),digitalWrite(6,LOW);
  else if(ox>600)
     digitalWrite(4,HIGH),digitalWrite(6,LOW);
  else if(oy<490)
     digitalWrite(5,HIGH),digitalWrite(6,LOW);
  else   if(oy>530)
     digitalWrite(3,HIGH),digitalWrite(6,LOW);
  else if(ox > 500 && ox < 550)
    {
         digitalWrite(5,LOW);
         digitalWrite(4,LOW);
         digitalWrite(3,LOW);
         digitalWrite(2,LOW);
         digitalWrite(6,HIGH);
    }
}
