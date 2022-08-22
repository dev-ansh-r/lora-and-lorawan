#include<SoftwareSerial.h>

// declare eui and key variables here
SoftwareSerial loraserial(2,3);

const int flexPin = A0;

// Pin connected to voltage divider output

// Change these constants according to your project's design
const int VCC = 5;      // voltage at Ardunio 5V line
const int R_DIV = 10000;  // resistor used to create a voltage divider
const int flatResistance = 16000; // resistance when flat
const int bendResistance = 17500;  // resistance at 90 deg

// declare ultrasonic sensor pins
int trig = 10;
int echo = 11;
float distance;
long duration;
String str1;
String str2;

void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(flexPin, INPUT);
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
    digitalWrite(trig, LOW);

// calculate distance and send to lora serial
    duration = pulseIn(echo, HIGH);
    delayMicroseconds(2);
    distance = duration * (0.034/2);
    str1 = String(distance, 3);
   
    if(distance >10){
      loraserial.println("AT+MSG=" + str1);
      delay(1000);
     Serial.println(str1);
     delay(1000);
   if(Serial.available()){
       loraserial.println("AT+MSG=" +str1);      
     
   }
    if(loraserial.available()){
        Serial.println(loraserial.readString());
        delay(50);

    }
     
     
  }

  // Use the calculated resistance to estimate the sensor's bend angle:
  int ADCflex = analogRead(flexPin);
  int Vflex = ADCflex * VCC / 1023;
  int Rflex = R_DIV * (VCC / Vflex - 1);
  int  angle = map(Rflex, flatResistance, bendResistance, 0, 90);
  //Serial.println("Bend: " + String(angle) + " degrees");
  //Serial.println();
  str2=String(angle);
   

  if(angle>=-2160){
     loraserial.println("AT+MSG=" + str2);
     delay(1000);
     Serial.println(str2);
     delay(1000);
   if(Serial.available()){
       loraserial.println("AT+MSG=" + str2);      
     
   }
    if(loraserial.available()){
        Serial.println(loraserial.readString());
        delay(50);

    }
  }

  delay(500);
}
