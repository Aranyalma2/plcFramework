#include "Logical_Selector.h"

// Constructor for Logical_Selector class
Logical_Selector::Logical_Selector(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the logical selection operation
float Logical_Selector::select()
{
  // Selector "bit" if not 0, select input 1, else select input 0
  return this->castToLogical(*inputs[2]) ? *inputs[1] : *inputs[0];
}

// Run the Logical_Selector block
uint8_t Logical_Selector::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->select(); // Execute the logical selection operation
    return 0;                    // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
