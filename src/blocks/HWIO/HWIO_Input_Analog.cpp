#include "HWIO_Input_Analog.h"
#include <Arduino.h>

HWIO_Input_Analog::HWIO_Input_Analog(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}
float HWIO_Input_Analog::input()
{
  return static_cast<float>(analogRead(*inputs[0]));
}

uint8_t HWIO_Input_Analog::run()
{
  if (this->checkValidity())
    outputs[0] = this->input();
  else
    return 1;
  return 0;
}