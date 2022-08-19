
const int flexPinone =A0; 
const int flexPintwo=A1;
 
void setup() 
{ 
  Serial.begin(9600);
} 
 
void loop() 
{ 
  int flexValueone;
  flexValueone = analogRead(flexPinone);
  Serial.print("sensor one value: ");
  Serial.println(flexValueone);
  delay(1000);

  
  int flexValuetwo;
  flexValuetwo = analogRead(flexPintwo);
  Serial.print("sensor two value ");
  Serial.println(flexValuetwo);
  delay(1000);
} 