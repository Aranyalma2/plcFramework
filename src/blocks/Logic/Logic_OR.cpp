#include "Logic_OR.h"

// Constructor for Logic_OR class
Logic_OR::Logic_OR(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the Logic OR operation
float Logic_OR::Or()
{
  // Output is the Logic OR of the two input values
  return static_cast<float>(this->castToLogic(*inputs[0]) || this->castToLogic(*inputs[1]));
}

// Invert the input value
float Logic_OR::inverter(float in)
{
  if (in == static_cast<float>(0))
    return static_cast<float>(1);
  else
    return static_cast<float>(0);
}

// Run the Logic_OR block
uint8_t Logic_OR::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->Or();                 // Execute the Logic OR operation
    outputs[1] = this->inverter(outputs[0]); // Invert the result and store it in the second output
    return 0;                                // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
