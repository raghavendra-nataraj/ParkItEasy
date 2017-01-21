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
     unsigned long value = mySwitch1.getReceivedValue();
     Serial.println( value );
     unsigned long onOff = value % 10;
     unsigned long pLotID = (value /10) % 10;
     unsigned long PID = (value /100)  %10 ;
     unsigned long zip = (value /1000) ;
      Serial.println( onOff );
      Serial.println( pLotID );
      Serial.println( PID );
      Serial.println( zip );
      Serial.print(" / ");
      Serial.print( mySwitch1.getReceivedBitlength() );
      Serial.print("bit ");
      Serial.print("Protocol: ");
      Serial.println( mySwitch1.getReceivedProtocol() );
    }
 
    mySwitch1.resetAvailable();
}
delay(200);
}

static char * dec2binWzerofill(unsigned long Dec, unsigned int bitLength) {
  static char bin[64]; 
  unsigned int i=0;

  while (Dec > 0) {
    bin[32+i++] = ((Dec & 1) > 0) ? '1' : '0';
    Dec = Dec >> 1;
  }

  for (unsigned int j = 0; j< bitLength; j++) {
    if (j >= bitLength - i) {
      bin[j] = bin[ 31 + i - (j - (bitLength - i)) ];
    } else {
      bin[j] = '0';
    }
  }
  bin[bitLength] = '\0';
  
  return bin;
}
