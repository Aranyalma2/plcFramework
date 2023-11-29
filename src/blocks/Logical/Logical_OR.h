#ifndef LOGICAL_OR_H
#define LOGICAL_OR_H

#include "../FunctionBlock.h"

/*
 * Logical_OR - Function Block for Logical OR Operation
 *
 * Description:
 * This class defines a Function Block, Logical_OR, for performing the logical OR operation.
 * It inherits from the FunctionBlock class and takes two input values, producing two output values.
 *
 * Inputs:
 *   - input 1: First input value for the logical OR operation
 *   - input 2: Second input value for the logical OR operation
 *
 * Outputs:
 *   - output: Result of the logical OR operation
 *   - inverted output: Inverted result of the logical OR operation
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (2 in this case)
 *   - OUTPUT_LENGTH: Number of output values (2 in this case)
 *   - inputs[2]: Array to store pointers to input values
 *   - inputConstants[2]: Array to store constant values (currently initialized to zero)
 *   - outputs[2]: Array to store the result of the logical OR operation
 *
 * Member Functions:
 *   - Logical_OR(uint16_t unique_id = 0): Constructor for Logical_OR, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the logical OR operation and updates the output array.
 *   - float Or(): Performs the logical OR operation on the input values.
 *   - float inverter(float in): Inverts the input value.
 *
 * Usage:
 *   - Create an instance of Logical_OR, set input values using inputs[], and call run() to perform
 *     the logical OR operation.
 *
 * Example:
 *   ```
 *   Logical_OR orBlock(0);
 *   orBlock.setInput(0, 1.0) // True
 *   orBlock.setInput(1, 0.0) // False
 *   orBlock.run();
 *   float result = orBlock.getOutput(); // Result will be 1.0 (True)
 *   float invertedResult = orBlock.getOutput(1); // Inverted result will be 0.0 (False)
 *   ```
 *
 */

class Logical_OR : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 2;
  static const uint8_t OUTPUT_LENGTH = 2;
  float *inputs[2] = {nullptr};
  float inputConstants[2] = {0};
  float outputs[2] = {0};

  float Or();
  float inverter(float in);

public:
  Logical_OR(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif