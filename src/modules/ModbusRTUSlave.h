#ifndef ModbusRTUSlave_h
#define ModbusRTUSlave_h

#define NO_DE_PIN 255

#include <Arduino.h>

class ModbusRTUSlave
{
public:
  ModbusRTUSlave(Stream &serial, uint8_t *buf, uint16_t bufSize, uint8_t dePin = NO_DE_PIN, uint32_t responseDelay = 0);

  void begin(uint8_t id, uint32_t baud, uint8_t config = 0x06);
  void poll();

  virtual int8_t coilRead(uint16_t address);
  virtual boolean coilWrite(unsigned int address, boolean value);
  virtual int8_t discreteInputRead(uint16_t address);
  virtual long holdingRegisterRead(uint16_t address);
  virtual boolean holdingRegisterWrite(word address, word value);
  virtual long inputRegisterRead(word address);

private:
  Stream *_serial;
  uint8_t *_buf;
  uint16_t _bufSize;
  uint8_t _dePin;
  uint16_t _numCoils = 1000;
  uint16_t _numDiscreteInputs = 1000;
  uint16_t _numHoldingRegisters = 1000;
  uint16_t _numInputRegisters = 1000;

  uint8_t _id;
  uint32_t _charTimeout;
  uint32_t _frameTimeout;
  uint32_t _responseDelay;
  void _processCoilRead();
  void _processDiscreteRead();
  void _processHoldingRead();
  void _processInputRead();
  void _exceptionResponse(uint8_t code);
  void _write(uint8_t len);
  uint16_t _crc(uint8_t len);
  uint16_t _div8RndUp(uint16_t value);
  uint16_t _bytesToWord(uint8_t high, uint8_t low);
};

#endif
