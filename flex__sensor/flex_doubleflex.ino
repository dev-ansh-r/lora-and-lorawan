const int flexPin = A0;
const int flexPinone=A1;

// Pin connected to voltage divider output

// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 47000.0;  // resistor used to create a voltage divider
const float flatResistance = 25000.0; // resistance when flat
const float bendResistance = 100000.0;  // resistance at 90 deg

void setup() {
  Serial.begin(9600);
  pinMode(flexPin, INPUT);
  pinMode(flexPinone,INPUT);
}

void loop() {

  //for first flex sensor
  
  // Read the ADC, and calculate voltage and resistance from it
  int ADCflex = analogRead(flexPin);
  float Vflex = ADCflex * VCC / 1023.0;
  float Rflex = R_DIV * (VCC / Vflex - 1.0);
  Serial.println("Resistance: " + String(Rflex) + " ohms  of flex sensor-1");

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle1 = map(Rflex, flatResistance, bendResistance, 0, 90.0);
  Serial.println("Bend: " + String(angle1) + " degrees of flex sensor-1");
  Serial.println();

  //for 2nd flex sensor

  int ADCflexone = analogRead(flexPinone);
  float Vflex1 = ADCflexone * VCC / 1023.0;
  float Rflex1 = R_DIV * (VCC / Vflex - 1.0);
  Serial.println("Resistance: " + String(Rflex1) + " ohms  of flex sensor-1");

  // Use the calculated resistance to estimate the sensor's bend angle:
  float angle2 = map(Rflex1, flatResistance, bendResistance, 0, 90.0);
  Serial.println("Bend: " + String(angle2) + " degrees of flex sensor-2");
  Serial.println();

  if((angle1>6000)&& (angle2>6000)){
    Serial.println("GOOD FLOW");
  }
  if((angle1>3500) && (angle2>3500)){
    Serial.println("MODERATE FLOW");
  }
  if((angle1 && angle2 ==2050)){
    Serial.println("NO FLOW OF WATER OR BLOACKAGE");
  }
  delay(500);
}