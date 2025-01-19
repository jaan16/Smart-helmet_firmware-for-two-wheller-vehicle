#ifndef ACCIDENTDETECTOR_H
#define ACCIDENTDETECTOR_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class AccidentDetector {
private:
    int vibrationSensorPin;

public:
    AccidentDetector(int pin);
    void init();
    bool isAccidentDetected();
    void sendAlert();
    String getGPSLocation();
};

#endif
