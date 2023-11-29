/*
   File: Math_Basic.cpp
   Author: Nemeth Balint

   Implementation for: Math_Basic.h
*/

#include "Math_Basic.h"

Math_Basic::Math_Basic(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

float Math_Basic::math()
{
  switch (static_cast<uint8_t>(*inputs[2]))
  {
  case 0:
    return *inputs[0] + *inputs[1]; // Addition
  case 1:
    return *inputs[0] - *inputs[1]; // Subtraction
  case 2:
    return *inputs[0] * *inputs[1]; // Multiplication
  case 3:
    return (*inputs[1] != 0.0) ? (*inputs[0] / *inputs[1]) : 0.0; // Division (handle division by zero)
  case 4:
    return abs(*inputs[0]); // Absolute Value
  case 5:
    return pow(*inputs[0], *inputs[1]); // Exponentiation
  case 6:
    return (*inputs[0] != 0.0) ? pow(*inputs[1], 1.0 / *inputs[0]) : 0.0; // nth Root (handle division by zero)
  case 7:
    return (*inputs[1] != 0.0 || *inputs[1] != 0.0) ? (log(*inputs[1]) / log(*inputs[0])) : 0.0; // Logarithm (handle any log(0))
  case 8:
    return max(*inputs[0], *inputs[1]); // Maximum
  case 9:
    return min(*inputs[0], *inputs[1]); // Minimum

  default:
    return 0.0; // Default case if operation code is not recognized
  }
}

// Run the Math_Basic block
uint8_t Math_Basic::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->math(); // Execute the mathematical operation
    return 0;                  // Return success
  }
  else
    return 1; // Return failure if inputs are not valid
}