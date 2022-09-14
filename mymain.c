#include "./mcal/io/io.h"

int main()
{   
    ioInit(PORT_A, 0, OUTPUT);

    while(1)
    {
        ioWrite(PORT_A, 0, HIGH);
    }
     
}