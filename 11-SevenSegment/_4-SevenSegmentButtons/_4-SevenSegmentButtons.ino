
#include "SimpleLibrary.h"

Sweeper toggler;
SevenSegment SSD;
Button buttonUp, buttonDown;
int pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void setup(){
  
  toggler.Format(0, 9, 1, NORMAL);
  SSD.Format(pins, COMMONANODE); 
  buttonUp.Format(8, 50);
  buttonDown.Format(9, 50);

}

void loop(){
    
  if(buttonUp.JustReleased())
    next(FORWARD);
  
  if(buttonDown.JustReleased())
    next(REVERSE);
}

void next(bool dir){
  toggler.SetDirection(dir);
  SSD.Display(toggler.Next(1));
}
