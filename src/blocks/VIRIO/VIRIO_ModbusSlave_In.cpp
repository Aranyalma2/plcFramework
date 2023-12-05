#include "VIRIO_ModbusSlave_In.h"

VIRIO_ModbusSlave_In::VIRIO_ModbusSlave_In(uint16_t unique_id, SerialInterface *connecedtIf) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
  interface = connecedtIf;
  if (connecedtIf == nullptr)
    return;
  interface->increaseInput();
}

void VIRIO_ModbusSlave_In::read()
{
  // IMPLEMENT
  if (firstRun)
  {
    interface->addInputBlock(this);
    firstRun = false;
  }
}

uint8_t VIRIO_ModbusSlave_In::run()
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