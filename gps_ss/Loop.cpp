#include "Components.h"

void readGps()
{
  while (gpsSerial.available())
  {
      gps.encode(gpsSerial.read());
  }
}

void loop()
{
  readGps();
  Serial.print("HDOP: ");
  Serial.print(gps.hdop());
  Serial.print(" SATS: ");
  Serial.println(gps.satellites());
}