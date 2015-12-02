
#include "SimpleLibrary.h"

Button button;
DigitalLED led;

void setup() {
  button.New(0, 50);
  led.New(11);
}

void loop() {
  button.Update();
  button.Pressed() ? led.TurnOn() : led.TurnOff(); 
}

// try !button.Pressed()
