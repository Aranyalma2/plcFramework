#include "VIRIO_ModbusSlave_Writer.h"

VIRIO_ModbusSlave_Writer::VIRIO_ModbusSlave_Writer(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}

void VIRIO_ModbusSlave_Writer::read()
{
  // IMPLEMENT
}

uint8_t VIRIO_ModbusSlave_Writer::run()
{
  if (this->checkValidity())
  {
    this->read();
    return 0;
  }
  else
  {
    return 1;
  }
}