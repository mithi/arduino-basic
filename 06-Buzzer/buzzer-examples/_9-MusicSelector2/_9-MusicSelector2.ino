
const byte c = 0;
const byte d = 1;
const byte e = 2;
const byte f = 3;
const byte g = 4;
const byte a = 5;
const byte b = 6;
const byte C = 7;

int half_period[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

struct melody{
  byte length;
  int tempo;
  byte notes[20];
  byte beats[20];
};

class Piezo{
  byte _pin;
  
  public:
    Piezo(byte pin){
      _pin = pin;
      pinMode(_pin, OUTPUT);
    }
    
    void set(bool state, int d){
      digitalWrite(_pin, state);
      delayMicroseconds(d);
    }
    
    void play(int note, byte beat, int tempo) {
      
      int duration = beat*tempo;
      int period = half_period[note]; 

      for (long i = 0; i < duration * 1000L; i += period * 2) {
        set(HIGH, period);
        set(LOW, period);
      }
      delay(duration);
    }
};


struct melody twinkle{
 14, 250,
 {c, c, g, g, a, a, g, f, f, e, e, d, d, c},
 {1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2}
};

struct melody birthday{
 12, 150,
 {c, c, d, c, f, e, c, c, d, c, g, f},
 {1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2}
};

struct melody comic{
  7, 100,
 {C, g, g, a, g, b, C},
 {2, 1, 1, 2, 4, 2, 2} 
};

Piezo piezo(13);

void playTune(struct melody *tune){
  for (int i = 0; i < tune->length; i++) 
    piezo.play(tune->notes[i], tune->beats[i], tune->tempo);
}

void setup() {
}

void loop() {
  playTune(&comic);
  delay(1000);
  playTune(&twinkle);
  delay(1000);
  playTune(&birthday);
  delay(1000);
}
