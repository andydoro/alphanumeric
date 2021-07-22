
void adjustBrightness(byte theHour) {
  if (theHour < MORNINGCUTOFF || theHour >= NIGHTCUTOFF) {
    myAlphanum.brightness(NIGHTBRIGHTNESS);
  } else {
    myAlphanum.brightness(DAYBRIGHTNESS);
  }
}
