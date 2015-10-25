const int sensorPin = A0;
int baselineTemp = 0;

void setup() {
  Serial.begin(9600);
  
  for (int pinNumber = 2; pinNumber < 5; pinNumber++)
  {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  baselineTemp = getTemperature();
}
int getTemperature()
{
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value:");
  Serial.print(sensorVal);
  
  float voltage = (sensorVal / 1024.0) * 5.0;
  
  Serial.print("Voltage:");
  Serial.print(voltage);
  
  float temperature = (voltage - 0.5) *100;
  
  Serial.print("Temperature:");
  Serial.print(temperature);
  
  return temperature;
}
void loop() {
    int temperature = getTemperature();
  if (temperature  < baselineTemp)
  {
     digitalWrite(2, HIGH);
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
  }
  else if (temperature  >= baselineTemp && temperature < baselineTemp + 5)
  {
     digitalWrite(2, LOW);
     digitalWrite(3, HIGH);
     digitalWrite(4, LOW);
  }
  else
  {
     digitalWrite(2, LOW);
     digitalWrite(3, LOW);
     digitalWrite(4, HIGH);
  }
  delay(1);
}

