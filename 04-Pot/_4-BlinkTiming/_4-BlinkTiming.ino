
#include "SimpleLibrary.h"

Potentiometer pot; 
DigitalLED led;
TimingManager blinkTime;
int lastValue = 0;
int currentValue;

void setup() {
  
  pot.New(A5);
  led.New(11);
}

void loop() {  
  
  potControl();
}

void potControl(){
  
  currentValue = pot.RawValue();

  if (currentValue != lastValue)
    changeTiming();

  if (blinkTime.Tick())
    led.Toggle();
}

void changeTiming(){
  
  int threshold = 50;
  
  if( abs(currentValue - lastValue) > threshold){ 
    blinkTime.New(currentValue);
    lastValue = currentValue;
  }
}

