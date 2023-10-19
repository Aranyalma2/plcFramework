#ifndef COMPORT_MODBUSSLAVE_H
#define COMPORT_MODBUSSLAVE_H

#include "ModbusRTUSlave.h"
#include "../blocks/FunctionBlock.h"

class Comport_ModbusSlave : ModbusRTUSlave
{
private:
  const uint16_t REGISTER_MAX = 65535; // MAX modbus register number
  const int BUFFER_SIZE = 128;         // Modbus communication buffer size
  byte buffer[128];
  uint8_t slaveID;    // Modbus slave address
  uint32_t baudrate;  // Modbus baudrate
  uint8_t serialMode; // Hardware serial settings

  // Blocks for communication
  FunctionBlock **readers;
  uint16_t num_of_readers;
  uint16_t index_of_readerArray = 0;
  FunctionBlock **writers;
  uint16_t num_of_writers;
  uint16_t index_of_writerArray = 0;

  // Modbus function overridde
  int8_t coilRead(uint16_t address);
  boolean coilWrite(uint16_t address, boolean value);
  int8_t discreteInputRead(uint16_t address);
  long holdingRegisterRead(uint16_t address);
  boolean holdingRegisterWrite(word address, word value);
  long inputRegisterRead(word address);

public:
  Comport_ModbusSlave(uint32_t baudrate, uint8_t address,
                      FunctionBlock **readers, uint16_t num_of_readers, FunctionBlock **writers, uint16_t num_of_writers,
                      Stream &serial, byte serialMode, uint8_t RS485_CONTROL_PIN)
      : ModbusRTUSlave(serial, buffer, BUFFER_SIZE, RS485_CONTROL_PIN), baudrate(baudrate), slaveID(address), serialMode(serialMode),
        readers(readers), num_of_readers(num_of_readers), writers(writers), num_of_writers(num_of_writers){};

  void begin();
  void addModbusReader(FunctionBlock *block);
  void addModbusWriter(FunctionBlock *block);
  void poll() { ModbusRTUSlave::poll(); }
};

#endif
