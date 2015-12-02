
#include "SimpleLibrary.h"

Sweeper toggler;
SevenSegment SSD;
Button button;

int pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void setup(){
  
  toggler.New(0, 9, NORMAL);
  SSD.New(pins, COMMONANODE); 
  button.New(8, 50);
}

void loop(){

 button.Update();
  
 if(button.JustPressed())
   SSD.Display(toggler.Next(1));
}

