#ifndef __CONTROLLER_PID_H__
#define __CONTROLLER_PID_H__

#include "../FunctionBlock.h"

/*
 * Controller_PID - Function Block for Proportional-Integral-Derivative (PID) Controller
 *
 * Description:
 * This class defines a Function Block, Controller_PID, for implementing a PID controller.
 * It inherits from the FunctionBlock class and takes six input values, producing one output value.
 *
 * Inputs:
 *   - Actual Value: Current value of the system being controlled
 *   - SetPoint: Desired setpoint for the system
 *   - kp: Proportional gain
 *   - ki: Integral gain
 *   - kd: Derivative gain
 *   - WorkMode (Direct: 0/Reverse: 1): Specifies the controller work mode (Direct or Reverse)
 *
 * Outputs:
 *   - Output: Result of the PID controller computation
 *
 * Member Variables:
 *   - INPUT_LENGTH: Number of input values (6 in this case)
 *   - OUTPUT_LENGTH: Number of output values (1 in this case)
 *   - inputs[6]: Array to store pointers to input values
 *   - inputConstants[2]: Array to store constant values (currently initialized to 6)
 *   - outputs[1]: Array to store the result of the PID controller computation
 *   - integral: Variable to store the integral term of the PID controller
 *   - prevError: Variable to store the previous error for computing the derivative term
 *
 * Member Functions:
 *   - Controller_PID(uint16_t unique_id = 0): Constructor for Controller_PID, initializes the object with a unique ID.
 *   - virtual uint8_t run() override: Executes the PID controller computation and updates the output array.
 *   - float pid(): Computes the PID controller output based on the input values and gains.
 *   - float inverter(float in): Inverts the input value.
 *
 * Usage:
 *   - Create an instance of Controller_PID, set input values using inputs[], and call run() to perform
 *     the PID controller computation.
 *
 * Example:
 *   ```
 *   Controller_PID pidController(123);
 *   pidController.setInput(0, 20.0).; // Actual Value
 *   pidController.setInput(0, 25.0); // SetPoint
 *   pidController.setInput(0, 1.5);  // kp
 *   pidController.setInput(0, 1.0);  // ki
 *   pidController.setInput(0, 0.1);  // kd
 *   pidController.setInput(0, 0.0);  // WorkMode (0.0 for Direct, 1.0 for Reverse)
 *   pidController.run();
 *   float result = pidController.getOutput(0); // Result will be the PID controller output
 *   ```
 *
 */

class Controller_PID : public FunctionBlock
{
private:
  static const uint8_t INPUT_LENGTH = 6;
  static const uint8_t OUTPUT_LENGTH = 1;
  float *inputs[6] = {nullptr};
  float inputConstants[2] = {6};
  float outputs[1] = {0};

  float integral = 0;  // Variable to store the integral term of the PID controller
  float prevError = 0; // Variable to store the previous error for computing the derivative term

  float pid();              // Perform the PID controller computation
  float inverter(float in); // Invert the input value

public:
  Controller_PID(uint16_t unique_id = 0);

  virtual uint8_t run() override;
};

#endif // __CONTROLLER_PID_H__
