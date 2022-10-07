/*******************************************************************************/
/*################################## SKELETON #################################*/
/*******************************************************************************/
// 1. Include needed libraries.
// 2. Define functions prototypes.
// 3. Define module macros

#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "./ecual/led/led.h"
#include "./ecual/button/button.h"
#include "./mcal/timer/timer.h"
#include "./mcal/isr/isr.h"

// Car port macro
#define CAR_PORT PORT_A

// Car leds pins
#define CAR_GREEN 0
#define CAR_YELLOW 1
#define CAR_RED 2

// Peds port macro
#define PED_PORT PORT_B

// Peds leds pins
#define PED_GREEN 0
#define PED_YELLOW 1
#define PED_RED 2

// Enum for leds states
typedef enum EN_trafficStatus_t
{
    RED_ON, YELLOW_R_ON, GREEN_ON, YELLOW_G_ON
}EN_trafficStatus_t;

// Enum for traffic modes
typedef enum EN_trafficMode_t
{
    NORMAl_MODE_OFF, NORMAL_MODE_ON
}EN_trafficMode_t;

// Initialize your modules here
void appInit();

// Write your logic
void appStart();

// Car stop state when normal mode is active
void carStop();

// Warning state when normal mode is active
void carMove();

// Car move state when normal mode is active
void carWarn();

// Pedestrian stop state when normal mode is inactive
void pedStop();

// Pedestrian move state when normal mode is inactive
void pedMove();

// Warning state when normal mode is inactive
void pedWarn();

#endif