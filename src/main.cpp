#include <Arduino.h>
#include "../include/wifi_connection.h"



void setup() {
  // put your setup code here, to run once:
  Serial.begin(921600);
  startupInternet();
}

void loop() {
  // put your main code here, to run repeatedly:
  connectInternet();
  delay(1000);
  
  delay(1000);
}
