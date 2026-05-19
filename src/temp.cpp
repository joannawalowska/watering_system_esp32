#include "../include/temp.h"

Adafruit_BMP085 bmp;

void startupTemp() {

    if(!bmp.begin()){
        Serial.println("Error temperature sensor");
        while(1) {}
    }

}

int getTemp() {

    int temperature = bmp.readTemperature();

    Serial.print("Temperature = ");
    Serial.print(temperature);
    Serial.println(" *C");
    
    return temperature;
}