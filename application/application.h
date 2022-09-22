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

typedef enum EN_trafficStatus_t
{
    RED_ON, YELLOW_R_ON, GREEN_ON, YELLOW_G_ON
}EN_trafficStatus_t;

void appInit();
void appStart();

void carStop();
void carMove();
void carWarn();
void pedStop();
void pedMove();
void pedWarn();

#endif