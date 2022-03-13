int buton=8;
int valoaredelay = 500;

void setup() {
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(buton, INPUT);

}
//random(2,7);


void loop() {
 
  int apasat = digitalRead(buton);

  if (apasat == HIGH)
   {
     for(int i=2;i<=7;i++)
      {
        digitalWrite(i,HIGH);
          delay(300);
      }

 for(int i=7;i>=2;i--)
    {  digitalWrite(i,LOW);
      delay(300);
    }
  int zar=random(2,8);
  
  for(int i=2;i<=zar;i++)    
    digitalWrite(i,HIGH);

    delay(2000);
  
  for(int i=2;i<=7;i++)
    digitalWrite(i,LOW);

   }
  
  
}
