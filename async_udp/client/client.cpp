#include <ESP8266WiFi.h>
#include "ESPAsyncUDP.h"
#include "access_point.h"

AsyncUDP udp;

void setup()
{
    Serial.begin(115200);
    Serial.println("client begins");
    delay(1000);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("WiFi Failed");
        while(1) {
            delay(1000);
        }
    }
    if(udp.connect(IPAddress(192,168,4,1), 1234)) {
        Serial.println("UDP connected");
        udp.onPacket([](AsyncUDPPacket packet) {
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
            //reply to the client
            //packet.printf("Got %u bytes of data", packet.length());
        });
        //Send unicast
//        udp.print("Hello Server!");
    }
}

int counter = 0;
unsigned long prevTimeSent = 0;
bool timeToSend()
{
    return (millis() - prevTimeSent) > 50;
}
void loop()
{
    if (timeToSend())
    {
        String message;
        message += counter++;
        udp.print(message);
        prevTimeSent = millis();
    }
}
