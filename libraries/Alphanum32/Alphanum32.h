#ifndef ALPHANUM32
#define ALPHANUM32

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

class Alphanum32 
{
public:
    Alphanum32();
    Adafruit_AlphaNum4 alpha[8];
    
    void begin();
    void clear();
    void brightness(uint8_t b);
    void write();
    void writeDigitAscii(uint8_t i, uint8_t c, bool dot = false);
    void displayAllSegs(uint8_t d);
    void displayAllChars(uint8_t d);


//private:
	//const uint8_t NUMCHARS = 32;
	//const uint8_t NUMALPHAS = 8;
};

#endif