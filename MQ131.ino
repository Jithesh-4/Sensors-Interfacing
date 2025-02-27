#define MQ131_PIN 34

void setup() {
  Serial.begin(115200);
  pinMode(MQ131_PIN, INPUT);
}

void loop() {
  int sensorValue = analogRead(MQ131_PIN);
  float voltage = sensorValue * (3.3 / 4095.0);

  float ozoneLevel = map(sensorValue, 0, 4095, 0, 1000); 
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  Serial.print("Voltage: ");
  Serial.println(voltage);
  Serial.print("Ozone Level: ");
  Serial.print(ozoneLevel); 
  Serial.println(" ppm");

  delay(1000); 
}
