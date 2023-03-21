#include<SoftwareSerial.h>

// declare eui and key variables here
SoftwareSerial loraserial(2,3);
char appeui = "8000000000000006";
char deveui = "2CF7F1203230D4E7";
char appkey = "9648BEF80D21DA31CA835206876FDAF9";

// declare ultrasonic sensor pins
int trig = 10;
int echo = 11;
float distance;
long duration;

void setup() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
// initialize the serial communications  and set up id's and key's
    loraserial.begin(9600);
    Serial.println("Process initiated");
    loraserial.println("AT+ID=appeui," + appeui);
    loraserial.println("AT+ID=deveui," + deveui);
    loraserial.println("AT+ID=appkey," + appkey);
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
    dtostrf(distance,6,3,char c[10]);


    if(Serial.available()){
        char c = Serial.read();
        loraserial.println("AT+MSG=" + c);
        Serial.println(loraserial.write(c));
    }
    if(loraserial.available()){
        char c = loraserial.read();
        Serial.write(c);
        Serial.println(c);
    }
}

/* Author : Devansh and Bhuvaneshwari*/