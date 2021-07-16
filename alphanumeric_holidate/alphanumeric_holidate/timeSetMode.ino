
int16_t varRollOver(int16_t var, int16_t minn, int16_t maxx) { // handle time var rollovers
  if (var < minn) {
    //var += maxx;// this really only works if minn is 0 or 1...
    var = maxx + 1 - (minn - var); // propah negative rollover!
  }
  var %= maxx + 1;
  var = constrain(var, minn, maxx);
  return var;
}

void timeSetMode(DateTime standardTime) {

  for (uint8_t i = 0; i < NUMALPHAS; i++) {
    alpha[i].setBrightness(DAYBRIGHTNESS); // max brightness
  }

  // button clicks
  if (! ss.digitalRead(SS_SWITCH)) {
    delay(SWITCH_DELAY); // debounce?
    //Serial.println("Button pressed!");
    //Serial.println("TIME SET MODE");
    // go into time set mode
    //timeSetMode = true;
    timeSpanMode++;

    if (timeSpanMode > 5) {
      timeSpanMode = 0;
    }
    // move indicator dot
    switch (timeSpanMode) {
      case 0: dotPos = 28;
        break;
      case 1: dotPos = 23;
        break;
      case 2: dotPos = 18;
        break;
      case 3: dotPos = 13;
        break;
      case 4: dotPos = 8;
        break;
      case 5: dotPos = 0;
        break;
    }
    timeSetCounter = 0; // reset counter
  }

  // encoder rotations
  int32_t new_position = ss.getEncoderPosition();
  // did we move arounde?
  if (encoder_position != new_position) {
    Serial.println(new_position);         // display new position
    int32_t pos_diff = encoder_position - new_position; // get the difference

    int16_t theYear = standardTime.year();
    int16_t theMon = standardTime.month();
    int16_t theDay = standardTime.day();
    int16_t theHour = standardTime.hour();
    int16_t theMin = standardTime.minute();
    int16_t theSec = standardTime.second();

    // create different modes to alter Y, M, D, H, S, etc

    // add constrains! or rollover?
    switch (timeSpanMode) {
      case 0: //standardTime = standardTime.unixtime() + pos_diff; // seconds
        theSec = theSec + pos_diff;
        theSec = varRollOver(theSec, 0, 59);
        break;
      case 1: //standardTime = standardTime.unixtime() + (60 * pos_diff); // minutes
        theMin = theMin + pos_diff;
        theMin = varRollOver(theMin, 0, 59);
        break;
      case 2: theHour = theHour + pos_diff; // hours
        theHour = varRollOver(theHour, 0, 23);
        break;
      case 3: theDay = theDay + pos_diff; // days

        theDay = varRollOver(theDay, 1, 31);
        break;
      case 4: theMon = theMon + pos_diff; // months... err... inexact!
        theMon = varRollOver(theMon, 1, 12);
        break;
      case 5: theYear += pos_diff; // years
        theYear = varRollOver(theYear, 2000, 2099);
        break;
    }
    rtc.adjust(DateTime(theYear, theMon, theDay, theHour, theMin, theSec));
    //rtc.adjust(standardTime); // write to RTC
    //theTime = dst.calculateTime(standardTime); // takes into account DST
    //printTheTime(theTime);
    timeSetCounter = 0; // reset counter
    encoder_position = new_position;      // and save for next round
  }

  DateTime theTime = dst.calculateTime(rtc.now()); // takes into account DST
  printTheTime(theTime);

  // display time
  uint16_t theYear = theTime.year();
  byte theMon = theTime.month();
  byte theDay = theTime.day();
  byte theHour = theTime.hour();
  byte theMin = theTime.minute();
  byte theSec = theTime.second();

  // char arrays for numbers
  char year_str[5];
  char mon_str[3];
  char day_str[3];
  char hour_str[3];
  char min_str[3];
  char sec_str[3];

  // format bytes into
  sprintf(year_str, "%4d", theYear);
  sprintf(mon_str, "%2d", theMon);
  sprintf(day_str, "%2d", theDay);
  sprintf(hour_str, "%2d", theHour);
  sprintf(min_str, "%2d", theMin);
  sprintf(sec_str, "%2d", theSec);

  // generate string based on the time
  strcpy(tempString, PSTR("Y "));
  strcat(tempString, year_str);
  strcat(tempString, PSTR(" MO "));
  strcat(tempString, mon_str);
  strcat(tempString, PSTR(" D "));
  strcat(tempString, day_str);
  strcat(tempString, PSTR(" H "));
  strcat(tempString, hour_str);
  strcat(tempString, PSTR(" M "));
  strcat(tempString, min_str);
  strcat(tempString, PSTR(" S "));
  strcat(tempString, sec_str);

  Serial.println(F(tempString));

  setChars();
  writeDisplays();

  timeSetCounter++;
  if (timeSetCounter > TIMESETCOUNTERLIMIT) {
    Serial.println("out of Time Set Mode");
    enterTimeSetMode = false;
    timeSetCounter = 0;
  }
  delay(FLIPUPDELAY);
}
