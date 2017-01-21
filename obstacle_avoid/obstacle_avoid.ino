#include <RCSwitch.h>
// IR Obstacle Collision Detection Module

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
  String id = "2";
  String zip = "57408";
  String lot = "1";
  long ret = 57408210;
  if (isObstacle == LOW)
  {
    mySwitch.send(ret + 1, 32);
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    mySwitch.send(ret + 0, 32);
    Serial.println(ret);
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}
