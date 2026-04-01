#include <Arduino.h>
#include "../include/wifi_connection.cpp"
#include <Adafruit_BMP085.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);
  startupInternet();
}

void loop() {
  // put your main code here, to run repeatedly:
  connectInternet();
  printDateTime();
}
