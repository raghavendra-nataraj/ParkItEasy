#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int LED = 13; // Use the onboard Uno LED

int isObstaclePin = 7;  // This is our input pin
int isObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

int isPathPin = 8;  // This is our input pin
int isPath = HIGH;  // High is no car in path

const int trigPin = 2;
const int echoPin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(isPathPin, INPUT);
  pinMode(isObstaclePin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  mySwitch.enableTransmit(10);
}

void loop() {
  long duration, inches, cm;
  // put your main code here, to run repeatedly:
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

  isPath = digitalRead(isPathPin);
  id = "3";
  zip = "47408";  
  lot = "2";
  ret = 47408320;
  if (isPath == LOW)
  {
    mySwitch.send(ret+1,32);
    Serial.println("Obstacle!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    mySwitch.send(ret+0,32);
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  id = "1";
  zip = "47408";
  lot = "3";
  ret = 47408130;
  if(cm>0 && cm < 5){
    mySwitch.send(ret+1,32);
  }else{
    mySwitch.send(ret+0,32);
  }
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
