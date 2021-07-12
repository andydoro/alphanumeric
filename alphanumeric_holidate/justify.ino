
void rightJustify() {
  int blanks = 32 - strlen(timePhrase);
  memmove(timePhrase + blanks, timePhrase, strlen(timePhrase));
  for (int i = 0; i < blanks; i++) {
    timePhrase[i] = ' ';
  }
}

void leftJustify() {
  int blanks = 32 - strlen(timePhrase);
  for (int i = 0; i < blanks; i++) {
    strcat(timePhrase, " ");
  }
}
