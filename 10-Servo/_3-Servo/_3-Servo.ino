
#include "SimpleLibrary.h"
#include <Servo.h>

Servo servo;
Sweeper sweeper;
Metronome metronome; 
Button button1, button2;

void setup() {
  servo.attach(9);
  sweeper.Format(0, 180, 1, BACKANDFORTH);
  metronome.Format(15);
  button1.Format(0, 50);
  button2.Format(1, 50);
}

void loop() {
  servo.write(sweeper.Next(metronome.Tick()));

  while(button1.Pressed());

  if(button2.JustPressed())
    sweeper.ToggleDirection();
}



