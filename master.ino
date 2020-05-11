// Code original de Will Donaldson
// Modifié par Armand Wayoff en 2019

#include <SoftwareSerial.h>

SoftwareSerial BTserial(1, 2); //TxD, RxD

const int OffPin = 3;
const int OnPin = 4; 
int Delai = 1500; 
int posOn = 100;
int posOff = 10;
int posIni = 60;


void setup() {
  BTserial.begin(38400);
  pinMode(OffPin, INPUT);
  pinMode(OnPin, INPUT);
}

void loop() {
  if(digitalRead(OffPin) == HIGH){        //User wants to turn off lights
    BTserial.write(posOff);                 //Send signal to move servo to off position
    delay(Delai);
    BTserial.write(posIni);
  }

  else if(digitalRead(OnPin) == HIGH){    //User wants to turn on lights
    BTserial.write(posOn);                //Send signal to move servo to on position
    delay(Delai);
    BTserial.write(posIni);                  
  }
}
