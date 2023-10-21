/*
* This file is part of the plcFramework library it is the main include.
* It will inlcude all the important headers for you.
* Author: Nemeth Balint
*/

#ifndef PLCFRAMEWORK_H_INCLUDED
#define PLCFRAMEWORK_H_INCLUDED

//Placable blocks
#include "blocks/HWIO/HWIO_Input_Analog.h"
#include "blocks/HWIO/HWIO_Input_Digital.h"
#include "blocks/HWIO/HWIO_Output_Digital.h"
#include "blocks/HWIO/HWIO_Output_PWM.h"
#include "blocks/VIRIO/VIRIO_ModbusSlave_Reader.h"
#include "blocks/VIRIO/VIRIO_ModbusSlave_Writer.h"
#include "blocks/Logical/Logical_AND.h"
#include "blocks/Logical/Logical_Counter.h"
#include "blocks/Logical/Logical_OR.h"
#include "blocks/Logical/Logical_Selector.h"

#endif
