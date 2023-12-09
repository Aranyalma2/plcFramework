#include "HWIO_Output_Digital.h"
#include <Arduino.h>

/* HWIO_Digital_Output
value: to output
 */

HWIO_Output_Digital::HWIO_Output_Digital(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
  pinMode(unique_id, OUTPUT);
}

void HWIO_Output_Digital::write()
{
  digitalWrite(static_cast<uint16_t>(*inputs[0]), static_cast<uint16_t>(*inputs[1]));
}

uint8_t HWIO_Output_Digital::run()
{
  if (this->checkValidity())
    this->write();
  else
    return 1;
  return 0;
}