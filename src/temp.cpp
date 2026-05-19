#include <Arduino.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void tempStartup();
int getTemp();

void tempStartup() {

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