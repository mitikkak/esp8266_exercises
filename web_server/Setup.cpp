#include "Arduino.h"
#include "Pins.h"
#include "Credentials.h"
#include "Components.h"

void setup()
{
	  Serial.begin(115200);
	  // Initialize the output variables as outputs
	  pinMode(output5, OUTPUT);
	  pinMode(output4, OUTPUT);
	  // Set outputs to LOW
	  digitalWrite(output5, LOW);
	  digitalWrite(output4, LOW);

	  // Connect to Wi-Fi network with SSID and password
	  Serial.print("Connecting to ");
	  Serial.println(ssid);
	  WiFi.begin(ssid, password);
	  while (WiFi.status() != WL_CONNECTED) {
	    delay(500);
	    Serial.print(".");
	  }
	  // Print local IP address and start web server
	  Serial.println("");
	  Serial.println("WiFi connected.");
	  Serial.println("IP address: ");
	  Serial.println(WiFi.localIP());
	  server.begin();
}
