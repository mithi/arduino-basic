
#include "SimpleLibrary.h"

int ledPins[] = {11,10,9,6,5,3};

byte sequenceType;
TimingManager timing;
Sequencer sequence;
LedsManager leds;

Button button;
Potentiometer pot1;
Potentiometer pot2;

void setup() {
  
  pot1.New(A5);
  pot2.New(A4);
  button.New(0, 50);
  
  timing.New(100);
  leds.New(ledPins);
  sequence.New(&leds);
  
  sequence.Start(STAIRSUP);
}

void loop() {

  button.Update();

  if(button.JustReleased())
    nextSequence();
    
  timing.NewInterval(pot1.MappedValue(50,300));
  leds.NewBrightness(pot2.MappedValue(0, 255));

  sequence.Update(timing.Tick());
}

byte nextSequence(){
  
  sequenceType++;
  
  if(sequenceType > 5 )
    sequenceType = 0;
  
  sequence.Start(sequenceType);  
}

