#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include "access.h"
#include "LoopLogger.h"

WiFiServer wifiServer(TCP_PORT);

static DNSServer DNS;

void setup() {
	Serial.begin(115200);
	delay(20);
	
	// create access point
	while (!WiFi.softAP(SSID, PASSWORD, 6, false, 15)) {
		delay(500);
	}
	Serial.println(WiFi.softAPIP());
    // start dns server
    if (!DNS.start(DNS_PORT, SERVER_HOST_NAME, WiFi.softAPIP()))
        Serial.printf("failed to start dns service \n\r");

	wifiServer.begin();
}

LoopLogger loopLogger(5000);
void loop() {
    WiFiClient client = wifiServer.available();

    if (client) {

      while (client.connected()) {

        while (client.available()>0) {
          char c = client.read();
          Serial.write(c);
        }

        delay(10);
      }

      client.stop();
      Serial.println("Client disconnected");

    }
	loopLogger.step();
}
