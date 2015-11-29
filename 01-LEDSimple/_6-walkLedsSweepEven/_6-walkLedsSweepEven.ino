
int maxBrightness = 200;
int DELAY = 500;

const int pin[6] = {11, 10, 9, 6, 5, 3};

void setup() {
  initializePins();  
}

void loop() {
  walkLEDs();
}

void walkLEDs(){
  for (int x = 0; x < 6; x++){
    offLeds();
    brightenLed(x);
  }
}

void brightenLed(int x){
  if(x % 2 == 0){
    blinkLed(x);
  }else{
    SweepUp(x, 5, 30);
    SweepDown(x, 5, 30);
  }
}

void initializePins(){
  for (int x = 0; x < 6; x ++)
    pinMode(pin[x], OUTPUT);
}

void offLeds(){
  for (int x = 0; x < 6; x ++)
    setLed(pin[x], 0, 0);
}

void blinkLed(int x){
  setLed(pin[x], maxBrightness, DELAY);
  setLed(pin[x], 0, DELAY);
}

void SweepUp(int x, int fadeAmount, int waitTime){
  for(int brightness = 0; brightness <= maxBrightness; brightness+=fadeAmount)
    setLed(pin[x], brightness, waitTime);
}

void SweepDown(int x, int fadeAmount, int waitTime){
  for(int brightness = maxBrightness; brightness >= 0; brightness-=fadeAmount)
    setLed(pin[x], brightness, waitTime);
}

void setLed(int p, int b, int d){
  analogWrite(p, b);
  delay(d);
}

