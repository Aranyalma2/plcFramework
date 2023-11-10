#include "ModbusRTUSlave.h"

ModbusRTUSlave::ModbusRTUSlave(uint8_t serialId, uint32_t baudrate, uint8_t slaveAddress, uint8_t dePin) : SerialInterface(serialId, baudrate)
{
  _id = slaveAddress;
  _dePin = dePin;
  _serial = SerialInterface::usedSerial;
}

void ModbusRTUSlave::run()
{
  if (!firstRun)
  {
    ModbusRTUSlave::poll();
    return;
  }
  else if (initFinished())
  {
    usedSerial->begin(baudrate);
    ModbusRTUSlave::begin();
    firstRun = false;
    return;
  }
  Serial.println("NO poll");
}

void ModbusRTUSlave::begin(uint8_t config)
{
  uint32_t startTime = micros();
  if (baudrate > 19200)
  {
    _charTimeout = 750;
    _frameTimeout = 1750;
  }
  else if (config == 0x2E || config == 0x3E)
  {
    _charTimeout = 18000000 / baudrate;
    _frameTimeout = 42000000 / baudrate;
  }
  else if (config == 0x0E || config == 0x26 || config == 0x36)
  {
    _charTimeout = 16500000 / baudrate;
    _frameTimeout = 38500000 / baudrate;
  }
  else
  {
    _charTimeout = 15000000 / baudrate;
    _frameTimeout = 35000000 / baudrate;
  }
  if (_dePin != 255)
  {
    digitalWrite(_dePin, LOW);
    pinMode(_dePin, OUTPUT);
  }
  do
  {
    if (_serial->available() > 0)
    {
      startTime = micros();
      _serial->read();
    }
  } while (micros() - startTime < _frameTimeout);
}

void ModbusRTUSlave::poll()
{
  if (_serial->available() > 0)
  {
    uint8_t i = 0;
    uint32_t startTime = 0;
    do
    {
      if (_serial->available() > 0)
      {
        startTime = micros();
        _buf[i] = _serial->read();
        i++;
      }
    } while (micros() - startTime < _charTimeout && i < _bufSize);
    while (micros() - startTime < _frameTimeout)
      ;
    if (_serial->available() == 0 && (_buf[0] == _id || _buf[0] == 0) && _crc(i - 2) == _bytesToWord(_buf[i - 1], _buf[i - 2]))
    {
      switch (_buf[1])
      {
      case 1: /* Read Coils */
        _processCoilRead();
        break;
      case 2: /* Read Discrete Inputs */
        _processDiscreteRead();
        break;
      case 3: /* Read Holding Registers */
        _processHoldingRead();
        break;
      case 4: /* Read Input Registers */
        _processInputRead();
        break;
      case 5: /* Write Single Coil */
      {
        uint16_t address = _bytesToWord(_buf[2], _buf[3]);
        uint16_t value = _bytesToWord(_buf[4], _buf[5]);
        if (value != 0 && value != 0xFF00)
          _exceptionResponse(3);
        else if (address >= _numCoils)
          _exceptionResponse(2);
        else if (!coilWrite(address, value))
          _exceptionResponse(4);
        else
          _write(6);
      }
      break;
      case 6: /* Write Single Holding Register */
      {
        uint16_t address = _bytesToWord(_buf[2], _buf[3]);
        uint16_t value = _bytesToWord(_buf[4], _buf[5]);
        if (address >= _numHoldingRegisters)
          _exceptionResponse(2);
        else if (!holdingRegisterWrite(address, value))
          _exceptionResponse(4);
        else
          _write(6);
      }
      break;
      case 15: /* Write Multiple Coils */
      {
        uint16_t startAddress = _bytesToWord(_buf[2], _buf[3]);
        uint16_t quantity = _bytesToWord(_buf[4], _buf[5]);
        if (quantity == 0 || quantity > ((_bufSize - 10) << 3) || _buf[6] != _div8RndUp(quantity))
          _exceptionResponse(3);
        else if ((startAddress + quantity) > _numCoils)
          _exceptionResponse(2);
        else
        {
          for (uint8_t j = 0; j < quantity; j++)
          {
            if (!coilWrite(startAddress + j, bitRead(_buf[7 + (j >> 3)], j & 7)))
            {
              _exceptionResponse(4);
              return;
            }
          }
          _write(6);
        }
      }
      break;
      case 16: /* Write Multiple Holding Registers */
      {
        uint16_t startAddress = _bytesToWord(_buf[2], _buf[3]);
        uint16_t quantity = _bytesToWord(_buf[4], _buf[5]);
        if (quantity == 0 || quantity > ((_bufSize - 10) >> 1) || _buf[6] != (quantity * 2))
          _exceptionResponse(3);
        else if (startAddress + quantity > _numHoldingRegisters)
          _exceptionResponse(2);
        else
        {
          for (uint8_t j = 0; j < quantity; j++)
          {
            if (!holdingRegisterWrite(startAddress + j, _bytesToWord(_buf[j * 2 + 7], _buf[j * 2 + 8])))
            {
              _exceptionResponse(4);
              return;
            }
          }
          _write(6);
        }
      }
      break;
      default:
        _exceptionResponse(1);
        break;
      }
    }
  }
}

void ModbusRTUSlave::_processCoilRead()
{
  uint16_t startAddress = _bytesToWord(_buf[2], _buf[3]);
  uint16_t quantity = _bytesToWord(_buf[4], _buf[5]);
  if (quantity == 0 || quantity > ((_bufSize - 6) * 8))
    _exceptionResponse(3);
  else if ((startAddress + quantity) > _numCoils)
    _exceptionResponse(2);
  else
  {
    for (uint8_t j = 0; j < quantity; j++)
    {
      int8_t value = coilRead(startAddress + j);
      if (value < 0)
      {
        _exceptionResponse(4);
        return;
      }
      bitWrite(_buf[3 + (j >> 3)], j & 7, value);
    }
    _buf[2] = _div8RndUp(quantity);
    _write(3 + _buf[2]);
  }
}

void ModbusRTUSlave::_processDiscreteRead()
{
  uint16_t startAddress = _bytesToWord(_buf[2], _buf[3]);
  uint16_t quantity = _bytesToWord(_buf[4], _buf[5]);
  if (quantity == 0 || quantity > ((_bufSize - 6) * 8))
    _exceptionResponse(3);
  else if ((startAddress + quantity) > _numDiscreteInputs)
    _exceptionResponse(2);
  else
  {
    for (uint8_t j = 0; j < quantity; j++)
    {
      int8_t value = discreteInputRead(startAddress + j);
      if (value < 0)
      {
        _exceptionResponse(4);
        return;
      }
      bitWrite(_buf[3 + (j >> 3)], j & 7, value);
    }
    _buf[2] = _div8RndUp(quantity);
    _write(3 + _buf[2]);
  }
}

void ModbusRTUSlave::_processHoldingRead()
{
  uint16_t startAddress = _bytesToWord(_buf[2], _buf[3]);
  uint16_t quantity = _bytesToWord(_buf[4], _buf[5]);
  if (quantity == 0 || quantity > ((_bufSize - 6) >> 1))
    _exceptionResponse(3);
  else if ((startAddress + quantity) > _numHoldingRegisters)
    _exceptionResponse(2);
  else
  {
    for (uint8_t j = 0; j < quantity; j++)
    {
      int32_t value = holdingRegisterRead(startAddress + j);
      if (value < 0)
      {
        _exceptionResponse(4);
        return;
      }
      _buf[3 + (j * 2)] = highByte(value);
      _buf[4 + (j * 2)] = lowByte(value);
    }
    _buf[2] = quantity * 2;
    _write(3 + _buf[2]);
  }
}

void ModbusRTUSlave::_processInputRead()
{
  uint16_t startAddress = _bytesToWord(_buf[2], _buf[3]);
  uint16_t quantity = _bytesToWord(_buf[4], _buf[5]);
  if (quantity == 0 || quantity > ((_bufSize - 6) >> 1))
    _exceptionResponse(3);
  else if ((startAddress + quantity) > _numInputRegisters)
    _exceptionResponse(2);
  else
  {
    for (uint8_t j = 0; j < quantity; j++)
    {
      int32_t value = inputRegisterRead(startAddress + j);
      if (value < 0)
      {
        _exceptionResponse(4);
        return;
      }
      _buf[3 + (j * 2)] = highByte(value);
      _buf[4 + (j * 2)] = lowByte(value);
    }
    _buf[2] = quantity * 2;
    _write(3 + _buf[2]);
  }
}

void ModbusRTUSlave::_exceptionResponse(uint8_t code)
{
  _buf[1] |= 0x80;
  _buf[2] = code;
  _write(3);
}

void ModbusRTUSlave::_write(uint8_t len)
{
  delay(_responseDelay);
  if (_buf[0] != 0)
  {
    uint16_t crc = _crc(len);
    _buf[len] = lowByte(crc);
    _buf[len + 1] = highByte(crc);
    if (_dePin != 255)
      digitalWrite(_dePin, HIGH);
    _serial->write(_buf, len + 2);
    _serial->flush();
    if (_dePin != 255)
      digitalWrite(_dePin, LOW);
  }
}

uint16_t ModbusRTUSlave::_crc(uint8_t len)
{
  uint16_t crc = 0xFFFF;
  for (uint8_t i = 0; i < len; i++)
  {
    crc ^= (uint16_t)_buf[i];
    for (uint8_t j = 0; j < 8; j++)
    {
      bool lsb = crc & 1;
      crc >>= 1;
      if (lsb == true)
      {
        crc ^= 0xA001;
      }
    }
  }
  return crc;
}

uint16_t ModbusRTUSlave::_div8RndUp(uint16_t value)
{
  return (value + 7) >> 3;
}

uint16_t ModbusRTUSlave::_bytesToWord(uint8_t high, uint8_t low)
{
  return (high << 8) | low;
}

// Function to read a holding register
long ModbusRTUSlave::holdingRegisterRead(uint16_t address)
{
  digitalWrite(13, 1);

  return numberOfOutput;
  for (uint16_t i = 0; i < numberOfOutput; i++)
  {
    if (*(outputBlocks[i]->getInputs()[0]) == address && *(outputBlocks[i]->getInputs()[1]) == 3)
      return static_cast<int16_t>((*(outputBlocks[i]->getInputs()[2])) * (*(outputBlocks[i]->getInputs()[3])));
  }

  return 99;
}