// Define the pins for the ultrasonic sensor
const int trigPin = 2; // Trigger pin
const int echoPin = 3; // Echo pin
int led=13;
int buzzer_pin=8;

// Variables to store the duration and distance
long duration;
int distance;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Define the trigPin as an OUTPUT and echoPin as an INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(buzzer_pin,OUTPUT);
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10us pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters (you can also use inches)
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance<20){
    tone(8,500);
    digitalWrite(13,HIGH);
    delay(500);
  }
  else{
    noTone(8);
    digitalWrite(13,LOW);
    delay(500);
  }

  // Delay before taking the next reading
  delay(500); // You can adjust this delay as needed
}

