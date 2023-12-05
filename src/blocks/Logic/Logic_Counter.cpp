#include "Logic_Counter.h"

/* Logic Counter input detaction high to low or low to high with start and way controlling.
 * Inputs:
 *  0 - input value 0/1 pulse
 *  1 - input detaction mode (low to high or high to low)
 *  2 - counter start number
 *  3 - count way (up or down) 1/-1
 *  4 - reset value 0/1 pulse
 *  5 - reset detaction mode (low to high or high to low)
 */
#include "Logic_Counter.h"

// Constructor for Logic_Counter class
Logic_Counter::Logic_Counter(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the Logic counting operation
float Logic_Counter::counter()
{
  // Extract logic values from input signals
  uint8_t inputState = this->castToLogic(*inputs[0]);
  uint8_t inputDetectionMode = this->castToLogic(*inputs[1]);

  uint8_t resetState = this->castToLogic(*inputs[4]);
  uint8_t resetDetectionMode = this->castToLogic(*inputs[5]);

  
    // Initialization on the first run
    if (firstRun)
    {
      // Initialize with the default value
      outputs[0] = *inputs[2];
    firstRun = 0;}/*
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
    lastReset = resetState;
  }

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
    lastInput = inputState;
  }

  return outputs[0]; // Return the current counter value
}

// Run the Logic_Counter block
uint8_t Logic_Counter::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->counter(); // Execute the Logic counting operation
    return 0;                     // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
