#ifndef LOGICAL_SELECTOR_H
#define LOGICAL_SELECTOR_H

#include "FunctionBlock.h"
/* Logical selector block select from 2 inputs by a selector value
 * Inputs:
 * - Select input 1
 * - Select input 2
 * - Selector value
 * NOT IMPLEMENTED - Selection limit (example, if limit==0, and selector value==0 selected will be first if value==3, it will be the second one)
 */

class Logical_Selector : public FunctionBlock
{
private:
  const uint8_t INPUT_LENGTH = 3;
  const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[3] = {nullptr};
  float inputConstants[3];
  float outputs[1];

  float select();

public:
  Logical_Selector(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif