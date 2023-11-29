#ifndef Logic_SELECTOR_H
#define Logic_SELECTOR_H

#include "../FunctionBlock.h"

/*
 * Logic_Selector - Function Block for Logic Selection
 *
 * Description:
 * This class defines a Function Block, Logic_Selector, for selecting between two input values based on a selector value.
 * It inherits from the FunctionBlock class and takes three input values, producing one output value.
 *
 * Inputs:
 *   - Select input 1: First input value for selection
 *   - Select input 2: Second input value for selection
 *   - Selector value: Value to determine which input to select
 *
 * Outputs:
 *   - Output: Selected output value based on the selector value
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (3 in this case)
 *   - OUTPUT_LENGTH: Number of output values (1 in this case)
 *   - inputs[3]: Array to store pointers to input values
 *   - inputConstants[3]: Array to store constant values (currently initialized to zero)
 *   - outputs[1]: Array to store the selected output value
 *
 * Member Functions:
 *   - Logic_Selector(uint16_t unique_id = 0): Constructor for Logic_Selector, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the Logic selection operation and updates the output array.
 *   - float select(): Selects the output value based on the selector value and input values.
 *
 * Usage:
 *   - Create an instance of Logic_Selector, set input values using inputs[], and call run() to perform
 *     the Logic selection operation.
 *
 * Example:
 *   ```
 *   Logic_Selector selectorBlock();
 *   selectorBlock.setInput(0, 1.0) // First input value
 *   selectorBlock.setInput(1, 2.0) // Second input value
 *   selectorBlock.setInput(2, 1.0) // Selector value
 *   selectorBlock.run();
 *   float result = selectorBlock.getOutput(0); // Result will be 2.0 (selected the second input)
 *   ```
 *
 */

class Logic_Selector : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 3;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[3] = {nullptr};
  float inputConstants[3] = {0};
  float outputs[1] = {0};

  float select(); // Perform the Logic selection operation

public:
  Logic_Selector(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif // Logic_SELECTOR_H
