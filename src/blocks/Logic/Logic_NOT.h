#ifndef Logic_NOT_H
#define Logic_NOT_H

#include "../FunctionBlock.h"

/*
 * Logic_NOT - Function Block for Logic NOT Operation
 *
 * Description:
 * This class defines a Function Block, Logic_NOT, for performing the Logic NOT operation.
 * It inherits from the FunctionBlock class and takes one input value and produces one output value.
 *
 * Inputs:
 *   - input 1: Input value for the Logic NOT operation
 *
 * Outputs:
 *   - output: Result of the Logic NOT operation
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (1 in this case)
 *   - OUTPUT_LENGTH: Number of output values (1 in this case)
 *   - inputs[1]: Array to store a pointer to the input value
 *   - inputConstants[1]: Array to store constant values (currently initialized to zero)
 *   - outputs[1]: Array to store the result of the Logic NOT operation
 *
 * Member Functions:
 *   - Logic_NOT(uint16_t unique_id = 0): Constructor for Logic_NOT, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the Logic NOT operation and updates the output array.
 *   - float negation(): Performs the Logic NOT operation on the input value.
 *
 * Usage:
 *   - Create an instance of Logic_NOT, set the input value using inputs[], and call run() to perform
 *     the Logic NOT operation.
 *
 * Example:
 *   ```
 *   Logic_NOT notBlock();
 *   notBlock.setInput(0, 1.0); // Input value
 *   notBlock.run();
 *   float result = notBlock.getOutput(); // Result will be 0.0 (Logic NOT of input)
 *   ```
 *
 */

class Logic_NOT : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 1;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[1] = {nullptr};
  float inputConstants[1] = {0};
  float outputs[1] = {0};

  float negation();

public:
  Logic_NOT(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif