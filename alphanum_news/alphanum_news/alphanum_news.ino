/*
   display the news using ESP8266

   feather huzzah esp8266
   - make sure EN pin is not attached!
   https://learn.adafruit.com/adafruit-feather-huzzah-esp8266/pinouts

*/
#include <avr/pgmspace.h>
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Alphanum32.h"

#include "_secrets.h"
#include <Ticker.h>
#include <ESP8266WiFi.h>
#include "NewsClient.h"


#define NUMCHARS 32
#define NUMALPHAS 8

#define COUNTERLIMIT 360
#define INITALLIMIT 165
#define STARTUPCOUNTER 60

// how fast the letters flip
#define FLIPUPDELAY 7

#define SCROLLDELAY 80

#define DAYBRIGHTNESS 15

int counter = 0;
int phraseCounter = 0;

String overflowStr;

bool overflowSwitch = false; // if we have too many chars

bool overflowFirstSwitch = false; // if we have too many chars



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


char theHeadline[NUMCHARS + 1];

Alphanum32 myAlphanum;

NewsClient news;
Ticker ticker;

// your network SSID (name)
char ssid[] = WIFISSID;

// your network password
char pass[] = PASSWORD;


// website domain name
String webDomain = DOMAINNAME;


// flag changed in the ticker function every 10 minutes
bool readyForNewsUpdate = true;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

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

  delay(500);

  // We start by connecting to a WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  counter = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    // could print something to display...

    counter++;
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  // update the news information every 5 mintues only
  ticker.attach(60 * 5, setReadyForNewsUpdate);

  strcpy(theHeadline, PSTR("         NEWS HEADLINES         "));

  for (uint8_t i = 0; i < STARTUPCOUNTER; i++) { // enough cycles to get there
    morphStrings();
    setChars();
    //writeDisplays();
    myAlphanum.write();
    //Serial.println("write displays");
    delay(FLIPUPDELAY);
  }
  delay(500);


}

void loop() {
  // put your main code here, to run repeatedly:


  if (readyForNewsUpdate) {
    readyForNewsUpdate = false;
    news.updateNewsData(webDomain);
  }

  if (overflowSwitch) {

    //  scroll..
    overflowStr.remove(0, 1); // chop off first char

    if (overflowStr.length() < 33) {
      overflowSwitch = false;
      overflowFirstSwitch = false;
      Serial.println("overflow off!");
    }

    String tempStr = overflowStr.substring(0, 32); // trim the excess

    String2CharArray(tempStr);

    for (uint8_t j = 0 ; j < NUMCHARS; j++) {
      tempString[j] = theHeadline[j];
    }
    setChars();

    //writeDisplays();
    myAlphanum.write();

    delay(SCROLLDELAY);
  } else {
    // use Ticker?
    if (counter > COUNTERLIMIT) {

      String headline = news.getHeadline(phraseCounter);

      if (headline.length() > 32) {
        overflowFirstSwitch = true;
        overflowStr = headline; // save the whole string to overflow
        headline.remove(32); // trim the excess
      }

      // convert to char array
      String2CharArray(headline);


      // format string
      if (strlen(theHeadline) > 32) {
        theHeadline[33] = '\0';

        //save overflow string?
      } else {

        rightJustify();
      }

      Serial.println(theHeadline);

      if (overflowSwitch == false) {
        phraseCounter++; // increment
        //Serial.println("increment");

      }

      phraseCounter %= (PHRASENUM + 2 - news.getSkips()); // prevent rollover
      Serial.print("phrasenum: ");
      Serial.println(phraseCounter);
      Serial.print("skips: ");
      Serial.println(news.getSkips());

      counter = 0;

    }

    morphStrings();

    setChars();

    //writeDisplays();
    myAlphanum.write();

    if (overflowFirstSwitch && counter > INITALLIMIT) {
      overflowSwitch = true;
      overflowFirstSwitch = false;
      //counter = 0;
    }

    counter++;

    delay(FLIPUPDELAY);
  }
}
