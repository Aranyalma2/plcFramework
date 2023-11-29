#include "Logic_Selector.h"

// Constructor for Logic_Selector class
Logic_Selector::Logic_Selector(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the Logic selection operation
float Logic_Selector::select()
{
  // Selector "bit" if not 0, select input 1, else select input 0
  return this->castToLogic(*inputs[2]) ? *inputs[1] : *inputs[0];
}

// Run the Logic_Selector block
uint8_t Logic_Selector::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->select(); // Execute the Logic selection operation
    return 0;                    // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
