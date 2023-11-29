#ifndef LOGICAL_NOT_H
#define LOGICAL_NOT_H

#include "../FunctionBlock.h"

/*
 * Logical_NOT - Function Block for Logical NOT Operation
 *
 * Description:
 * This class defines a Function Block, Logical_NOT, for performing the logical NOT operation.
 * It inherits from the FunctionBlock class and takes one input value and produces one output value.
 *
 * Inputs:
 *   - input 1: Input value for the logical NOT operation
 *
 * Outputs:
 *   - output: Result of the logical NOT operation
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (1 in this case)
 *   - OUTPUT_LENGTH: Number of output values (1 in this case)
 *   - inputs[1]: Array to store a pointer to the input value
 *   - inputConstants[1]: Array to store constant values (currently initialized to zero)
 *   - outputs[1]: Array to store the result of the logical NOT operation
 *
 * Member Functions:
 *   - Logical_NOT(uint16_t unique_id = 0): Constructor for Logical_NOT, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the logical NOT operation and updates the output array.
 *   - float negation(): Performs the logical NOT operation on the input value.
 *
 * Usage:
 *   - Create an instance of Logical_NOT, set the input value using inputs[], and call run() to perform
 *     the logical NOT operation.
 *
 * Example:
 *   ```
 *   Logical_NOT notBlock();
 *   notBlock.setInput(0, 1.0); // Input value
 *   notBlock.run();
 *   float result = notBlock.getOutput(); // Result will be 0.0 (logical NOT of input)
 *   ```
 *
 */

class Logical_NOT : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 1;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[1] = {nullptr};
  float inputConstants[1] = {0};
  float outputs[1] = {0};

  float negation();

public:
  Logical_NOT(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif