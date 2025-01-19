#ifndef DUSTSENSOR_H
#define DUSTSENSOR_H

#include <Arduino.h>

class DustSensor {
private:
    int sensorPin;

public:
    DustSensor(int pin);
    void init();
    int getPollutionLevel();
};

#endif
