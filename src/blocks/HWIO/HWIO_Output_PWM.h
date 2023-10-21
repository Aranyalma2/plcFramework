#ifndef HWIO_OUTPUT_PWM_H
#define HWIO_OUTPUT_PWM_H

#include "../FunctionBlock.h"
/*----------------------------------------------------------------
Hardware Pin analog output block (PWM)
HWIO_Input
0 : HW pin
1 : PWM value
2 : Minimum
3 : Maximum

*/

class HWIO_Output_PWM : public FunctionBlock
{
private:
  const uint8_t INPUT_LENGTH = 4;
  const uint8_t OUTPUT_LENGTH = 0;
  float *inputs[4] = {nullptr};
  float inputConstants[4];
  float outputs[0];

  void write();

public:
  HWIO_Output_PWM(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif