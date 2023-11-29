#ifndef Logic_AND_H
#define Logic_AND_H

#include "../FunctionBlock.h"

/*
 * Logic_AND - Function Block for Logic AND Operation
 *
 * Description:
 * This class defines a Function Block, Logic_AND, for performing the Logic AND operation.
 * It inherits from the FunctionBlock class and takes two input values and produces two outputs:
 *   - Output: Represents the result of the Logic AND operation between input 1 and input 2.
 *   - Inverted Output: Represents the Logic NOT of the result (inverted output).
 *
 * Inputs:
 *   - input 1
 *   - input 2
 *
 * Outputs:
 *   - output: Result of the Logic AND operation (input 1 AND input 2)
 *   - inverted output: Logic NOT of the result (inverted output)
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (2 in this case)
 *   - OUTPUT_LENGTH: Number of output values (2 in this case)
 *   - inputs[2]: Array to store pointers to input values
 *   - inputConstants[2]: Array to store constant values (currently initialized to zero)
 *   - outputs[2]: Array to store the results of the Logic AND operation and its inversion
 *
 * Member Functions:
 *   - Logic_AND(uint16_t unique_id = 0): Constructor for Logic_AND, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the Logic AND operation and updates the output arrays.
 *   - float And(): Performs the Logic AND operation between input 1 and input 2.
 *   - float inverter(float in): Calculates the Logic NOT (inversion) of the input.
 *
 * Usage:
 *   - Create an instance of Logic_AND, set input values using inputs[], and call run() to perform
 *     the Logic AND operation.
 *
 * Example:
 *   ```
 *   Logic_AND andBlock(456);
 *   andBlock.setInput(0, 1.0) // True
 *   andBlock.setInput(1, 0.0) // False
 *   andBlock.run();
 *   float result = andBlock.getOutput(); // Result will be 0.0 (False)
 *   float invertedResult = andBlock.getOutput(1); // Inverted result will be 1.0 (True)
 *   ```
 *
 */

class Logic_AND : public FunctionBlock
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
  Logic_AND(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif