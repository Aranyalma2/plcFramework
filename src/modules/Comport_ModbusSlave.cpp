#include "Comport_ModbusSlave.h"

void Comport_ModbusSlave::begin()
{
  ModbusRTUSlave::begin(slaveID, baudrate, serialMode);
}

// Function to read a coil
int8_t Comport_ModbusSlave::coilRead(uint16_t address)
{
  for (uint16_t i = 0; i < num_of_writers; i++)
  {
    if (*(writers[i]->getInputs()[0]) == address && *(writers[i]->getInputs()[1]) == 1)
      return static_cast<int8_t>((*(writers[i]->getInputs()[2])));
  }
  return 0;
}

// Function to write a coil
boolean Comport_ModbusSlave::coilWrite(uint16_t address, boolean value)
{
  {
    for (uint16_t i = 0; i < num_of_readers; i++)
    {
      if (*(writers[i]->getInputs()[0]) == address && *(writers[i]->getInputs()[1]) == 1)
      {
        (*(writers[i]->getOutput())) = static_cast<float>(value);
        return true;
      }
    }
    return false;
  }
}

// Function to read a discrete input
int8_t Comport_ModbusSlave::discreteInputRead(uint16_t address)
{
  for (uint16_t i = 0; i < num_of_writers; i++)
  {
    if (*(writers[i]->getInputs()[0]) == address && *(writers[i]->getInputs()[1]) == 2)
      return static_cast<int8_t>((*(writers[i]->getInputs()[2])));
  }
  return 0;
}

// Function to read a holding register
long Comport_ModbusSlave::holdingRegisterRead(uint16_t address)
{
  /*
  for (uint16_t i = 0; i < num_of_writers; i++)
  {
    if (*(writers[i]->getInputs()[0]) == address && *(writers[i]->getInputs()[1]) == 3)
      return static_cast<int16_t>((*(writers[i]->getInputs()[2])) * (*(writers[i]->getInputs()[3])));
  }
  */
  return 0;
}

// Function to write a holding register
boolean Comport_ModbusSlave::holdingRegisterWrite(word address, word value)
{
  {
    for (uint16_t i = 0; i < num_of_readers; i++)
    {
      if (*(writers[i]->getInputs()[0]) == address && *(writers[i]->getInputs()[1]) == 3)
      {
        (*(writers[i]->getOutput())) = static_cast<float>(value) * (*(writers[i]->getInputs()[3]));
        return true;
      }
    }
    return false;
  }
}

// Function to read an input register
long Comport_ModbusSlave::inputRegisterRead(word address)
{
  for (uint16_t i = 0; i < num_of_writers; i++)
  {
    if (*(writers[i]->getInputs()[0]) == address && *(writers[i]->getInputs()[1]) == 4)
      return static_cast<int16_t>((*(writers[i]->getInputs()[2])) * (*(writers[i]->getInputs()[3])));
  }
  return 0;
}

// Function to add a Modbus reader block reference for read data from modbus register
void Comport_ModbusSlave::addModbusReader(FunctionBlock *block)
{
  readers[index_of_readerArray] = block;
  index_of_readerArray++;
}

// Function to add a Modbus writer block reference for data write to modbus register
void Comport_ModbusSlave::addModbusWriter(FunctionBlock *block)
{
  writers[index_of_writerArray] = block;
  index_of_writerArray++;
}
