
const int pin[6] = {11, 10, 9, 6, 5, 3};
int del = 250; 

void setup() {
  initializePins();  
}

void loop() {
  walkLEDs();
}

void walkLEDs(){
  for (int x = 0; x < 6; x++){
    offLeds();
    ledOn(x);
  }
}

void ledOn(int x){
  analogWrite(pin[x], 150); 
  delay(del);
}

void initializePins(){
  for (int x = 0; x < 6; x++)
    pinMode(pin[x], OUTPUT);
}

void offLeds(){
  for (int x = 0; x < 6; x++)
    analogWrite(pin[x], 0);
}


