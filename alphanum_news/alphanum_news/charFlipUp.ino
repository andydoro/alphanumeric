
void morphStrings() {
  for (uint8_t j = 0 ; j < NUMCHARS; j++) {
    if ( !(tempString[j] == theHeadline[j]) ) { // if the chars doesn't match...
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
    myAlphanum.writeDigitAscii(i, tempString[i]);
  }
}

// convert and copy String to char array
void String2CharArray(String str) {

  byte buflen = str.length() + 1;
  char tempBuf[buflen];
  str.toCharArray(tempBuf, buflen);
  strcpy(theHeadline, tempBuf);

}

void rightJustify() {
  int blanks = 32 - strlen(theHeadline);
  memmove(theHeadline + blanks, theHeadline, strlen(theHeadline));
  for (int i = 0; i < blanks; i++) {
    theHeadline[i] = ' ';
  }
}
