
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
void setChars() {
  // set every digit to the buffer
  // need to use special undocumented "true" argument to display dots

  for (uint8_t i = 0; i < NUMCHARS; i++) {
    if (i == dotPos) {
      myAlphanum.writeDigitAscii(i, tempString[i], true);
    } else {
      myAlphanum.writeDigitAscii(i, tempString[i]);
    }
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
