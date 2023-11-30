/*
 * This file is part of the plcFramework library it is the main include.
 * It will inlcude all the important headers for you.
 * Author: Nemeth Balint
 */

#ifndef PLCFRAMEWORK_H_INCLUDED
#define PLCFRAMEWORK_H_INCLUDED

// Placable blocks
#include "blocks/HWIO/HWIO_Input_Analog.h"
#include "blocks/HWIO/HWIO_Input_Digital.h"
#include "blocks/HWIO/HWIO_Output_Digital.h"
#include "blocks/HWIO/HWIO_Output_PWM.h"
#include "blocks/VIRIO/VIRIO_ModbusSlave_Out.h"
#include "blocks/VIRIO/VIRIO_ModbusSlave_In.h"
#include "blocks/Logic/Logic_AND.h"
#include "blocks/Logic/Logic_Counter.h"
#include "blocks/Logic/Logic_OR.h"
#include "blocks/Logic/Logic_NOT.h"
#include "blocks/Logic/Logic_Selector.h"
#include "blocks/Controller/Controller_PID.h"
#include "blocks/Math/Math_Basic.h"
#include "blocks/Math/Math_Map.h"
#include "blocks/Math/Math_Limiter.h"

#endif
