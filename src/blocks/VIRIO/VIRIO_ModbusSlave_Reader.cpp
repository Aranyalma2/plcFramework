#include "VIRIO_ModbusSlave_Reader.h"

VIRIO_ModbusSlave_Reader::VIRIO_ModbusSlave_Reader(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}

void VIRIO_ModbusSlave_Reader::write()
{
  // IMPLEMENT
}

uint8_t VIRIO_ModbusSlave_Reader::run()
{
  if (this->checkValidity())
  {
    this->write();
    return 0;
  }
  else
  {
    return 1;
  }
}