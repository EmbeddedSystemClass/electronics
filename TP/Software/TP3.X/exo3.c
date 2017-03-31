/*
 * Clignotement LED non bloquant
 */

// PIC32MX340F512H Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include <sys/attribs.h>
#include "exo3.h"

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



/*
 *  RF1 LED
 * RD8  BUTTON
 */
#define LOW 0
#define HIGH 1
//#pragma config FSRSSEL = PRIORITY_7     /* Assign the SRS to level 7 priority handlers peut etre*/

u16 HZ = 62500;

void    init()
{
//GPIO
   TRISF = 0b00;
   TRISDbits.TRISD8 = 1;
 //timer
   T1CON = 0;
   T1CONbits.ON = 1;
   T1CONbits.TCKPS = 0b01;
   TMR1 = 0;
//INTERRUPT
   IPC1bits.INT1IP = 3;     //priority
   IFS0bits.INT1IF = LOW; //set flag = no flag
   IEC0bits.INT1IE = HIGH; // enable interupt
   //INTCONSET = _INTCON_MVEC_MASK; //set interrupt controller for multi vector
   INTCONbits.MVEC = 1;
   __builtin_enable_interrupts(); //set CP0 IE on or global interrupt on

}
//Interupt Service Routine
//void __attribute__ (( interrupt(ipl3), vector(7))) InterruptHandler(void)
void    __ISR(_EXTERNAL_1_VECTOR, IPL3) Button_Interrupt(void)
{
   LATFINV = 0x02; // LED on/off
   IFS0bits.INT1IF = LOW; //clear flag
}

int     main()
{
    init();
    while (1);
    {
         WDTCONSET = 0x0001;     //reset watchdog
   }
    return (0);
}

