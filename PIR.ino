// Pin configuration
const int pirPin = 2;   // PIR sensor output pin
const int ledPin = 13;  // LED pin

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
    // Give some time to stabilize
}

void loop() {
  int pirState = digitalRead(pirPin);  // Read PIR sensor state


  if (pirState == HIGH) {
    // Motion detected
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Motion detected!");
    delay(300);  // Delay to avoid multiple detections
  } else {
    // No motion detected
    digitalWrite(ledPin, LOW);
    Serial.println("Motion Not detected!");  // Turn off the LED
    delay(500);
  }
}

