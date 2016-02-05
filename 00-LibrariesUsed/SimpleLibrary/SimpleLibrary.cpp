
/*******************************************************************
 * 
 * Written by Mithi Sevilla | Nov 30, 2015 | http://mithi.xyz
 * 
 *******************************************************************/

#include "SimpleLibrary.h"

/**********************************
 * DIGITAL OUTPUT
 **********************************/

void DigitalOutput::Format(int p){
  _pin = p;
  pinMode(_pin, OUTPUT);
  Set(LOW);
}

void DigitalOutput::Set(bool s){
  digitalWrite(_pin, s);
  _state = s;   
}

void DigitalOutput::On(){
  Set(HIGH);
}

void DigitalOutput::Off(){
  Set(LOW);
}

void DigitalOutput::Toggle(){
  Set(!_state);
}

bool DigitalOutput::State(){
  return _state;
}

/**********************************
 * ANALOG  OUTPUT
 **********************************/

void AnalogOutput::Format(int p){
  _pin = p;
  _state = 0;
  pinMode(_pin, OUTPUT);
  Set(_state);
}

void AnalogOutput::Set(int b){
  analogWrite(_pin, b);
}

int AnalogOutput::State(){
  return _state;
}

/**********************************
 * ANALOG INPUT!
 **********************************/

void AnalogInput::Format(int p){
  _pin = p; 
  pinMode(_pin, INPUT);
}

int AnalogInput::RawValue(){
  return analogRead(_pin);
}

int AnalogInput::MappedValue(int mn, int mx){
  return map(RawValue(), 0, 1023, mn, mx);
}

/**********************************
 * RGB
 **********************************/

void RGB::Format(int r, int g, int b){
  _redPin = r;
  _greenPin = g;
  _bluePin = b;
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void RGB::Red(int brightness){
  analogWrite(_redPin, brightness);
}

void RGB::Green(int brightness){
  analogWrite(_greenPin, brightness);
}

void RGB::Blue(int brightness){
  analogWrite(_bluePin, brightness);
}

void RGB::ColorRaw(int r, int g, int b){
  Red(r);
  Green(g);
  Blue(b);
}

void RGB::Color(byte c){
  
  // red, orange, yellow, green, blue, purple, pink, aqua, white, lime, indigo, teal, turquoise
  int numberOfColors = 13;
  int  h = 100; 
  
  int red[] =   {255,255, 255,   0,   0, 255, 255,   0, 255,   h,   h,   0,   0};
  int green[] = {0,    h, 255, 255, 255,   0,   0, 255, 255, 255,   0,   h, 255};
  int blue[] =  {0,    0,   0,   0, 255, 255,   h,   h, 255,   0, 255, 255, 255};
  
  if(c < numberOfColors)
    ColorRaw(red[c], green[c], blue[c]);
}

/**********************************
 * DIGITAL SENSOR  
 **********************************/

void DigitalSensor::Format(int p, int m, bool i){
  _state = LOW;
  _pin = p;
  _mode = m;
  _inverted = i;
  pinMode(_pin, _mode);
}

int DigitalSensor::Pin(){
  return _pin;
}

bool DigitalSensor::Value(){
  return digitalRead(_pin);
}

bool DigitalSensor::State(){
  return !_inverted ? Value() : !Value();
}

/**********************************
 * ANALOG SENSOR 
 **********************************/

void AnalogSensor::Format(int p, int m, int t, bool i, float cm, float cb){
  _inverted = i;
  _state = 0;
  _pin = p;
  _mode = m;
  _threshold = constrain(t, 0, 1023);
  _M = cm;
  _B = cb;
  pinMode(_pin, _mode);
}

float AnalogSensor::ProcessedValue(){
  return _M*RawValue() + _B;
}

bool AnalogSensor::IsTrue(){
  bool value;
  RawValue() > _threshold ? value = HIGH : value = LOW;
  return !_inverted ? value : !value;
}

int AnalogSensor::RawValue(){
  return analogRead(_pin);
}
  
int AnalogSensor::MappedRawValue(int mn, int mx){
  return map(RawValue(), 0, 1023, mn, mx);
}

/**********************************
 * BUZZER
 **********************************/

void Buzzer::Format(int p, int ps, int wnp){
    _pin = p;
    _pauseScale = ps;
    _wholeNotePeriod = wnp;
    pinMode(_pin, OUTPUT);
}

void Buzzer::PlayNote(int pitch, float duration){
  float sp = SoundPeriod(duration);
  tone(_pin, pitch, sp);
  Pause(sp);
}

void Buzzer::Play(int pitch, float period, int d){
  tone(_pin, pitch, period);
  delay(d);
}

float Buzzer::SoundPeriod(float sp){
  return _wholeNotePeriod/sp;
}

float Buzzer::PausePeriod(float sp){
  return sp*_pauseScale;
}

void Buzzer::Pause(float sp){
  delay(PausePeriod(sp));
  noTone(_pin);
}

/**********************************
 * BUTTON
 **********************************/

void Button::Format(int p, int dd){
  _pin = p;
  _debounceDelay = dd;
  pinMode(_pin, INPUT_PULLUP);
}

void Button::_NextState(){
  if(millis() - _lastDebounceTime > _debounceDelay)
    _reading != _buttonState ? _Changed() : _NoChange();
}

void Button::_Changed(){
  _buttonState = _reading;
  _hasChanged = HIGH;
  _buttonState == LOW? _justPressed = HIGH : _justReleased = HIGH;
}

void Button::_NoChange(){
  _hasChanged = LOW;
  _justPressed = LOW;
  _justReleased = LOW;
}

void Button::_UpdateLastDebounceTime(){
  if(_reading != _lastButtonState){
    _lastDebounceTime = millis();
  }
}

void Button::Update(){
  _reading = digitalRead(_pin);
  _UpdateLastDebounceTime();
  _NextState();
  _lastButtonState = _reading;
}

bool Button::HasChanged(){
  Update();
  return _hasChanged;
}

bool Button::JustReleased(){
  Update();
  return _justReleased;
}

bool Button::JustPressed(){
  Update();
  return _justPressed;
}

bool Button::Pressed(){
  Update();
  return _buttonState? LOW : HIGH;  
}

/**********************************
 * SEVEN SEGMENT DISPLAY
 **********************************/

void SevenSegment::Format(int p[], int c){
  _isCommonCathode = c;
  for(int i=0; i<8; i++){
    _pin[i] = p[i];
    pinMode(_pin[i], OUTPUT);
  }
  Display(OFF);
}

void SevenSegment::SetRaw(int n[]){
  for(int i=0; i<8; i++)
    _set(i, n[i]);
}

void SevenSegment::Display(byte n){
  for(int i=0; i<8; i++)
    _set(i, NUMBER[n][i]);
}

void SevenSegment::_set(int p, byte n){
    _isCommonCathode ? digitalWrite(_pin[p], n) : digitalWrite(_pin[p], !n);
}

/**********************************
 * SWEEPER
 **********************************/

void Sweeper::Format(int s, int e, int st, byte x) {

  if (s < e) {
    _dir = FORWARD;
    _start = s;
    _end = e;
    _state = s - st;
  } else {
    _dir = REVERSE;
    _start = e;
    _end = s;
    _state = s + st;
  }
  _sweepsMade = 0;
  _step = st;
  _type = x;
}

int Sweeper::Next(bool itIsTime) {

  if (itIsTime) {

    if(_type == NORMAL) {
      _dir == FORWARD ? _forward() : _reverse(); 
    } else {
      _dir == FORWARD ? _backAndForthForward() : _backAndForthReverse();
    }
  }

  return _state;
}

unsigned long Sweeper::SweepsMade(){
  return _type == NORMAL ? _sweepsMade : _sweepsMade / 2;
}

void Sweeper::SetDirection(bool d){
  _dir = d;
}

void Sweeper::ToggleDirection(){
  _dir = !_dir;
}

void Sweeper::_forward() {
  _state += _step;
  if (_state > _end) {
    _state = _start;
    _sweepsMade++;
  }
}

void Sweeper::_reverse() {
  _state -= _step;
  if (_state < _start) {
    _state = _end;
    _sweepsMade++;
  }
}

void Sweeper::_backAndForthForward(){

  if (_state < _end) {
    _state += _step;

  } else {
    _dir = REVERSE;
    _state -= _step;
    _sweepsMade++;
  }
}

void Sweeper::_backAndForthReverse(){

  if (_state > _start) {
    _state -= _step;
  } else {
    _dir = FORWARD;
    _state += _step;
    _sweepsMade++;
  }
}


/*****************************************************
 *  METRONOME
 *****************************************************/

void Metronome::Format(unsigned long t){
  _interval= t;
  _previousTime = millis();
  _currentTime = millis();
}

void Metronome::SetInterval(unsigned long t){
  _interval= t;
}

bool Metronome::Tick(){
  _currentTime = millis();
  bool _answer = _currentTime - _previousTime >= _interval;
  if(_answer)
    _previousTime = _currentTime;
  return _answer;
}

/*****************************************************
 *  SEQUENCER
 *****************************************************/

void Sequencer::Format(LedsManager* LM){
  _state = 0;
  _type = 0;
  ledsManager = LM;
}

void Sequencer::Update(bool itsTime){
  if(itsTime)
    _selectSequence();
}

void Sequencer::Start(byte t){
  _state = 0;
  _type = t; 
}

void Sequencer::_selectSequence(){
  switch(_type){
    case STAIRSUP:
      _state = ledsManager->StairsUp(_state);
      break;
    case STAIRSDOWN:
      _state = ledsManager->StairsDown(_state);
      break;
    case STAIRS:
      _state = ledsManager->Stairs(_state);
      break;
    case WALKSUP:
      _state = ledsManager->WalksUp(_state);
      break;
    case WALKSDOWN:
      _state = ledsManager->WalksDown(_state);
      break;
    case WALKS:
      _state = ledsManager->Walks(_state);
      break; 
    default:
     ledsManager->AllLeds(0);
     break;    
  } 
}

/*****************************************************
 *  LEDS MANAGER
 *****************************************************/

void LedsManager::Format(int p[]){
  _brightness = 255;
  for(int x=0; x<6; x++){
    _pin[x] = p[x];
    pinMode(_pin[x], OUTPUT);
  } 
}

void LedsManager::SetBrightness(int b){
  _brightness = b;
}

byte LedsManager::_nextState(byte state, byte numberOfStates){
  state++;
  return state >= numberOfStates ? 0 : state;
}
void LedsManager::AllLeds(int b){
  for(int x=0; x<6; x++)
    _led(x, b);
}

void LedsManager::_singleLed(int p){
  AllLeds(0);                     
  _led(p, _brightness);  
}

void LedsManager::_led(int p, int brightness){
  analogWrite(_pin[p], brightness);
}
  
byte LedsManager::WalksUp(byte state){
  int p[12] = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5};
  _singleLed(p[state]);
  return _nextState(state, 12);
}

byte LedsManager::WalksDown(byte state){
  int p[12] = {5, 4, 3, 2, 1, 0, 5, 4, 3, 2, 1, 0};
  _singleLed(p[state]);
  return _nextState(state, 12);
}

byte LedsManager::Walks(byte state){
  int p[12] = {0, 1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 0};
  _singleLed(p[state]);
  return _nextState(state, 12);
}

byte LedsManager::StairsUp(byte state){
  _stairsHelper(0, state);                       //0-stairsUp, 1-stairsDown
  return _nextState(state, 14);
}

byte LedsManager::StairsDown(byte state){
  _stairsHelper(1, state);                      //0-stairsUp, 1-stairsDown
  return _nextState(state, 14);
}

byte LedsManager::Stairs(byte state){
  state >= 7 ? StairsDown(state) : StairsUp(state);
  return _nextState(state, 14);

}

void LedsManager::_stairsHelper(byte maxxer, byte state){
  
  byte y; 
  byte cutOff;

  AllLeds(0);

  state >= 7 ? y = state - 7 : y = state;   
  maxxer == 1 ? cutOff = 6 - y : cutOff = y; 
  
  for (byte x=0; x<cutOff; x++)
    _led(x, _brightness);
}

