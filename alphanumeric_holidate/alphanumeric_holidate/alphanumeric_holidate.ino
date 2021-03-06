
// uses C strings / char arrays
// should move static strings into PROGMEM

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Alphanum32.h"

// clock libs
#include "RTClib.h"
#include "DST_RTC.h"
#include "Dusk2Dawn_mod.h"

// set time
#include "Adafruit_seesaw.h"
//#include <seesaw_neopixel.h>

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

const char s_am[] PROGMEM = " AM";
const char s_pm[] PROGMEM = " PM";

const char s_manhattanhenge[] PROGMEM = "      IT IS MANHATTANHENGE      ";

const char s_space[] PROGMEM = " ";

const char s_title[] PROGMEM = "THIRTY-TWO CHARACTER WORD CLOCK ";

// New York City
#define LATITUDE 40.6914
#define LONGITUDE -73.9899
#define GMTOFFSET -5

const byte NUMCHARS = 32;
const byte NUMALPHAS = 8;

// how fast the letters flip
const byte FLIPUPDELAY = 15;

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

Alphanum32 myAlphanum;

RTC_DS3231 rtc; // clock object
DST_RTC dst; // dst object

// Define US or EU rules for DST comment out as required. More countries could be added with different rules in DST_RTC.cpp
const char rulesDST[] = "US"; // US DST rules
// const char rulesDST[] = "EU";   // EU DST rules

// brightness based on time of day
// 0-15
const byte DAYBRIGHTNESS = 15;
const byte NIGHTBRIGHTNESS = 5;

// cutoff times for day / night brightness. feel free to modify.
const byte MORNINGCUTOFF = 7;  // when does daybrightness begin?   7am
const byte NIGHTCUTOFF = 22; // when does nightbrightness begin? 10pm

boolean firstTime = true; // save time recalculating sunrise/sunset

int dotPos = -1; // location for dot

int SR_dotPos = -1;
int SS_dotPos = -1;

const byte SS_DOTPOS = 26; // sunset dot doesn't change bc it's right justified

// rot encode constants
#define SS_SWITCH 24
//#define SS_NEOPIX        6

#define SEESAW_ADDR 0x36

boolean hasEncoder = true;

Adafruit_seesaw ss;
//seesaw_NeoPixel sspixel = seesaw_NeoPixel(1, SS_NEOPIX, NEO_GRB + NEO_KHZ800);
int32_t encoder_position;


boolean enterTimeSetMode = false;

byte timeSpanMode = 0; // keep track of what we're changing

int timeSetCounter = 0;

const int TIMESETCOUNTERLIMIT = 500;

const int SWITCH_DELAY = 50;

// lookup table for Time Set Mode dot positions
const byte timeSetDotPositions[6] = {28, 23, 18, 13, 8, 0};

void setup() {
  // put your setup code here, to run once:

  delay(500);
  Serial.begin(115200);

  // check for rot encoder
  if (! ss.begin(SEESAW_ADDR)) {
    Serial.println("Couldn't find seesaw on default address");
    //while (1) delay(10);
    hasEncoder = false;
  } else {
    //sspixel.begin(SEESAW_ADDR);
    Serial.println("seesaw started");

    uint32_t version = ((ss.getVersion() >> 16) & 0xFFFF);
    if (version  != 4991) {
      Serial.print("Wrong firmware loaded? ");
      Serial.println(version);
      //  while (1) delay(10);
    }
    Serial.println("Found Product 4991");

    // set not so bright!
    // sspixel.setBrightness(20);
    // sspixel.show();

    // use a pin for the built in encoder switch
    ss.pinMode(SS_SWITCH, INPUT_PULLUP);

    // get starting position
    encoder_position = ss.getEncoderPosition();

    Serial.println("Turning on interrupts");
    delay(10);
    ss.setGPIOInterrupts((uint32_t)1 << SS_SWITCH, 1);
    ss.enableEncoderInterrupt();
  }




  if (! rtc.begin()) {
    Serial.println(F("Couldn't find RTC"));
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
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

  // initialize all NUMALPHAS and clear
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

  //Serial.println("startup animation complete");
  delay(500);

  strcpy(timePhrase, s_title);
  for (uint8_t i = 0; i < 100; i++) { // enough cycles to get there
    morphStrings();

    setChars();

    myAlphanum.write();

    delay(FLIPUPDELAY);
  }

  delay(2000);

  // adjust brightness on startup
  DateTime theTime = dst.calculateTime(rtc.now()); // takes into account DST
  adjustBrightness(theTime.hour());

  // figure out our phrases... need this in case of what mode we start up in
  dayLightPhrases(theTime);

}

void loop() {
  // put your main code here, to run repeatedly:

  // get the time
  DateTime standardTime = rtc.now();
  //DateTime theTime = dst.calculateTime(standardTime); // takes into account DST

  // rot encoder
  if (hasEncoder) {
    if (! ss.digitalRead(SS_SWITCH)) {
      delay(SWITCH_DELAY); // debounce?
      //Serial.println("Button pressed!");
      Serial.println("TIME SET MODE");
      // go into time set mode
      enterTimeSetMode = true;
      timeSetCounter = 0; // reset counter
    }
  }

  if (enterTimeSetMode) {
    timeSetMode(standardTime);
  } else {

    // default display modes
    DateTime theTime = dst.calculateTime(standardTime); // takes into account DST

    byte theSec = theTime.second();
    byte tenSec = theSec / 10; // use to figure out which mode to enter

    byte theHour = theTime.hour();
    byte theMin = theTime.minute();
    byte theDay = theTime.day();

    dotPos = -1; // default don't show dotPos

    switch (tenSec) { // which time mode to display
      case 1: // :10 - :19

        if (theSec < 15) { // :10 - :14
          // day of week
          dotwPhrase(theTime.dayOfTheWeek());

          // left justify
          leftJustify();

          if (theSec == 12 && firstTime) { // only adjust once per minute...
            // adjust brightness based on hour
            adjustBrightness(theHour);
            // calculate dayLightPhrases
            // we can probably do this more efficiently, saving sunrise, sunset once per day and then comparing to current time
            dayLightPhrases(theTime);
          }
        } else { // :15 - :19
          // date
          datePhrase(theTime.month(), theDay);
          rightJustify();
        }
        break;

      case 2: // :20 - :29
        // special dates
        // check for friday the 13th
        if (theDay == 13 && theTime.dayOfTheWeek() == 5) {
          // it's Friday the 13th!
          strcpy(timePhrase, PSTR("YIKES IT'S FRIDAY THE THIRTEENTH"));
        } else {
          holidate(theTime.month(), theDay, theHour, theMin);
        }
        break;

      case 3:  // :30 - :39
        strcpy(timePhrase, sunrisePhrase);
        dotPos = SR_dotPos;
        break;

      case 4: // :40 - :49
        strcpy(timePhrase, sunsetPhrase);
        dotPos = SS_dotPos;
        break;

      default: // :50 - :09
        // get ready to calculate sunrise / sunset again
        firstTime = true;

        // the time in words
        genTimePhrase(theHour, theMin);
        break;
    }

    printTheTime(theTime);

    Serial.println(F(timePhrase));

    morphStrings();

    setChars();

    myAlphanum.write();

    delay(FLIPUPDELAY);
  }
}
