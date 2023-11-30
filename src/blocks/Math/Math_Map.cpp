#include "Math_Map.h"

// Constructor for Math_Map class
Math_Map::Math_Map(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the value range mapping operation
float Math_Map::map()
{
    // Formula to map the input value from the original range to the new range
    return ((*inputs[0] - *inputs[1]) / (*inputs[2] - *inputs[1]) * (*inputs[4] - *inputs[3]) + *inputs[3]);
}

// Run the Math_Map block
uint8_t Math_Map::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->map(); // Execute the value range mapping operation
    return 0;                 // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
