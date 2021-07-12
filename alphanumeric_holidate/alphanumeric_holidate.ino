
// uses C strings / char arrays
// should move static strings into PROGMEM

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

// clock libs
#include "RTClib.h"
#include "DST_RTC.h"
#include "Dusk2Dawn_mod.h"

// const char strings
const char s_1[] PROGMEM = "ONE";
const char s_2[] PROGMEM = "TWO";
const char s_3[] PROGMEM = "THREE";
const char s_4[] PROGMEM = "FOUR";
const char s_5[] PROGMEM = "FIVE";
const char s_6[] PROGMEM = "SIX";
const char s_7[] PROGMEM = "SEVEN";
const char s_8[] PROGMEM = "EIGHT";
const char s_9[] PROGMEM = "NINE";
const char s_10[] PROGMEM = "TEN";
const char s_11[] PROGMEM = "ELEVEN";
const char s_12[] PROGMEM = "TWELVE";
const char s_13[] PROGMEM = "THIRTEEN";
const char s_14[] PROGMEM = "FOURTEEN";
const char s_quarter[] PROGMEM = "A QUARTER";
const char s_16[] PROGMEM = "SIXTEEN";
const char s_17[] PROGMEM = "SEVENTEEN";
const char s_18[] PROGMEM = "EIGHTEEN";
const char s_19[] PROGMEM = "NINETEEN";
const char s_20[] PROGMEM = "TWENTY";

const char s_noon[] PROGMEM = "NOON";
const char s_midnight[] PROGMEM = "MIDNIGHT";

const char s_itis[] PROGMEM = "IT IS ";

const char s_will_be_at[] PROGMEM = "WILL BE AT ";
const char s_was_at[] PROGMEM = "WAS AT ";
const char s_is_now[] PROGMEM = "IS HAPPENING NOW";

const char s_colon[] PROGMEM = "."; // ":" looks weird on alphanumeric

const char s_am[] PROGMEM = " AM";
const char s_pm[] PROGMEM = " PM";

const char s_manhattanhenge[] PROGMEM = "      IT IS MANHATTANHENGE      ";


// New York City
#define LATITUDE 40.6914
#define LONGITUDE -73.9899
#define GMTOFFSET -5

#define NUMCHARS 32
#define NUMALPHAS 8

//#define BRIGHTNESS 64

// how fast the letters flip
#define FLIPUPDELAY 15

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
char sunrisePhrase[NUMCHARS + 1];
char sunsetPhrase[NUMCHARS + 1];

Adafruit_AlphaNum4 alpha[NUMALPHAS];

RTC_DS3231 rtc; // clock object
DST_RTC dst; // dst object

// Define US or EU rules for DST comment out as required. More countries could be added with different rules in DST_RTC.cpp
const char rulesDST[] = "US"; // US DST rules
// const char rulesDST[] = "EU";   // EU DST rules

// brightness based on time of day
// 0-15
#define DAYBRIGHTNESS 15
#define NIGHTBRIGHTNESS 5

// cutoff times for day / night brightness. feel free to modify.
#define MORNINGCUTOFF 7  // when does daybrightness begin?   7am
#define NIGHTCUTOFF 22 // when does nightbrightness begin? 10pm


boolean firstTime = true; // save time recalculating sunrise/sunset


void setup() {
  // put your setup code here, to run once:

  delay(1000);
  Serial.begin(115200);

  // initialize all NUMALPHAS and clear
  for (uint8_t i = 0; i < NUMALPHAS; i++) {
    alpha[i].begin(0x70 + i); // pass in the addresses
    alpha[i].clear();
    alpha[i].setBrightness(DAYBRIGHTNESS); // quarter brightness
    alpha[i].writeDisplay();
  }

  // display each LED segment - check for bad connections
  displayAllSegs();

  // display every character,
  displayAllChars();

  //Serial.println("startup animation complete");
  delay(500);

  //THIRTY-TWO CHAR CLOCK, ANDY DORO
  //   THIRTY-TWO CHARACTER CLOCK
  strcpy(timePhrase, PSTR("THIRTY-TWO CHARACTER WORD CLOCK "));

  for (uint8_t i = 0; i < 100; i++) { // enough cycles to get there
    morphStrings();

    setChars();

    writeDisplays();

    //Serial.println("write displays");
    delay(FLIPUPDELAY);
  }

  delay(2000);

  if (! rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // When time needs to be re-set on a previously configured device, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2021, 2, 17, 17, 34, 0));

    // DST? If we're in it, let's subtract an hour from the RTC time to keep our DST calculation correct. This gives us
    // Standard Time which our DST check will add an hour back to if we're in DST.
    DateTime standardTime = rtc.now();
    if (dst.checkDST(standardTime) == true) { // check whether we're in DST right now. If we are, subtract an hour.
      standardTime = standardTime.unixtime() - 3600;
    }
    rtc.adjust(standardTime);
  }

  // adjust brightness on startup
  DateTime theTime = dst.calculateTime(rtc.now()); // takes into account DST
  adjustBrightness(theTime.hour());

  // figure out our phrases... need this in case of what mode we start up in
  dayLightPhrases(theTime);

}

void loop() {
  // put your main code here, to run repeatedly:

  // get the time
  //DateTime theTime = rtc.now();
  DateTime theTime = dst.calculateTime(rtc.now()); // takes into account DST

  byte theSec = theTime.second();
  byte tenSec = theSec / 10; // use to figure out which mode to enter
  //byte theHour = theTime.hour();

  // sunrise sunset
  // calculate once because it takes too long
  byte theHour = theTime.hour();
  byte theMin = theTime.minute();


  if (tenSec == 1) { // :10 - :19

    if (theSec < 15) { // :10 - :14
      // day of week
      dotwPhrase(theTime.dayOfTheWeek());

      // left justify
      leftJustify();

      // adjust brightness based on hour
      if (theSec == 12) { // only adjust once per minute...
        delay(1); // help with crashes?
        adjustBrightness(theHour);

        // get ready to calculate sunrise / sunset again
        firstTime = true;

        // only calculate once per minute, otherwise it's too slow
        if (firstTime == true) {
          dayLightPhrases(theTime);
        }
      }
    } else { // :15 - :19
      // date
      datePhrase(theTime.month(), theTime.day());
      rightJustify();
    }

  } else if (tenSec == 2) { // :20 - :29
    // special dates
    //byte theMon = theTime.month();
    byte theDay = theTime.day();
    // check for friday the 13th
    if (theDay == 13 && theTime.dayOfTheWeek() == 5) {
      // it's Friday the 13th!
      strcpy(timePhrase, PSTR("YIKES IT'S FRIDAY THE THIRTEENTH"));
    } else {
      holidate(theTime.month(), theDay, theHour, theMin);
    }
  } else if (tenSec == 3) { // :30 - :39
    strcpy(timePhrase, sunrisePhrase);

  } else if (tenSec == 4) { // :40 - :49
    strcpy(timePhrase, sunsetPhrase);

  } else { // :50 - :09
    // the time in words
    genTimePhrase(theHour, theMin);
  }

  printTheTime(theTime);

  Serial.println(F(timePhrase));

  morphStrings();

  setChars();

  writeDisplays();

  delay(FLIPUPDELAY);

}
