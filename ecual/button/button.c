#include "button.h"

void btnInit(uint8_t port, uint8_t pin)
{
    ioInit(port, pin, INPUT);
}

void btnRead(uint8_t port, uint8_t pin, uint8_t *data)
{
    ioRead(port, pin, data);
}