#ifndef __SERIALINTERFACE_H__
#define __SERIALINTERFACE_H__

#include <Arduino.h>
#include "../blocks/FunctionBlock.h"
#include "../global_constants.h"

class SerialInterface
{
private:
  uint16_t idxInput = 0;
  uint16_t idxOutput = 0;
  bool firstRun = true;

protected:
  HardwareSerial *usedSerial;
  uint32_t baudrate;
  uint16_t numberOfInput = 0;
  uint16_t numberOfOutput = 0;
  FunctionBlock **inputBlocks;
  FunctionBlock **outputBlocks;

public:
  SerialInterface(unsigned int serialId = 0, uint32_t _baudrate = 19200)
  {
    usedSerial = &usableSerials[serialId];
    baudrate = _baudrate;
  };

  void increeseInput() { numberOfInput++; }
  void increeseOutput() { numberOfOutput++; }

  void addInputBlock(FunctionBlock *block)
  {
    inputBlocks[idxInput] = block;
    idxInput++;
  }

  void addOutputBlock(FunctionBlock *block)
  {
    outputBlocks[idxOutput] = block;
    idxOutput++;
    Serial.println("OutAdded");
  }

  bool initFinished()
  {
    if (firstRun)
    {
      inputBlocks = new FunctionBlock *[numberOfInput];
      outputBlocks = new FunctionBlock *[numberOfOutput];
      firstRun = false;
      Serial.println("Dynamic reved");
      return false;
    }
    else if (idxInput != numberOfInput && idxOutput != numberOfOutput)
    {
      return false;
    }
    return true;
  }
};

#endif // __SERIALINTERFACE_H__