
void morphStrings() {
  for (uint8_t j = 0 ; j < NUMCHARS; j++) {
    if ( !(tempString[j] == timePhrase[j]) ) { // if the chars doesn't match...
      tempString[j] = tempString[j] + 1;
      // rollover
      if (tempString[j] > 'Z') { // that's the last ASCII char!
        tempString[j] = ' '; // first ASCII char
      }
    }
    //Serial.println(tempString);
  }
}

void morphStringsSkip() {

  for (uint8_t j = 0 ; j < NUMCHARS; j++) {
    if (j == digitSkip) { // skipping
      tempString[j] = timePhrase[j]; // just set it, no "morph"
    }
    else {
      if ( !(tempString[j] == timePhrase[j]) ) { // if the chars doesn't match...
        tempString[j] = tempString[j] + 1;
        // rollover
        if (tempString[j] > 'Z') { // that's the last ASCII char!
          tempString[j] = ' '; // first ASCII char
        }
      }
      //Serial.println(tempString);
    }
  }
}

void setChars() {
  // set every digit to the buffer
  for (uint8_t i = 0; i < 32; i++) {
    myAlphanum.writeDigitAscii(i, tempString[i]);
  }
}

// print time to serial
void printTheTime(DateTime theTimeP) {
  Serial.print(theTimeP.year(), DEC);
  Serial.print('/');
  Serial.print(theTimeP.month(), DEC);
  Serial.print('/');
  Serial.print(theTimeP.day(), DEC);
  Serial.print(' ');
  Serial.print(theTimeP.hour(), DEC);
  Serial.print(':');
  Serial.print(theTimeP.minute(), DEC);
  Serial.print(':');
  Serial.print(theTimeP.second(), DEC);
  Serial.println();
}
