
void adjustBrightness(byte theHour) {
  if (theHour < MORNINGCUTOFF || theHour >= NIGHTCUTOFF) {
    for (uint8_t i = 0; i < NUMALPHAS; i++) {
      alpha[i].setBrightness(NIGHTBRIGHTNESS); // quarter brightness
    }
    //Serial.println("dim");
  } else {
    for (uint8_t i = 0; i < NUMALPHAS; i++) {
      alpha[i].setBrightness(DAYBRIGHTNESS); // quarter brightness
    }
    //Serial.println("bright");
  }
}
