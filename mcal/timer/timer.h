/*******************************************************************************/
/*################################## SKELETON #################################*/
/*******************************************************************************/
// 1. Include needed libraries.
// 2. Define the functions prototypes
// 3. Define module macros

#ifndef TIMER_H
#define TIMER_H

#include "../../util/registers.h"

// Micro second timer initialization
void timerInit();

// Micro seconds to delay
void usTimerDelay(uint16_t us);

// Milli seconds to delay
void msTimerDelay(uint16_t ms); 

// Normal timer delay
void normTimerDelay();

#endif