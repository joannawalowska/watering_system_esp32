#include <Arduino.h>
#include "../include/wifi_connection.h"
#include "../include/temp.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);
  startupInternet();
  startupTemp();
}

void loop() {
  // put your main code here, to run repeatedly:
  connectInternet();
  delay(1000);
  getTemp();
  delay(1000);
}
