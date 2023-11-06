#ifndef LOGICAL_AND_H
#define LOGICAL_AND_H

#include "../FunctionBlock.h"
/* Logical AND
 * Inputs:
 * - input 1
 * - input 2
 * - output
 * - inverted output
 */

namespace
{
  const uint8_t INPUT_LENGTH = 2;
  const uint8_t OUTPUT_LENGTH = 2;
}

class Logical_AND : public FunctionBlock
{
private:
  float *inputs[2] = {nullptr};
  float inputConstants[2];
  float outputs[2];

  float And();
  float inverter(float in);

public:
  Logical_AND(uint16_t unique_id = 0) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
  {
  }

  virtual uint8_t run() override;
};

#endif