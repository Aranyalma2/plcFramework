#include "Logical_NOT.h"

Logical_NOT::Logical_NOT(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}

float Logical_NOT::negation()
{
  // output is inverted
  return static_cast<float>(!this->castToLogical(*inputs[0]));

}

uint8_t Logical_NOT::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->negation();
    return 0;
  }
  else
    return 1;
}