#include<SoftwareSerial.h>

// declare eui and key variables here
SoftwareSerial loraserial(2,3);


// declare ultrasonic sensor pins
int trig = 10;
int echo = 11;
float distance;
long duration;
char buffer[5];

void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
// initialize the serial communications  and set up id's and key's
    loraserial.begin(9600);
    Serial.println("Process initiated");
    delay(500);
    loraserial.println("AT+JOIN");
}


void loop(){ 

// set pin modes for ultrasonic sensor
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(2);
    digitalWrite(trig, LOW);git 

// calculate distance and send to lora serial
    duration = pulseIn(echo, HIGH);
    delayMicroseconds(2);
    distance = duration * (0.034/2);
    String str1 = String(distance, 3);
    if(distance < 5){
        Serial.println(str1);
      
   if(Serial.available()){
       loraserial.println("AT+MSG=" +str1);      
      
   }
    if(loraserial.available()){
        Serial.println(loraserial.readString());
        delay(50);

    }
      
      
  }
}

   