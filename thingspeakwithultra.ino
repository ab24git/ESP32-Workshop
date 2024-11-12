// channel id :  2413886
//channel read api key : E2YR01G6CYGF4WF3

#include <WiFi.h>
#include "ThingSpeak.h"

// Pin configuration
const int echo_PIN = 4;   // Pin connected to the DHT sensor
const int triger_PIN = 2;   // Pin connected to the LED
float distance=0;
float duration=0;
// WiFi credentials
const char* WIFI_NAME = "*********";
const char* WIFI_PASSWORD = "*********";

// ThingSpeak channel details
const int myChannelNumber =  2741217;
const char* myApiKey = "*********";
const char* server = "*********";


WiFiClient client;

void setup() {
  Serial.begin(115200);

  pinMode(triger_PIN, OUTPUT);
  pinMode(echo_PIN, INPUT);

  // Connect to WiFi
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Wifi not connected");
  }
  Serial.println("Wifi connected !");
  Serial.println("Local IP: " + String(WiFi.localIP()));

  // Set WiFi mode to STA (station) mode
  WiFi.mode(WIFI_STA);

  // Initialize ThingSpeak client
  ThingSpeak.begin(client);
}

void loop() {
  // Read values from ultrasonic sensor
  digitalWrite(triger_PIN,LOW);
  delayMicroseconds(10);
  digitalWrite(triger_PIN,HIGH);
  duration = pulseIn(echo_PIN,HIGH);
  distance =( 0.017 * duration)/100;

    // Update ThingSpeak fields
  ThingSpeak.setField(1, distance);
  
  int x = ThingSpeak.writeFields(myChannelNumber, myApiKey);

  // Print distance a to serial monitor
  Serial.println("Disatnce: " + String(distance) + "m");
 
  // Check if data was successfully pushed to ThingSpeak
  if (x == 200) {
    Serial.println("Data pushed successfully");
  } else {
    Serial.println("Push error: " + String(x));
  }
  Serial.println("---");

  delay(15000);
}
