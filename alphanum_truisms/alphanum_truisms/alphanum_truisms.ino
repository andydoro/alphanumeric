/*
   displays some slogans / truisms randomly

   from Truisms by Jenny Holzer 1978-87
*/
#include <avr/pgmspace.h>
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#include "truisms.h"

// how long is the slogan list?
#define ARRAYLENGTH 42

#define NUMCHARS 32
#define NUMALPHAS 8

// use physical processes to make pseudorandom more pseudorandom
#define RANDOMPIN 0

#define COUNTERLIMIT 400


int counter = 0;

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

Adafruit_AlphaNum4 alpha[NUMALPHAS];


void setup() {
  // put your setup code here, to run once:

  delay(1000);

  Serial.begin(15200);

  //make it more pseudorandom!
  randomSeed(analogRead(RANDOMPIN));


  // initialize all NUMALPHAS and clear
  for (uint8_t i = 0; i < NUMALPHAS; i++) {
    alpha[i].begin(0x70 + i); // pass in the addresses
    alpha[i].clear();
    alpha[i].setBrightness(DAYBRIGHTNESS); // quarter brightness
    alpha[i].writeDisplay();
  }

  // display each LED segment - check for bad connections

  displayAllSegs();

  displayAllChars();

  delay(500);

  strcpy(theTruism, PSTR("TRUISMS BY JENNY HOLZER 1978-87 "));

  for (uint8_t i = 0; i < 70; i++) { // enough cycles to get there
    morphStrings();

    setChars();

    writeDisplays();

    //Serial.println("write displays");
    delay(FLIPUPDELAY);
  }
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:

  // choose random truism every so often

  if (counter > COUNTERLIMIT) {
    strcpy_P(theTruism, (char*)pgm_read_word(&(truisms[int(random(ARRAYLENGTH))])));
    // add blanks to end of truism
    int blanks = 32 - strlen(theTruism);
    memmove(theTruism + blanks, theTruism, strlen(theTruism));
    for (int i = 0; i < blanks; i++) {
      theTruism[i] = ' ';
    }
    counter = 0;
  }

  morphStrings();

  setChars();

  writeDisplays();

  counter++;

  delay(FLIPUPDELAY);


}
