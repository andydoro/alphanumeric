/*

*/

#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Alphanum32.h"


Alphanum32::Alphanum32()
{

}

void Alphanum32::begin()
{
  for (uint8_t i = 0; i < 8; i++) {
    alpha[i].begin(0x70 + i); // pass in the addresses
  }
}

void Alphanum32::clear()
{
  for (uint8_t i = 0; i < 8; i++) {
    alpha[i].clear();
  }
}

void Alphanum32::brightness(uint8_t b)
{
  for (uint8_t i = 0; i < 8; i++) {
    alpha[i].setBrightness(b);
  }
}

void Alphanum32::write()
{
  for (uint8_t i = 0; i < 8; i++) {
    alpha[i].writeDisplay();
  }
}

void Alphanum32::writeDigitAscii(uint8_t i, char c)
{
  alpha[i / 4].writeDigitAscii((i % 4), c);
}

void Alphanum32::displayAllSegs(uint8_t d)
{
  for (uint8_t i = 0; i < 32; i++) {
    alpha[i / 4].writeDigitRaw(i % 4, 0x7FFF);
    Alphanum32::write();
    delay(d);
  }
}

void Alphanum32::displayAllChars(uint8_t d)
{
  for (uint8_t i = '!'; i <= '~'; i++) {
    for (uint8_t j = 0; j < 32; j++) {
      uint8_t l = i + j;
      // create blanks when characters go past '~'
      if (l >= '~') l = ' ';
      alpha[j / 4].writeDigitAscii(j % 4, l);
    }
    Alphanum32::write();
    delay(d);
  }
}


