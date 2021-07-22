
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

  myAlphanum.brightness(DAYBRIGHTNESS);

  // button clicks
  if (! ss.digitalRead(SS_SWITCH)) {
    delay(SWITCH_DELAY); // debounce?
    //Serial.println("Button pressed!");
    timeSpanMode++;

    if (timeSpanMode > 5) {
      timeSpanMode = 0;
    }
    // move indicator dot
    dotPos = timeSetDotPositions[timeSpanMode];
    
    timeSetCounter = 0; // reset counter
  }

  // encoder rotations
  int32_t new_position = ss.getEncoderPosition();
  // did we move arounde?
  if (encoder_position != new_position) {
    Serial.println(new_position);         // display new position
    int32_t pos_diff = encoder_position - new_position; // get the difference

    int16_t stdYear = standardTime.year();
    int16_t stdMon = standardTime.month();
    int16_t stdDay = standardTime.day();
    int16_t stdHour = standardTime.hour();
    int16_t stdMin = standardTime.minute();
    int16_t stdSec = standardTime.second();

    // create different modes to alter Y, M, D, H, S, etc

    // add constrains! or rollover?
    switch (timeSpanMode) {
      case 0: //standardTime = standardTime.unixtime() + pos_diff; // seconds
        stdSec = stdSec + pos_diff;
        stdSec = varRollOver(stdSec, 0, 59);
        break;
      case 1: //standardTime = standardTime.unixtime() + (60 * pos_diff); // minutes
        stdMin = stdMin + pos_diff;
        stdMin = varRollOver(stdMin, 0, 59);
        break;
      case 2: stdHour = stdHour + pos_diff; // hours
        stdHour = varRollOver(stdHour, 0, 23);
        break;
      case 3: stdDay = stdDay + pos_diff; // days

        stdDay = varRollOver(stdDay, 1, 31);
        break;
      case 4: stdMon = stdMon + pos_diff; // months... err... inexact!
        stdMon = varRollOver(stdMon, 1, 12);
        break;
      case 5: stdYear += pos_diff; // years
        stdYear = varRollOver(stdYear, 2000, 2099);
        break;
    }
    rtc.adjust(DateTime(stdYear, stdMon, stdDay, stdHour, stdMin, stdSec));
    timeSetCounter = 0; // reset counter
    encoder_position = new_position;      // and save for next round
  }

  DateTime theTime = dst.calculateTime(rtc.now()); // takes into account DST
  printTheTime(theTime);

  // display time
  uint16_t stdYear = theTime.year();
  byte stdMon = theTime.month();
  byte stdDay = theTime.day();
  byte stdHour = theTime.hour();
  byte stdMin = theTime.minute();
  byte stdSec = theTime.second();

  // char arrays for numbers
  char year_str[5];
  char mon_str[3];
  char day_str[3];
  char hour_str[3];
  char min_str[3];
  char sec_str[3];

  // format bytes into
  sprintf(year_str, "%4d", stdYear);
  sprintf(mon_str, "%2d", stdMon);
  sprintf(day_str, "%2d", stdDay);
  sprintf(hour_str, "%2d", stdHour);
  sprintf(min_str, "%2d", stdMin);
  sprintf(sec_str, "%2d", stdSec);

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
  myAlphanum.write();

  timeSetCounter++;
  if (timeSetCounter > TIMESETCOUNTERLIMIT) {
    Serial.println("out of Time Set Mode");
    enterTimeSetMode = false;
    timeSetCounter = 0;
  }
  delay(FLIPUPDELAY);
}
