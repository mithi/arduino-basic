
#include "SimpleLibrary.h"

const int numberOfLeds = 6;
const int numberOfButtons = 4;

DigitalLED led[numberOfLeds];
Button button[numberOfButtons]; 
int ledPin[numberOfLeds] = {11,10,9,6,5,3};
int buttonPin[numberOfButtons] = {0, 1, 2, 4};

TimingManager ledsTiming;
Sweeper sweeper;

void setup() {
  initializeObjects();
}

void loop() {

  updateButtons();

  button[0].Pressed() ? led[0].TurnOn() : led[0].TurnOff();
  
  if(button[1].JustReleased())
    led[1].Toggle();

  if(button[2].JustPressed())
    led[2].Toggle();

  if(button[3].JustPressed()){ 
    doLEDSequence();
  }
}

void doLEDSequence(){
  while(button[3].Pressed()){ //all other buttons are disabled unless button[3] is released
    int x = sweeper.Update(ledsTiming.IsTimeToUpdate());
    ledsOff();
    led[x].TurnOn();
    button[3].Update();
  }
}

void updateButtons(){
  for(int x=0; x<numberOfButtons; x++)
    button[x].Update();  
}

void ledsOff(){
  for(int x=0; x<numberOfLeds; x++)
    led[x].TurnOff(); 
}

void initializeObjects(){
  
  for(int x=0; x<numberOfButtons; x++)
    button[x].New(buttonPin[x], 50);

  for(int x=0; x<numberOfLeds; x++)
    led[x].New(ledPin[x]);  

  ledsTiming.New(50);
  sweeper.New(0,numberOfLeds-1, BACKANDFORTH);
}

