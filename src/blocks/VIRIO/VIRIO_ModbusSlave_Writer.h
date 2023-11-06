#ifndef __VIRIO_MODBUSSLAVE_WRITER_H__
#define __VIRIO_MODBUSSLAVE_WRITER_H__

#include "../FunctionBlock.h"

/* Modbus Interface module, IN interface
 * Inputs:
 * - Modbus address
 * - Function Code
 * - Multiplier
 */

class VIRIO_ModbusSlave_Writer : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 3;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[3];
  float inputConstants[3];
  float outputs[1];

  void read();

public:
  VIRIO_ModbusSlave_Writer(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif // __VIRIO_MODBUSSLAVE_WRITER_H__