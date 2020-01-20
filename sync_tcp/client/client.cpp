#include <ESP8266WiFi.h>

#include "access.h"
#include "LoopLogger.h"

void setup() {
	Serial.begin(115200);
	delay(20);

	// connects to access point
	WiFi.mode(WIFI_STA);
	WiFi.begin(SSID, PASSWORD);
	while (WiFi.status() != WL_CONNECTED) {
		Serial.print('.');
		delay(500);
	}
}

LoopLogger loopLogger(5000);
unsigned long prevTimeSent{0};
bool timeToSend()
{
    return (millis() - prevTimeSent) >= 1000;
}
int counter = 0;
void loop()
{
    loopLogger.step();
    if (timeToSend())
    {
        WiFiClient client;
        if (client.connect("192.168.4.1", TCP_PORT))
        {
            Serial.printf("sending message %u \n\r", counter);
            String msg(counter++);
            client.print(msg);
        }
        else
        {
            Serial.printf("client connect failed! \n\r");
        }
        prevTimeSent = millis();
    }
}
