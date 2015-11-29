
#include "SimpleLibrary.h"

Potentiometer pot1, pot2; 
AnalogLED led;
TimingManager blinkTime;

int lastValue = 0;
int currentValue;
bool state = 0;

void setup() {
  
  pot1.New(A5);
  pot2.New(A4);
  led.New(11);
}

void loop() {
  
  potControl();
}

void potControl(){
  
  currentValue = pot1.RawValue();
  
  if (currentValue != lastValue)
    changeTiming();

  if (blinkTime.IsTimeToUpdate()){
    state == HIGH ? led.NewBrightness(pot2.MappedValue(0, 255)) : led.NewBrightness(0);
    state = !state;
  }   
}

void changeTiming(){
  
  int threshold = 50;
  
  if( abs(currentValue - lastValue) > threshold){ 
    blinkTime.New(currentValue);
    lastValue = currentValue;
  }
}


