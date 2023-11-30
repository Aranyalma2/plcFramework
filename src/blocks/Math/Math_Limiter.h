#ifndef __MATH_LIMITER_H__
#define __MATH_LIMITER_H__

#include "../FunctionBlock.h"

/* 
 * Math_Limiter - Function Block for Value Limiting
 *
 * Description:
 * This class defines a Function Block, Math_Limiter, for limiting a given value within a specified range.
 * It inherits from the FunctionBlock class and takes three input values, producing one output value.
 *
 * Inputs:
 *   - Value: Input value to be limited
 *   - Minimum: Minimum allowed value
 *   - Maximum: Maximum allowed value
 * 
 * Outputs:
 *   - Output: Limited value within the specified range
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (3 in this case)
 *   - OUTPUT_LENGTH: Number of output values (1 in this case)
 *   - inputs[3]: Array to store pointers to input values
 *   - inputConstants[3]: Array to store constant values (currently initialized to zero)
 *   - outputs[1]: Array to store the limited output value
 *
 * Member Functions:
 *   - Math_Limiter(uint16_t unique_id = 0): Constructor for Math_Limiter, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the value limiting operation and updates the output array.
 *   - float limiter(): Limits the input value within the specified range.
 *
 * Usage:
 *   - Create an instance of Math_Limiter, set input values using inputs[], and call run() to perform
 *     the value limiting operation.
 *
 * Example:
 *   ```
 *   Math_Limiter limiterBlock();
 *   limiterBlock.setInput(0, 25.0); // Input value
 *   limiterBlock.setInput(1, 0.0);  // Minimum allowed value
 *   limiterBlock.setInput(2, 10.0); // Maximum allowed value
 *   limiterBlock.run();
 *   float result = limiterBlock.getOutput(); // Result will be the limited value within the specified range => result = 10.0
 *   ```
 *
 */


class Math_Limiter : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 3;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[3] = {nullptr};
  float inputConstants[3] = {0};
  float outputs[1] = {0};

  float limiter();

public:
  Math_Limiter(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif // __MATH_LIMITER_H__