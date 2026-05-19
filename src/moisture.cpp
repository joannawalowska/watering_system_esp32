#include "../include/moisture.h"


int getMoisture() {
    int data = 0;
    data = analogRead(34);
    Serial.println(data);
    double Vdata = data / (pow(2, 12)-1) * 1.100;
    Serial.println(Vdata);
    return Vdata;
}