
#include "SimpleLibrary.h"

Button button;
DigitalOutput led;

void setup() {
  button.Format(0, 50);
  led.Format(11);
}

void loop() {
  button.Pressed() ? led.On() : led.Off(); 
}

// try !button.Pressed()
