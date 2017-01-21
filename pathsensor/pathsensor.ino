#include "RCSwitch.h"

RCSwitch mySwitch = RCSwitch();



int LED = 13; // Use the onboard Uno LED
int isPathPin = 4;  // This is our input pin
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
   String id = "1_";
  String zip = "47408_";  
  String lot = "p2_"
  if (isPath == LOW)
  {
    String ret = id+zip+lot+"True" ;
    mySwitch.send(ret.c_str());
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    String ret = id+zip+lot+"False";
    mySwitch.send(ret.c_str());
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}
