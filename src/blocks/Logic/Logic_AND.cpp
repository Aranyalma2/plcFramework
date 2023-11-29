#include "Logic_AND.h"

// Constructor for Logic_AND class
Logic_AND::Logic_AND(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform Logic AND operation
float Logic_AND::And()
{
  return static_cast<float>(this->castToLogic(*inputs[0]) && this->castToLogic(*inputs[1]));
}

// Invert the input value
float Logic_AND::inverter(float in)
{
  // Output inverter
  if (in == static_cast<float>(0))
    return static_cast<float>(1);
  else
    return static_cast<float>(0);
}

// Run the Logic_AND block
uint8_t Logic_AND::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->And();                // Execute the Logic AND operation
    outputs[1] = this->inverter(outputs[0]); // Invert the result and store it in the second output
    return 0;                                // Return success
  }
  else
    return 1; // Return failure if inputs are not valid
}