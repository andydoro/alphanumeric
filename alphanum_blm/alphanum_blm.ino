/*
   displays some names in order
*/
#include <avr/pgmspace.h>
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Alphanum32.h"

#include "list.h"

// how long is the slogan list?
#define ARRAYLENGTH 113

#define NUMCHARS 32
//#define NUMALPHAS 8

// use physical processes to make pseudorandom more pseudorandom
//#define RANDOMPIN 0

#define COUNTERLIMIT 300

#define STARTUPCOUNTER 55

int counter = 0;

int whichName = 0;

// how fast the letters flip
#define FLIPUPDELAY 7

#define DAYBRIGHTNESS 15

// makes them all clear

char tempString[NUMCHARS + 1] = {' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' '
                                };


char theTruism[NUMCHARS + 1];

Alphanum32 myAlphanum;


void setup() {
  // put your setup code here, to run once:

  //Serial.begin(115200);

  //make it more pseudorandom!
  //randomSeed(analogRead(RANDOMPIN));

  // initialize all NUMALPHAS and clear
  myAlphanum.begin();
  myAlphanum.clear();
  myAlphanum.brightness(DAYBRIGHTNESS);
  myAlphanum.write();


  // display each LED segment - check for bad connections
  myAlphanum.displayAllSegs(20);

  delay(1000);

  myAlphanum.displayAllChars(20);

  delay(500);

  strcpy(theTruism, PSTR("       BLACK LIVES MATTER       "));

  for (uint8_t i = 0; i < STARTUPCOUNTER; i++) { // enough cycles to get there
    morphStrings();
    setChars();
    myAlphanum.write();
    delay(FLIPUPDELAY);
  }
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (counter > COUNTERLIMIT) {
    strcpy_P(theTruism, (char*)pgm_read_word(&(truisms[whichName])));

    // alternate justification
    if (whichName % 2 == 0) {
      rightJustify();
    } else {
      leftJustify();
    }
    whichName++; // go to next one
    if (whichName >= ARRAYLENGTH) {
      whichName = 0;
    }
    counter = 0;
  }

  morphStrings();

  setChars();

  myAlphanum.write();

  counter++;

  delay(FLIPUPDELAY);

}
