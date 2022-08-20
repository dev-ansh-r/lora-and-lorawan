#include<SoftwareSerial.h>

// declare eui and key variables here
SoftwareSerial loraserial(2,3);

const int flexPin = A0;

// Pin connected to voltage divider output

// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 47000.0;  // resistor used to create a voltage divider
const float flatResistance = 25000.0; // resistance when flat
const float bendResistance = 100000.0;  // resistance at 90 deg

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
    if(distance < 5){
        Serial.println(str1);
      
   if(Serial.available()){
       loraserial.println("AT+MSG=" +str1);
       loraserial.println("AT+MSG=" +str2);    
      
   }
    if(loraserial.available()){
        Serial.println(loraserial.readString());
        delay(50);

    } 
  }
  // Read the ADC, and calculate voltage and resistance from it
  int ADCflex = analogRead(flexPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  Serial.println("Resistance: " + String(Rflex) + " ohms");

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  str2 = String(angle, 3);
  Serial.println("Bend: " + String(angle) + " degrees");
  Serial.println();

  delay(500);
}

// Language: cpp