
#include "SimpleLibrary.h"

int ledPins[] = {11,10,9,6,5,3};

byte sequenceType;
TimingManager ledsTiming;
SequenceStateUpdater sequence;
LedsManager leds;

Button button;
Potentiometer pot1;
Potentiometer pot2;

void setup() {
  
  pot1.New(A0);
  pot2.New(A1);
  button.New(0, 50);
  
  ledsTiming.New(100);
  leds.New(ledPins);
  sequence.New(&leds);
  
  sequence.Start(STAIRSUP);
}

void loop() {

  button.Update();

  if(button.JustReleased())
    nextSequence();
    
  ledsTiming.NewChangeTime(pot1.MappedValue(50,300));
  leds.NewBrightness(pot2.MappedValue(0, 255));

  sequence.Update(ledsTiming.IsTimeToUpdate());
}

byte nextSequence(){
  
  sequenceType++;
  
  if(sequenceType > 5 )
    sequenceType = 0;
  
  sequence.Start(sequenceType);  
}

