#include "global_constants.h"
#include "HWInterfaces/SerialInterface.h"

const char16_t INPUT_RESOLUTION = 1023;
const char PWM_DUTY = 255;
const float REFERNCE_VOLTAGE = 5.0;
HardwareSerial *usableSerials = {&Serial};
