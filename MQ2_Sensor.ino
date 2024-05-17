// Include the required libraries
#include <WiFi.h>

// Define the analog pin connected to the MQ2 sensor
#define ANALOG_PIN A0

// WiFi credentials
const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";

void setup() {
  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Print ESP32 IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Read the analog value from the MQ2 sensor
  int sensorValue = analogRead(ANALOG_PIN);

  // Convert analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Print the voltage value
  Serial.print("Voltage: ");
  Serial.println(voltage);

  // Wait for a short duration
  delay(1000);
}
