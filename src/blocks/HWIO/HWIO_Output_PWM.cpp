#include "HWIO_Output_PWM.h"
#include <Arduino.h>
#include "../../global_constants.h"

/* HWIO_Input
0 : Source
1 : PWM freq
2 : Minimum
3 : Maximum
 */

HWIO_Output_PWM::HWIO_Output_PWM(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH)
{
}
void HWIO_Output_PWM::write()
{
  float range = *inputs[3] - *inputs[2];
  uint16_t out = static_cast<uint16_t>(*inputs[1] * PWM_DUTY / range);
  analogWrite(*inputs[0], out);
}

uint8_t HWIO_Output_PWM::run()
{
  if (this->checkValidity())
  {
    this->write();
    return 0;
  }
  else
  {
    return 1;
  }
}