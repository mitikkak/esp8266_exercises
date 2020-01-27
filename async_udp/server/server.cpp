#ifdef ESP32
#include "WiFi.h"
#include "AsyncUDP.h"
#else
#include <ESP8266WiFi.h>
#include "ESPAsyncUDP.h"
#endif
#include "access_point.h"

AsyncUDP udp;

unsigned int numOfMsgs{0}, numOfSkipped{0};
unsigned int sn{0};
String message{};
bool msgReceived{false};
void setup()
{
    Serial.begin(115200);
//    WiFi.mode(WIFI_STA);
    WiFi.softAP(ssid, password);
    Serial.println("IP: ");
    Serial.println(WiFi.softAPIP());

    if(udp.listen(1234)) {
        Serial.print("UDP Listening on IP: ");
        Serial.println(WiFi.localIP());
        udp.onPacket([](AsyncUDPPacket packet) {
#if 0
            Serial.print("UDP Packet Type: ");
            Serial.print(packet.isBroadcast()?"Broadcast":packet.isMulticast()?"Multicast":"Unicast");
            Serial.print(", From: ");
            Serial.print(packet.remoteIP());
            Serial.print(":");
            Serial.print(packet.remotePort());
            Serial.print(", To: ");
            Serial.print(packet.localIP());
            Serial.print(":");
            Serial.print(packet.localPort());
            Serial.print(", Length: ");
            Serial.print(packet.length());
            Serial.print(", Data: ");
            Serial.write(packet.data(), packet.length());
            Serial.println();
#endif
            numOfMsgs++;
#if 0
            const char* data = (char*) packet.data();
            unsigned int newSn = atoi(data);
            numOfSkipped += (newSn - sn) - 1;
            sn = newSn;
#else
            message = String((const char*) packet.data());
            //Serial.printf("[%lu] RCV %u %u \n\r", millis(), message.length(), packet.length());
#endif
            msgReceived = true;
            //reply to the client
            //packet.printf("Got %u bytes of data", packet.length());
        });
    }
}

unsigned long prevTimeReport = 0;
bool timeToReport()
{
    return msgReceived;
    //return (millis() - prevTimeReport) > 5000;
}

void loop()
{
    if (timeToReport())
    {
        //Serial.printf("numOfMsgs: %u, sn: %u, numOfSkipped: %u \n\r", numOfMsgs, sn, numOfSkipped);
        Serial.println(message);
        prevTimeReport = millis();
        numOfSkipped = 0;
        numOfMsgs = 0;
        msgReceived = false;
    }
//    delay(1000);
    //Send broadcast
    //udp.print("Greetings from server!");
    //udp.broadcast("Anyone here?");
}
