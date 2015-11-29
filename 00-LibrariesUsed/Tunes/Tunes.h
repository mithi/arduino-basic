
#include "Pitches.h"

/*******************************
 *  SUPER MARIO TUNE
 *******************************/

int superMarioTune[] = { 
  NOTE_E7, NOTE_E7, 0, NOTE_E7, 0, NOTE_C7, NOTE_E7, 0, NOTE_G7, 0, 0,  0, NOTE_G6, 0, 0, 0, 
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, 
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0,
  NOTE_C7, 0, 0, NOTE_G6, 0, 0, NOTE_E6, 0, 0, NOTE_A6, 0, NOTE_B6, 0, NOTE_AS6, NOTE_A6, 0, 
  NOTE_G6, NOTE_E7, NOTE_G7, NOTE_A7, 0, NOTE_F7, NOTE_G7, 0, NOTE_E7, 0,NOTE_C7, NOTE_D7, NOTE_B6, 0, 0
};

int superMarioTuneTempo[] = {
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,12, 12, 12, 12, 
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 
  9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
  9, 9, 9, 12, 12, 12, 12, 12, 12, 12, 12,12, 12, 12, 12,
};

int superMarioTuneSize = sizeof(superMarioTune) / sizeof(int);

/*******************************
 *  UNDERWORLD TUNE
 *******************************/

int underworldTune[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0, NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4, NOTE_AS3, NOTE_AS4, 0, 0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0, 0, NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4, NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4, NOTE_CS4, NOTE_DS4, NOTE_DS4, NOTE_GS3, NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4,NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4, NOTE_GS4, NOTE_DS4, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_GS3, 0, 0, 0
};

int underworldTuneTempo[] = { 
  12, 12, 12, 12,  12, 12, 6, 3, 12, 12, 12, 12,  12, 12, 6, 3, 12, 12, 12, 12, 12, 12, 6,3,
  12, 12, 12, 12, 12, 12, 6, 6, 18, 18, 18, 6, 6, 6, 6, 6, 6, 18, 18, 18, 18, 18, 18,
  10, 10, 10, 10, 10, 10, 3, 3, 3
};

int underworldTuneSize = sizeof(underworldTune) / sizeof(int);

int starSpangledBannerTune[] = {
  NOTE_F5,NOTE_D5,NOTE_AS4,NOTE_D5,NOTE_F5,NOTE_AS5,NOTE_D6,NOTE_C6,NOTE_AS5,NOTE_D5,NOTE_E5,NOTE_F5,
  NOTE_F5,NOTE_F5,NOTE_D6,NOTE_C6,NOTE_AS5,NOTE_A5,NOTE_G5,NOTE_A5,NOTE_AS5,NOTE_AS5,NOTE_F5,NOTE_D5,NOTE_AS4,
  NOTE_D6,NOTE_D6,NOTE_D6,NOTE_DS6,NOTE_F6,NOTE_F6,NOTE_DS6,NOTE_D6,NOTE_C6,NOTE_D6,NOTE_DS6,NOTE_DS6,
  0,NOTE_DS6,NOTE_D6,NOTE_C6,NOTE_AS5,NOTE_A5,NOTE_G5,NOTE_A5,NOTE_AS5,NOTE_D5,NOTE_E5,NOTE_F5,
  NOTE_F5,NOTE_AS5,NOTE_AS5,NOTE_AS5,NOTE_A5,NOTE_G5,NOTE_G5,NOTE_G5,NOTE_C6,NOTE_DS6,NOTE_D6,NOTE_C6,NOTE_AS5,NOTE_AS5,NOTE_A5,
  NOTE_F5,NOTE_F5,NOTE_AS5,NOTE_C6,NOTE_D6,NOTE_DS6,NOTE_F6,NOTE_AS5,NOTE_C6,NOTE_D6,NOTE_DS6,NOTE_C6,NOTE_AS5
};

/*******************************
 *  STAR-SPANGLED BANNER
 *******************************/

float starSpangledBannerTuneTempo[] = {
  6,12,4,4,4,2,6,12,4,4,4,2, 8,8,8/2.9,8,4,2,8,8,4,4,4,4,4,6,12,4,4,4,2,8,8,4,4,4,2,
  8,8,8/2.9,8,4,2,8,8,4,4,4,2, 4,4,4,8,8,4,4,4,4,8,8,8,8,4,4, 8,8,8/2.9,8,8,8,2,8,8,4,4,4,2
};

int starSpangledBannerTuneSize=sizeof(starSpangledBannerTune)/sizeof(int);


/*******************************
 *  STARWARS IMPERIAL MARCH
 *******************************/

int firstTuneA[] = {NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, 0 };
int firstTuneB[] = {NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5, NOTE_GS4, NOTE_F4, NOTE_C5, NOTE_A4, 0};
int secondTuneA[] = {NOTE_A5, NOTE_A4, NOTE_A4, NOTE_A5, NOTE_GS5, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_FS5, 0};
int secondTuneB[] = {455, NOTE_DS5, NOTE_D5, NOTE_CS5, NOTE_C5, 466, NOTE_C5, 0, 0, 0};
int variantTune1[] = {NOTE_F4, NOTE_GS4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_C5, NOTE_E5, 0, 0};
int variantTune2[] = {NOTE_F4, NOTE_GS4, NOTE_F4,NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, 0, 0};
float tuneTempo1[] = {2, 2, 2, 3, 8, 2, 3, 8, 3/2, 4};
float tuneTempo2A[] = {2, 3, 8, 2, 3, 16/3, 8, 8, 4, 4};
float tuneTempo2B[] = {4, 2, 3, 16/3, 8, 8, 4, 3, 1000, 1000};
float variantTuneTempo[] = {4, 2, 3, 8, 2, 8/3.0, 8, 3/2, 2, 1000};

int tuneSize  = 10;

/*******************************
 *  GAME OF THRONES 
 *******************************/

int backTune1[] = {NOTE_C3, NOTE_DS3, NOTE_F3, NOTE_G3};
int backTune1Period[] = {375, 175, 175, 375};
int tune1[] = {NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4};
int tune2[] = {NOTE_F4, NOTE_AS4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_AS3, NOTE_DS4, NOTE_D4};
int tune3[] = {NOTE_G5, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4};
int tune4[] = {NOTE_G5, NOTE_C5, NOTE_DS5, NOTE_F5, NOTE_G5, NOTE_C5, NOTE_DS5, NOTE_F5};
int tuneX[] = {NOTE_F5, NOTE_AS4, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_AS4};
int backTune2[] = {NOTE_C5, NOTE_DS3, NOTE_F3, NOTE_G3};
int tunePeriod[] = {1175, 1175, 175, 175, 775, 775, 175, 175};
int tunePeriodX[] = {1175, 1175, 575, 575, 575, 575};
int backTune2Period[] = {375, 175, 175, 375};
int backTuneSize = 4;
int GOTTuneSize = 8;
int tuneXSize = 6;


