#ifndef __MATH_BASIC_H__
#define __MATH_BASIC_H__

#include "../FunctionBlock.h"
/* Math-Basic
 * Inputs:
 * - input 1
 * - input 2
 * - operation (ADD/SUB/MUL/DIV)
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