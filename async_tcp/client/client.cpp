#ifdef ESP32
#include "WiFi.h"
#include "AsyncTCP.h"
#else
#include "ESP8266WiFi.h"
#include "ESPAsyncTCP.h"
#endif

//extern "C" {
//#include <osapi.h>
//#include <os_type.h>
//}

#include "access.h"
#include "LoopLogger.h"

//static os_timer_t intervalTimer;

int counter{0};
static void sendToServer(void* arg) {
	AsyncClient* client = reinterpret_cast<AsyncClient*>(arg);

	// send reply
	Serial.printf("[%lu] space: %lu canSend: %u \n\r", millis(), client->space(), client->canSend());
	if (client->space() > 32 && client->canSend()) {
		//char message[32];
		//sprintf(message, "%s", WiFi.localIP().toString().c_str());
	    String message(counter);
		client->add(message.c_str(), message.length());
		client->send();
		counter++;
	}
}

/* event callbacks */
static void handleData(void* arg, AsyncClient* client, void *data, size_t len) {
	Serial.printf("[%lu] data received from %s \n\r", millis(), client->remoteIP().toString().c_str());
	Serial.write((uint8_t*)data, len);

	//os_timer_arm(&intervalTimer, 2000, true); // schedule for reply to server at next 2s
}
static void handleAck(void* arg, AsyncClient* client, size_t len, uint32_t time)
{
    Serial.printf("[%lu] handleAck \n\r", millis());
}

static void handleAckTimeout(void* arg, AsyncClient* client, uint32_t time)
{
    Serial.printf("[%lu] handleAckTimeout \n\r", millis());
}

void onConnect(void* arg, AsyncClient* client) {
	Serial.printf("[%lu] client has been connected to %s on port %d \n\r", millis(), SERVER_HOST_NAME, TCP_PORT);
	//sendToServer(client);
}

AsyncClient* client{nullptr};
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

	client = new AsyncClient;
	client->onData(&handleData, client);
	client->onConnect(&onConnect, client);
	client->connect(SERVER_HOST_NAME, TCP_PORT);
	client->onAck(&handleAck, client);
	client->onTimeout(&handleAckTimeout, client);
	Serial.printf("client [%u][%u][%u][%u] \n\r", client->getMss(), client->getRxTimeout(), client->getAckTimeout(), client->getNoDelay());

//	os_timer_disarm(&intervalTimer);
//	os_timer_setfn(&intervalTimer, &sendToServer, client);
}

LoopLogger loopLogger(5000);
unsigned long prevTimeSent{0};
bool timeToSend()
{
    return (millis() - prevTimeSent) >= 1000;
}
void loop()
{
    loopLogger.step();
    if (timeToSend())
    {
        sendToServer(client);
        prevTimeSent = millis();
    }
}
