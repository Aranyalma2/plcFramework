#ifndef HWIO_INPUT_DIGITAL_H
#define HWIO_INPUT_DIGITAL_H

#include "../FunctionBlock.h"
/*----------------------------------------------------------------
Hardware Pin digital input block
Output the read value 0-1

*/

class HWIO_Input_Digital : public FunctionBlock
{
private:
  const uint8_t INPUT_LENGTH = 1;
  const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[1] = {nullptr};
  float inputConstants[1];
  float outputs[1];

  uint8_t lastPinMode = 0;
  float input();

public:
  HWIO_Input_Digital(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif