
#include "Arduino.h"
#include "Components.h"
#include "Pins.h"

// Variable to store the HTTP request
String header{""};

// Auxiliar variables to store the current output state
String output5State = "off";
String output4State = "off";

class HttpLines
{
public:
	const String& operator[](const int idx) const
	{
		if (idx >= numOf) { return empty; }
		return *lines[idx];
	}
	int length() const { return numOf; }
	bool add(const String& line)
	{
		if (numOf >= max_lines) { return false; }
		lines[numOf] = new String(line + String("\n"));
	    numOf++;
		return true;
	}
private:
	static constexpr int max_lines{20};
	static const String empty;
	int numOf{};
	String* lines[max_lines]{nullptr};
};
const String HttpLines::empty{};

class HttpParser
{
public:
	HttpParser()
	{
		createHeader();
	}
	void createHeader()
	{
        // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
        // and a content-type so the client knows what's coming, then a blank line:
		headerLines.add(String("HTTP/1.1 200 OK"));
		headerLines.add(String("Content-type:text/html"));
		headerLines.add(String("Connection: close"));
		headerLines.add(String(""));
	}
	const HttpLines& header() const
	{
		return headerLines;
	}
private:
	HttpLines headerLines{};
};

HttpParser httpParser;

void printHttpHeader(WiFiClient& client)
{
	const HttpLines& httpHeader = httpParser.header();
	for (int i = 0; i < httpHeader.length(); i++)
	{
		const String& line = httpHeader[i];
		client.println(line);
	}
}
void loop()
{
	 WiFiClient client = server.available();   // Listen for incoming clients

	  if (client) {                             // If a new client connects,
	    lcd.setCursor(0,2);
	    //lcd.print("New Client.");          // print a message out in the serial port
	    String currentLine = "";                // make a String to hold incoming data from the client
	    while (client.connected()) {            // loop while the client's connected
	      if (client.available()) {             // if there's bytes to read from the client,
	        char c = client.read();             // read a byte, then
	        //lcd.print(c);                    // print it out the serial monitor
	        header += c;
	        if (c == '\n') {                    // if the byte is a newline character
	          // if the current line is blank, you got two newline characters in a row.
	          // that's the end of the client HTTP request, so send a response:
	          if (currentLine.length() == 0) {
	        	printHttpHeader(client);

	            // turns the GPIOs on and off
	            if (header.indexOf("GET /5/on") >= 0) {
	              lcd.print("GPIO 5 on ");
	            } else if (header.indexOf("GET /5/off") >= 0) {
	              lcd.print("GPIO 5 off");
	            } else if (header.indexOf("GET /4/on") >= 0) {
	              lcd.print("GPIO 4 on ");
	            } else if (header.indexOf("GET /4/off") >= 0) {
	              lcd.print("GPIO 4 off");
	            }

	            // Display the HTML web page
	            client.println("<!DOCTYPE html><html>");
	            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
	            client.println("<link rel=\"icon\" href=\"data:,\">");
	            // CSS to style the on/off buttons
	            // Feel free to change the background-color and font-size attributes to fit your preferences
	            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
	            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
	            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
	            client.println(".button2 {background-color: #77878A;}</style></head>");

	            // Web Page Heading
	            client.println("<body><h1>ESP8266 Web Server</h1>");

	            // Display current state, and ON/OFF buttons for GPIO 5
	            client.println("<p>GPIO 5 - State " + output5State + "</p>");
	            // If the output5State is off, it displays the ON button
	            if (output5State=="off") {
	              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
	            } else {
	              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
	            }

	            // Display current state, and ON/OFF buttons for GPIO 4
	            client.println("<p>GPIO 4 - State " + output4State + "</p>");
	            // If the output4State is off, it displays the ON button
	            if (output4State=="off") {
	              client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
	            } else {
	              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
	            }
	            client.println("</body></html>");

	            // The HTTP response ends with another blank line
	            client.println();
	            // Break out of the while loop
	            break;
	          } else { // if you got a newline, then clear currentLine
	            currentLine = "";
	          }
	        } else if (c != '\r') {  // if you got anything else but a carriage return character,
	          currentLine += c;      // add it to the end of the currentLine
	        }
	      }
	    }
	    // Clear the header variable
	    header = "";
	    // Close the connection
	    client.stop();
	    //Serial.println("Client disconnected.");
	    //Serial.println("");
	  }
}
