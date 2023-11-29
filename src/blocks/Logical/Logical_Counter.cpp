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
#include "Logical_Counter.h"

// Constructor for Logical_Counter class
Logical_Counter::Logical_Counter(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the logical counting operation
float Logical_Counter::counter()
{
  // Extract logic values from input signals
  uint8_t inputState = this->castToLogical(*inputs[0]);
  uint8_t inputDetectionMode = this->castToLogical(*inputs[1]);

  uint8_t resetState = this->castToLogical(*inputs[4]);
  uint8_t resetDetectionMode = this->castToLogical(*inputs[5]);

  /*
    // Initialization on the first run
    if (firstRun)
    {
      // Initialize with the default value
      outputs[0] = *inputs[2];

      // If the input or reset detection mode is high to low, change last states to inverse
      if (inputDetectionMode == 1)
      {
        lastInput = 1;
      }
      if (resetDetectionMode == 1)
      {
        lastReset = 1;
      }
      firstRun = 0; // Set firstRun flag to false after initialization
    }
    */

  // Check if the input value has changed since the last time
  if (inputState != lastInput)
  {
    // Input value has changed, check if it has gone from high to low or low to high
    if (inputDetectionMode == 1)
    { // High to low
      if (inputState == 0 && lastInput == 1)
      {
        lastInput = inputState;
        return outputs[0] + *inputs[3]; // Increment the counter
      }
    }
    else
    { // Low to high
      if (inputState == 1 && lastInput == 0)
      {
        lastInput = inputState;
        return outputs[0] + *inputs[3]; // Increment the counter
      }
    }
    lastInput = inputState; // Update lastInput with the current input state
  }

  // Reset check
  if (resetState != lastReset)
  {
    if (resetDetectionMode == 1)
    { // High to low
      if (lastReset == 1 && resetState == 0)
      {
        lastReset = resetState;
        return *inputs[2]; // Reset the counter
      }
    }
    else
    { // Low to high
      if (lastReset == 0 && resetState == 1)
      {
        lastReset = resetState;
        return *inputs[2]; // Reset the counter
      }
    }
    lastInput = inputState; // Update lastInput with the current input state
  }

  return outputs[0]; // Return the current counter value
}

// Run the Logical_Counter block
uint8_t Logical_Counter::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->counter(); // Execute the logical counting operation
    return 0;                     // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
