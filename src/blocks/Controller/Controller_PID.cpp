#include "Controller_PID.h"

Controller_PID::Controller_PID(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

float Controller_PID::pid()
{
  float error = *inputs[1] - *inputs[0];
  integral += error;
  float derivative = error - prevError;

  prevError = error;

  if (this->castToLogical(*inputs[5]) == 0)
  {
    return *inputs[2] * error + *inputs[3] * integral + *inputs[4] * derivative;
  }
  else if (this->castToLogical(*inputs[5]) == 1)
  {
    return -(*inputs[2] * error + *inputs[3] * integral + *inputs[4] * derivative);
  }
}

uint8_t Controller_PID::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->pid();
    return 0;
  }
  else
    return 1;
}