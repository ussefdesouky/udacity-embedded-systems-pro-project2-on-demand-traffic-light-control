// implement cars traffic light func
// switch from red to green

// switch from green to red

// yellow blink


// implement pedestrian interrupt

// implement peds traffic light
// switch from red to green

// switch from green to red

// yellow blink
#include "application.h"

uint8_t btnPressed = 0;
uint8_t trafficCycle = 0;
EN_trafficStatus_t trafficStatus = RED_ON;

void appInit()
{   
    isrInit(INT_0);
    isrMode(INT_0, RISING);

    timerInit();

    ledInit(CAR_PORT, CAR_GREEN);
    ledInit(CAR_PORT, CAR_YELLOW);
    ledInit(CAR_PORT, CAR_RED);

    ledInit(PED_PORT, PED_GREEN);
    ledInit(PED_PORT, PED_YELLOW);
    ledInit(PED_PORT, PED_RED);
}

void appStart()
{
    if(trafficStatus > 4)
    {
        trafficStatus = RED_ON;
    }
    switch (trafficStatus)
    {
        case RED_ON:
            if(trafficCycle > 0)
            {
                btnPressed = 0;
            }
            if(btnPressed == 0)
            {
                carStop();
                trafficStatus = YELLOW_R_ON;
            }
            else if(btnPressed == 1)
            {
                pedMove();
                trafficStatus = YELLOW_R_ON;
            }
            break;

        case YELLOW_R_ON:
            if(btnPressed == 0)
            {
                carWarn();
                if(trafficStatus == YELLOW_R_ON)
                {
                    trafficStatus = GREEN_ON;
                }
                else if(trafficStatus == YELLOW_G_ON)
                {
                    trafficStatus = RED_ON;
                }
            }
            else if(btnPressed == 1)
            {
                pedWarn();
                if(trafficStatus == YELLOW_R_ON)
                {
                    trafficStatus = GREEN_ON;
                }
                else if(trafficStatus == YELLOW_G_ON)
                {
                    trafficStatus = RED_ON;
                }
            }
            break;

        case GREEN_ON:
            if(btnPressed == 0)
            {
                carMove();
                trafficStatus = YELLOW_G_ON;
            }
            else if(btnPressed == 1)
            {
                pedStop();
                trafficStatus = YELLOW_G_ON;
            }
            break;
        
        case YELLOW_G_ON:
            if(btnPressed == 0)
            {
                carWarn();
                if(trafficStatus == YELLOW_R_ON)
                {
                    trafficStatus = GREEN_ON;
                }
                else if(trafficStatus == YELLOW_G_ON)
                {
                    trafficStatus = RED_ON;
                }
            }
            else if(btnPressed == 1)
            {
                pedWarn();
                if(trafficStatus == YELLOW_R_ON)
                {
                    trafficStatus = GREEN_ON;
                }
                else if(trafficStatus == YELLOW_G_ON)
                {
                    trafficStatus = RED_ON;
                }
                trafficCycle++;
            }
            break;

        default:
            break;
    }
}

ISR(EXT_INT0){
    if(trafficStatus == GREEN_ON || trafficStatus == YELLOW_R_ON)
    {
        btnPressed = 1;
        trafficCycle = 0;
        trafficStatus = YELLOW_G_ON;
    }
}

void carStop()
{   
    ledOff(PED_PORT, PED_GREEN);
    ledOff(PED_PORT, PED_YELLOW);
    ledOff(PED_PORT, PED_RED);
    ledOff(CAR_PORT, CAR_GREEN);
    ledOff(CAR_PORT, CAR_YELLOW);
    ledOn(CAR_PORT, CAR_RED);
    for(uint8_t i = 0; i < 10; i++){
        msTimerDelay(500);
    }
}

void carMove()
{
    btnPressed = 0;
    ledOff(PED_PORT, PED_GREEN);
    ledOff(PED_PORT, PED_YELLOW);
    ledOff(PED_PORT, PED_RED);
    ledOff(CAR_PORT, CAR_RED);
    ledOff(CAR_PORT, CAR_YELLOW);
    ledOn(CAR_PORT, CAR_GREEN);
    for(uint8_t i = 0; i < 10; i++){
        msTimerDelay(500);
        if(btnPressed == 1 && trafficCycle == 0)
        {   
            pedWarn();
            break;
        }
    }
}

void carWarn()
{
    ledOff(PED_PORT, PED_GREEN);
    ledOff(PED_PORT, PED_YELLOW);
    ledOff(PED_PORT, PED_RED);
    for(uint8_t i = 0; i < 10; i++){
        ledToggle(CAR_PORT, CAR_YELLOW, 500);
        if(btnPressed == 1)
        {   
            pedWarn();
            break;
        }
        
    }
}

void pedStop()
{
    ledOff(CAR_PORT, CAR_RED);
    ledOff(PED_PORT, PED_GREEN);
    ledOff(CAR_PORT, CAR_YELLOW);
    ledOff(PED_PORT, PED_YELLOW);
    ledOn(CAR_PORT, CAR_GREEN);
    ledOn(PED_PORT, PED_RED);
    for(uint8_t i = 0; i < 10; i++){
        msTimerDelay(500);
    }
}

void pedMove()
{
    ledOff(CAR_PORT, CAR_GREEN);
    ledOff(PED_PORT, PED_RED);
    ledOff(CAR_PORT, CAR_YELLOW);
    ledOff(PED_PORT, PED_YELLOW);
    ledOn(CAR_PORT, CAR_RED);
    ledOn(PED_PORT, PED_GREEN);
    for(uint8_t i = 0; i < 10; i++){
        msTimerDelay(500);
    }
}

void pedWarn()
{
    for(uint8_t i = 0; i < 5; i++){
        ledOn(CAR_PORT, CAR_YELLOW);
        ledOn(PED_PORT, PED_YELLOW);
        msTimerDelay(500);
        ledOff(CAR_PORT, CAR_YELLOW);
        ledOff(PED_PORT, PED_YELLOW);
        msTimerDelay(500);
    }
}