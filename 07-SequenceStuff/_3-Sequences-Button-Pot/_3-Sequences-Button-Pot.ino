
#include "SimpleLibrary.h"

Button button;
Potentiometer pot;

TimingManager ledsTiming;
SequenceStateUpdater sequence;
LedsManager leds;

int ledPins[] = {11,10,9,6,5,3};
byte sequenceType;

void setup() {
  
  pot.New(A0);
  button.New(0, 50);
  
  ledsTiming.New(100);
  leds.New(ledPins);
  sequence.New(&leds);
  
  sequence.Start(STAIRSUP);
}

void loop() {

  sequence.Update(ledsTiming.IsTimeToUpdate());
  button.Update();

  ledsTiming.NewChangeTime(pot.MappedValue(50,300));
  
  if(button.JustReleased())
    nextSequence();
}

byte nextSequence(){
  
  sequenceType++;
    
  if(sequenceType > 5 )
    sequenceType = 0;
  
  sequence.Start(sequenceType);  
}


