#ifndef DIO_H
#define DIO_H
 
/*******************************************************************************/
/*############################## IO PORTS MACROS ##############################*/
/*******************************************************************************/
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'


/*******************************************************************************/
/*############################ IO DIRECTION MACROS ############################*/
/*******************************************************************************/
#define INPUT 0
#define OUTPUT 1

/*******************************************************************************/
/*############################ IO WRITE DATA MACROS ###########################*/
/*******************************************************************************/
#define LOW 0
#define HIGH 1

/*******************************************************************************/
/*################################## TYPEDEFS #################################*/
/*******************************************************************************/
typedef unsigned char uint8_t;

/*******************************************************************************/
/*############################## FUNC() PROTOTYPES ############################*/
/*******************************************************************************/
void ioInit(uint8_t port, uint8_t pin, uint8_t dir);
void ioWrite(uint8_t port, uint8_t pin, uint8_t data);
void ioToggle(uint8_t port, uint8_t pin);
uint8_t ioRead(uint8_t port, uint8_t pin, uint8_t *data);


#endif