// IR Obstacle Collision Detection Module
// Henry's Bench
#include "RCSwitch.h"

RCSwitch mySwitch = RCSwitch();

int LED = 13; // Use the onboard Uno LED
int isObstaclePin = 7;  // This is our input pin
int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
    mySwitch.enableTransmit(10);  
}

void loop() {
  isObstacle = digitalRead(isObstaclePin);
  String id = "2_";
  String zip = "57408_";  
  String lot = "p1_"
  if (isObstacle == LOW)
  {
    String ret = id+zip+lot+"True" ;
    mySwitch.send(ret.c_str());
    
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    String ret = id+zip+lot+"False" ;
    mySwitch.send(ret.c_str());
    
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}
