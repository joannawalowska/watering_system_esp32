#include <Arduino.h>
#include <WiFi.h>
#include <time.h>
#include "wifi_config.cpp"

const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -1000;    
const int daylightOffset_sec = 3600; 
bool isConnected = false;

// Print formatted date and time
void printDateTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return;
  }
  char formattedTime[80];  // Buffer to store the formatted string
  strftime(formattedTime, sizeof(formattedTime), "%A, %B %d %Y %H:%M:%S", &timeinfo);
  Serial.println(formattedTime);
}

void startupInternet() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    pinMode(LED_BUILTIN, OUTPUT);
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
}

void connectInternet() {
    if(WiFi.status()== WL_CONNECTED && !isConnected){
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Connected");
    Serial.println(WiFi.localIP());
    isConnected = true;
  }

  if(WiFi.status() != WL_CONNECTED){
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    delay(1000);
    isConnected = false;
  }
}

