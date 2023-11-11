#include "Math_Basic.h"

Math_Basic::Math_Basic(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

float Math_Basic::math()
{
  switch (static_cast<uint8_t>(*inputs[2]))
  {
  // ADD
  case 0:
  {
    return *inputs[0] + *inputs[1];
  }
  // SUBTRACT
  case 1:
  {
    return *inputs[0] - *inputs[1];
  }
  // MULTIPLY
  case 2:
  {
    return *inputs[0] * *inputs[1];
  }
  // DIVIDE
  case 3:
  {
    return *inputs[0] / *inputs[1];
  }
  default:
    0;
  }
}

uint8_t Math_Basic::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->math();
    return 0;
  }
  else
    return 1;
}