#ifndef __VIRIO_MODBUSSLAVE_WRITER_H__
#define __VIRIO_MODBUSSLAVE_WRITER_H__

#include "../FunctionBlock.h"
#include "../../HWInterfaces/SerialInterface.h"

/* Modbus Interface module, IN interface
 * Inputs:
 * - Modbus address
 * - Function Code
 * - Multiplier
 */

class VIRIO_ModbusSlave_In : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 3;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[3];
  float inputConstants[3];
  float outputs[1];

  SerialInterface *interface;

  bool firstRun = true;

  void read();

public:
  VIRIO_ModbusSlave_In(uint16_t unique_id, SerialInterface *connecedtIf);

  virtual uint8_t run() override;
};

#endif // __VIRIO_MODBUSSLAVE_WRITER_H__