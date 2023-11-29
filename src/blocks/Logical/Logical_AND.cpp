#include "Logical_AND.h"

// Constructor for Logical_AND class
Logical_AND::Logical_AND(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform logical AND operation
float Logical_AND::And()
{
  return static_cast<float>(this->castToLogical(*inputs[0]) && this->castToLogical(*inputs[1]));
}

// Invert the input value
float Logical_AND::inverter(float in)
{
  // Output inverter
  if (in == static_cast<float>(0))
    return static_cast<float>(1);
  else
    return static_cast<float>(0);
}

// Run the Logical_AND block
uint8_t Logical_AND::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->And();                // Execute the logical AND operation
    outputs[1] = this->inverter(outputs[0]); // Invert the result and store it in the second output
    return 0;                                // Return success
  }
  else
    return 1; // Return failure if inputs are not valid
}