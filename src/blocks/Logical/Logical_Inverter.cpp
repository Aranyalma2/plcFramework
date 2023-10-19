#include "Logical_Inverter.h"

Logical_Inverter::Logical_Inverter(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}

float Logical_Inverter::inverter(float in)
{
  // output is inverted
  if (static_cast<int32_t>(in) == 0)
    return static_cast<float>(1);
  else
    return static_cast<float>(0);
}

uint8_t Logical_Inverter::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->inverter(*inputs[0]);
    return 0;
  }
  else
    return 1;
}