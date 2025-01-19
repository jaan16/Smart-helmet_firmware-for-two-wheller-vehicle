#ifndef MOTORCONTROLLER_H
#define MOTORCONTROLLER_H

#include <Arduino.h>

class MotorController {
private:
    int motorPin;

public:
    MotorController(int pin);
    void init();
    void setSpeed(int speed);
    void stop();
};

#endif
