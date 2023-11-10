#ifndef GLOBAL_CONSTANTS_H
#define GLOBAL_CONSTANTS_H
#include <Arduino.h>

// HWIO ANALOG INPUT RESOLUTION
extern const char16_t INPUT_RESOLUTION;
// HWIO ANALOG OUTPUT RESOLUTION
extern const char PWM_DUTY;
// HW REFERENCE VOLTAGE
extern const float REFERNCE_VOLTAGE;

extern HardwareSerial *usableSerials;

#endif