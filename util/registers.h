#ifndef REGISTERS_H
#define REGISTERS_H

#include "types.h"

/*******************************************************************************/
/*############################### DIO REGISTERS ###############################*/
/*******************************************************************************/
#define PORTA *((volatile uint8_t *)0x3B)           //PORTA -> 0x3B     8-bit reg
#define DDRA *((volatile uint8_t *)0x3A)            //DDRA  -> 0x3A     8-bit reg
#define PINA *((volatile uint8_t *)0x39)            //PINA  -> 0x39     8-bit reg

#define PORTB *((volatile uint8_t *)0x38)           //PORTB -> 0x38     8-bit reg
#define DDRB *((volatile uint8_t *)0x37)            //DDRB  -> 0x37     8-bit reg
#define PINB *((volatile uint8_t *)0x36)            //PINB  -> 0x36     8-bit reg

#define PORTC *((volatile uint8_t *)0x35)           //PORTC -> 0x35     8-bit reg
#define DDRC *((volatile uint8_t *)0x34)            //DDRC  -> 0x34     8-bit reg
#define PINC *((volatile uint8_t *)0x33)            //PINC  -> 0x33     8-bit reg

#define PORTD *((volatile uint8_t *)0x32)           //PORTD -> 0x32     8-bit reg
#define DDRD *((volatile uint8_t *)0x31)            //DDRD  -> 0x31     8-bit reg
#define PIND *((volatile uint8_t *)0x30)            //PIND  -> 0x30     8-bit reg

/*******************************************************************************/
/*############################## TIMER0 REGISTERS #############################*/
/*******************************************************************************/
#define TCCR0 *((volatile uint8_t *)0x53)           //Timer counter control reg     -> 0x53     8-bit reg
#define TCNT0 *((volatile uint8_t *)0x52)           //Timer Counter                 -> 0x52     8-bit reg
#define TIFR *((volatile uint8_t *)0x58)            //Timer interrupt flag reg      -> 0x58     8-bit reg

/*******************************************************************************/
/*########################## EXT INTERRUPTS REGISTERS #########################*/
/*******************************************************************************/
#define MCUCR *((volatile uint8_t *)0x55)           //MCU control reg               -> 0x55     8-bit reg
#define MCUCSR *((volatile uint8_t *)0x54)          //MCU control & status reg      -> 0x54     8-bit reg
#define GICR *((volatile uint8_t *)0x5B)            //General interrupt control reg -> 0x5B     8-bit reg
#define GIFR *((volatile uint8_t *)0x5A)            //General interrupt flag reg    -> 0x5A     8-bit reg

#endif