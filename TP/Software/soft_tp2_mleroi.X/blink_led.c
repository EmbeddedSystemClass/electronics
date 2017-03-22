
#include <xc.h>

#define LOW 0
#define HIGH 1

void    init()
{
    LATFbits.LATF1 = LOW;
    TRISFbits.TRISF1 = LOW;
}

int main()
{
    init();

    while (1)
    {
       
    }
    return (0);
}