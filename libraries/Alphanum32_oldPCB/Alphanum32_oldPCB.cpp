/*

*/

#include "Arduino.h"
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Alphanum32_oldPCB.h"


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

uint8_t Alphanum32::_swapDigit(uint8_t charNum) 
{
  if (charNum < 2) {
    charNum += 2;
  } else {
    charNum -= 2;
  }
  return charNum;
}

 void Alphanum32::_oldPCBmap(uint8_t i)
 {
  _a = i / 4;
  _n = i % 4;
  if (i > 3) {
    _n = Alphanum32::_swapDigit(_n);
  } 
 }

void Alphanum32::writeDigitAscii(uint8_t i, uint8_t c, bool d)
{
  Alphanum32::_oldPCBmap(i);
  if (d) {
    alpha[_a].writeDigitAscii(_n, c, d);
  } else {
    alpha[_a].writeDigitAscii(_n, c);
  }
}

void Alphanum32::displayAllSegs(uint8_t d)
{
  for (uint8_t i = 0; i < 32; i++) {
    Alphanum32::_oldPCBmap(i);
    alpha[_a].writeDigitRaw(_n, 0x7FFF);
    Alphanum32::write();
    delay(d);
  }
}

void Alphanum32::displayAllChars(uint8_t d)
{
  for (uint8_t i = '!'; i <= '~'; i++) {
    for (uint8_t j = 0; j < 32; j++) {
      uint8_t l = i + j;
      Alphanum32::_oldPCBmap(j);
      // create blanks when characters go past '~'
      if (l >= '~') l = ' ';
      alpha[_a].writeDigitAscii(_n, l);
    }
    Alphanum32::write();
    delay(d);
  }
}




