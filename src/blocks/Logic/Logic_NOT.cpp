#include "Logic_NOT.h"

// Constructor for Logic_NOT class
Logic_NOT::Logic_NOT(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the Logic NOT operation
float Logic_NOT::negation()
{
  // Output is inverted
  return static_cast<float>(!this->castToLogic(*inputs[0]));
}

// Run the Logic_NOT block
uint8_t Logic_NOT::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->negation(); // Execute the Logic NOT operation
    return 0;                      // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
