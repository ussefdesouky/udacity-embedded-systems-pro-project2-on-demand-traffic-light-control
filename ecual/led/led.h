#ifndef LED_H
#define LED_H

#include "../../mcal/io/io.h"

void ledInit(uint8_t port, uint8_t pin);
void ledOn(uint8_t port, uint8_t pin);
void ledOff(uint8_t port, uint8_t pin);
void ledToggle(uint8_t port, uint8_t pin, uint16_t delay);
void ledDim(uint8_t port, uint8_t pin, uint8_t intensity);

#endif