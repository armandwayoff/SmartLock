// Code original de Will Donaldson
// Modifié par Armand Wayoff en 2019

#include <SoftwareSerial.h>
#include <SoftwareServo.h> 

SoftwareSerial BTserial(1, 2);   //TxD, RxD

SoftwareServo servo;
const int pinServo = 3;
int pos = 0;

void setup() {
  BTserial.begin(38400);
  servo.attach(pinServo);
}

void loop() {
  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
    pos = BTserial.read(); // Reads the data from the serial port
    for(int i=0; i<200; i+=1){ 
      servo.write(pos);
      delay(1);
      SoftwareServo::refresh();
    }
  }
}
