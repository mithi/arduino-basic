
#include "SimpleLibrary.h"

DigitalOutput led;
const int DELAY = 500;


void setup() {
  led.Format(11);
  Serial.begin(115200);
}


void loop() {
 
  led.On();
  Serial.print(led.State());
  delay(DELAY);
 
  led.Off();
  Serial.print(led.State());
  delay(DELAY);
}

