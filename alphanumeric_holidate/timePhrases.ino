
void minPhrase(byte m) {
  if (m < 10) {
    minPhrase2ndDigit(m);
  } else if (m < 20) {
    switch (m) {
      case 10: strcat(timePhrase, s_10);
        break;
      case 11: strcat(timePhrase, s_11);
        break;
      case 12: strcat(timePhrase, s_12);
        break;
      case 13: strcat(timePhrase, s_13);
        break;
      case 14: strcat(timePhrase, s_14);
        break;
      case 15: strcat(timePhrase, s_quarter);
        break;
      case 16: strcat(timePhrase, s_16);
        break;
      case 17: strcat(timePhrase, s_17);
        break;
      case 18: strcat(timePhrase, s_18);
        break;
      case 19: strcat(timePhrase, s_19);
        break;
    }
  } else if (m < 30) {
    strcat(timePhrase, s_20);
    if (m != 20) {
      strcat(timePhrase, PSTR("-"));
      minPhrase2ndDigit(m);
    }
  } else if (m == 30) {
    strcat(timePhrase, PSTR("HALF"));
  }
}

// generate word for second digit
void minPhrase2ndDigit (byte m) {
  m = m % 10;
  switch (m) {
    case 0:
      break;
    case 1: strcat(timePhrase, s_1);
      break;
    case 2: strcat(timePhrase, s_2);
      break;
    case 3: strcat(timePhrase, s_3);
      break;
    case 4: strcat(timePhrase, s_4);
      break;
    case 5: strcat(timePhrase, s_5);
      break;
    case 6: strcat(timePhrase, s_6);
      break;
    case 7: strcat(timePhrase, s_7);
      break;
    case 8: strcat(timePhrase, s_8);
      break;
    case 9: strcat(timePhrase, s_9);
      break;
  }
}

void hourPhrase(byte h) {
  switch (h) {
    case 0:
      strcat(timePhrase, s_midnight);
      break;
    case 1:
    case 13:
      strcat(timePhrase, s_1);
      break;
    case 2:
    case 14:
      strcat(timePhrase, s_2);
      break;
    case 3:
    case 15:
      strcat(timePhrase, s_3);
      break;
    case 4:
    case 16:
      strcat(timePhrase, s_4);
      break;
    case 5:
    case 17:
      strcat(timePhrase, s_5);
      break;
    case 6:
    case 18:
      strcat(timePhrase, s_6);
      break;
    case 7:
    case 19:
      strcat(timePhrase, s_7);
      break;
    case 8:
    case 20:
      strcat(timePhrase, s_8);
      break;
    case 9:
    case 21:
      strcat(timePhrase, s_9);
      break;
    case 10:
    case 22:
      strcat(timePhrase, s_10);
      break;
    case 11:
    case 23:
      strcat(timePhrase, s_11);
      break;
    case 12:
      strcat(timePhrase, s_noon);
      break;
    default: strcat(timePhrase, PSTR("HRERR")); // "hour error" error handing for weird RTC responses
  }
}

void genTimePhrase(byte theHour, byte theMin) {

  // generate string based on the time
  strcpy(timePhrase, s_itis); // "IT IS "

  if (theMin == 0) {
    // O'CLOCK
    // get hour phrase
    hourPhrase(theHour);
    if ((theHour != 0) && (theHour != 12)) { // exclude noon and midnight
      strcat(timePhrase, PSTR(" O'CLOCK")); // apostrophe!
    }
  } else if (theMin < 31) {
    minPhrase(theMin);
    // PAST
    strcat(timePhrase, PSTR(" PAST "));
    // get hour phrase
    hourPhrase(theHour);
  } else { // over 30
    minPhrase(60 - theMin); // invert minutes
    strcat(timePhrase, PSTR(" TO "));     // TO
    // get hour phrase
    theHour = (theHour + 1) % 24;
    hourPhrase(theHour);
  }
  rightJustify();
}
