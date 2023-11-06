#ifndef LOGICAL_COUNTER_H
#define LOGICAL_COUNTER_H

#include "../FunctionBlock.h"
/* Logical Counter input detaction high to low or low to high with start and way controlling.
 * Inputs:
 * - input value 0/1 pulse
 * - input detaction mode (low to high or high to low)
 * - counter start number
 * - count way (up or down) 1/-1
 * - reset value 0/1 pulse
 * - reset detaction mode (low to high or high to low)
 */

class Logical_Counter : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 7;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[7] = {nullptr};
  float inputConstants[7];
  float outputs[1];

  uint8_t lastInput = 0;
  uint8_t lastReset = 0;
  float counter();

public:
  Logical_Counter(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif