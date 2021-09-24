int buzzer=13;
int red=12;
int gre=11;
#include <SoftwareSerial.h>
SoftwareSerial gasSerial(2, 3);
void setup()
{
  gasSerial.begin(9600);
 Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(gre, OUTPUT);
 digitalWrite(buzzer, LOW);
  digitalWrite(gre,HIGH);
  digitalWrite(red, LOW);
  gasSerial.println("AT");
 Serial.print("AT");
 delay(100);
 gasSerial.println("AT+CMGF=1");
  Serial.println("AT+CMGF=1");
 delay(100);
 gasSerial.println("AT+CNMI=2,2,0,0,0");
 Serial.println("AT+CNMI=2,2,0,0,0");
       delay(100);
Serial.print("VR GAS SAFETY SYSTEM");
delay(5000);
}
void loop()
{
  digitalWrite(buzzer,LOW);
  int gasval=analogRead(A1);
   Serial.println(gasval);
 delay(2000);
 if(gasval>100)
 {
 digitalWrite(buzzer,HIGH);
 digitalWrite(red,HIGH);
 digitalWrite(gre,LOW);
 Serial.println("RED-HIGH ,GRE:LOW,BUZZER:HIGH");
 delay(1000);

  gasSerial.println("AT+CMGS=\"9666626425\"");
  Serial.println("AT+CMGS=\"9177736542\"");
  delay(1000);
  gasSerial.print("GAS SAFTY SYSTEM");
  gasSerial.print("Warning  Gas lekage  ");
    Serial.print("Warning  Gas lekage  ");
        gasSerial.write(26);
         delay(5000);
   digitalWrite(buzzer,LOW);
  digitalWrite(red,LOW);
  digitalWrite(gre,HIGH);
  Serial.println("RED-LOW ,GRE:HIGH,BUZZER:LOW");
  }
}

