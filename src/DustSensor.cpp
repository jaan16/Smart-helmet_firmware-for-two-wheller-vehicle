#include "DustSensor.h"

DustSensor::DustSensor(int pin) : sensorPin(pin) {}

void DustSensor::init() {
    pinMode(sensorPin, INPUT);
}

int DustSensor::getPollutionLevel() {
    int rawValue = analogRead(sensorPin);
    return map(rawValue, 0, 1023, 0, 500); // Convert to PM level
}
