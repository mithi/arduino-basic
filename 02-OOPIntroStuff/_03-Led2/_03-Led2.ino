
#include "SimpleLibrary.h"

DigitalLED led;

void setup() {
  led.New(9);
  Serial.begin(9600);
}


void loop() {
  led.Toggle();
  Serial.print(led.IsOn());
  delay(500);
}

