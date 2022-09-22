#include "led.h"

void ledInit(uint8_t port, uint8_t pin)
{
    ioInit(port, pin, OUTPUT);
}

void ledOn(uint8_t port, uint8_t pin)
{
    ioWrite(port, pin, HIGH);
}

void ledOff(uint8_t port, uint8_t pin)
{
    ioWrite(port, pin, LOW);
}

void ledToggle(uint8_t port, uint8_t pin, uint16_t delay)
{
    ioToggle(port, pin, delay);
}

void ledDim(uint8_t port, uint8_t pin, uint8_t intensity)
{
    // Needs PWM implementation
}