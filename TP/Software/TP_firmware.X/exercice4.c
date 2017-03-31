
//
//~~~SOFTWARE~~~
//DIM de la LED (a.k.a pour-les-vrais-qui-en-ont-dans-le-slip-ou-le-string)
//Votre code fait toujours la même chose, mais sur un appui long (>2s) la led
//passe en mode DIM, en 5s son intensité passe de 0 à 100% puis de 100% à 0% (et ainsi de suite)
//Pour cela vous coderez en firmware un PWM sur la GPIO qui contrôle la LED.
//
//~~~HARDWARE~~~
//      LED: RF1
//      BUT: RD8


// PIC32MX340F512H Configuration Bit Settings

// 'C' source line config statements

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
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disabled)
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

#define LED_BIT 0x0002
#define BUT_BIT 0x0100

void    init(void)
{
//GPIO
    LATFCLR  = LED_BIT;
    TRISFCLR = LED_BIT;
    TRISDSET = BUT_BIT;
    //  INT1 : External Interrupt 1 7 7 IFS0<7> IEC0<7> IPC1<28:26> IPC1<25:24>
    IPC1SET   = 0x08000000;       //Priority = 2, sub = 0
    IEC0SET   = 0x00000080;
    IFS0CLR   = 0x00000080;
    INTCONCLR = 0x00000002;       //Ext interrupt 1 polarity (falling)

//OSC
    OSCCONCLR = 0x07000000;	//FRC clk div = 1:1

//TIMER2 (16)
    T2CONSET = 0x8000;          //ON
    T2CONbits.TCKPS = 0x04;     //Prescale @ 1:16 (125000Hz)
    PR2 = 62500;                //1s
    TMR2 = 0;
    //  T2 : Timer2 8 8 IFS0<8> IEC0<8> IPC2<4:2> IPC2<1:0>
    IPC2bits.T2IP = 0x01;       //Priority = 1, sub = 0
    IEC0SET = 0x00000100;
    IFS0CLR = 0x00000100;

//TIMER4-5
    T4CONCLR = 0x8000;          //OFF
    T4CONSET = 0x0078;          //32bits, 1:256 (1953Hz)
    PR4  = 0xffffffff;           //2199164s (~1.5Y)
    TMR4 = 0;
    //  T4 : Timer4 16 16 IFS0<16> IEC0<16> IPC4<4:2> IPC4<1:0>
    IPC4bits.T4IP = 0x03;               //Set timer interrupt priority to 3 , subpriority to 0
    IEC0SET = 0x00010000;               //Enable timer1 interrupt flag
    IFS0CLR = 0x00010000;               //Clear  timer1 interrupt flag

//INTERRUPT INIT
    INTCONSET = 0x01000;        //Multi-vector mode
    __asm("ei");
}

uint8_t DIM = 0;
uint8_t freq = 8;

void __attribute__ (( interrupt(IPL1AUTO), vector(8))) Interrupt_Timer2(void)
{
    IFS0CLR = 0x00000100;       //Clear interrupt flag
    if (DIM)
    {
        
        
    }
    else
    {
        LATFINV = LED_BIT;
    }
}

void __attribute__ (( interrupt(IPL2AUTO), vector(7))) Interrupt_Button(void)
{
    IFS0CLR = 0x00000080;       //Clear interrupt flag
    INTCONINV = 0x00000002;     //Reverse external 1 interrupt polarity
    if (INTCONbits.INT1EP)
    {
	TMR4 = 0;		//Timer4 reset
	T4CONSET = 0x8000;	//Timer4 ON
        return;
    }
    else
    {
	if (TMR4 > 3906)	//Timer 4 > 2sec
	{
	    //change mode
	    DIM ^= 1;
            if (DIM)
            {
                PR2 = 10;
            }
            else
            {
                PR2 = 62500;
            }
	}
	else
	{
	    //change blink freq
	    T2CONbits.TCKPS--;  //prescale /= 2;
	}
	T4CONCLR = 0x8000;	//Timer4 OFF
    }
}

void __attribute__ (( interrupt(IPL2AUTO), vector(16))) Interrupt_Timer4_Overflow(void)
{
   IFS0CLR = 0x00010000;
   TMR4 = 0;
}

void    main(void)
{
    init();
    while(TRUE)
    {
        WDTCONCLR = 0x0001;     //CLEAR watchdog
    }
}
