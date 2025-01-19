
#include <Arduino.h>
#include "MotorController.h"
#include "DustSensor.h"
#include "AccidentDetector.h"

// Define pin mappings and thresholds
#define MOTOR_PIN 9
#define DUST_SENSOR_PIN A0
#define VIBRATION_SENSOR_PIN 3
#define POLLUTION_THRESHOLD 150

MotorController motorController(MOTOR_PIN);
DustSensor dustSensor(DUST_SENSOR_PIN);
AccidentDetector accidentDetector(VIBRATION_SENSOR_PIN);

void setup() {
    Serial.begin(9600);

    // Initialize modules
    motorController.init();
    dustSensor.init();
    accidentDetector.init();

    Serial.println("System Initialized");
}

void loop() {
    // Read pollution levels
    int pollutionLevel = dustSensor.getPollutionLevel();

    // Check for accidents
    bool accidentDetected = accidentDetector.isAccidentDetected();

    // Handle pollution control
    if (pollutionLevel > POLLUTION_THRESHOLD) {
        motorController.setSpeed(50); // Reduce motor speed
        Serial.println("High pollution detected. Reducing motor speed.");
    } else {
        motorController.setSpeed(100); // Normal operation
        Serial.println("Pollution level normal. Operating motor at full speed.");
    }

    // Handle accident detection
    if (accidentDetected) {
        Serial.println("Accident detected! Sending alert...");
        accidentDetector.sendAlert(); // Send alert via SIM module
        motorController.stop();       // Stop the motor for safety
    }

    delay(1000); // Wait before the next loop
}
