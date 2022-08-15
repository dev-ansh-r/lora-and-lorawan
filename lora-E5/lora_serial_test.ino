#include<SoftwareSerial.h>

SoftwareSerial loraserial(2,3);

void setup(){
    Serial.begin(9600);
    loraserial.begin(9600);

    Serial.println("hello of arduino");

    loraserial.println("hello of lora");
}

void loop(){
    if(Serial.available()){
        char c = Serial.read();
        Serial.println(loraserial.write(c));
    }
    if(loraserial.available()){
        char c = loraserial.read();
        Serial.println(c);
    }
}