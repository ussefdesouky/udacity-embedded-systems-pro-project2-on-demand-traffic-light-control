#include "application.h"

uint8_t trafficCycle = 0;

EN_trafficMode_t trafficMode = NORMAL_MODE_ON;
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
    switch (trafficStatus)
    {
        case RED_ON:
            if(trafficCycle > 1)
            {
                trafficMode = NORMAL_MODE_ON;
            }
            if(trafficMode == NORMAL_MODE_ON)
            {
                carStop();
            }
            else if(trafficMode == NORMAl_MODE_OFF)
            {
                pedMove();
            }
            trafficStatus = YELLOW_R_ON;
            break;

        case YELLOW_R_ON:
            if(trafficMode == NORMAL_MODE_ON)
            {
                carWarn();
                trafficStatus = GREEN_ON;
            }
            else if(trafficMode == NORMAl_MODE_OFF)
            {   
                pedWarn();
                trafficStatus = GREEN_ON;
            }
            break;

        case GREEN_ON:
            if(trafficMode == NORMAL_MODE_ON)
            {
                carMove();
                trafficStatus = YELLOW_G_ON;
            }
            else if(trafficMode == NORMAl_MODE_OFF)
            {
                pedStop();
                pedWarn();
                trafficStatus = RED_ON;
            }
            break;
        
        case YELLOW_G_ON:
            if(trafficMode == NORMAL_MODE_ON)
            {
                carWarn();
            }
            else if(trafficMode == NORMAl_MODE_OFF)
            {   
                ledOn(PED_PORT, PED_RED);
                pedWarn();
                trafficCycle++;
            }
            trafficStatus = RED_ON;
            break;

        default:
            break;
    }
}

ISR(EXT_INT0){
    if(trafficStatus == GREEN_ON)
    {
        trafficMode = NORMAl_MODE_OFF;
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
    msTimerDelay(5000);
}

void carMove()
{
    trafficMode = NORMAL_MODE_ON;

    ledOff(PED_PORT, PED_GREEN);
    ledOff(PED_PORT, PED_YELLOW);
    ledOff(PED_PORT, PED_RED);
    ledOff(CAR_PORT, CAR_RED);
    ledOff(CAR_PORT, CAR_YELLOW);
    ledOn(CAR_PORT, CAR_GREEN);
    for(uint8_t i = 0; i < 20; i++){
        msTimerDelay(500);
        if(trafficMode == NORMAl_MODE_OFF && trafficCycle == 0)
        {   
            break;
        }
    }
}

void carWarn()
{
    ledOff(PED_PORT, PED_GREEN);
    ledOff(PED_PORT, PED_YELLOW);
    ledOff(PED_PORT, PED_RED);
    for(uint8_t i = 0; i < 8; i++){
        ledToggle(CAR_PORT, CAR_YELLOW, 1000);
    }
}

void pedStop()
{   
    trafficMode = NORMAL_MODE_ON;

    ledOff(CAR_PORT, CAR_RED);
    ledOff(PED_PORT, PED_GREEN);
    ledOff(CAR_PORT, CAR_YELLOW);
    ledOff(PED_PORT, PED_YELLOW);
    ledOn(CAR_PORT, CAR_GREEN);
    ledOn(PED_PORT, PED_RED);
    
    for(uint8_t i = 0; i < 20; i++){
        msTimerDelay(500);
        if(trafficMode == NORMAl_MODE_OFF && trafficCycle < 2)
        {   
            pedWarn();
            break;
        }
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
    for(uint8_t i = 0; i < 20; i++){
        msTimerDelay(500);
    }
}

void pedWarn()
{
    for(uint8_t i = 0; i < 4; i++){
        ledOn(CAR_PORT, CAR_YELLOW);
        ledOn(PED_PORT, PED_YELLOW);
        msTimerDelay(1000);
        ledOff(CAR_PORT, CAR_YELLOW);
        ledOff(PED_PORT, PED_YELLOW);
        msTimerDelay(1000);
    }
}