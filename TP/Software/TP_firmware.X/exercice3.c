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
#pragma config FSOSCEN = OFF             // Secondary Oscillator Enable (Enabled)
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

#define PR1_one_second 1953

uint8_t  PR_index = 0;                            //Index for below
uint16_t PR1_set[5] = {1953, 977, 448, 244, 122}; //PR1 values at 0.5Hz, 1Hz, 2Hz, 4Hz, 8Hz

void    init(void)                  //SETUP
{
    //GPIO
    LATDCLR  = 0x0100;                  //BUT LOW
    TRISDSET = 0x0100;                  //BUT INPUT
    LATFCLR  = 0x0002;                  //LED LOW
    TRISFCLR = 0x0002;                  //LED OUTPUT

    //TIMER1
    T1CONSET = 0x8000 | 0x0030;         //TIMER1 ENABLE | 1:256 prescale value
    PR1 = PR1_set[0];                   //Interupt & reset period (~= 1sec)
    TMR1 = 0;                           //reset TIMER1

    //INTERUPTS
    __asm ("ei");
    //__builtin_enable_interrupts();      //Enable interupts
    //_CP0_BIS_STATUS(0x0001);
    //_bsc0 (12, 0, 0x0001);
    //
    //uint32_t    tmp;
    //__asm   ("mfc0 %0, $12" : "=r"(tmp));
    //tmp |= 0x0001;
    //__asm    ("mtc0 %0, $12" : "+r"(tmp));
    //

    INTCONSET = 0x1000;                 //Enable multivector

    //TIMER INTERUPT
        //(T1 ? Timer1 Vector4 IFS0<4> IEC0<4> IPC1<4:2> IPC1<1:0>)
    IPC1SET = 0x0000000c | 0x00000000;  //Set timer interrupt priority to 3 , subpriority to 0
    IEC0SET = 0x00000010;               //Enable timer1 interrupt flag
    IFS0CLR = 0x00000010;               //Clear  timer1 interrupt flag

    //BUTTON INTERRUPT
        //(INT1 ? External Interrupt 1 Vector7 IFS0<7> IEC0<7> IPC1<28:26> IPC1<25:24>)
    IPC1SET   = 0x10000000;               //Priority = 4, subPriority = 0
    IEC0SET   = 0x00000080;               //Enable externat interupt 1
    INTCONCLR = 0x00000002;             //Ext. Int. 1: falling edge polarity
    IFS0CLR   = 0x00000080;               //Clear external interupt flag
 }

void __attribute__ (( interrupt(IPL3AUTO), vector(4))) InterruptLED(void)
{
    IFS0CLR = 0x0010;   //Clear timer1 interupt flag
    LATFINV = 0x0002;   //Toggle LED
}

void __attribute__ (( interrupt(IPL4AUTO), vector(7)))  InterruptBUT(void)
{
    IFS0CLR = 0x00000080;                 //Clear external interupt flag
    PR_index++;                           //Increase blink freq
    if (PR_index > 4)
    {
        PR_index = 0;
    }
    PR1 = PR1_set[PR_index];
    TMR1 = 0;
}

void    main(void)
{
    init();                     //Setup
    while (TRUE)                //Main loop
    {
        WDTCONSET = 0x0001;     //Reset watchdog
    }
}
*/