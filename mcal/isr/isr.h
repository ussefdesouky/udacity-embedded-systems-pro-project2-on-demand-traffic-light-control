#ifndef ISR_H
#define ISR_H

#include "../../util/registers.h"
#include "../../util/types.h"

/*******************************************************************************/
/*############################ INTERRUPT CONTROL BITS #########################*/
/*******************************************************************************/
#define INT0 6
#define INT1 7
#define INT2 5

/*******************************************************************************/
/*######################## INTERRUPT CONTROL BITS MACROS ######################*/
/*******************************************************************************/
#define INT_0 '0'
#define INT_1 '1'
#define INT_2 '2'

/*******************************************************************************/
/*############################### INTERRUPT MODES #############################*/
/*******************************************************************************/
#define RISING      'R'
#define FALLING     'F'
#define CHANGE      'C'
#define LOW_LEVEL   'L'
#define NOTHING     'N'

/*******************************************************************************/
/*######################## INTERRUPT SENSE CONTROL BITS #######################*/
/*******************************************************************************/
// INT0 sense control
#define ISC00 0
#define ISC01 1

// INT1 sense control
#define ISC10 2
#define ISC11 3

// INT2 sense control
#define ISC2 6

/*******************************************************************************/
/*############################## INTERRUPT VECTORS ############################*/
/*******************************************************************************/
// External interrupt request 0
#define EXT_INT0 __vector_1
// External interrupt request 1
#define EXT_INT1 __vector_2
// External interrupt request 2
#define EXT_INT2 __vector_3

// Set global interrupts, set the I-bit in status  register to 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

// Clear global interrupts, set the I-bit in status  register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

//Rising edge
#define RISING_EDGE_SETUP() MCUCR|= (1<<1) | (1<<0)

//Setup use INT0
#define SETUP_INT0() GICR|=(1<<6)

// ISR definition
#define ISR(INT_VECT) \
    void INT_VECT(void) __attribute__ ((signal,used)); \
    void INT_VECT(void)

// Initialize the desired interrupt pin
void isrInit(uint8_t pin);

// Select the desired control sense mode
void isrMode(uint8_t pin, uint8_t mode);

#endif