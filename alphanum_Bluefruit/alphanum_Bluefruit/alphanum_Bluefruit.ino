/*********************************************************************
  QuadAlphaNum Bluefruit Display

  Hardware
  - QuadAlphaNum x 8 https://www.adafruit.com/product/2157
  - Feather Bluefruit 32u4 - compile as Feather 32u4 https://www.adafruit.com/product/2829

  This is an example for our nRF51822 based Bluefruit LE modules

  Pick one up today in the adafruit shop!

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  MIT license, check LICENSE for more information
  All text above, and the splash screen below must be included in
  any redistribution
*********************************************************************/

#include <Arduino.h>
#include <SPI.h>
#if not defined (_VARIANT_ARDUINO_DUE_X_) && not defined (_VARIANT_ARDUINO_ZERO_)
#include <SoftwareSerial.h>
#endif

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Alphanum32.h"

#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "Adafruit_BluefruitLE_UART.h"

#include "BluefruitConfig.h"


#define NUMCHARS 32
#define NUMALPHAS 8

#define BRIGHTNESS 15

// how fast the letters flip
#define FLIPUPDELAY 5

// makes them all clear
char displaybuffer[NUMCHARS + 1] = {' ', ' ', ' ', ' ',
                                    ' ', ' ', ' ', ' ',
                                    ' ', ' ', ' ', ' ',
                                    ' ', ' ', ' ', ' ',
                                    ' ', ' ', ' ', ' ',
                                    ' ', ' ', ' ', ' ',
                                    ' ', ' ', ' ', ' ',
                                    ' ', ' ', ' ', ' '
                                   };

char targetString[NUMCHARS + 1] = {' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' '
                                  };

char tempString[NUMCHARS + 1] = {' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' ',
                                 ' ', ' ', ' ', ' '
                                };

int k = 0;

// flag to see if msg was sent
boolean msgSent = false;

Alphanum32 myAlphanum;

/*=========================================================================
    APPLICATION SETTINGS

      FACTORYRESET_ENABLE       Perform a factory reset when running this sketch
     
                                Enabling this will put your Bluefruit LE module
                              in a 'known good' state and clear any config
                              data set in previous sketches or projects, so
                                running this at least once is a good idea.
     
                                When deploying your project, however, you will
                              want to disable factory reset by setting this
                              value to 0.  If you are making changes to your
                                Bluefruit LE device via AT commands, and those
                              changes aren't persisting across resets, this
                              is the reason why.  Factory reset will erase
                              the non-volatile memory where config data is
                              stored, setting it back to factory default
                              values.
         
                                Some sketches that require you to bond to a
                              central device (HID mouse, keyboard, etc.)
                              won't work at all with this feature enabled
                              since the factory reset will clear all of the
                              bonding data stored on the chip, meaning the
                              central device won't be able to reconnect.
    MINIMUM_FIRMWARE_VERSION  Minimum firmware version to have some new features
    MODE_LED_BEHAVIOUR        LED activity, valid options are
                              "DISABLE" or "MODE" or "BLEUART" or
                              "HWUART"  or "SPI"  or "MANUAL"
    -----------------------------------------------------------------------*/
#define FACTORYRESET_ENABLE         1
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
#define MODE_LED_BEHAVIOUR          "MODE"
/*=========================================================================*/

// Create the bluefruit object, either software serial...uncomment these lines
/*
  SoftwareSerial bluefruitSS = SoftwareSerial(BLUEFRUIT_SWUART_TXD_PIN, BLUEFRUIT_SWUART_RXD_PIN);

  Adafruit_BluefruitLE_UART ble(bluefruitSS, BLUEFRUIT_UART_MODE_PIN,
                      BLUEFRUIT_UART_CTS_PIN, BLUEFRUIT_UART_RTS_PIN);
*/

/* ...or hardware serial, which does not need the RTS/CTS pins. Uncomment this line */
// Adafruit_BluefruitLE_UART ble(BLUEFRUIT_HWSERIAL_NAME, BLUEFRUIT_UART_MODE_PIN);

/* ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST */
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);

/* ...software SPI, using SCK/MOSI/MISO user-defined SPI pins and then user selected CS/IRQ/RST */
//Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_SCK, BLUEFRUIT_SPI_MISO,
//                             BLUEFRUIT_SPI_MOSI, BLUEFRUIT_SPI_CS,
//                             BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);


// A small helper
void error(const __FlashStringHelper*err) {
  Serial.println(err);
  while (1);
}

/**************************************************************************/
/*!
    @brief  Sets up the HW an the BLE module (this function is called
            automatically on startup)
*/
/**************************************************************************/
void setup(void)
{
  //while (!Serial);  // required for Flora & Micro
  delay(500);

  Serial.begin(115200);
  Serial.println(F("Adafruit Bluefruit Command <-> Data Mode Example"));
  Serial.println(F("------------------------------------------------"));

  /* Initialise the module */
  Serial.print(F("Initialising the Bluefruit LE module: "));

  if ( !ble.begin(VERBOSE_MODE) )
  {
    error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }
  Serial.println( F("OK!") );

  if ( FACTORYRESET_ENABLE )
  {
    /* Perform a factory reset to make sure everything is in a known state */
    Serial.println(F("Performing a factory reset: "));
    if ( ! ble.factoryReset() ) {
      error(F("Couldn't factory reset"));
    }
  }

  /* Disable command echo from Bluefruit */
  ble.echo(false);

  Serial.println("Requesting Bluefruit info:");
  /* Print Bluefruit information */
  ble.info();

  Serial.println(F("Please use Adafruit Bluefruit LE app to connect in UART mode"));
  Serial.println(F("Then Enter characters to send to Bluefruit"));
  Serial.println();

  ble.verbose(false);  // debug info is a little annoying after this point!


  // initialize display and clear
  myAlphanum.begin();
  myAlphanum.clear();
  myAlphanum.brightness(BRIGHTNESS); // max brightness
  myAlphanum.write();

  // display each LED segment - check for bad connections
  myAlphanum.displayAllSegs(20);
  delay(1000);

  // display all ASCII chars
  myAlphanum.displayAllChars(20);
  delay(500);


  /* Wait for connection */
  while (! ble.isConnected()) {
    delay(500);
  }

  Serial.println(F("******************************"));

  // LED Activity command is only supported from 0.6.6
  if ( ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION) )
  {
    // Change Mode LED Activity
    Serial.println(F("Change LED activity to " MODE_LED_BEHAVIOUR));
    ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR);
  }

  // Set module to DATA mode
  Serial.println( F("Switching to DATA mode!") );
  ble.setMode(BLUEFRUIT_MODE_DATA);

  Serial.println(F("******************************"));

  //Serial.println("Start typing to display!");
  //Serial.write('ready');

}

/**************************************************************************/
/*!
    @brief  Constantly poll for new command or response data
*/
/**************************************************************************/
void loop(void)
{

  // only if there's data...
  //if ( ble.available() ) {
  if (ble.available() > 0) {

    char c = ble.read();
    //Serial.print(c);

    if (! isPrintable(c)) return; // only printable!
    
    // build buffer
    if (k < NUMCHARS) {
      displaybuffer[k] = c;
    }
    k++;

    msgSent = true;
  } else {
    // reset buffer
    // clear chars that weren't set in last message
    for (uint8_t i = k; i < NUMCHARS; i++) {
      displaybuffer[i] = ' ';
    } 

    if (msgSent) {
      strcpy(targetString, displaybuffer);
      //targetString[k] = c;
      Serial.println(targetString);
      msgSent = false;
    }

    //Serial.println("reset!");
    k = 0;
  }

  // move to morphStrings() ?
  for (uint8_t j = 0; j < NUMCHARS; j++) {
    if ( !(tempString[j] == targetString[j]) ) { // if the chars doesn't match...
      tempString[j] = tempString[j] + 1;
      //if (tempString[j] == NULL) {
      //  tempString[j] = ' ';
      //}
      // rollover
      if (tempString[j] > '~') { // that's the last ASCII char!
        tempString[j] = ' '; // first ASCII char
      }
    }
    //Serial.println(tempString);
  }

  // set every digit to the buffer
  for (uint8_t i = 0; i < NUMCHARS; i++) {
    myAlphanum.writeDigitAscii(i, tempString[i]);
  }

  //writeDisplays();
  myAlphanum.write();
  delay(FLIPUPDELAY);



}
