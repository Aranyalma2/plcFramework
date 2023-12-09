#ifndef __MODBUSRTUSLAVE_H__
#define __MODBUSRTUSLAVE_H__

#include "SerialInterface.h"

class ModbusRTUSlave : public SerialInterface
{
public:
  ModbusRTUSlave(uint8_t serialId, uint32_t baudrate, uint8_t slaveAddress, uint8_t dePin = 255);

  void run();

private:
  Stream *_serial;
  uint8_t _buf[128];
  uint16_t _bufSize = 128;
  uint8_t _dePin;
  uint16_t _numCoils = 1000;
  uint16_t _numDiscreteInputs = 1000;
  uint16_t _numHoldingRegisters = 1000;
  uint16_t _numInputRegisters = 1000;

  uint8_t _id;
  uint32_t _charTimeout;
  uint32_t _frameTimeout;
  uint32_t _responseDelay = 0;

  void begin(uint8_t config = 0x06);
  void poll();

  void _processCoilRead();
  void _processDiscreteRead();
  void _processHoldingRead();
  void _processInputRead();
  void _exceptionResponse(uint8_t code);
  void _write(uint8_t len);

  uint16_t _crc(uint8_t len);
  uint16_t _div8RndUp(uint16_t value);
  uint16_t _bytesToWord(uint8_t high, uint8_t low);

  int8_t coilRead(uint16_t address) { return 0; }
  boolean coilWrite(unsigned int address, boolean value) { return 0; }
  int8_t discreteInputRead(uint16_t address) { return 0; }
  long holdingRegisterRead(uint16_t address);
  boolean holdingRegisterWrite(word address, word value);
  long inputRegisterRead(word address) { return 0; }

};
#endif // __MODBUSRTUSLAVE_H__