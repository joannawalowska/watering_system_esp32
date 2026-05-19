#include "../include/wifi_connection.h"

const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = -1500;    
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
  //strftime(formattedTime, sizeof(formattedTime), "%H", &timeinfo);
  Serial.println(formattedTime);
  //Serial.println( sizeof(formattedTime) );
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

char getHour() {
  char hour = 0;
  
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return hour;
  }
  char formattedTime[5];
  strftime(formattedTime, sizeof(formattedTime), "%H", &timeinfo);
  Serial.println(formattedTime);
  return hour;
}

bool getConnectedStatus() {
  if(isConnected) {
    Serial.println("TAK");
  }
  return isConnected;
}
  