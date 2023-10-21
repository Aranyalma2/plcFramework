#include "Logical_AND.h"

Logical_AND::Logical_AND(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}

float Logical_AND::And()
{
  return static_cast<float>(this->castToLogical(*inputs[0]) && this->castToLogical(*inputs[1]));
}

float Logical_AND::inverter(float in)
{
  // output is inverted
  if (in == static_cast<float>(0))
    return static_cast<float>(1);
  else
    return static_cast<float>(0);
}

uint8_t Logical_AND::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->And();
    outputs[1] = this->inverter(outputs[0]);
    return 0;
  }
  else
    return 1;
}