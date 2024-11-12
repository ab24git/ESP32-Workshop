// Define the pins
const int irSensorPin = 5;   // IR sensor output pin
const int ledPin = 18;         // LED control pin

void setup() {
  pinMode(irSensorPin, INPUT);   // Set IR sensor pin as input
  pinMode(ledPin, OUTPUT);       // Set LED pin as output
  Serial.begin(9600);          // Start serial communication for debugging
}

void loop() {
  int irValue = digitalRead(irSensorPin); // Read the IR sensor output

  if (irValue == LOW) {                   // Assuming LOW means object detected
    digitalWrite(ledPin, HIGH);           // Turn on the LED
    Serial.println("Object detected! LED ON");
  } else {
    digitalWrite(ledPin, LOW);            // Turn off the LED
    Serial.println("No object detected. LED OFF");
  }

  delay(100); // Small delay for stability
}
