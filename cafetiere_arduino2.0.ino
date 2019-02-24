#include <SoftwareSerial.h>
 
SoftwareSerial HC06(11,10);
const char DOUT_LED = 6;
const char DOUT_LED2 = 8;
String messageRecu;
int A= 10;
int B= 200;
int C = 5;
int D = 1;
void setup() {
  Serial.begin(9600);
  HC06.begin(9600); 
  pinMode(DOUT_LED, OUTPUT);
  digitalWrite(DOUT_LED, LOW);
  pinMode(DOUT_LED2, OUTPUT);
  digitalWrite(DOUT_LED2, LOW);
}
void loop()
{
    int Z=0;
    int Y = 0;
    while(HC06.available())
    {
      delay(3);
      char c = HC06.read();
      messageRecu += c;
    }
    if (messageRecu.length() >0)
    {
      Serial.println(messageRecu);
      if (messageRecu == "LED:1"){
        digitalWrite(DOUT_LED, HIGH);
        delay(B);
        digitalWrite(DOUT_LED, LOW);
        delay(A);
        }
        if (messageRecu == "LED:0"){
        digitalWrite(DOUT_LED, HIGH);
        delay(B);
        digitalWrite(DOUT_LED, LOW);
        delay(A);
        }
     if (messageRecu == "LED:2"){
        digitalWrite(DOUT_LED2, HIGH);
        delay(A);
     }
        if (messageRecu == "LED:3"){
        digitalWrite(DOUT_LED2, LOW);
        delay(A);
        }
    if (messageRecu == "AUTO"){
        Serial.println("debut boucle auto");
        digitalWrite(DOUT_LED, HIGH);
        delay(B);
        digitalWrite(DOUT_LED, LOW);
        delay(A);
        messageRecu="";
        while(Z< 2000) {
          
          Serial.println("prechauffe");
          delay(D);
          Z++;
          int Y = 0;
        }
        if (Z >= 1800) {
          digitalWrite(DOUT_LED2, HIGH);
          delay(C);
          Serial.println("Envoye caffe");
          while(Y < 5000) {
            Serial.println(Y);

            delay(D);
            
            Y++;
        }
        if(Y >= 1500) {
          Serial.println("fin cafe");
          digitalWrite(DOUT_LED2, LOW);
          delay(A);
          int Y = 0;
          int Z = 0;
        }
    }
    }
      messageRecu="";
    
    }
}
