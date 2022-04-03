#include <IRremote.h>

int startt=0;
int valoaredelay = 600;
int lastupdatetime = 0;
int ledcurent=1;

int joclum=0;

int operatie=1;
int stareled=HIGH;
int intrerup=1;

IRrecv irrecv(11);
decode_results results;

void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(11, INPUT);

    Serial.begin(9600);
    irrecv.enableIRIn();
}


/*
 ~INSTRUCTIUNI~

 acestea sunt butoanele folosite si scopul lor:
 -EFECTE LUMINOASE: 1,2,3,4
 -Pauza/Pornire: butonul verde deschis "play/pause"
 -Viteza: butonul "vol-" si "vol+"
*/


void curatareleduri()
{
    for(int i=2; i<=6; i++)
        digitalWrite(i,LOW);
    operatie=1;
    stareled=HIGH;
    ledcurent=1;
}

void joclumini()       ///jocuri de lumini in functie de "joclum"
{
    if(joclum==1)   ///lumina merge de la stanga la dreapta
    {
        digitalWrite(ledcurent,LOW);

        if(ledcurent==6)
            ledcurent=2;
        else
            ledcurent++;

        digitalWrite(ledcurent,HIGH);
    }


    if(joclum==2)   ///lumina se intalneste in mijloc
    {
        digitalWrite(ledcurent,LOW);
        digitalWrite(8-ledcurent,LOW);

        if(ledcurent==4)
            ledcurent=2;
        else
            ledcurent++;

        digitalWrite(ledcurent,HIGH);
        digitalWrite(8-ledcurent,HIGH);
    }



    if(joclum==3)  ///lumina se plimba dintr-o parte in alta<3 (preferata mea)
    {
        digitalWrite(ledcurent,LOW);
        int ledanterior=ledcurent;

        if(ledanterior==6)
            operatie=-1;
        if(ledanterior==2)
            operatie=1;

        ledcurent=ledcurent+operatie;

        digitalWrite(ledcurent,HIGH);
    }



    if(joclum==4)   ///umplere de la stanga la dreapta urmata de golire de la stanga la dreapta
    {

        digitalWrite(ledcurent,stareled);

        if(ledcurent==6)
        {
            if(stareled==HIGH)
                stareled=LOW;
            else
                stareled=HIGH;
            ledcurent=1;

        }
        ledcurent++;

    }
}


void delayer()            ///parcurge ledurile folosind noua viteza - functie conceputa pentru a schimba valoarea de delay intre oricare 2 pasi ai ciclului
{
    int runtime = millis();

    if(runtime-lastupdatetime >= valoaredelay)
    {
        lastupdatetime=lastupdatetime+valoaredelay;
        joclumini();
    }

}


void updatedelay(int faster, int slower)    ////schimba viteza
{
    if(faster==1)
    {
        if(valoaredelay<=200)
             valoaredelay = 50;
        else
             valoaredelay = valoaredelay-500;
    }

    if(slower==1)
    {
        if(valoaredelay<=500)
            valoaredelay = 500;
        else
            valoaredelay = valoaredelay+1000;
    }
    if(valoaredelay<=0)
    valoaredelay=25;
}

void loop()
{

    if (irrecv.decode(&results))
    {
        switch(results.value)
        {
        case 0xFFC23D:   ///daca a citit butonul "0xFFC23D", stinge toate ledurile si nu mai apeleaza functia delay, folosindu-se de variabila "intrerup"
        {
            if(intrerup==0)
                intrerup=1;
            else
                intrerup=0;
        }
        break;

        case 0xFFE01F:
            updatedelay(0,1);
            break;

        case 0xFFA857:
            updatedelay(1,0);
            break;

        case 0xFF30CF:
            joclum=1;
            startt=1;
            curatareleduri();
            break;

        case 0xFF18E7:
            joclum=2;
            startt=1;
            curatareleduri();
            break;

        case 0xFF7A85:
            joclum=3;
            startt=1;
            curatareleduri();
            break;

        case 0xFF10EF:             
            joclum=4;
            startt=1;
            curatareleduri();
            break;


        }
        delay(500);
        irrecv.resume();
    }

    if(intrerup==0)
        curatareleduri();

    delay(500);

    if(startt==1 && intrerup==1)
        delayer();
}
