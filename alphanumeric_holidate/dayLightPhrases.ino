
void dayLightPhrases(DateTime theTime) {

  // do we need to adjust offset for DST?
  boolean isDST = false;
  //byte dstOffset = 0;
  if (dst.checkDST(theTime) == true) {
    isDST = true;
    //dstOffset = 1;
  }

  int theYear = theTime.year();
  byte theMon = theTime.month();
  byte theDay = theTime.day();
  byte theHour = theTime.hour();
  byte theMin = theTime.minute();

  /*  Multiple instances can be created. Arguments are longitude, latitude, and
    time zone offset in hours from UTC.

    The first two must be in decimal degrees (DD), e.g. 10.001, versus the
    more common degrees, minutes, and seconds format (DMS), e.g. 10° 00′ 3.6″.
    The time zone offset can be expressed in float in the few cases where the
    the zones are offset by 30 or 45 minutes, e.g. "5.75" for Nepal Standard
    Time.

    HINT: An easy way to find the longitude and latitude for any location is
    to find the spot in Google Maps, right click the place on the map, and
    select "What's here?". At the bottom, you’ll see a card with the
    coordinates.
  */

  Dusk2Dawn newYorkCity(LATITUDE, LONGITUDE, GMTOFFSET);

  /*  Available methods are sunrise() and sunset(). Arguments are year, month,
      day, and if Daylight Saving Time is in effect.
  */

  int nycSunrise = newYorkCity.sunrise(theYear, theMon, theDay, isDST);
  int nycSunset = newYorkCity.sunset(theYear, theMon, theDay, isDST);

  /*  Time is returned in minutes elapsed since midnight. If no sunrises or
        sunsets are expected, a "-1" is returned.
  */
  Serial.println(nycSunrise);  // 418
  Serial.println(nycSunset);   // 1004

  /*  A static method converts the returned time to a 24-hour clock format.
      Arguments are a character array and time in minutes.
  */
  //char sunriseTime[6];
  //char sunsetTime[6];
  //Serial.println(sunriseTime); // 06:58
  //Serial.println(sunsetTime); // 06:58

  int sunriseHour = nycSunrise / 60;
  int sunriseMin = nycSunrise % 60;

  int sunsetHour = nycSunset / 60; // % 12; // use 12 hour time.
  // we're just going to assume sunrise happens in the AM and sunset in the PM but we should at some point have the code calculate this
  int sunsetMin = nycSunset % 60;

  // print the sunrise / sunset calculations
  Serial.print("sunrise: ");
  Serial.print(sunriseHour);
  Serial.print(':');
  Serial.println(sunriseMin);

  Serial.print("sunset: ");
  Serial.print(sunsetHour);
  Serial.print(':');
  Serial.println(sunsetMin);

  char SR_hour_str[3];
  char SR_min_str[3];
  char SS_hour_str[3];
  char SS_min_str[3];

  sprintf(SR_hour_str, "%d", sunriseHour); // just assume sunrise is before noon
  sprintf(SR_min_str, "%02d", sunriseMin);
  sprintf(SS_hour_str, "%d", sunsetHour % 12); // 12 hour time
  sprintf(SS_min_str, "%02d", sunsetMin);

  // add some way to change phrase before and after
  // SUNRISE
  strcpy(sunrisePhrase, PSTR("SUNRISE "));
  if ((theHour < sunriseHour) || ((theHour == sunriseHour) && (theMin < sunriseMin))) {
    strcat(sunrisePhrase, s_will_be_at);

    strcat(sunrisePhrase, SR_hour_str);
    strcat(sunrisePhrase, s_colon); // ":" looks weird
    strcat(sunrisePhrase, SR_min_str);
    strcat(sunrisePhrase, s_am);
  } else if ((theHour == sunriseHour) && (theMin == sunriseMin)) {
    strcat(sunrisePhrase, s_is_now);
  } else {
    strcat(sunrisePhrase, s_was_at);
    strcat(sunrisePhrase, SR_hour_str);
    strcat(sunrisePhrase, s_colon); // ":" looks weird
    strcat(sunrisePhrase, SR_min_str);
    strcat(sunrisePhrase, s_am);
  }


  // left justify
  int blanks = 32 - strlen(sunrisePhrase);
  for (int i = 0; i < blanks; i++) {
    strcat(sunrisePhrase, " ");
  }


  // SUNSET
  strcpy(sunsetPhrase, PSTR("SUNSET "));
  if ((theHour < sunsetHour) || ((theHour == sunsetHour) && (theMin < sunsetMin))) {
    strcat(sunsetPhrase, s_will_be_at);
    strcat(sunsetPhrase, SS_hour_str);
    strcat(sunsetPhrase, s_colon); // ":" looks weird
    strcat(sunsetPhrase, SS_min_str);
    strcat(sunsetPhrase, s_pm);
  } else if ((theHour == sunsetHour) && (theMin == sunsetMin)) {
    strcat(sunsetPhrase, s_is_now);
  } else {
    strcat(sunsetPhrase, s_was_at);
    strcat(sunsetPhrase, SS_hour_str);
    strcat(sunsetPhrase, s_colon); // ":" looks weird
    strcat(sunsetPhrase, SS_min_str);
    strcat(sunsetPhrase, s_pm);
  }

  // right justify
  blanks = 32 - strlen(sunsetPhrase);
  memmove(sunsetPhrase + blanks, sunsetPhrase, strlen(sunsetPhrase));
  for (int i = 0; i < blanks; i++) {
    sunsetPhrase[i] = ' ';
  }

  // don't need to recalculate until next time flag is reset
  firstTime = false;
}
