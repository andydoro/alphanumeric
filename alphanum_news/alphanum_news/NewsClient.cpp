/**The MIT License (MIT)

  Copyright (c) 2015 by Daniel Eichhorn

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  See more at http://blog.squix.ch
*/

#include "NewsClient.h"
#include <ESP8266WiFi.h>

#define URLPATH "/path/to/news.php"

void NewsClient::updateNewsData(String domainName) {
  WiFiClient client;
  const int httpPort = 80;

  skips = 0;

  Serial.print("Connecting to server: ");
  Serial.println(domainName);

  // connnect to our server
  while (!client.connect(domainName.c_str(), httpPort)) {
    Serial.println("connection failed, retrying...");
    delay(10000);
  }

  // We now create a URI for the request
  String url = "http://" + domainName + URLPATH;

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: YOURDOMAINNAME\r\n" +
               "Connection: close\r\n\r\n");

  // wait for response from server
  while (!client.available()) {

    delay(200);
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
    String key = getKey(line);
    if (key.length() > 0) {
      String value = getValue(line);
      for (int i = 0; i < PHRASENUM; i++) {
        if (key.toInt() == i) {
          headline[i] = value;
        }
      }
    }
  }

  Serial.println();
  Serial.println("closing connection");
}

String NewsClient::getKey(String line) {
  int separatorPosition = line.indexOf("=");
  if (separatorPosition == -1) {
    skips++;
    return "";
  }
  return line.substring(0, separatorPosition);
}

String NewsClient::getValue(String line) {
  int separatorPosition = line.indexOf("=");
  if (separatorPosition == -1) {
    return "";
  }
  return line.substring(separatorPosition + 1);
  //return line;
}

String NewsClient::getHeadline(int i) {
  return headline[i];
}

int NewsClient::getSkips(void) {
  return skips;
}
