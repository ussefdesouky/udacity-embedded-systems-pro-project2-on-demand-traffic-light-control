/*******************************************************************************/
/*################################## SKELETON #################################*/
/*******************************************************************************/
// 1. Include needed libraries.
// 2. Define the functions prototypes.
// 3. Define module macros.
// 4. Define global variables.

#include "timer.h"

uint16_t overFlowCnt = 0;
uint32_t overFlowNum = 0;

// Micro second timer initialization
void timerInit()
{
    TCCR0 = 0x00;
    TCNT0 = 0x00;
}

// Micro seconds to delay
/*void usTimerDelay(uint16_t us)
{

}*/

// Milli seconds to delay
void msTimerDelay(uint16_t ms)
{
    // Set the timer counter control mode (No prescaling)
    TCCR0 |= (1 << 0);

    overFlowNum = ms / 256;
    overFlowNum = overFlowNum * 1000;

    while(overFlowCnt < overFlowNum)
    { 
        // Wait till the ovf flag triggers
        while((TIFR & (1 << 0)) == 0);

        // Clear the overflow flag by setting it's reg to one
        TIFR |= (1 << 0);

        overFlowCnt++;
    }
    overFlowCnt = 0;

    // Stop timer
    TCCR0 = 0x00;
} 

// Normal timer delay
void normTimerDelay()
{
    // Set the timer counter control mode (No prescaling)
    TCCR0 |= (1 << 0);

    // Wait till the ovf flag triggers
    while((TIFR & (1 << 0)) == 0);

    // Clear the overflow flag by setting it's reg to one
    TIFR |= (1 << 0);

    // Stop timer
    TCCR0 = 0x00;
} 
