#ifndef BUTTON_H
#define BUTTON_H

#include "../../mcal/io/io.h"

void btnInit(uint8_t port, uint8_t pin);
void btnRead(uint8_t port, uint8_t pin, uint8_t *data);

#endif
