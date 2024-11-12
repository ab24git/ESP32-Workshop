#include <ESP32Servo.h>

Servo myServo;           // Create a servo object
const int servoPin = 18;  // GPIO pin connected to the servo signal line

void setup() {
  myServo.attach(servoPin);  // Attach the servo to the GPIO pin
  Serial.begin(115200);      // Start serial communication for debugging
}

void loop() {
  // Rotate the servo to 0 degrees
  myServo.write(0);
  Serial.println("Servo at 0 degrees");
  delay(1000);  // Wait 1 second

  // Rotate the servo to 90 degrees
  myServo.write(90);
  Serial.println("Servo at 90 degrees");
  delay(1000);  // Wait 1 second

  // Rotate the servo to 180 degrees
  myServo.write(180);
  Serial.println("Servo at 180 degrees");
  delay(1000);  // Wait 1 second
}
