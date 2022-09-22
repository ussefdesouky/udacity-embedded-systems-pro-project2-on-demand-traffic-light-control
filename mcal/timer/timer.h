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