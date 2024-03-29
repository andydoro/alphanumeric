
// made more flexible, 4 digit days 
// to do: add years?


#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Alphanum32.h"

// clock libs
#include "RTClib.h"
#include "DST_RTC.h"

// const char strings
const char s_days[] PROGMEM = " DAYS ";
const char s_hours[] PROGMEM = " HOURS ";
const char s_hrs[] PROGMEM = " HRS ";
const char s_mins[] PROGMEM = " MINS ";
const char s_secs[] PROGMEM = " SECS";

const char s_day[] PROGMEM = " DAY  ";
const char s_hour[] PROGMEM = " HOUR  ";
const char s_hr[] PROGMEM = " HR  ";
const char s_min[] PROGMEM = " MIN  ";
const char s_sec[] PROGMEM = " SEC ";


const char s_day_blank[] PROGMEM = "        ";
const char s_hour_blank[] PROGMEM = "                ";
const char s_hr_blank[] PROGMEM = "              ";
const char s_min_blank[] PROGMEM = "                        ";

const char s_intro[] PROGMEM = "        COUNTDOWN CLOCK         ";

const char countdownComplete[] PROGMEM = "         TIME IS UP             ";

//const byte NUMCHARS = 32;
#define NUMCHARS 32
//const byte NUMALPHAS = 8;

// how fast the letters flip
#define FLIPUPDELAY 2

// makes them all clear

char tempString[NUMCHARS + 1] = {' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' '
                                };

char timePhrase[NUMCHARS + 1];

Alphanum32 myAlphanum;

RTC_DS3231 rtc; // clock object
DST_RTC dst; // dst object

// Define US or EU rules for DST comment out as required. More countries could be added with different rules in DST_RTC.cpp
const char rulesDST[] = "US"; // US DST rules
// const char rulesDST[] = "EU";   // EU DST rules


// brightness based on time of day
// 0-15
#define DAYBRIGHTNESS 15
#define NIGHTBRIGHTNESS 7

// cutoff times for day / night brightness. feel free to modify.
#define MORNINGCUTOFF 7  // when does daybrightness begin?   7am
#define NIGHTCUTOFF 22 // when does nightbrightness begin? 10pm


//byte digitSkip = 27; // assume 3 digits

// unix target date
// countdown until:
// July 1, 2047, 12:00:00 am GMT
// using: https://www.epochconverter.com/
//
// this date is in Standard Time
// verify calculations here:
// https://www.timeanddate.com/date/durationresult.html
const unsigned long countdownOver = 2445552000000;
// July 1, 2047

// Do you live in a country or territory that observes Daylight Saving Time?
// https://en.wikipedia.org/wiki/Daylight_saving_time_by_country
// This is programmed for DST in the US / Canada. If your territory's DST operates differently,
// you'll need to modify the code in the calcTheTime() function to make this work properly.
const boolean OBSERVE_DST = true;

// constants for calculations
//const unsigned int SECONDS_PER_DAY = 86400; // apparently built-in constant for RTClib
//const signed int SECONDS_PER_HOUR = 3600; // must be signed or math gets weird
#define SECONDS_PER_HOUR 3600


// check whether countdown date is in DST or not
boolean useDst = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);


  //Serial.println("start!");

  // initialize display and clear
  myAlphanum.begin();
  myAlphanum.clear();
  myAlphanum.brightness(DAYBRIGHTNESS); // max brightness
  myAlphanum.write();

  // display each LED segment - check for bad connections
  myAlphanum.displayAllSegs(20);
  delay(1000);

  // display all ASCII chars
  myAlphanum.displayAllChars(20);
  delay(500);

  if (! rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // DST? If we're in it, let's subtract an hour from the RTC time to keep our DST calculation correct. This gives us
    // Standard Time which our DST check will add an hour back to if we're in DST.
    DateTime standardTime = rtc.now();
    if (dst.checkDST(standardTime) == true) { // check whether we're in DST right now. If we are, subtract an hour.
      standardTime = standardTime.unixtime() - 3600;
    }
    rtc.adjust(standardTime);
  }

  // check whether countdown date is in DST or not
  if (dst.checkDST(countdownOver) == true) { // check whether countdown date is in DST
    useDst = true; // takes into account DST
  } else {
    useDst = false;
  }


  strcpy(timePhrase, s_intro);

  for (uint8_t i = 0; i < 100; i++) { // enough cycles to get there
    morphStrings();
    setChars();
    myAlphanum.write();
    delay(FLIPUPDELAY);
  }

  delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:

  // get the time
  // do we need to use daylight savings time based on the countdown time?

  DateTime theTime; // we want to calculate from standard time

  if (useDst) { // check whether countdown date is in DST
    theTime = dst.calculateTime(rtc.now()); // takes into account DST
  } else {
    theTime = rtc.now();
  }

  //theTime = rtc.now();
  //DateTime theTime = dst.calculateTime(rtc.now()); // takes into account DST

  //printTheTime(theTime);

  long secondsLeft; // var for counting the seconds left. needs to be long, int doesn't work!

  secondsLeft = countdownOver - theTime.unixtime();

  if (secondsLeft > -1) {

    int daysLeft, hoursLeft, minutesLeft, leftoverSecondsLeft; // create vars

    int numDayDigits = 4; // how many digits do we want for days?
    // changed dynamically based on number of days left

    // calculate days, hours, minutes left
    daysLeft = secondsLeft / SECONDS_PER_DAY;
    hoursLeft = (secondsLeft % SECONDS_PER_DAY) / SECONDS_PER_HOUR; // throw away anything over a full day, divide by number of seconds in an hour
    minutesLeft = (secondsLeft % SECONDS_PER_HOUR) / 60; // throw away anything over a full hour, divide by 60 (seconds per minute)
    leftoverSecondsLeft = secondsLeft % 60;

    // print our calculations of time left
    Serial.print("days left: ");
    Serial.println(daysLeft);
    Serial.print("hours left: ");
    Serial.println(hoursLeft);
    Serial.print("minutes left: ");
    Serial.println(minutesLeft);
    Serial.print("seconds left: ");
    Serial.println(leftoverSecondsLeft);


    // figure out days left, which affects our display
    // what's our max? lets do 3 or else "SEC" word looks weird
    if (daysLeft > 999) {
      numDayDigits = 4;
      // set HOURS to HRS
    } else if (daysLeft > 99) {
      numDayDigits = 3;
    } else {
      numDayDigits = 2;
    }

    //Serial.println(numDayDigits);

    // define which seconds digit to skip morph
    // can make more dynamic
    byte digitSkip = 26; // assume 2 or 4 day digits
    if (numDayDigits == 3) {
      digitSkip = 27;
    } else {
      digitSkip = 26;
    }

    //Serial.println(digitSkip);

    // char arrays for numbers
    char day_str[numDayDigits + 1];
    char hour_str[3];
    char min_str[3];
    char sec_str[3];

    // generate string based on the time
    //if (numDayDigits == 3) {
    if (numDayDigits == 4) {
      sprintf(day_str, "%4d", daysLeft); // convert int to str
    } else if (numDayDigits == 3) {
      sprintf(day_str, "%3d", daysLeft); // convert int to str
    } else {
      sprintf(day_str, "%2d", daysLeft); // convert int to str
    }
    sprintf(hour_str, "%2d", hoursLeft);
    sprintf(min_str, "%2d", minutesLeft);
    sprintf(sec_str, "%2d", leftoverSecondsLeft);

    if (daysLeft == 0) {
      strcpy(timePhrase, s_day_blank); // blank, no number
    } else if (daysLeft == 1) {
      strcpy(timePhrase, day_str); // number of days
      strcat(timePhrase, s_day); // " day"
    } else {
      strcpy(timePhrase, day_str); // number of days
      strcat(timePhrase, s_days); // " days"
    }

    if (numDayDigits == 4) {
      if (daysLeft == 0 && hoursLeft == 0) {
        strcpy(timePhrase, s_hr_blank); // blank, no number
      } else if (hoursLeft == 1) {
        strcat(timePhrase, hour_str);
        strcat(timePhrase, s_hr); // " hr "
      } else {
        strcat(timePhrase, hour_str);
        strcat(timePhrase, s_hrs); // " hrs "
      }
    } else {
      if (daysLeft == 0 && hoursLeft == 0) {
        strcpy(timePhrase, s_hour_blank); // blank, no number
      } else if (hoursLeft == 1) {
        strcat(timePhrase, hour_str);
        strcat(timePhrase, s_hour); // " hour "
      } else {
        strcat(timePhrase, hour_str);
        strcat(timePhrase, s_hours); // " hours "
      }
    }

    if (daysLeft == 0 && hoursLeft == 0 && minutesLeft == 0) {
      strcpy(timePhrase, s_min_blank); // blank, no number
    } else if (minutesLeft == 1) {
      strcat(timePhrase, min_str);
      strcat(timePhrase, s_min); // " min "
    } else {
      strcat(timePhrase, min_str);
      strcat(timePhrase, s_mins); // " mins "
    }

    strcat(timePhrase, sec_str);
    if (leftoverSecondsLeft == 1 || numDayDigits == 3) { // prevents overflow of char array?
      strcat(timePhrase, s_sec); // " sec"
    } else {
      strcat(timePhrase, s_secs); // " secs"
    }

    // adjust brightness based on hour
    // check less often? like once a minute?

    if (leftoverSecondsLeft == 15) {
      byte theHour = theTime.hour();
      //delay(1); // help with crashes?
      adjustBrightness(theHour);
    }


    printTheTime(theTime);

    Serial.println(F(timePhrase));

    morphStringsSkip(digitSkip);

  } else { // less than zero

    // move to const str at top
    strcpy(timePhrase, countdownComplete);

    morphStrings();

  }

  setChars();
  myAlphanum.write();
  delay(FLIPUPDELAY);

}
