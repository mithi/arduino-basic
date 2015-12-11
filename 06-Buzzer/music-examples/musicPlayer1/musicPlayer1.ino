#include "SimpleLibrary.h"
#include "Tunes.h"


Buzzer buzzer;

void setup() {
  buzzer.Format(13, 1.5, 1000);
}

void loop() {
  
  playImperialMarch();
  playGameOfThrones();
  playMusic(superMarioTune, superMarioTuneTempo, superMarioTuneSize);
  playMusic(underworldTune, underworldTuneTempo, underworldTuneSize);
  playMusic(starSpangledBannerTune, starSpangledBannerTuneTempo, starSpangledBannerTuneSize);

}

void playMusic(int tune[], byte tempo[], int tuneSize){
  for(int note = 0; note < tuneSize; note++)
    buzzer.PlayNote(tune[note], float(tempo[note]));
}

void playMusicFloat(int tune[], float tempo[], int tuneSize){
  for(int note = 0; note < tuneSize; note++)
    buzzer.PlayNote(tune[note], tempo[note]);
}

void playMusicFade(int tune[], int period[], int tuneSize){
  for(int note = 0; note < tuneSize; note++)
    buzzer.Play(tune[note], period[note], period[note]+25);
}

void playImperialMarch(){
  
  playMusicFloat(firstTuneA, tuneTempo1, tuneSize);
  playMusicFloat(firstTuneB, tuneTempo1, tuneSize);

  playMusicFloat(secondTuneA, tuneTempo2A, tuneSize);
  playMusicFloat(secondTuneB, tuneTempo2B, tuneSize);

  playMusicFloat(variantTune1, variantTuneTempo, tuneSize);

  playMusicFloat(secondTuneA, tuneTempo2A, tuneSize);
  playMusicFloat(secondTuneB, tuneTempo2B, tuneSize);

  playMusicFloat(variantTune2, variantTuneTempo, tuneSize);
}

void GOTBackTune14x(){
  for(int x=0; x<4; x++)
    playMusicFade(backTune1, backTune1Period, backTuneSize);
}

void GOTBackTune24x(){
  for(int x=0; x<4; x++)
    playMusicFade(backTune2, backTune2Period, backTuneSize);
}
void playGameOfThrones(){
  GOTBackTune14x();
  playMusicFade(tune1, tunePeriod, GOTTuneSize);
  GOTBackTune14x();
  playMusicFade(tune2, tunePeriod, GOTTuneSize);
  GOTBackTune14x();
  playMusicFade(tune3, tunePeriod, GOTTuneSize);
  GOTBackTune14x();
  playMusicFade(tune4, tunePeriod, GOTTuneSize);
  GOTBackTune14x();
  playMusicFade(tuneX, tunePeriodX, tuneXSize);
  GOTBackTune24x();
}
