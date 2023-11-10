#include "VIRIO_ModbusSlave_Out.h"
#include "../../global_constants.h"

VIRIO_ModbusSlave_Out::VIRIO_ModbusSlave_Out(uint16_t unique_id, SerialInterface *connecedtIf) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
  interface = connecedtIf;
  if (&connecedtIf == nullptr)
    return;
  interface->increeseOutput();
}

void VIRIO_ModbusSlave_Out::write()
{
  // IMPLEMENT
  if (firstRun)
  {
    interface->addOutputBlock(this);
    firstRun = false;
  }
}

uint8_t VIRIO_ModbusSlave_Out::run()
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