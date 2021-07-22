/*
  basic example for Alphanum32 library
*/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Alphanum32.h"

const char helloWorld[33] PROGMEM = "hello world          HELLO WORLD";

const char pangram1[33] PROGMEM = "PACKMYBOXWITHFIVEDOZENLIQUORJUGS";
const char pangram2[33] PROGMEM = "HOW VEXINGLYQUICK DAFTZEBRASJUMP";
const char pangram3[33] PROGMEM = "SPHINX OFBLACK QUARTZ JUDGEMYVOW";
const char pangram4[33] PROGMEM = "THEFIVEBOXINGWIZARDS JUMPQUICKLY";


Alphanum32 myAlphanum;

const int DELAYTIME = 2000;

void setup() {
  // put your setup code here, to run once:

  delay(1000);

  Serial.begin(115200);

  // initialize all NUMALPHAS and clear
  myAlphanum.begin();
  myAlphanum.clear();
  myAlphanum.brightness(15); // max brightness
  myAlphanum.write();

  // display each LED segment - check for bad connections
  myAlphanum.displayAllSegs(20);
  delay(1000);

  // display all ASCII chars
  myAlphanum.displayAllChars(20);
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (uint8_t i = 0; i < 32; i++) {
    myAlphanum.writeDigitAscii(i, helloWorld[i]);
  }
  myAlphanum.write();
  delay(DELAYTIME);

  myAlphanum.clear();
  myAlphanum.write();
  delay(500);

  for (uint8_t i = 0; i < 32; i++) {
    myAlphanum.writeDigitAscii(i, pangram1[i]);
  }
  myAlphanum.write();
  delay(DELAYTIME);

  myAlphanum.clear();
  myAlphanum.write();
  delay(500);


  for (uint8_t i = 0; i < 32; i++) {
    myAlphanum.writeDigitAscii(i, pangram2[i]);
  }
  myAlphanum.write();
  delay(DELAYTIME);

  myAlphanum.clear();
  myAlphanum.write();
  delay(500);


  for (uint8_t i = 0; i < 32; i++) {
    myAlphanum.writeDigitAscii(i, pangram3[i]);
  }
  myAlphanum.write();
  delay(DELAYTIME);

  myAlphanum.clear();
  myAlphanum.write();
  delay(500);



  for (uint8_t i = 0; i < 32; i++) {
    myAlphanum.writeDigitAscii(i, pangram4[i]);
  }
  myAlphanum.write();
  delay(DELAYTIME);

  myAlphanum.clear();
  myAlphanum.write();
  delay(500);

}
