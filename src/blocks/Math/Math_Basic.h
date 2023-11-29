#ifndef __MATH_BASIC_H__
#define __MATH_BASIC_H__

#include "../FunctionBlock.h"
/*
 * Math_Basic - Function Block for Basic Mathematical Operations
 *
 * Description:
 * This class defines a Function Block, Math_Basic, for performing basic mathematical operations.
 * It inherits from the FunctionBlock class and provides functionality for addition, subtraction,
 * multiplication, and division based on two input values and an operation code.
 *
 * Supported Operations:
 *   0: Addition
 *   1: Subtraction
 *   2: Multiplication
 *   3: Division (handles division by zero)
 *   4: Absolute value
 *   5: Exponentiation (base raised to the power exponent)
 *   6: nth root (exponentiation with 1/n as the exponent)
 *   7: Logarithm (B to the base A)
 *   8: Maximum of two values
 *   9: Minimum of two values
 *
 * Inputs:
 *   - input 1
 *   - input 2
 *   - operation (0-9 to specify the operation)
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (3 in this case)
 *   - OUTPUT_LENGTH: Number of output values (1 in this case)
 *   - inputs[3]: Array to store pointers to input values
 *   - inputConstants[3]: Array to store constant values (currently initialized to zero)
 *   - outputs[1]: Array to store the result of the mathematical operation
 *
 * Member Functions:
 *   - Math_Basic(uint16_t unique_id = 0): Constructor for Math_Basic, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the mathematical operation and updates the output array.
 *   - float math(): Performs the mathematical operation based on the specified operation code.
 *
 * Usage:
 *   - Create an instance of Math_Basic, set input values using inputs[], and call run() to perform
 *     the specified mathematical operation.
 *
 * Example:
 *   ```
 *   Math_Basic mathBlock(123);
 *   mathBlock.inputs[0] = 5.0;
 *   mathBlock.inputs[1] = 3.0;
 *   mathBlock.inputs[2] = 0; // Addition
 *   mathBlock.run();
 *   float result = mathBlock.outputs[0]; // Result will be 8.0
 *   ```
 *
 */

class Math_Basic : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 3;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[3] = {nullptr};
  float inputConstants[3] = {0};
  float outputs[1] = {0};

  float math();

public:
  Math_Basic(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif // __MATH_BASIC_H__