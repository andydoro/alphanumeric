void dotwPhrase(byte w) {
  strcpy(timePhrase, s_itis);
  switch (w) {
    case 0: strcat(timePhrase, PSTR("SUNDAY"));
      break;
    case 1: strcat(timePhrase, PSTR("MONDAY"));
      break;
    case 2: strcat(timePhrase, PSTR("TUESDAY"));
      break;
    case 3: strcat(timePhrase, PSTR("WEDNESDAY"));
      break;
    case 4: strcat(timePhrase, PSTR("THURSDAY"));
      break;
    case 5: strcat(timePhrase, PSTR("FRIDAY"));
      break;
    case 6: strcat(timePhrase, PSTR("SATURDAY"));
      break;
    default: strcat(timePhrase, PSTR("DOTWERROR")); // catch error if day of the week is not 0-6 somehow
  }
}
