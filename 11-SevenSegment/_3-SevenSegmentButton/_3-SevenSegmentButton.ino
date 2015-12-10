
#include "SimpleLibrary.h"

Sweeper toggler;
SevenSegment SSD;
Button button;

int pins[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void setup(){
  
  toggler.Format(0, 9, 1, NORMAL);
  SSD.Format(pins, COMMONANODE); 
  button.Format(8, 50);
}

void loop(){
    
 if(button.JustPressed())
   SSD.Display(toggler.Next(1));
}

