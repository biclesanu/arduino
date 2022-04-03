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
int valoare=1;

void loop() {

  digitalWrite(i, valoare);
   
   if(digitalRead(button)==LOW)
      tinutapasat=0;
      
   if(digitalRead(button)==HIGH && tinutapasat==0)
     {
       delay(300);
       if(i<7)
         i++; 
       else
         {
          i=2;
          if(valoare==0)
          valoare=1;
          else
          valoare=0;
         }
       
       if(digitalRead(button)==HIGH)
        tinutapasat=1;  
        
     }
   
}
