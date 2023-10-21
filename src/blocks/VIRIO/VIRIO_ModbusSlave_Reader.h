#ifndef VIRIO_MODBUSSLAVE_READER_H
#define VIRIO_MODBUSSLAVE_READER_H

#include "../FunctionBlock.h"

/* Modbus Interface module, OUT interface
 * Inputs:
 * - Modbus address
 * - Function Code
 * - Data to write out from flow to modbus
 * - Multiplier
 */

class VIRIO_ModbusSlave_Reader : public FunctionBlock
{
private:
  const uint8_t INPUT_LENGTH = 4;
  const uint8_t OUTPUT_LENGTH = 0;
  float *inputs[4];
  float inputConstants[4];
  float outputs[0];

  void write();

public:
  VIRIO_ModbusSlave_Reader(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif