#ifndef REGISTERS_H
#define REGISTERS_H

#include "types.h"

/*******************************************************************************/
/*############################### DIO REGISTERS ###############################*/
/*******************************************************************************/
#define PORTA *((volatile uint8_t *)0x3B)           //PORTA -> 0x3B     8-bit reg
#define DDRA *((volatile uint8_t *)0x3A)            //DDRA  -> 0x3A     8-bit reg
#define PINA *((volatile uiint8_t *)0x39)           //PINA  -> 0x39     8-bit reg

#define PORTB *((volatile uint8_t *)0x38)           //PORTA -> 0x38     8-bit reg
#define DDRB *((volatile uint8_t *)0x37)            //DDRA  -> 0x37     8-bit reg
#define PINB *((volatile uiint8_t *)0x36)           //PINA  -> 0x36     8-bit reg

#define PORTC *((volatile uint8_t *)0x35)           //PORTA -> 0x35     8-bit reg
#define DDRC *((volatile uint8_t *)0x34)            //DDRA  -> 0x34     8-bit reg
#define PINC *((volatile uiint8_t *)0x33)           //PINA  -> 0x33     8-bit reg

#define PORTD *((volatile uint8_t *)0x32)           //PORTA -> 0x32     8-bit reg
#define DDRD *((volatile uint8_t *)0x31)            //DDRA  -> 0x31     8-bit reg
#define PIND *((volatile uiint8_t *)0x30)           //PINA  -> 0x30     8-bit reg

#endif