// LED ON RF1
//BUTTON ON RB8

#include <xc.h>

#define HIGH 1
#define LOW 0

void init()
{
    //LED
    LATFbits.LATF1 = LOW;
    TRISFbits.TRISF1 = LOW; // only this bits
    //TRISF = 0x0000; for all register's bits at 0;
}
int main()
{
    //INIT

    init();

    //MAIN LOOP
    while(1)
    {
        if (PORTDbits.RD8 == LOW) // button pressed
        {
            if (LATFbits.LATF1 == LOW) // if LED off
                LATFbits.LATF1 = HIGH; // LED on
            else
                LATFbits.LATF1 = LOW; // LED off
        }
    }
    return (0);
}
