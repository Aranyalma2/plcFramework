#include "Logical_NOT.h"

// Constructor for Logical_NOT class
Logical_NOT::Logical_NOT(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the logical NOT operation
float Logical_NOT::negation()
{
  // Output is inverted
  return static_cast<float>(!this->castToLogical(*inputs[0]));
}

// Run the Logical_NOT block
uint8_t Logical_NOT::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->negation(); // Execute the logical NOT operation
    return 0;                      // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
