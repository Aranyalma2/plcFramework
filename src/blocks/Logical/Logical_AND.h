#ifndef LOGICAL_AND_H
#define LOGICAL_AND_H

#include "../FunctionBlock.h"

/*
 * Logical_AND - Function Block for Logical AND Operation
 *
 * Description:
 * This class defines a Function Block, Logical_AND, for performing the logical AND operation.
 * It inherits from the FunctionBlock class and takes two input values and produces two outputs:
 *   - Output: Represents the result of the logical AND operation between input 1 and input 2.
 *   - Inverted Output: Represents the logical NOT of the result (inverted output).
 *
 * Inputs:
 *   - input 1
 *   - input 2
 *
 * Outputs:
 *   - output: Result of the logical AND operation (input 1 AND input 2)
 *   - inverted output: Logical NOT of the result (inverted output)
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (2 in this case)
 *   - OUTPUT_LENGTH: Number of output values (2 in this case)
 *   - inputs[2]: Array to store pointers to input values
 *   - inputConstants[2]: Array to store constant values (currently initialized to zero)
 *   - outputs[2]: Array to store the results of the logical AND operation and its inversion
 *
 * Member Functions:
 *   - Logical_AND(uint16_t unique_id = 0): Constructor for Logical_AND, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the logical AND operation and updates the output arrays.
 *   - float And(): Performs the logical AND operation between input 1 and input 2.
 *   - float inverter(float in): Calculates the logical NOT (inversion) of the input.
 *
 * Usage:
 *   - Create an instance of Logical_AND, set input values using inputs[], and call run() to perform
 *     the logical AND operation.
 *
 * Example:
 *   ```
 *   Logical_AND andBlock(456);
 *   andBlock.inputs[0] = 1.0; // True
 *   andBlock.inputs[1] = 0.0; // False
 *   andBlock.run();
 *   float result = andBlock.outputs[0]; // Result will be 0.0 (False)
 *   float invertedResult = andBlock.outputs[1]; // Inverted result will be 1.0 (True)
 *   ```
 *
 */

class Logical_AND : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 2;
  static const uint8_t OUTPUT_LENGTH = 2;
  float *inputs[2] = {nullptr};
  float inputConstants[2] = {0};
  float outputs[2] = {0};

  float And();
  float inverter(float in);

public:
  Logical_AND(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif