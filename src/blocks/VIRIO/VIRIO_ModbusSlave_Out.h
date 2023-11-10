#ifndef VIRIO_MODBUSSLAVE_READER_H
#define VIRIO_MODBUSSLAVE_READER_H

#include "../FunctionBlock.h"
#include "../../HWInterfaces/SerialInterface.h"

/* Modbus Interface module, OUT interface
 * Inputs:
 * - Modbus address
 * - Function Code
 * - Data to expose out from flow to modbus
 * - Multiplier
 */

class VIRIO_ModbusSlave_Out : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 4;
  static const uint8_t OUTPUT_LENGTH = 0;
  float *inputs[4];
  float inputConstants[4];
  float outputs[0];
  SerialInterface *interface;

  bool firstRun = true;

  void write();

public:
  VIRIO_ModbusSlave_Out(uint16_t unique_id, SerialInterface *connecedtIf);

  virtual uint8_t run() override;
};

#endif