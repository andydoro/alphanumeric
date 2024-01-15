void morphStrings() {
  for (uint8_t j = 0 ; j < 32; j++) {
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
  for (uint8_t i = 0; i < 32; i++) {
    myAlphanum.writeDigitAscii(i, tempString[i]);
  }
}
