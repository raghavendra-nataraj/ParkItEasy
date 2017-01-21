int LED = 13; // Use the onboard Uno LED
int isPathPin = 4;  // This is our input pin
int isPath = HIGH;  // HIGH MEANS NO OBSTACLE

void setup() {
  // put your setup code here, to run once:
 pinMode(LED, OUTPUT);
  pinMode(isPathPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   isPath = digitalRead(isPathPin);
  if (isPath == LOW)
  {
    Serial.println("OBSTACLE!!, OBSTACLE!!");
    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.println("clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}
