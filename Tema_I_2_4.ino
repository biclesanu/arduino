int valoaredelay = 500;

int lastupdatetime = 0;
int primulled=2;
int ultimulled=6;

bool pressed = false;
bool start = true;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);

}


void writenewled()
{
    digitalWrite(primulled,LOW);  
    digitalWrite(ultimulled,LOW); 

    if(primulled>=4)
     primulled=2;
    else
     primulled++;

    if(ultimulled<=4)
     ultimulled=6;
    else
    ultimulled--;
    

    digitalWrite(primulled,HIGH);
    digitalWrite(ultimulled,HIGH); 
}


void delayer()
{
    int runtime = millis();

    if(runtime-lastupdatetime >= valoaredelay)
    {
      lastupdatetime=lastupdatetime+valoaredelay;
      writenewled();
    }
  
}


void updatedelay(int faster, int slower)
{
  if(faster==1 && pressed==false)
  {
     if(valoaredelay<=500)
    valoaredelay = valoaredelay-50;
   else
    valoaredelay = valoaredelay-250;
     pressed=true;
  }

  if(slower==1 && pressed==false)
  {
    if(valoaredelay<=500)
    valoaredelay = valoaredelay+100;
   else
    valoaredelay = valoaredelay+1000;
    pressed=true;
  }

  if(valoaredelay<=0)
     valoaredelay=25; 
     
  if(slower==0 && faster==0)
   pressed=false;
}

void loop() {

 if(start)
 {
  digitalWrite(2,HIGH);
  digitalWrite(6,HIGH);
  start=0;
 }
 int fastbutton = digitalRead(8); 
 int slowbutton = digitalRead(9);

 updatedelay(fastbutton, slowbutton);
 delayer();
  
}
