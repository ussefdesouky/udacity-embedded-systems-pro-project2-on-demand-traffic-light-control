/*******************************************************************************/
/*################################## SKELETON #################################*/
/*******************************************************************************/
// 1. Include needed libraries.
// 2. Define functions prototypes.

#ifndef BUTTON_H
#define BUTTON_H

#include "../../mcal/io/io.h"

// Initialize button pin as input
void btnInit(uint8_t port, uint8_t pin);

// Read io data
void btnRead(uint8_t port, uint8_t pin, uint8_t *data);

#endif
