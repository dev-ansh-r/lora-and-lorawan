#include <SoftwareSerial.h>

int PIN_TX = 3;
int PIN_RX = 2;

SoftwareSerial mySerial(PIN_RX, PIN_TX);

String s;

unsigned long lastMillis;

  void setup() {
  Serial.begin(9600);
  delay(3000);
  mySerial.begin(9600);

    sendATcommand("AT+JOIN" , 5000);
    Serial.print("Joining the network");

      mySerial.println("AT+MSG=HI");

//  sendATcommand("AT+1D", 2000);
//  Serial.print("returns ID");
//  sendATcommand("AT+JOIN", 2000);
//  Serial.print("Joining the network");    
 
}

void loop() {
  if(mySerial.available()){
    Serial.println(mySerial.readString());
  }

  if(Serial.available()){
//    Serial.println(Serial.readString());
    s = Serial.readString();
        Serial.println(s);

    mySerial.println(s);
  }

  mySerial.println("AT+MSG=HI");
  delay(10000);
}



String sendATcommand(const char *toSend, unsigned long milliseconds) {
  String result;
  Serial.print("Sending: ");
  Serial.println(toSend);
  mySerial.println(toSend);
  delay(milliseconds);
  
}
//  unsigned long startTime = millis();
//  Serial.print("Received: ");
//  while (millis() - startTime < milliseconds) {
//    if (mySerial.available()) {
//      char c = mySerial.read();
//      Serial.write(c);
//      result += c;  // append to the result string
//    }
//  }
//Serial.println();  // new line after timeout.
//return result;
//}




                                 //AT command for  sending



//  sendATcommand("AT+ID=DevEui,"70B3D57ED005387F"", 2000);
//  Serial.print("Add the device eui");
//  sendATcommand("AT+ID=AppEui,"0000000000000000"", 2000);
//  Serial.print("Add the app eui");
//  sendATcommand("AT+KEY=APPKEY,"7EE269E9615C462D915AE2BBA38A221E"", 2000);
//Serial.print("Add the APP key");





/* Author : Devansh and Bhuvaneshwari*/