/*******************************************************************************/
/*################################## SKELETON #################################*/
/*******************************************************************************/
// 1. Include needed libraries.
// 2. Define functions.

#include "isr.h"

void isrInit(uint8_t pin)
{
    sei();
    switch (pin)
    {
        case INT_0:
            GICR |= (1 << INT0);
            // Set PIN2 in PORTD as INPUT
            *((volatile uint8_t *)0x31) &= ~(1 << 2);   //DDRD
            // For debugging
            *((volatile uint8_t *)0x35) |= (1 << 7);    //PORTC
            *((volatile uint8_t *)0x34) |= (1 << 7);    //DDRC
            break;
        
        case INT_1:
            GICR |= (1 << INT1);
            // Set PIN3 in PORTD as INPUT
            *((volatile uint8_t *)0x31) &= ~(1 << 3);   //DDRD
            break;

        case INT_2:
            GICR |= (1 << INT2);
            // Set PIN2 in PORTB as INPUT
            *((volatile uint8_t *)0x37) &= ~(1 << 2);   //DDRB
            break;
    
        default:
            // Error handling
            *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
            *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            break;
    }
}

void isrMode(uint8_t pin, uint8_t mode)
{
    switch (pin)
    {
        case INT_0:
            if(mode == RISING)
            {
                MCUCR |= (1 << ISC00) | (1 << ISC01);
                // For debugging
                *((volatile uint8_t *)0x35) |= (1 << 3);            //PORTC
                *((volatile uint8_t *)0x34) |= (1 << 3);            //DDRC
            }
            else if(mode == FALLING)
            {
                MCUCR &= ~(1 << ISC00);
                MCUCR |= (1 << ISC01);
            }
            else if(mode == CHANGE)
            {
                MCUCR |= (1 << ISC00);
                MCUCR &= ~(1 << ISC01);
            }
            else if(mode == LOW_LEVEL)
            {   
                MCUCR &= ~(1 << ISC00) & ~(1 << ISC01);
            }
            else{
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;
        
        case INT_1:
            if(mode == RISING)
            {
                MCUCR |= (1 << ISC10) | (1 << ISC11);
            }
            else if(mode == FALLING)
            {
                MCUCR &= ~(1 << ISC10);
                MCUCR |= (1 << ISC11);
            }
            else if(mode == CHANGE)
            {
                MCUCR |= (1 << ISC10); 
                MCUCR &= ~(1 << ISC11);
            }
            else if(mode == LOW_LEVEL)
            {
                MCUCR &= ~(1 << ISC00) & ~(1 << ISC01);
            }
            else{
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;

        case INT_2:
            if(mode == RISING)
            {
                MCUCR |= (1 << ISC2);
            }
            else if(mode == FALLING)
            {
                MCUCR &= ~(1 << ISC2);
            }
            else
            {
                MCUCR &= ~(1 << ISC2);
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;
    
        default:
            *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
            *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            break;
    }
}
