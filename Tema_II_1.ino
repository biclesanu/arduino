void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT);

}

int button=8;
int i=2;
int tinutapasat=0;

void loop() {

  digitalWrite(i, HIGH);
   
   if(digitalRead(button)==LOW)
      tinutapasat=0;
      
   if(digitalRead(button)==HIGH && tinutapasat==0)
     {
       delay(300);
     digitalWrite(i, LOW);
       if(i<7)
         i++;
       else
         i=2;

       if(digitalRead(button)==HIGH)
        tinutapasat=1;
     }
   
}
