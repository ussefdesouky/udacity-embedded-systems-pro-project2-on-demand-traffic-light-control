MCU = atmega32
MCU2 = m32
F_CPU = 1000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -std=c99 -Wall -g -Os -mmcu=${MCU} -DF_CPU=${F_CPU} -I.
PORT = /dev/ttyS10
TARGET = io
SRCS = io.c 

all:
		${CC}  ${CFLAGS} -o ${TARGET}.o -c ${SRCS} 
		${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.o ${TARGET}.hex

flash:
		avrdude -p ${MCU} -c avr109 -U flash:w:${TARGET}.hex:i -F -P ${PORT}

clean:
		rm -f *.bin *.hex *.o