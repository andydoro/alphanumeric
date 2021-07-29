/*
   display the weather using ESP8266

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
#include "WeatherClient.h"

// New York City
#define LATITUDE 40.71
#define LONGITUDE -74

#define NUMCHARS 32
#define NUMALPHAS 8


#define COUNTERLIMIT 400

#define STARTUPCOUNTER 60

#define PHRASENUM 5

int counter = 0;
int phraseCounter = 0;

String overflowStr;

bool overflowSwitch = false; // if we have too many chars

bool overflowFirstSwitch = false; // if we have too many chars

// how fast the letters flip
#define FLIPUPDELAY 7

#define SCROLLDELAY 70

#define DAYBRIGHTNESS 15

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


char theWeather[NUMCHARS + 1];

Alphanum32 myAlphanum;

WeatherClient weather;
Ticker ticker;

// your network SSID (name)
char ssid[] = WIFISSID;

// your network password
char pass[] = PASSWORD;

// Go to forecast.io and register for an API KEY
String forecastApiKey = FORECASTAPIKEY;

// website domain name
String webDomain = DOMAINNAME;


// Coordinates of the place you want
// weather information for
double latitude = LATITUDE;
double longitude = LONGITUDE;


// flag changed in the ticker function every 10 minutes
bool readyForWeatherUpdate = true;


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


  // update the weather information every 10 mintues only
  // forecast.io only allows 1000 calls per day
  ticker.attach(60 * 10, setReadyForWeatherUpdate);

  strcpy(theWeather, PSTR("        WEATHER FORECAST        "));

  for (uint8_t i = 0; i < STARTUPCOUNTER; i++) { // enough cycles to get there
    morphStrings();
    setChars();
    // set every digit to the buffer

    myAlphanum.write();
    //writeDisplays();
    //Serial.println("write displays");
    delay(FLIPUPDELAY);
  }
  delay(500);


}

void loop() {
  // put your main code here, to run repeatedly:


  if (readyForWeatherUpdate) {
    readyForWeatherUpdate = false;
    weather.updateWeatherData(webDomain, forecastApiKey, latitude, longitude);
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
      tempString[j] = theWeather[j];
    }

    setChars();
    myAlphanum.write();

    delay(SCROLLDELAY);
  } else {
    // use Ticker?
    if (counter > COUNTERLIMIT) {

      switch (phraseCounter) {

        case 0: // currently
          {
            String current = String(weather.getCurrentTemp());

            current = "CURRENTLY " + current + " AND " + weather.getCurrentSummary();

            if (current.length() > 32) {
              overflowFirstSwitch = true;
              overflowStr = current; // save the whole string to overflow
              current.remove(32); // trim the excess
            }

            // convert to char array
            String2CharArray(current);

          }
          break;

        case 1: // today high and low
          {
            String highlow = String(weather.getMaxTempToday());

            highlow = "TODAY HIGH " + highlow + " LOW " + weather.getMinTempToday();

            // convert to char array
            String2CharArray(highlow);

          }
          break;

        case 2: // today summary
          {
            String todaySum = weather.getSummaryToday();
            //todaySum.toUpperCase();

            todaySum = "TODAY " + todaySum;

            if (todaySum.length() > 32) {
              overflowFirstSwitch = true;
              overflowStr = todaySum; // save the whole string to overflow
              todaySum.remove(32); // trim the excess
            }

            // convert to char array
            String2CharArray(todaySum);
          }
          break;

        case 3: // tomorrow high and low
          {

            String highlow = String(weather.getMaxTempTomorrow());

            highlow = "TOMORROW HIGH " + highlow + " LOW " + weather.getMinTempTomorrow();

            // convert to char array
            String2CharArray(highlow);

          }
          break;

        case 4: // tomorrow summary
          {
            String tomSum = weather.getSummaryTomorrow();

            tomSum = "TOMORROW " + tomSum;

            if (tomSum.length() > 32) {
              overflowFirstSwitch = true;
              overflowStr = tomSum; // save the whole string to overflow
              tomSum.remove(32); // trim the excess
            }

            // convert to char array
            String2CharArray(tomSum);
          }
          break;

      }


      // format string
      if (strlen(theWeather) > 32) {
        theWeather[33] = '\0';

        //save overflow string?
      } else {

        int blanks = 32 - strlen(theWeather); // catch overflow if message is 32+ ?

        /*
          // left justified
            for (int i = 0; i < blanks; i++) {
              strcat(theWeather, " ");
              //strcat(" ", timePhrase);
            };
        */
        // right justified
        memmove(theWeather + blanks, theWeather, strlen(theWeather));
        for (int i = 0; i < blanks; i++) {
          theWeather[i] = ' ';
        }
      }

      Serial.println(theWeather);

      if (overflowSwitch == false) {
        phraseCounter++; // increment
        Serial.println("increment");

      }

      phraseCounter %= PHRASENUM; // prevent rollover
      Serial.print("phrasenum: ");
      Serial.println(phraseCounter);

      counter = 0;

    }

    morphStrings();

    setChars();

    //writeDisplays();
    myAlphanum.write();


    if (overflowFirstSwitch && counter > 80) {
      overflowSwitch = true;
      overflowFirstSwitch = false;
      //counter = 0;
    }

    counter++;

    delay(FLIPUPDELAY);
  }
}
