#include "HWIO_Input_Digital.h"
#include <Arduino.h>

#define INPUT_LENGTH 1
#define OUTPUT_LENGTH 1

/* HWIO_Input
pinmode: use internel pull-up resistor
0 : INPUT
1 : INPUT_PULLUP
 */

HWIO_Input_Digital::HWIO_Input_Digital(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}

float HWIO_Input_Digital::input()
{
  if (lastPinMode != static_cast<uint8_t>(*inputs[1]))
  {
    lastPinMode = *inputs[1];
    switch (lastPinMode)
    {
    case 0:
      pinMode(static_cast<uint16_t>(*inputs[0]), INPUT);
      break;
    case 1:
      pinMode(static_cast<uint16_t>(*inputs[0]), INPUT_PULLUP);
      break;
    }
  }

  return static_cast<float>(digitalRead(static_cast<uint16_t>(*inputs[0])));
}

uint8_t HWIO_Input_Digital::run()
{
  if (this->checkValidity())
    outputs[0] = this->input();
  else
    return 1;
  return 0;
}