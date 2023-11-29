/*
   File: Math_Basic.cpp
   Author: Nemeth Balint

   Description:
   This file defines the implementation of the Math_Basic class, which is a subclass of FunctionBlock.
   It provides basic mathematical operations such as addition, subtraction, multiplication, division,
   absolute value, exponentiation, logarithms, maximum, and minimum.

   Class Overview:
   - Math_Basic: Handles various mathematical operations based on the input parameters.
                 Inherits from FunctionBlock.

   Member Functions:
   - Math_Basic(uint16_t unique_id): Constructor initializes the Math_Basic object with a unique ID,
                                     sets up input and output arrays.

   - float math(): Performs the mathematical operation based on the specified operation code.
                   Returns the result of the operation.

   - uint8_t run(): Checks the validity of inputs and executes the mathematical operation.
                   Updates the output array with the result.

   Supported Operations (specified by *inputs[2]):
   0: Addition
   1: Subtraction
   2: Multiplication
   3: Division (handles division by zero)
   4: Absolute value
   5: Exponentiation (base raised to the power exponent)
   6: nth root (exponentiation with 1/n as the exponent)
   7: Logarithm (B to the base A)
   8: Maximum of two values
   9: Minimum of two values

   Note: If the specified operation code is not recognized, the default return value is 0.0.

   Dependencies:
   - FunctionBlock: Base class providing the structure for function blocks.

   Usage:
   - Create an instance of Math_Basic, set input values using inputs[], and call run() to perform
     the specified mathematical operation.

   Example:
   ```
    Math_Basic mathBlock();
    mathBlock.inputs[0] = 5.0;
    mathBlock.inputs[1] = 3.0;
    mathBlock.inputs[2] = 0; // Addition
    mathBlock.run();
    float result = mathBlock.outputs[0]; // Result will be 8.0
    ```

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