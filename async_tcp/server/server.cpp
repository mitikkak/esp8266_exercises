#ifdef ESP32
#include "WiFi.h"
#include "AsyncTCP.h"
#include "ESPmDNS.h"
#else
#include "ESP8266WiFi.h"
#include "ESPAsyncTCP.h"
#include "ESP8266mDNS.h"
#endif
#include <vector>

#include "access.h"
#include "LoopLogger.h"

static std::vector<AsyncClient*> clients; // a list to hold all clients

 /* clients events */
static void handleError(void* arg, AsyncClient* client, int8_t error) {
	Serial.printf("[%lu] connection error %s from client %s \n\r", millis(), client->errorToString(error), client->remoteIP().toString().c_str());
}

unsigned int expected = 0;
static void handleData(void* arg, AsyncClient* client, void *data, size_t len) {
	Serial.printf("[%lu] data received from client %s \n\r", millis(), client->remoteIP().toString().c_str());
	Serial.write((uint8_t*)data, len);
	Serial.printf(" expected: %u \n\r", expected);
	expected++;

#if 0
	// reply to client
	if (client->space() > 32 && client->canSend()) {
		char reply[32];
		sprintf(reply, "this is from %s", SERVER_HOST_NAME);
		client->add(reply, strlen(reply));
		client->send();
	}
#endif
}

static void handleDisconnect(void* arg, AsyncClient* client) {
	Serial.printf("[%lu] client %s disconnected \n\r", millis(), client->remoteIP().toString().c_str());
}

static void handleTimeOut(void* arg, AsyncClient* client, uint32_t time) {
	Serial.printf("[%lu] client ACK timeout ip: %s \n\r", millis(), client->remoteIP().toString().c_str());
}


/* server events */
static void handleNewClient(void* arg, AsyncClient* client) {
	Serial.printf("[%lu] new client has been connected to server, ip: %s\n\r", millis(), client->remoteIP().toString().c_str());

	// add to list
	clients.push_back(client);
	
	// register events
	client->onData(&handleData, NULL);
	client->onError(&handleError, NULL);
	client->onDisconnect(&handleDisconnect, NULL);
	client->onTimeout(&handleTimeOut, NULL);
}

void setup() {
	Serial.begin(115200);
	delay(20);
	
	// create access point
	while (!WiFi.softAP(SSID, PASSWORD, 6, false, 15)) {
		delay(500);
	}

	// start dns server
	if (not MDNS.begin(SERVER_HOST_NAME))
	{
		Serial.printf("failed to start dns service \n\r");
	}

	AsyncServer* server = new AsyncServer(TCP_PORT); // start listening on tcp port 7050
	server->onClient(&handleNewClient, server);
	server->setNoDelay(true);
	server->begin();
}

LoopLogger loopLogger(5000);
void loop() {
	loopLogger.step();
}
