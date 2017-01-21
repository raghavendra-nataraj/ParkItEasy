#include "RCSwitch.h"
RCSwitch mySwitch1 = RCSwitch(); 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Transmitter is connected to Arduino Pin #10  
  mySwitch1.enableReceive(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(mySwitch1.available());
  if (mySwitch1.available()) {
 
    int value = mySwitch1.getReceivedValue();
 
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
 
     Serial.print("Received ");
      Serial.print( mySwitch1.getReceivedValue() );
      Serial.print(" / ");
      Serial.print( mySwitch1.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch1.getReceivedProtocol() );
    }
 
    mySwitch1.resetAvailable();
}
