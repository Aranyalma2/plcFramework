#include "Logical_Selector.h"

Logical_Selector::Logical_Selector(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}

float Logical_Selector::select()
{

  
  // selector "bit" if not 0 select 1, else 0
  return this->castToLogical(*inputs[2]) ? *inputs[1] : *inputs[0];

}

uint8_t Logical_Selector::run()
{
  if (this->checkValidity())
  {
    outputs[0] = this->select();
    return 0;
  }
  else
  {
    return 1;
  }
}