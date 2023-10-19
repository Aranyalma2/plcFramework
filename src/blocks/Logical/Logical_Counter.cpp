#include "Logical_Counter.h"

#define INPUT_LENGTH 7
#define OUTPUT_LENGTH 1

/* Logical Counter input detaction high to low or low to high with start and way controlling.
 * Inputs:
 * - input value 0/1 pulse
 * - input detaction mode (low to high or high to low)
 * - counter start number
 * - count way (up or down) 1/-1
 * - reset value 0/1 pulse
 * - reset detaction mode (low to high or high to low)
 */

Logical_Counter::Logical_Counter(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

float Logical_Counter::counter()
{
  uint8_t inputState = static_cast<uint8_t>(*inputs[0]);
  inputState = static_cast<uint8_t>(inputState > 0);
  uint8_t inputDetactionMode = static_cast<uint8_t>(*inputs[1]);
  // Check if the input value has changed since last time
  if (inputState != lastInput)
  {
    // Input value has changed, check if it has gone from high to low or low to high
    if (inputDetactionMode == 1)
    { // High to low
      if (inputState == 0 && lastInput == 1)
      {
        return outputs[0] + *inputs[3];
      }
    }
    else
    { // Low to high
      if (inputState == 1 && lastInput == 0)
      {
        return outputs[0] + *inputs[3];
      }
    }
    lastInput = inputState;
  }

  // reset check
  uint8_t resetState = static_cast<uint8_t>(*inputs[4]);
  resetState = static_cast<uint8_t>(resetState > 0);
  uint8_t resetDetactionMode = static_cast<uint8_t>(*inputs[5]);
  if (resetState != lastReset)
  {
    if (resetDetactionMode == 1)
    { // High to low
      if (lastReset == 1 && resetState == 0)
      {
        return *inputs[2];
      }
    }
    else
    { // Low to high
      if (lastReset == 0 && resetState == 1)
      {
        return *inputs[2];
      }
    }
  }
  lastReset = resetState;

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