#ifndef LOGICAL_INV_H
#define LOGICAL_INV_H

#include "../FunctionBlock.h"
/* Logical Inverter
 * Inputs:
 * - input 1
 * - output
 */

class Logical_Inverter : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 1;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[1] = {nullptr};
  float inputConstants[1] = {0};
  float outputs[1] = {0};

  float inverter();

public:
  Logical_Inverter(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif