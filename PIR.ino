#define PIR_PIN 5  // GPIO connected to the PIR sensor output

void setup() {
  Serial.begin(9600);        // Initialize serial communication
  pinMode(PIR_PIN, INPUT);     // Set PIR pin as input
}

void loop() {
  int pirState = digitalRead(PIR_PIN);  // Read PIR sensor state
  Serial.print(pirState);
  Serial.print("\n");
  if (pirState == HIGH) {
    Serial.println("Motion detected!"); // If motion is detected
  } else {
    Serial.println("No motion.");       // If no motion is detected
  }
  delay(100);  // Delay for readability
}
