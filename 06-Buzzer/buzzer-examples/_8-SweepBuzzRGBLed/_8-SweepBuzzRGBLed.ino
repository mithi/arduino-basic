
#include "SimpleLibrary.h"

Sweeper sweeper; 
Sweeper toggler;
Buzzer buzzer;
Button button;
RGB rgb;

int dwell = 3;
int pause = 1;
int f1 = 3000;
int f2 = 4000;
int maxSweepType = 2;
int mode = 0;
int f = 0;

void setup() {
  
  sweeper.New(f1, f2, BACKANDFORTH); 
  toggler.New(0, maxSweepType, NORMAL);
  buzzer.New(13, 1.3, 1000);
  button.New(0, 50);
  rgb.New(6, 10, 9);
  
  rgb.ColorRaw(0,0,0);
}

void loop() {
  
  f = sweeper.Next(1); 
 
  buzzer.Play(f, dwell, pause);
  
  nextColor(map(f, f1, f2, 0, 50));
  
  button.Update();
  
  if (button.JustPressed())
    processSweep();
}


void nextColor(int brightness){

  if(mode == 0)
    rgb.Red(brightness);

  if(mode == 1)
    rgb.Green(brightness);

  if(mode == 2)
    rgb.Blue(brightness);

}

void processSweep(){
  
    mode = toggler.Next(1);
    rgb.ColorRaw(0,0,0);
    nextSweep(mode);
}

void nextSweep(int c){
  
  if(c == 0)
    sweeper.New(f1, f2, BACKANDFORTH);
 
  if(c == 1)
    sweeper.New(f1, f2, NORMAL);
  
  if(c == 2)
    sweeper.New(f2, f1, NORMAL);
}

