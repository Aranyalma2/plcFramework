#include "Controller_PID.h"

// Constructor for Controller_PID class
Controller_PID::Controller_PID(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the PID controller computation
float Controller_PID::pid()
{
  // Compute the error, integral, and derivative terms
  float error = *inputs[1] - *inputs[0];
  integral += error;
  float derivative = error - prevError;

  // Update the previous error for the next iteration
  prevError = error;

  // Check the work mode (Direct or Reverse) and compute the PID controller output accordingly
  if (this->castToLogic(*inputs[5]) == 0)
  {
    // Direct mode
    return *inputs[2] * error + *inputs[3] * integral + *inputs[4] * derivative;
  }
  else if (this->castToLogic(*inputs[5]) == 1)
  {
    // Reverse mode
    return -(*inputs[2] * error + *inputs[3] * integral + *inputs[4] * derivative);
  }
  else
  {
    // Should never happen, return 0.0 in case of unexpected work mode value
    return 0.0;
  }
}

// Run the Controller_PID block
uint8_t Controller_PID::run()
{
  // Check if inputs are valid
  if (this->checkValidity())
  {
    outputs[0] = this->pid(); // Execute the PID controller computation
    return 0;                 // Return success
  }
  else
  {
    return 1; // Return failure if inputs are not valid
  }
}
