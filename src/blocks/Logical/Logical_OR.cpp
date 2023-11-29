#include "Logical_OR.h"

// Constructor for Logical_OR class
Logical_OR::Logical_OR(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the logical OR operation
float Logical_OR::Or()
{
  // Output is the logical OR of the two input values
  return static_cast<float>(this->castToLogical(*inputs[0]) || this->castToLogical(*inputs[1]));
}

// Invert the input value
float Logical_OR::inverter(float in)
{
  if (in == static_cast<float>(0))
    return static_cast<float>(1);
  else
    return static_cast<float>(0);
}

// Run the Logical_OR block
uint8_t Logical_OR::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->Or();                 // Execute the logical OR operation
    outputs[1] = this->inverter(outputs[0]); // Invert the result and store it in the second output
    return 0;                                // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
