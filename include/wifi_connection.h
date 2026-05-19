#include <Arduino.h>
#include <WiFi.h>
#include <string>
#include <time.h>
#include "wifi_config.cpp"
/* you need to create file wifi_config
#define WIFI_SSID "name od your wifi"
#define WIFI_PASSWORD "your wifi_password"
*/

void printDateTime();
void startupInternet();
void connectInternet();
char getHour();
bool getConnectedStatus();
