
/*******************************************************************
 * 
 * Written by Mithi Sevilla | Nov 30, 2015 | http://mithi.xyz
 * 
 *******************************************************************/
 
#include <Arduino.h>

/****************************************
 * CONSTANTS FOR SEVEN SEGMENT DISPLAY
 ****************************************/

const byte OFF = 11;
const byte DOT = 10;
const bool COMMONCATHODE = HIGH;
const bool COMMONANODE = LOW;

const bool NUMBER[12][8]= {
    {0,1,1,1,1,1,1,0},
    {0,0,0,1,0,0,1,0},
    {1,0,1,1,1,1,0,0},
    {1,0,1,1,0,1,1,0},
    {1,1,0,1,0,0,1,0},
    {1,1,1,0,0,1,1,0},
    {1,1,1,0,1,1,1,0},
    {0,0,1,1,0,0,1,0},
    {1,1,1,1,1,1,1,0},
    {1,1,1,1,0,1,1,0},
    {0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
};

/****************************************
 * CONSTANTS FOR SEQUENCE STATE UPDATER
 ****************************************/

const byte STAIRSUP = 0;
const byte STAIRSDOWN = 1;
const byte STAIRS = 2;
const byte WALKSUP = 3;
const byte WALKSDOWN = 4;
const byte WALKS = 5;
const byte STOP = 6;

/****************************************
 * CONSTANTS FOR SWEEPER
 ****************************************/

const bool BACKANDFORTH = 0;
const bool NORMAL = 1;
const bool FORWARD = 0;
const bool REVERSE = 1;

/****************************************
 * CONSTANTS FOR RGB
 ****************************************/

const byte RED = 0;         //200 
const byte ORANGE = 1;      //210 
const byte YELLOW = 2;      //220 
const byte GREEN = 3;       //020
const byte BLUE = 4;        //002
const byte PURPLE = 5;      //202 
const byte PINK = 6;        //201 
const byte AQUA = 7;        //021
const byte WHITE = 8;       //222 
const byte LIME = 9;        //120
const byte INDIGO = 10;     //102 
const byte TEAL = 11;       //012
const byte TURQUOISE = 12;  //022
