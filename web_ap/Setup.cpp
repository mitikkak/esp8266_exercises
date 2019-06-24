#include "Arduino.h"
#include "Pins.h"
#include "Credentials.h"
#include "Components.h"
#include "FS.h"


#if 0
static const char ROOT_HTML[] = R"rawliteral(
<html>
<head>
    <title></title>
</head>
<body>
<h1>Pr&auml;ss&auml;ysohjelmoija</h1>

<form action="asas" enctype="text/plain" id="dfg" method="post" name="as" target="_self">
<p>sdffsdf</p>
</form>

<p>&nbsp;</p>
</body>
</html> 
)rawliteral";
void handleRoot() {

#if 0
  snprintf ( htmlResponse, 3000,
"<!DOCTYPE html>\
<html lang=\"en\">\
  <head>\
    <meta charset=\"utf-8\">\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\
  </head>\
  <body>\
          <h1>Vaihe</h1>\
          <input type='text' name='date_hh' id='date_hh' size=2 autofocus> linja \
          <input type='text' name='date_mm' id='date_mm' size=2 autofocus> aika \
          <input type='text' name='date_ss' id='date_ss' size=2 autofocus> ss \
          <div>\
          <br><button id=\"save_button\">Tallenna</button>\
          </div>\
    <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js\"></script>\    
    <script>\
      var hh;\
      var mm;\
      var ss;\
      $('#save_button').click(function(e){\
        e.preventDefault();\
        hh = $('#date_hh').val();\
        mm = $('#date_mm').val();\
        ss = $('#date_ss').val();\
        $.get('/save?hh=' + hh + '&mm=' + mm + '&ss=' + ss, function(data){\
          console.log(data);\
        });\
      });\
    </script>\
  </body>\
</html>");"
#endif
   server.send ( 200, "text/html", ROOT_HTML );

}
#else

#if 0
static const char INDEX_HEAD_HTML[] = R"rawliteral( 
<!DOCTYPE html>
<html>
<head>
<title>Sarmarin ohjaus</title>
</head>
<body>
<form method="post" action="/createProgram" >
Uusi ohjelma:<br><input name="line" type="text" size="16000" value="" ><br><br>
<input type="submit" name="clk_action" value="Luo ohjelma">
</form>
<form method="post" action="/example" >
<input type="submit" name="clk_action" value="wifi">
</form>
<form method="post" action="openProgram">
<br><button id=\"openProgram\">Avaa ohjelma</button>
</form>
<form method="post" action="deleteAllPrograms">
<br><button id=\"deleteAllPrograms\">Poista kaikki ohjelmat</button>
</form>
</body>
</html>
)rawliteral";
#endif

static const char INDEX_HEAD_HTML[] = R"rawliteral( 
<!DOCTYPE html>
<html>
<head>
<title>Sarmarin ohjaus</title>
</head>
<body>
)rawliteral";
static const char INDEX_MIDDLE_HTML[] = R"rawliteral(
<form method="post" action="/createProgram" >
Uusi ohjelma:<br><input name="line" type="text" size="16000" value="" ><br><br>
<input type="submit" name="clk_action" value="Luo ohjelma">
</form>
<form method="post" action="/example" >
<input type="submit" name="clk_action" value="wifi">
</form>
<form method="post" action="openProgram">
<br><button id=\"openProgram\">Avaa ohjelma</button>
</form>
<form method="post" action="deleteAllPrograms">
<br><button id=\"deleteAllPrograms\">Poista kaikki ohjelmat</button>
)rawliteral";
static const char INDEX_TAIL_HTML[] = R"rawliteral(
</form>
</body>
</html>
)rawliteral";

//---------------------------------------------------------
int constexpr htmlResponseSize{3000};
int constexpr programMaxLength{1000};
char htmlResponse[htmlResponseSize]{};
void handleRoot() {
  memset(htmlResponse, 0, sizeof(htmlResponseSize));
  int writtenBytes = snprintf(&htmlResponse[0], sizeof(INDEX_HEAD_HTML), INDEX_HEAD_HTML);
  Serial.print("sendResp: "); Serial.println(writtenBytes);
  writtenBytes += snprintf(&htmlResponse[writtenBytes-1], sizeof(INDEX_MIDDLE_HTML), INDEX_MIDDLE_HTML);
  Serial.print("sendResp: "); Serial.println(writtenBytes);
  //
  String programs = "<p><textarea cols=\"";
  programs += String(programMaxLength);
  programs += "\" name=\"Ohjelmat\" rows=\"10\">dfsdf</textarea></p>";
  writtenBytes += snprintf(&htmlResponse[writtenBytes-1], programs.length(), programs.c_str());
  Serial.print("sendResp: "); Serial.println(writtenBytes);
  writtenBytes += snprintf(&htmlResponse[writtenBytes-1], sizeof(INDEX_TAIL_HTML), INDEX_TAIL_HTML);
  Serial.print("sendResp: "); Serial.println(writtenBytes);
  Serial.println(htmlResponse);
  server.send(200, "text/html", htmlResponse);
}
#endif

void handleNotFound() {
  server.send(404, "text/plain", "Page not found ...");
}
#if 0
void handleSave() {
  lcd.clear();
  lcd.setCursor(0,0);
  if (server.arg("hh")!= ""){
    lcd.print(" H: " + server.arg("hh"));
  }

  if (server.arg("mm")!= ""){
    lcd.print(" M: " + server.arg("mm"));
  }

  if (server.arg("ss")!= ""){
    lcd.print(" S: " + server.arg("ss"));
  }

}
#else
String const programFile = "/programs.txt";
void handlecreateProgram() {
  String str = "Tallennetaan ohjelma ...\r\n";
  if (server.args() == 2 )
  {
      File file = SPIFFS.open(programFile, "a+");
      if (!file) {
        str += "Tiedoston luonti epäonnistui! \n";
      }
      else
      {
          String const lineStr = server.arg(0);
          //String const periodStr = server.arg(1);
          String const endLineStr = "\n";
          Serial.print("Line: "); Serial.println(lineStr);
          //Serial.print("Period: "); Serial.println(periodStr);
//          uint8_t buf[] = "[1:1234][2:2345][3:3456]\n";
          size_t writtenBytes = file.write((const uint8_t*)(lineStr.c_str()), lineStr.length());
          //writtenBytes += file.write((const uint8_t*)(periodStr.c_str()), periodStr.length());
          writtenBytes += file.write((const uint8_t*)endLineStr.c_str(), endLineStr.length());
          str += "Kirjoitettu: ";
          str += writtenBytes;
          str += " tavua \n";
      }
      file.close();
  }
  else
  {
      str += "Väärät parametrit!";
  }

  server.send(200, "text/plain", str.c_str());
}
#endif

void handleDeleteAllPrograms()
{
    String str = "";
    bool const retValue = SPIFFS.remove(programFile);
    if (retValue)
    {
        str += "Kaikki ohjelmat poistettu";
    }
    else
    {
        str += "Ei onnistunut!";
    }
    server.send(200, "text/plain", str.c_str());
}
void handleOpenProgram() {
    String str = "";
    if (SPIFFS.exists(programFile))
    {
        File file = SPIFFS.open(programFile, "r");
#if 0
        str += programFile + " koko :";
        str += file.size() + "\n";
        str += "Ohjelmat ovat: \n";
        while (file.available() && file.position() < file.size())
        {
            str += file.readStringUntil('\n');
        }
#endif
        Serial.print("size: "); Serial.println(file.size());
        for(int i=0;i<file.size();i++)
        {
            const char c = (char)file.read();
            Serial.print(c);
            str += c;
        }
        file.close();
    }
    else
    {
        str += "Ei ohjelmia! \n";
    }
    server.send(200, "text/plain", str.c_str());
}

static const char EXAMPLE_HTML[] = R"rawliteral(
<!DOCTYPE html>
<html>
    <head>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <style>
            body {
                color: #434343;
                font-family: "Helvetica Neue",Helvetica,Arial,sans-serif;
                font-size: 14px;
                line-height: 1.42857142857143;
                padding: 20px;
            }

            .container {
                margin: 0 auto;
                max-width: 400px;
            }

            form .field-group {
                box-sizing: border-box;
                clear: both;
                padding: 4px 0;
                position: relative;
                margin: 1px 0;
                width: 100%;
            }

            form .field-group > label {
                color: #757575;
                display: block;
                margin: 0 0 5px 0;
                padding: 5px 0 0;
                position: relative;
                word-wrap: break-word;
            }

            input[type=text] {
                background: #fff;
                border: 1px solid #d0d0d0;
                border-radius: 2px;
                box-sizing: border-box;
                color: #434343;
                font-family: inherit;
                font-size: inherit;
                height: 2.14285714em;
                line-height: 1.4285714285714;
                padding: 4px 5px;
                margin: 0;
                width: 100%;
            }

            input[type=text]:focus {
                border-color: #4C669F;
                outline: 0;
            }

            .button-container {
                box-sizing: border-box;
                clear: both;
                margin: 1px 0 0;
                padding: 4px 0;
                position: relative;
                width: 100%;
            }

            button[type=submit] {
                box-sizing: border-box;
                background: #f5f5f5;
                border: 1px solid #bdbdbd;
                border-radius: 2px;
                color: #434343;
                cursor: pointer;
                display: inline-block;
                font-family: inherit;
                font-size: 14px;
                font-variant: normal;
                font-weight: 400;
                height: 2.14285714em;
                line-height: 1.42857143;
                margin: 0;
                padding: 4px 10px;
                text-decoration: none;
                vertical-align: baseline;
                white-space: nowrap;
            }
        </style>
    </head>
    <body>
        <div class="container">
            <h1 style="text-align: center;">Wifi Details</h1>
            <form method="post" action="/">
                <div class="field-group">
                    <label>SSID</label>
                    <input name="ssid" type="text" length=32>
                </div>
                <div class="field-group">
                    <label>Password</label>
                    <input name="password" type="text" length=64>
                </div>
                <div class="button-container">
                    <button type="submit">Save</button
                </div>
            </form>
        </div>
    </body>
</html>
)rawliteral";

//---------------------------------------------------------
void handleExample() {
  server.send(200, "text/html", EXAMPLE_HTML);
}

void setup()
{
    Serial.begin(115200);
    lcd.init();
    // Connect to Wi-Fi network with SSID and password
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Connecting to ");
    lcd.setCursor(0,1);
    lcd.print(ssid);
    lcd.setCursor(0,2);
    //WiFi.begin(ssid, password);
    WiFi.softAP(ssid, password);
//    while (WiFi.status() != WL_CONNECTED)
//    {
//        delay(500);
//        lcd.print(".");
//    }
    // Print local IP address and start web server
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ssid: ");
    lcd.print(ssid);
    lcd.setCursor(0,1);
    lcd.print("passwd: ");
    lcd.print(password);
    lcd.setCursor(0,2);
    lcd.print("IP address: ");
    lcd.setCursor(0,3);
    lcd.print(WiFi.softAPIP());
//    server.begin();
    server.on("/", handleRoot);
    server.on("/createProgram", handlecreateProgram);
    server.on("/openProgram", handleOpenProgram);
    server.on("/deleteAllPrograms", handleDeleteAllPrograms);
    server.onNotFound(handleNotFound);
    server.on("/example", handleExample);

    server.begin();
    SPIFFS.begin();
//    Serial.println ( "HTTP server started" );
}
