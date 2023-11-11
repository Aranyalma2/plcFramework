#ifndef __CONTROLLER_PID_H__
#define __CONTROLLER_PID_H__

#include "../FunctionBlock.h"
/* Controller PID
 * Inputs:
 * - Actual Value
 * - SetPoint
 * - kp
 * - ki
 * - kd
 * - WorkMode (Direct/Reverse)
 */

class Controller_PID : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 6;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[6] = {nullptr};
  float inputConstants[2] = {6};
  float outputs[1] = {0};

  float integral = 0;
  float prevError = 0;

  float pid();
  float inverter(float in);

public:
  Controller_PID(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif // __CONTROLLER_PID_H__