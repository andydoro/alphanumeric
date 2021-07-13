
void writeDisplays() {
  for (uint8_t i = 0; i < NUMALPHAS; i++) {
    alpha[i].writeDisplay();
  }
}

