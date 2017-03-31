/*
//
//~~~SOFTWARE~~~
//      Clignotement de la LED
//      La led clignotte au rythme d'un changement d'état par seconde (0.5Hz, 1s on/1s off).
//      Une pression sur le bouton multiplie par deux le rythme de clignotement. Arrivé à 8Hz, une pression sur le bouton remet le rythme à 0.5Hz.
//      La "séquence" sera donc : 0.5Hz, 1Hz, 2Hz, 4Hz, 8hZ, 0.5Hz, 1Hz, ...
//      Vous devez utiliser un timer pour régler la vitesse de clignotement
//
//~~~HARDWARE~~~
//      LED: RF1
//      BUT: RD8

//~~~PIC32MX340F512H Configuration Bit Settings~~~
#include <xc.h>
#include "tp_firmware.h"

// DEVCFG3
// USERID = No Setting

// DEVCFG2
#pragma config FPLLIDIV = DIV_12        // PLL Input Divider (12x Divider)
#pragma config FPLLMUL = MUL_24         // PLL Multiplier (24x Multiplier)
#pragma config FPLLODIV = DIV_256       // System PLL Output Clock Divider (PLL Divide by 256)

// DEVCFG1
#pragma config FNOSC = FRCDIV           // Oscillator Selection Bits (Fast RC Osc w/Div-by-N (FRCDIV))
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = ON            // CLKO Output Signal Active on the OSCO Pin (Enabled)
#pragma config FPBDIV = DIV_8           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (WDT Enabled)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (ICE EMUC2/EMUD2 pins shared with PGC2/PGD2)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

void    init(void)      //setup
{
    //GPIO
    LATDCLR  = 0x0100;  //BUT LOW
    TRISDSET = 0x0100;  //BUT INPUT
    LATFCLR  = 0x0002;  //LED LOW
    TRISFCLR = 0x0002;  //LED OUTPUT
    //TIMER1
    T1CONSET = 0x8000 | 0x0030;  //TIMER1 ENABLE | 1:256 prescale
    PR1 = 0xffff;                //max period
}

//~~CALCUATE delay_time~~
//  PBCLK frequence
//  PBCLK = FRC / FRCDIV / PBDIV
//        = 8.10e6 / 2 / 8
//        = 500KHz
//
//  TMR1 freq   (ON = 1, TGATE = 0, TCKPS = 0b11, TSYNC = 0, TCS = 0)
//  TMR1 = TPBCLK / TCKPS
//       = 500KHz / 256
//       = ~1953Hz
//
//  So for 1 sec delay, we need to wait 1953 timer counts.
#define delay_time 1953
uint8_t speed_mult = 1;
void    delay(void)
{
    TMR1 = 0;
    while (TMR1 < delay_time / speed_mult){}
}

void    main(void)
{
    init();         //setup
    while (TRUE)    //main loop
    {
        while (!(PORTD & 0x0100))
        {
            delay();
            LATFINV = 0x0002;           //switch LED
        }
        while (PORTD & 0x0100)
        {
            delay();
            LATFINV = 0x0002;
        }
        if (speed_mult != 16)
        {
            speed_mult *=2;
        }
        else
        {
            speed_mult = 1;
        }
    }
}
*/