

#include "max6675.h" // max6675.h file is part of the library that you should download from Robojax.com

int soPin = 12;// SO=Serial Out
int csPin = 15;// CS = chip select CS pin
int sckPin = 14;// SCK = Serial Clock pin
MAX6675 Module(sckPin, csPin, soPin);// create instance object of MAX6675

void setup() {

          
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  Serial.println("MAX6675"); 

}

void loop() {
  // basic readout test, just print the current temp
   Serial.print("C = "); 
   Serial.println(Module.readCelsius());
   delay(1000);
}
