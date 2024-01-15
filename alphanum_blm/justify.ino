void rightJustify() {
  int blanks = 32 - strlen(theTruism);
  // add blanks to end of truism
  memmove(theTruism + blanks, theTruism, strlen(theTruism));
  for (byte i = 0; i < blanks; i++) {
    theTruism[i] = ' ';
  }
}

void leftJustify() {
  int blanks = 32 - strlen(theTruism);
  for (byte i = 0; i < blanks; i++) {
    strcat(theTruism, " ");
  }
}
