
#include "SimpleLibrary.h"

Button button;
DigitalOutput led;

void setup() {
  button.New(0, 50);
  led.New(11);
}

void loop() {
  button.Pressed() ? led.On() : led.Off(); 
}

// try !button.Pressed()
