#ifndef LOGICAL_COUNTER_H
#define LOGICAL_COUNTER_H

#include "../FunctionBlock.h"

/*
 * Logical_Counter - Function Block for Logical Counter count by pulse detection
 *
 * Description:
 * This class defines a Function Block, Logical_Counter, for counting pulses based on input parameter.
 * It inherits from the FunctionBlock class and extends it by counting up or down edge of a pulse,
 * specifying the start number, controlling the counting direction and amount, reset by up or down edge of another pulse.
 *
 * Inputs:
 *   - input value: 0/1 pulse representing the input signal
 *   - input detection mode: Specifies the transition (low to high or high to low) to trigger counting
 *   - counter start number: Initial value of the counter
 *   - count way: Specifies the counting direction (up or down) with values 1 or -1, respectively
 *   - reset value: 0/1 pulse representing the reset signal
 *   - reset detection mode: Specifies the transition (low to high or high to low) to trigger resetting
 *
 * Outputs:
 *   - output: Counter state
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (6 in this case)
 *   - OUTPUT_LENGTH: Number of output values (1 in this case)
 *   - inputs[6]: Array to store pointers to input values
 *   - inputConstants[6]: Array to store constant values (currently initialized to zero)
 *   - outputs[1]: Array to store the result of the logical counting operation
 *   - lastInput: Holds the last value of the input for detecting changes
 *   - lastReset: Holds the last value of the reset signal for detecting changes
 *   - firstRun: Flag indicating the first execution of the run function
 *
 * Member Functions:
 *   - Logical_Counter(uint16_t unique_id = 0): Constructor for Logical_Counter, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the logical counting operation based on the input signals.
 *   - float counter(): Performs the counting operation based on input signals and updates the counter value.
 *
 * Usage:
 *   - Create an instance of Logical_Counter, set input values using inputs[], and call run() to perform
 *     the logical counting operation.
 *
 * Example:
 *   ```
 *   Logical_Counter counterBlock();
 *   counterBlock.setInput(0, 1.0); // Input pulse
 *   counterBlock.setInput(1, 1.0); // High to low transition detection
 *   counterBlock.setInput(2, 10.0); // Counter start number
 *   counterBlock.setInput(3, 1.0); // Count up by 1
 *   counterBlock.setInput(4, 0.0); // Reset pulse
 *   counterBlock.setInput(5, 0.0); // Low to high transition detection for reset
 *   counterBlock.run();
 *
 *   counterBlock.setInput(0, 0.0); // Change input pulse
 *   counterBlock.run();
 *
 *   float result = counterBlock.getOutput(); // result = 11
 *   ```
 *
 */

class Logical_Counter : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 6;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[6] = {nullptr};
  float inputConstants[6] = {0};
  float outputs[1] = {0};

  uint8_t lastInput = 0;
  uint8_t lastReset = 0;
  uint8_t firstRun = 1;
  float counter();

public:
  Logical_Counter(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif