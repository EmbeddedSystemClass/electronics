/*
 *  Dispay water tank level
 */

#include <xc.h>
#include "header.h"

void init_bargraph(void)
{
    int count = 0;

    TRISACLR  = SER_PIN | RCLK_PIN | SRCLK_PIN;
    LATACLR = SER_PIN | RCLK_PIN | SRCLK_PIN;
    bargraph_write(0);                  //Clear
}

void bargraph_srclk_pulse(void)
{
        LATASET = SRCLK_PIN;
        //__asm("nop");
        LATACLR = SRCLK_PIN;
}

void bargraph_rclk_pulse(void)
{
        LATASET = RCLK_PIN;
        __asm("nop");
        LATACLR = RCLK_PIN;
}

/*Bargraph value calculation*/
//  led    |  1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |...
//  color  |R   G   R   G | R   G   R   G | R   G   R   G | R   G   R   G |...
//  bit    |1   2   4   8 | 1   2   4   8 | 1   2   4   8 | 1   2   4   8 |...
void bargraph_write(uint32_t value)
{
    uint8_t count = bargraph_howmuchpins;

    while (count > 0)
    {
        LATAbits.LATA1 = (value >> count - 1) & 1u;     //push most significative bits first
        bargraph_srclk_pulse();
        count--;
    }
    bargraph_rclk_pulse();
}

