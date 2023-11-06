#include "Logical_OR.h"

float Logical_OR::Or()
{
  return static_cast<float>(this->castToLogical(*inputs[0]) || this->castToLogical(*inputs[1]));
}

float Logical_OR::inverter(float in)
{
  // output is inverted
  if (in == static_cast<float>(0))
    return static_cast<float>(1);
  else
    return static_cast<float>(0);
}

uint8_t Logical_OR::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->Or();
    outputs[1] = this->inverter(outputs[0]);
    return 0;
  }
  else
  {
    return 1;
  }
}