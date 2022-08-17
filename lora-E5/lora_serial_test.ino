#include<SoftwareSerial.h>

SoftwareSerial loraserial(2,3);
char appeui = 8000000000000006;
char deveui = 2CF7F1203230D4E7;
char appkey = 9648BEF80D21DA31CA835206876FDAF9;

void setup(){
    Serial.begin(9600);
    loraserial.begin(9600);
// initialize the serial communications  and set up id's and key's

    Serial.println("Process initiated");
    loraserial.println("AT+ID=appeui," + appeui);
    loraserial.println("AT+ID=deveui," + deveui);
    loraserial.println("AT+ID=appkey," + appkey);
    loraserial.println("AT+JOIN");
}

void loop(){
    if(Serial.available()){
        char c = 10;
        loraserial.println("AT+MSG=" + c);
        Serial.println(loraserial.write(c));
    }
    if(loraserial.available()){
        char c = loraserial.read();
        Serial.write(c);
        Serial.println(c);
    }
}