#ifndef FUNCTIONBLOCK_H
#define FUNCTIONBLOCK_H

#include <Arduino.h>

/********************************
Logical modules primitive class
contains:   -IO list pointer - float list pointer
            -Run function
            -validity IO check
            -details function for IO handler
********************************/

class FunctionBlock
{
protected:
  // block uuid uinque for all blocks
  uint16_t unique_id;

  // Input connection container
  float **inputs;
  // Output value container
  float *outputs;
  // Constant input value container
  float *inputConstants;

  uint8_t inputSize;
  uint8_t outputSize;

public:
  FunctionBlock(const uint16_t _unique_id, float **_inputs, float *_inputConstants, uint8_t inputLength, float *_outputs, uint8_t outputLength)
  {
    unique_id = _unique_id;

    inputs = _inputs;
    outputs = _outputs;
    inputConstants = _inputConstants;

    inputSize = inputLength;
    outputSize = outputLength;
  };

  // get number of inputs
  uint8_t getInputsNumber() const
  {
    return inputSize;
  };

  // get number of outputs
  uint8_t getOutputsNumber() const
  {
    return outputSize;
  };

  // getInputArray
  float **getInputs()
  {
    return inputs;
  }

  // get any output pointer
  float *getOutput(uint8_t id = 0)
  {
    if (id >= getOutputsNumber())
    {
      id = 0;
    }
    return &outputs[id];
  }

  // If user set a const to the module input, store it as local const container and use that pointer in *inputs[id]
  void setInput(uint8_t id, float value)
  {
    if (getInputsNumber() >= id)
    {
      inputConstants[id] = value;
      inputs[id] = &inputConstants[id];
    }
  }

  // If user set a const to the module input, store it as local const container and use that pointer in *inputs[id]
  void setInput(uint8_t id, double value)
  {
    if (getInputsNumber() >= id)
    {
      inputConstants[id] = static_cast<float>(value);
      inputs[id] = &inputConstants[id];
    }
  }

  // If user set a const to the module input, store it as local const container and use that pointer in *inputs[id]
  // int cast float for pure function call
  void setInput(uint8_t id, int value)
  {
    if (getInputsNumber() >= id)
    {
      inputConstants[id] = static_cast<float>(value);
      inputs[id] = &inputConstants[id];
    }
  }

  // If user set another module/input/etc as input, set that pointer to the *inputs[id]
  void setInput(uint8_t id, float *value)
  {
    if (getInputsNumber() >= id)
      inputs[id] = value;
  }

  // check block validity, all input is valid
  bool checkValidity()
  {
    for (uint8_t i = 0; i < inputSize; i++)
    {
      if (inputs[i] == nullptr)
      {
        return false;
      }
    }
    return true;
  }

  //Normalize all input value to 3 decimal point float
  void normalizeInputs(){
    for (uint8_t i = 0; i < inputSize; i++){
      double tmp = static_cast<double>(*inputs[i]);
      //Positive
      if(tmp >= 0.0)
        *inputs[i] = static_cast<float>(static_cast<int64_t>(tmp * 1000 + 0.5))/1000;
      //Negative
      else
        *inputs[i] = static_cast<float>(static_cast<int64_t>(tmp * 1000 - 0.5))/1000;
    }
  }

  // DEBUG MSG for dev purpose. Log inputs, outputs, constants
  void debug() {}

  // Execute logic calc function
  virtual uint8_t run() = 0;

  // virtual String getDetails() const = 0;
};

#endif