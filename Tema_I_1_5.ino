void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

}

void loop() {

  
    for(int i=6;i>=2;i--){
    digitalWrite(i, HIGH);
  delay(300);
    
   }
  
   for(int i=6;i>=2;i--){
    digitalWrite(i, LOW);
  delay(300);
    
   }
    
    
     
}
