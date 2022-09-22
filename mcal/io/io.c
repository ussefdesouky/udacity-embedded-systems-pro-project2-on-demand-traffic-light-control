#include "io.h"

void ioInit(uint8_t port, uint8_t pin, uint8_t dir)
{
    switch (port)
    {
        case PORT_A:
            if(dir == INPUT)
            {
                DDRA &= ~(1 << pin);
            }
            else if(dir == OUTPUT)
            {
                DDRA |= (1 << pin);
            }
            else
            {
                // Errors are handeled using a red led connected to PORTD and set HIGH
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;

        case PORT_B:
            if(dir == INPUT)
            {
                DDRB &= ~(1 << pin);
            }
                
            else if(dir == OUTPUT)
            {
                DDRB |= (1 << pin);
            }
            else
            {
                // Errors are handeled using a red led connected to PORTD and set HIGH
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;
        
        case PORT_C:
            if(dir == INPUT)
            {
                DDRC &= ~(1 << pin);
            }
                
            else if(dir == OUTPUT)
            {
                DDRC |= (1 << pin);
            }
            else
            {
                // Errors are handeled using a red led connected to PORTD and set HIGH
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;
        
        case PORT_D:
            if(dir == INPUT)
            {
                DDRD &= ~(1 << pin);
            }
                
            else if(dir == OUTPUT)
            {
                DDRD |= (1 << pin);
            }
            else
            {
                // Errors are handeled using a red led connected to PORTD and set HIGH
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;
    
        default:
            break;
    }
}

void ioWrite(uint8_t port, uint8_t pin, uint8_t data)
{
    switch (port)
    {
        case PORT_A:
            if(data == LOW)
            {
                PORTA &= ~(1 << pin);
            }
            else if(data == HIGH)
            {
                PORTA |= (1 << pin);
            }
            else
            {
                // Errors are handeled using a red led connected to PORTD and set HIGH
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;

        case PORT_B:
            if(data == LOW)
            {
                PORTB &= ~(1 << pin);
            }
                
            else if(data == HIGH)
            {
                PORTB |= (1 << pin);
            }
            else
            {
                // Errors are handeled using a red led connected to PORTD and set HIGH
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;
        
        case PORT_C:
            if(data == LOW)
            {
                PORTC &= ~(1 << pin);
            }
                
            else if(data == HIGH)
            {
                PORTC |= (1 << pin);
            }
            else
            {
                // Errors are handeled using a red led connected to PORTD and set HIGH
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;
        
        case PORT_D:
            if(data == LOW)
            {
                PORTD &= ~(1 << pin);
            }
                
            else if(data == HIGH)
            {
                PORTD |= (1 << pin);
            }
            else
            {
                // Errors are handeled using a red led connected to PORTD and set HIGH
                *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
                *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            }
            break;
    
        default:
            break;
    }
}

void ioToggle(uint8_t port, uint8_t pin, uint16_t delay)
{
    switch (port)
    {
        case PORT_A:
            PORTA ^= (1 << pin);
            msTimerDelay(delay);
            break;

        case PORT_B:
            PORTB ^= (1 << pin); 
            msTimerDelay(delay);
            break;
        
        case PORT_C:
            PORTC ^= (1 << pin); 
            msTimerDelay(delay);
            break;
        
        case PORT_D:
            PORTD ^= (1 << pin); 
            msTimerDelay(delay);
            break;
    
        default:
            // Errors are handeled using a red led connected to PORTD and set HIGH
            *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
            *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            break;
    }
}


void ioRead(uint8_t port, uint8_t pin, uint8_t *data)
{
    switch (port)
    {
        case PORT_A:
            *data =  (PINA & (1 << pin)) >> pin;
            break;

        case PORT_B:
            *data =  (PINB & (1 << pin)) >> pin;
            break;

        case PORT_C:
            *data =  (PINC & (1 << pin)) >> pin;
            break;
            
        case PORT_D:
            *data =  (PIND & (1 << pin)) >> pin;
            break;
        
        default:
            // Errors are handeled using a red led connected to PORTD and set HIGH
            *((volatile uint8_t *)0x31)  |= (1 << 7);   //DDRD
            *((volatile uint8_t*)0x32) |= (1 << 7);     //PORTD
            break;
    }
}
