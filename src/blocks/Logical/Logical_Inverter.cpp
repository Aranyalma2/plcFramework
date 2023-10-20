#include "Logical_Inverter.h"

Logical_Inverter::Logical_Inverter(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}

float Logical_Inverter::inverter()
{
  // output is inverted
  return static_cast<float>(!this->castToLogical(*inputs[0]));

}

uint8_t Logical_Inverter::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->inverter();
    return 0;
  }
  else
    return 1;
}