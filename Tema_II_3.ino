int red= 9;
int green= 10;
int blue = 11;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {

  for(int r=0;r<=255;r=r+15)
     {
      for(int g=0;g<=255;g=g+15)
       {
        for(int b=0;b<=255;b=b+15){ 
         delay(30);
         analogWrite(red, r);
         analogWrite(green, g);
         analogWrite(blue, b);
      }
     }
    }

    delay(2000);

}
