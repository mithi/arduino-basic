
#include "SimpleLibrary.h"

const int numberOfLeds = 6;
const int numberOfButtons = 4;

DigitalOutput led[numberOfLeds];
Button button[numberOfButtons]; 
int ledPin[numberOfLeds] = {11,10,9,6,5,3};
int buttonPin[numberOfButtons] = {0, 1, 2, 4};

Metronome metronome;
Sweeper sweeper;

void setup() {
  initializeObjects();
}

void loop() {

  button[0].Pressed() ? led[0].On() : led[0].Off();
  
  if(button[1].JustReleased())
    led[1].Toggle();

  if(button[2].JustPressed())
    led[2].Toggle();

  if(button[3].JustPressed())
    doLEDSequence();
}

void doLEDSequence(){
  while(button[3].Pressed()){ //all other buttons are disabled unless button[3] is released
    int x = sweeper.Next(metronome.Tick());
    ledsOff();
    led[x].On();
  }
  ledsOff();
}

void ledsOff(){
  for(int x=0; x<numberOfLeds; x++)
    led[x].Off(); 
}

void initializeObjects(){
  
  for(int x=0; x<numberOfButtons; x++)
    button[x].New(buttonPin[x], 50);

  for(int x=0; x<numberOfLeds; x++)
    led[x].New(ledPin[x]);  

  metronome.New(50);
  sweeper.New(0,numberOfLeds-1, 1, BACKANDFORTH);
}

