
const int greenLed = 9;
const int redLed = 11;
const int blueLed = 10;

const int redSensor = A0;
const int greenSensor = A1;
const int blueSensor = A2;

int redValue = 0;
int greenValue =0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensor);
  delay(5);
  greenSensorValue = analogRead(greenSensor);
  delay(5);
  blueSensorValue = analogRead(blueSensor);
  Serial.print("RR");
  Serial.print(redSensorValue);
  Serial.print("GR");
  Serial.print(greenSensorValue);
  Serial.print("BR");
  Serial.print(blueSensorValue);
  delay(1000);
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;  
  
  analogWrite(redLed, redValue);
  analogWrite(greenLed, greenValue);
  analogWrite(blueLed, blueValue);
  
  Serial.print("R");
  Serial.print(redValue);
  Serial.print("G");
  Serial.print(greenValue);
  Serial.print("B");
  Serial.print(blueValue);
  
  delay(1000);
}
