#include "Logical_Counter.h"

/* Logical Counter input detaction high to low or low to high with start and way controlling.
 * Inputs:
 *  0 - input value 0/1 pulse
 *  1 - input detaction mode (low to high or high to low)
 *  2 - counter start number
 *  3 - count way (up or down) 1/-1
 *  4 - reset value 0/1 pulse
 *  5 - reset detaction mode (low to high or high to low)
 */

Logical_Counter::Logical_Counter(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

float Logical_Counter::counter()
{
  uint8_t inputState = this->castToLogical(*inputs[0]);
  uint8_t inputDetactionMode = this->castToLogical(*inputs[1]);

  uint8_t resetState = this->castToLogical(*inputs[4]);
  uint8_t resetDetactionMode = this->castToLogical(*inputs[5]);

  if (firstRun)
  {
    // defaut value
    outputs[0] = *inputs[2];
    // work mode change last states to inverse
    if (inputDetactionMode == 1)
    {
      lastInput = 1;
    }
    if (resetDetactionMode == 1)
    {
      lastReset = 1;
    }
    firstRun = 0;
  }

  // Check if the input value has changed since last time
  if (inputState != lastInput)
  {
    // Input value has changed, check if it has gone from high to low or low to high
    if (inputDetactionMode == 1)
    { // High to low
      if (inputState == 0 && lastInput == 1)
      {
        lastInput = inputState;
        return outputs[0] + *inputs[3];
      }
    }
    else
    { // Low to high
      if (inputState == 1 && lastInput == 0)
      {
        lastInput = inputState;
        return outputs[0] + *inputs[3];
      }
    }
    lastInput = inputState;
  }

  // reset check
  if (resetState != lastReset)
  {
    if (resetDetactionMode == 1)
    { // High to low
      if (lastReset == 1 && resetState == 0)
      {
        lastReset = resetState;
        return *inputs[2];
      }
    }
    else
    { // Low to high
      if (lastReset == 0 && resetState == 1)
      {
        lastReset = resetState;
        return *inputs[2];
      }
    }
    lastInput = inputState;
  }

  return outputs[0];
}

uint8_t Logical_Counter::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->counter();
    return 0;
  }
  else
  {
    return 1;
  }
}