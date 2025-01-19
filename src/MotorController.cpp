#include "MotorController.h"

MotorController::MotorController(int pin) : motorPin(pin) {}

void MotorController::init() {
    pinMode(motorPin, OUTPUT);
    analogWrite(motorPin, 0); // Ensure motor is off
}

void MotorController::setSpeed(int speed) {
    int pwmValue = map(speed, 0, 100, 0, 255);
    analogWrite(motorPin, pwmValue);
}

void MotorController::stop() {
    analogWrite(motorPin, 0); // Stop the motor
}
