#include "Math_Limiter.h"

// Constructor for Math_Limiter class
Math_Limiter::Math_Limiter(uint16_t unique_id) : FunctionBlock(unique_id, inputs, inputConstants, INPUT_LENGTH, outputs, OUTPUT_LENGTH) {}

// Perform the value limiting operation
float Math_Limiter::limiter()
{
    // Check if the input value is below the minimum
    if (*inputs[0] < *inputs[1])
        return *inputs[1];
    
    // Check if the input value is above the maximum
    if (*inputs[0] > *inputs[2])
        return *inputs[2];
    
    // Input value is within the specified range, return the original value
    return *inputs[0];
}

// Run the Math_Limiter block
uint8_t Math_Limiter::run()
{
    // Check if inputs are valid
    if (this->checkValidity())
    {
        outputs[0] = this->limiter(); // Execute the value limiting operation
        return 0;                     // Return success
    }
    else
    {
        return 1; // Return failure if inputs are not valid
    }
}
