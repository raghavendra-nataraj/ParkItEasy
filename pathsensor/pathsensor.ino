#include "RCSwitch.h"

RCSwitch mySwitch = RCSwitch();



int LED = 13; // Use the onboard Uno LED
int isPathPin = 8;  // This is our input pin
int isPath = HIGH;  // HIGH MEANS NO OBSTACLE

void setup() {
  // put your setup code here, to run once:
 pinMode(LED, OUTPUT);
  pinMode(isPathPin, INPUT);
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
}

void loop() {
  // put your main code here, to run repeatedly:
   isPath = digitalRead(isPathPin);
   String id = "1";
  String zip = "47408";  
  String lot = "2";
  long ret = 47408120;
  if (isPath == LOW)
  {
    mySwitch.send(ret+1,32);
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    mySwitch.send(ret+0,32);
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}
