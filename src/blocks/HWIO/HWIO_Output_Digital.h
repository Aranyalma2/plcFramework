#ifndef HWIO_OUTPUT_DIGITAL_H
#define HWIO_OUTPUT_DIGITAL_H

#include "../FunctionBlock.h"
/*----------------------------------------------------------------
Hardware Pin digital output block
Output the read value 0-1023

*/

class HWIO_Output_Digital : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 1;
  static const uint8_t OUTPUT_LENGTH = 0;
  float *inputs[1] = {nullptr};
  float inputConstants[1];
  float outputs[0];

  void write();

public:
  HWIO_Output_Digital(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif