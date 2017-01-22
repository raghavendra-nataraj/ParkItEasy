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
  if (mySwitch1.available()) {
 
    int value = mySwitch1.getReceivedValue();
 
    if (value == 0) {
      Serial.print("Unknown encoding");
    } else {
     unsigned long value = mySwitch1.getReceivedValue();
     unsigned long onOff = value % 10;
     unsigned long pLotID = (value /10) % 10;
     unsigned long PID = (value /100)  %10 ;
     unsigned long zip = (value /1000) ;
      Serial.print( onOff );
      Serial.print( "_");
      Serial.print( pLotID );
      Serial.print( "_");
      Serial.print( PID );
      Serial.print( "_");
      Serial.println( zip );
    }
 
    mySwitch1.resetAvailable();
}
delay(200);
}
