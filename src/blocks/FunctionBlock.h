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
    Serial.println(inputSize);
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
    // Serial.println("----");
    // Serial.println(inputSize);
    // Serial.println("----");
    for (uint8_t i = 0; i < inputSize; i++)
    {
      Serial.println(*inputs[i]);
      if (inputs[i] == nullptr)
      {
        // Serial.println("Invalid");
        return false;
      }
    }
    // Serial.println("----");
    normalizeInputs();
    return true;
  }

  // Normalize all input value to 3 decimal point float
  void normalizeInputs()
  {
    for (uint8_t i = 0; i < inputSize; i++)
    {
      double tmp = static_cast<double>(*inputs[i]);
      // Positive
      if (tmp >= 0.0)
        *inputs[i] = static_cast<float>(static_cast<int64_t>(tmp * 1000 + 0.5)) / 1000;
      // Negative
      else
        *inputs[i] = static_cast<float>(static_cast<int64_t>(tmp * 1000 - 0.5)) / 1000;
    }
  }

  // Cast given float number to int by multiply it by 1000
  int64_t castToInt64(float number)
  {
    // Positive
    if (number >= 0.0)
      return static_cast<int64_t>(static_cast<double>(number) * 1000 - 0.5);
    // Negative
    else
      return static_cast<int64_t>(static_cast<double>(number) * 1000 - 0.5);
  }

  // Convert float to 0 OR 1 if value is NOT 0 it will became 1
  uint8_t castToLogic(float number)
  {
    if (number > 0.0 || number < 0.0)
      return 1;
    else
      return 0;
  }

  // DEBUG MSG for dev purpose. Log inputs, outputs, constants
  void debug() {}

  // Execute logic calc function
  virtual uint8_t run() = 0;

  // virtual String getDetails() const = 0;
};

#endif