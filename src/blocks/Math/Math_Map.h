#ifndef __MATH_MAP_H__
#define __MATH_MAP_H__

#include "../FunctionBlock.h"

/* 
 * Math_Map - Function Block for Value Range Mapping
 *
 * Description:
 * This class defines a Function Block, Math_Map, for mapping a value from one range to another.
 * It inherits from the FunctionBlock class and takes five input values, producing one output value.
 *
 * Inputs:
 *   - Input value: Value to be mapped
 *   - Original range min: Minimum value of the original range
 *   - Original range max: Maximum value of the original range
 *   - New range min: Minimum value of the new range
 *   - New range max: Maximum value of the new range
 * 
 * Outputs:
 *   - Output: Mapped value within the new range
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (5 in this case)
 *   - OUTPUT_LENGTH: Number of output values (1 in this case)
 *   - inputs[5]: Array to store pointers to input values
 *   - inputConstants[5]: Array to store constant values (currently initialized to zero)
 *   - outputs[1]: Array to store the mapped output value
 *
 * Member Functions:
 *   - Math_Map(uint16_t unique_id = 0): Constructor for Math_Map, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the value range mapping operation and updates the output array.
 *   - float map(): Maps the input value from the original range to the new range.
 *
 * Usage:
 *   - Create an instance of Math_Map, set input values using inputs[], and call run() to perform
 *     the value range mapping operation.
 *
 * Example:
 *   ```
 *   Math_Map mapperBlock(456);
 *   mapperBlock.setInput(0, 5.0); // Input value
 *   mapperBlock.setInput(1, 0.0);  // Original range min
 *   mapperBlock.setInput(2, 10.0); // Original range max
 *   mapperBlock.setInput(3, 50.0);  // New range min
 *   mapperBlock.setInput(4, 100.0);  // New range max
 *   mapperBlock.run();
 *   float result = mapperBlock.getOutput(); // Result will be the mapped value within the new range => result = 75
 *   ```
 *
 */

class Math_Map : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 5;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[5] = {nullptr};
  float inputConstants[5] = {0};
  float outputs[1] = {0};

  float map();

public:
  Math_Map(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif // __MATH_MAP_H__