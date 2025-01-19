#include "AccidentDetector.h"
#include <SoftwareSerial.h>
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// SIM module pins
SoftwareSerial simSerial(10, 11); // RX, TX

AccidentDetector::AccidentDetector(int vibrationPin) : vibrationSensorPin(vibrationPin) {}

void AccidentDetector::init() {
    pinMode(vibrationSensorPin, INPUT);
    Wire.begin();
    mpu.initialize();

    simSerial.begin(9600);
    Serial.println("Accident Detection System Initialized");
}

bool AccidentDetector::isAccidentDetected() {
    int vibrationValue = digitalRead(vibrationSensorPin);

    // Check MPU6050 for abrupt motion
    int16_t ax, ay, az;
    mpu.getAcceleration(&ax, &ay, &az);

    bool abruptMotion = (abs(ax) > 15000 || abs(ay) > 15000 || abs(az) > 15000);

    return (vibrationValue == HIGH || abruptMotion);
}

void AccidentDetector::sendAlert() {
    simSerial.println("AT+CMGF=1"); // Set SMS mode
    delay(100);
    simSerial.println("AT+CMGS=\"+1234567890\""); // Replace with your number
    delay(100);
    simSerial.print("Accident Detected! Location: ");
    simSerial.println(getGPSLocation());
    delay(100);
    simSerial.write(26); // ASCII for CTRL+Z
}

String AccidentDetector::getGPSLocation() {
    // Mock GPS data
    return "Latitude: 12.9716, Longitude: 77.5946"; // Replace with real GPS parsing logic
}
