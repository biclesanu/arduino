void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}
void loop() {
  
   for(int i=0;i<=2;i++){ 
     digitalWrite(6-i, HIGH);
    digitalWrite(i+2, HIGH);
  delay(250);
    digitalWrite(i+2, LOW);
    digitalWrite(6-i, LOW);

}
}
