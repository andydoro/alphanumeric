void morphStrings() {
  for (uint8_t j = 0 ; j < NUMCHARS; j++) {
    if ( !(tempString[j] == theTruism[j]) ) { // if the chars doesn't match...
      tempString[j] = tempString[j] + 1;
      // rollover
      if (tempString[j] > 'z') { // that's the last ASCII char!
        tempString[j] = ' '; // first ASCII char
      }
    }
    //Serial.println(tempString);
  }
}

void setChars() {
  // set every digit to the buffer
  for (uint8_t i = 0; i < NUMCHARS; i++) {
    alpha[i / 4].writeDigitAscii((i % 4), tempString[i]);
  }
}

void displayAllSegs() {
  for (uint8_t i = 0; i < NUMCHARS; i++) {
    alpha[i / 4].writeDigitRaw(i % 4, 0x7FFF);
    writeDisplays();
    delay(20);
  }
  delay(2000);
}


void displayAllChars() {
  for (uint8_t i = '!'; i <= '~'; i++) {
    for (uint8_t j = 0; j < NUMCHARS; j++) {
      uint8_t l = i + j;
      // create blanks when characters go past '~'
      if (l >= '~') l = ' ';
      alpha[j / 4].writeDigitAscii(j % 4, l);
    }
    writeDisplays();
    delay(20);
  }
}


void writeDisplays() {
  for (uint8_t i = 0; i < NUMALPHAS; i++) {
    alpha[i].writeDisplay();
  }
}
