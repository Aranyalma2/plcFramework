#include "SerialInterface.h"
#include "../global_constants.h"

 bool SerialInterface::initFinished()
  {
    if (firstRun)
    {
      inputBlocks = new FunctionBlock *[numberOfInput];
      outputBlocks = new FunctionBlock *[numberOfOutput];
      firstRun = false;
      return false;
    }
    return true;
  }

