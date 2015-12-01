
#include "SimpleLibrary.h"

DigitalLED led;
const int DELAY = 500;


void setup() {
  led.New(9);
  Serial.begin(9600);
}


void loop() {
 
  led.TurnOn();
  Serial.print(led.IsOn());
  delay(DELAY);
 
  led.TurnOff();
  Serial.print(led.IsOn());
  delay(DELAY);
}

