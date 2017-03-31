/*
//
//~~~SOFTWARE~~~
//      Commande de la LED par le bouton (a.k.a Hello World!)
//      Une pression sur le bouton allume la led
//      Une autre pression sur le bouton éteint la led
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

void    init(void)      //GPIO setup
{
    LATDCLR  = 0x0100;  //BUT LOW
    TRISDSET = 0x0100;  //BUT INPUT
    LATFCLR  = 0x0002;  //LED LOW
    TRISFCLR = 0x0002;  //LED OUTPUT
}

void    main(void)
{
    init();         //setup
    while (TRUE)    //main loop
    {
        //BUT has pullup
        while (!(PORTD & 0x0100)){} //while BUT pressed
        while (PORTD & 0x0100){}    //while BUT released
        LATFINV = 0x0002;           //switch LED
    }
}
*/