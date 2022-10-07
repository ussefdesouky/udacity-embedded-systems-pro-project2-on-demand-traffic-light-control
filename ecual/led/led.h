/*******************************************************************************/
/*################################## SKELETON #################################*/
/*******************************************************************************/
// 1. Include needed libraries.
// 2. Define the functions prototypes

#ifndef LED_H
#define LED_H

#include "../../mcal/io/io.h"

// Initialize led pin as output
void ledInit(uint8_t port, uint8_t pin);

// Set led pin data to HIGH
void ledOn(uint8_t port, uint8_t pin);

// Set led pin data to LOW
void ledOff(uint8_t port, uint8_t pin);

// Toggle led pin data
void ledToggle(uint8_t port, uint8_t pin, uint16_t delay);

// Set led pin intensity
void ledDim(uint8_t port, uint8_t pin, uint8_t intensity);

#endif