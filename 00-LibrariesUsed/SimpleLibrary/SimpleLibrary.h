
/*******************************************************************
 * 
 * Written by Mithi Sevilla | Nov 30, 2015 | http://mithi.xyz
 * 
 *******************************************************************/

#include "SimpleLibraryConstants.h"

class DigitalOutput{
  int _pin;
  bool _state; 
  public:
  void New(int p);
  void Set(bool s);
  void On();
  void Off();
  void Toggle();
  bool State();
};

class AnalogOutput{
  int _pin;
  int _state;
  public:
  void New(int p);
  void Set(int b);
  int State();
};

class AnalogInput{
  int _pin;
  public:
  void New(int p);
  int RawValue();
  int MappedValue(int mn, int mx);
};

class RGB{
  int _redPin;
  int _greenPin;
  int _bluePin;
  public:
  void New(int r, int g, int b);
  void Red(int r);
  void Green(int g);
  void Blue(int b);
  void ColorRaw(int r, int g, int b);
  void Color(byte c);
};

class DigitalSensor{
  bool _state;
  bool _inverted;
  int _pin; 
  int _mode;
  public:
  void New(int p, int m, bool i);
  int Pin();
  bool Value();
  bool State();
};

class AnalogSensor{
  bool _inverted;
  bool _state;
  int _pin;
  int _mode;
  int _threshold;
  float _coefficientM;
  float _coefficientB;
  public:
  void New(int p, int m, int t, bool i, float cm, float cb);
  void NewLinearCoefficient(float cm, float cb);
  void NewThreshold(int t, bool i);
  bool IsTrue();
  float ProcessedValue();
  int RawValue();
  int MappedRawValue(int mn, int mx);
};

class Buzzer{
  int _wholeNotePeriod;
  int _pin;
  float _pauseScale;
  public:
  void New(int p, int ps, int wnp);
  void PlayNote(int pitch, float duration);
  void Play(int freq, float period, int d);
  void Pause(float sp);
  float SoundPeriod(float sp);
  float PausePeriod(float sp);
};

class Button{
  bool _lastButtonState = HIGH;
  bool _buttonState;             //LOW if PRESSED because INPUT_PULLUP 
  bool _hasChanged = 0;
  bool _justReleased = 0; 
  bool _justPressed = 0; 
  int _debounceDelay;
  int _reading;
  int _pin;
  int _lastDebounceTime = 0;
  
  public:
  void New(int p, int dd);
  void Update();
  bool Pressed();
  bool HasChanged();
  bool JustPressed();
  bool JustReleased();

  private: 
  void _UpdateLastDebounceTime();
  void _NextState();
  void _Changed();
  void _NoChange();
};

class SevenSegment{
  int _pin[8];
  bool _isCommonCathode; // commonCathode = commonGround
  public:
  void New(int p[], int c);
  void SetRaw(int n[]);
  void Display(byte n);
  private:
  void _set(int p, byte n);
};

class Sweeper{
  bool _dir;
  bool _type; 
  int _state;
  int _start;
  int _end;
  int _step;
  unsigned long _sweepsMade;
  public:
  void New(int s, int e, int st, byte x);
  int Next(bool itsTime);
  unsigned long SweepsMade();
  void ToggleDirection();
  void Direction(bool d);
  private:
  void _forward();
  void _reverse();
  void _backAndForth();
};

class Metronome{
  unsigned long _interval; 
  unsigned long _previousTime;
  unsigned long _currentTime;
  public:
  void New(unsigned long t);
  bool Tick();
  void NewInterval(unsigned long t);
};

class LedsManager{
  int _brightness;
  int _pin[6];
  int _count;
  public:
  void New(int p[]);
  void NewBrightness(int b);
  byte Walks(byte state);
  byte WalksUp(byte state);
  byte WalksDown(byte state);
  byte Stairs(byte state);
  byte StairsUp(byte state);
  byte StairsDown(byte state);
  void AllLeds(int b);
  private:
  void _stairsHelper(byte maxxer, byte state);
  void _led(int p, int b);
  void _singleLed(int p);
  byte _nextState(byte state, byte numberOfStates);
};

class Sequencer{
  byte _state;
  byte _type;
  LedsManager* ledsManager; 
  public:
  void New(LedsManager* LM);
  void Update(bool itIsTime);
  void Start(byte type);
  private:
  void _selectSequence();
};


