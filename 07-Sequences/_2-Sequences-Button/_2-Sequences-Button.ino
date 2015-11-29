
#include "SimpleLibrary.h"

Button button;

TimingManager ledsTiming;
SequenceStateUpdater sequence;
LedsManager leds;
byte sequenceType;

int ledPins[] = {11,10,9,6,5,3};

void setup() {
  
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

  sequence.Update(ledsTiming.IsTimeToUpdate());
}

byte nextSequence(){
  
  sequenceType++;
    
  if(sequenceType > 5 )
    sequenceType = 0;
  
  sequence.Start(sequenceType);  
}

