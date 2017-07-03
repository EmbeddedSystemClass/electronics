/*
 *  Display water tank level
 */

#include "header.h"

void init_bargraph(void)
{
    int count = 0;

    TRISACLR  = SER_PIN | RCLK_PIN | SRCLK_PIN;
    LATACLR = SER_PIN | RCLK_PIN | SRCLK_PIN;
    bargraph_write(0);                  //Clear
}

void bargraph_srclk_pulse(void)         //SHIFT
{
        SRCLK_PIN = 1;
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        SRCLK_PIN = 0;
}

void bargraph_rclk_pulse(void)          //OUTPUT
{
        RCLK_PIN = 1;
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        __asm("nop");
        RCLK_PIN = 0;
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
        SER_PIN = (value >> count - 1) & 1u;     //push most significative bits first
        bargraph_srclk_pulse();
        count--;
    }
    bargraph_rclk_pulse();
}

