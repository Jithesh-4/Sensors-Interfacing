#define MQ135_PIN 34

void setup() {
  Serial.begin(115200); 
  pinMode(MQ135_PIN, INPUT);
}

void loop() {
  int sensorValue = analogRead(MQ135_PIN); 
  float voltage = sensorValue * (3.3 / 4095.0); 

  float gasLevel = map(sensorValue, 0, 4095, 0, 1000); 
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V: ");
  Serial.print("Gas Level: ");
  Serial.print(gasLevel);
  Serial.println(" ppm");

  delay(1000); 
}
