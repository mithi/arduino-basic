
#include "SimpleLibrary.h"

Sweeper toggler;
SevenSegment SSD;
Button buttonUp, buttonDown;
int pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void setup(){
  
  toggler.New(0, 9, 1, NORMAL);
  SSD.New(pins, COMMONANODE); 
  buttonUp.New(8, 50);
  buttonDown.New(9, 50);

}

void loop(){
    
  if(buttonUp.JustReleased()){
    toggler.Direction(FORWARD);
    SSD.Display(toggler.Next(1));
  }
  
  if(buttonDown.JustReleased()){
    toggler.Direction(REVERSE);
    SSD.Display(toggler.Next(1));
  }
}

