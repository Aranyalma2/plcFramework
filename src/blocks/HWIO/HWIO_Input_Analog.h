#ifndef HWIO_INPUT_ANALOG_H
#define HWIO_INPUT_ANALOG_H

#include "../FunctionBlock.h"
/*----------------------------------------------------------------
Hardware Pin analog input block
Input the hardware pin id
Output the read value 0-1023

*/
class HWIO_Input_Analog : public FunctionBlock
{
private:
  const uint8_t INPUT_LENGTH = 1;
  const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[1];
  float inputConstants[1];
  float outputs[1];

  float input();

public:
  HWIO_Input_Analog(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif