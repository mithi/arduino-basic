
#include "SimpleLibrary.h"
#include <Servo.h>

Servo servo;
Sweeper sweeper;
Metronome metronome; 
Button button1, button2;

void setup() {
  servo.attach(9);
  sweeper.New(0, 180, 1, BACKANDFORTH);
  metronome.New(15);
  button1.New(0, 50);
  button2.New(1, 50);
}

void loop() {
  servo.write(sweeper.Next(metronome.Tick()));

  while(button1.Pressed());

  if(button2.JustPressed())
    sweeper.ToggleDirection();
}



