
void datePhrase(byte mon, byte d) {
  
  strcpy(timePhrase, PSTR("THE "));

  dayPhrase(d);

  strcat(timePhrase, PSTR(" OF "));

  // month
  switch (mon) {
    case 1: strcat(timePhrase, PSTR("JANUARY"));
      break;
    case 2: strcat(timePhrase, PSTR("FEBRUARY"));
      break;
    case 3: strcat(timePhrase, PSTR("MARCH"));
      break;
    case 4: strcat(timePhrase, PSTR("APRIL"));
      break;
    case 5: strcat(timePhrase, PSTR("MAY"));
      break;
    case 6: strcat(timePhrase, PSTR("JUNE"));
      break;
    case 7: strcat(timePhrase, PSTR("JULY"));
      break;
    case 8: strcat(timePhrase, PSTR("AUGUST"));
      break;
    case 9: strcat(timePhrase, PSTR("SEPTEMBER"));
      break;
    case 10: strcat(timePhrase, PSTR("OCTOBER"));
      break;
    case 11: strcat(timePhrase, PSTR("NOVEMBER"));
      break;
    case 12: strcat(timePhrase, PSTR("DECEMBER"));
      break;
    default: strcat(timePhrase, PSTR("MONERROR")); // month error
  }
}

void dayPhrase(byte d) {
  if (d < 10) {
    dayPhrase2ndDigit(d);
  } else if (d < 21) {
    switch (d) {
      case 10: strcat(timePhrase, PSTR("TENTH"));
        break;
      case 11: strcat(timePhrase, PSTR("ELEVENTH"));
        break;
      case 12: strcat(timePhrase, PSTR("TWELFTH"));
        break;
      case 13: strcat(timePhrase, PSTR("THIRTEENTH"));
        break;
      case 14: strcat(timePhrase, PSTR("FOURTEENTH"));
        break;
      case 15: strcat(timePhrase, PSTR("FIFTEENTH"));
        break;
      case 16: strcat(timePhrase, PSTR("SIXTEENTH"));
        break;
      case 17: strcat(timePhrase, PSTR("SEVENTEENTH"));
        break;
      case 18: strcat(timePhrase, PSTR("EIGHTEENTH"));
        break;
      case 19: strcat(timePhrase, PSTR("NINETEENTH"));
        break;
      case 20: strcat(timePhrase, PSTR("TWENTIETH"));
        break;
    }
  } else if (d < 30) {
    strcat(timePhrase, PSTR("TWENTY-"));
    dayPhrase2ndDigit(d);
  } else if  (d == 30) { // 30th
    strcat(timePhrase, PSTR("THIRTIETH"));
  } else if (d == 31) { // 31st
    strcat(timePhrase, PSTR("THIRTY-FIRST"));
  } else {
    strcat(timePhrase, PSTR("DAYERROR")); // something went wrong
  }
}

// generate word for second digit
void dayPhrase2ndDigit (byte d) {
  d = d % 10;
  switch (d) {
    case 0:
      break;
    case 1: strcat(timePhrase, PSTR("FIRST"));
      break;
    case 2: strcat(timePhrase, PSTR("SECOND"));
      break;
    case 3: strcat(timePhrase, PSTR("THIRD"));
      break;
    case 4: strcat(timePhrase, PSTR("FOURTH"));
      break;
    case 5: strcat(timePhrase, PSTR("FIFTH"));
      break;
    case 6: strcat(timePhrase, PSTR("SIXTH"));
      break;
    case 7: strcat(timePhrase, PSTR("SEVENTH"));
      break;
    case 8: strcat(timePhrase, PSTR("EIGHTH"));
      break;
    case 9: strcat(timePhrase, PSTR("NINTH"));
      break;
  }
}
