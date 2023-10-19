#ifndef LOGICAL_OR_H
#define LOGICAL_OR_H

#include "../FunctionBlock.h"
/* Logical OR
 * - input 1
 * - input 2
 * - output
 * - inverted output
 */

class Logical_OR : public FunctionBlock
{
private:
  const uint8_t INPUT_LENGTH = 2;
  const uint8_t OUTPUT_LENGTH = 2;
  float *inputs[2] = {nullptr};
  float inputConstants[2];
  float outputs[2];

  float Or();
  float inverter(float in);

public:
  Logical_OR(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif