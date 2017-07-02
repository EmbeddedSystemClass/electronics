/*RTCC ATTEMPT*/

// DEVCFG3
// USERID = No Setting
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier)
#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider (PLL Divide by 2)

// DEVCFG1
#pragma config FNOSC = FRCPLL           // Oscillator Selection Bits (Fast RC Osc w/Div-by-N (FRCDIV))
#pragma config FSOSCEN = ON            // Secondary Oscillator Enable (Enabled)
#pragma config IESO = OFF                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_4           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window Size is 25%)

// DEVCFG0
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Port Enabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include "header.h"
#include <sys/attribs.h>
#include <xc.h>

void init_gpio(void)
{
    /*GPIO*/
    //Set all GPIOs to DIGITAL OUTPUT LOW by default. (Safer for unused pins)
    LATA  = 0;             //low
    TRISA = 0;             //output
    ANSELA = 0;            //digital
    LATB  = 0;
    TRISB = 0;
    ANSELB = 0;
}

void init_watchdog(void)
{
	WDTCONSET = 0x8000;		//Enable
}

void        system_unlock(void)
{
    SYSKEY = 0x0;
    SYSKEY = 0xaa996655;
    SYSKEY = 0x556699aa;
}

void        system_lock(void)
{
    SYSKEY = 0x0;
}

void        init_rtcc(void)
{
    //SET RTCC
    system_unlock();
    RTCCONbits.RTCWREN = 1;         // WRTENable
    //Enable Secondary Oscillator
    OSCCONbits.SOSCEN = 1;          // Secondary Oscillator
    while (!(OSCCONbits.SOSCRDY));  // Warm up
    IEC0bits.RTCCIE = 0;            // Clear RTCC Interrupt
    RTCCONbits.ON = 0;              // turn off the RTCC
    RTCCONbits.CAL = 0x1ff;
    while(RTCCONbits.RTCCLKON);     // wait for clock to be turned off
    //Interrupt controller
    IFS0bits.RTCCIF = 0;            // clear RTCC existing event
    IPC6bits.RTCCIP = 3;            // clear the priority
    IPC6bits.RTCCIS = 1;            // Set IPL=3, subpriority 1
    IEC0bits.RTCCIE = 1;            // Enable RTCC interrupts
    //Set time and data
    RTCTIME = 0x0;                  // safe to update time to 0 hr, 0 min, 0 sec
    RTCDATE = 0x0;                  // update the date
    //Set Alarm
    RTCALRMCLR = 0xCFFF;            // clear ALRMEN, CHIME, AMASK and ARPT;
    ALRMTIME = 0x1000;              // set alarm time to 0 hr, 0 min, 10 sec
    ALRMDATE = 0x0;                 // set alarm date to Friday 27 Oct 2006
    RTCALRMbits.CHIME = 1;          // Rollover
    RTCALRMbits.AMASK = 0b10;        // Every 1sec
    //Enable All
    RTCALRMbits.ALRMEN = 1;         // Enable Alrm
    RTCCONbits.ON = 1;              // turn on the RTCC
    while(!(RTCCONbits.RTCCLKON));
    system_lock();
}

void        init_sleep()
{
    system_unlock();
    OSCCONbits.SLPEN = 1;           //Enable Sleep mode
    CFGCONbits.PMDLOCK = 0;       //Unlock PMD
    PMD1bits.AD1MD = 1;
    PMD1bits.CTMUMD = 1;
    PMD1bits.CVRMD = 1;
    PMD2bits.CMP1MD = 1;
    PMD2bits.CMP2MD = 1;
    PMD2bits.CMP3MD = 1;
    PMD3bits.IC1MD = 1;
    PMD3bits.IC2MD = 1;
    PMD3bits.IC3MD = 1;
    PMD3bits.IC4MD = 1;
    PMD3bits.IC5MD = 1;
    PMD3bits.OC1MD = 1;
    PMD3bits.OC2MD = 1;
    PMD3bits.OC3MD = 1;
    PMD3bits.OC4MD = 1;
    PMD3bits.OC5MD = 1;
    PMD4bits.T1MD = 0;
    PMD4bits.T2MD = 1;
    PMD4bits.T3MD = 1;
    PMD4bits.T4MD = 1;
    PMD4bits.T5MD = 1;
    PMD5bits.I2C1MD = 1;
    PMD5bits.I2C2MD = 1;
    PMD5bits.SPI1MD = 1;
    PMD5bits.SPI2MD = 1;
    PMD5bits.U1MD = 1;
    PMD5bits.U2MD = 1;
    PMD6bits.PMPMD = 1;
    PMD6bits.REFOMD = 1;
    RTCCONbits.ON = 0;
    PMD6bits.RTCCMD = 0;          //Enable Rtcc when sleep
    CFGCONbits.PMDLOCK = 1;       //Lock PMD
    system_lock();
}

void    init_sosco()
{
    //SET GPIO
    LATBbits.LATB4 = 1;             //hight
    TRISAbits.TRISA4 = 1;           //Input
    system_unlock();
    OSCCONbits.SOSCEN = 1;
    while (!(OSCCONbits.SOSCRDY));
    system_lock();
}

void    init_tmr1()
{    
    /*TIMER1*/
    T1CON = 0;
    T1CONbits.TCS = 1;      // External clock from TxCKI pin
    T1CONbits.TCKPS = 0x0;  //1:8
    T1CONbits.TSYNC = 0;
    PR1 = 0xffff;           //
    TMR1 = 0;
    /*INTERRUPT*/
    //T3 ? Timer3 14 12 IFS0<14> IEC0<14> IPC3<4:2> IPC3<1:0> No
    IFS0bits.T1IF = 0;
    IPC1bits.T1IP = 6;      //Priority = 2
    IPC1bits.IC1IS = 0;     //Subpriority = 0
    IEC0bits.T1IE = 1;        
    T1CONbits.ON = 1;
}

void __attribute__ ((interrupt(IPL6AUTO), vector(4))) led_alert_interrupt(void)
{
	IFS0bits.T1IF = 0;
    LATBINV = LED_BITS;
}

void        go_to_sleep()
{
    system_unlock();
    __asm volatile("wait");
    system_lock();
}

void        __ISR(_RTCC_VECTOR, IPL3AUTO)  RTCC_interrupt()
{
    IFS0bits.RTCCIF = 0;
    LATBINV = LED_BITS;
}

void        enable_interrupt()
{
    system_unlock();
    INTCONbits.MVEC = 1;            // Multivector
    __asm("ei");
    system_lock();
}

void        disable_interrupt()
{
    system_unlock();
    __asm("di");
    system_lock();
}

int         main(void)
{
    init_gpio();
    disable_interrupt();
    init_sosco();
    init_sleep();
    init_led();
    init_tmr1();
    enable_interrupt();
    //init_rtcc();
    init_watchdog();

    while (1)
    {
        go_to_sleep();
        WDTCONbits.WDTCLR = 1;          //Clear Watchdog;
    }
    return (0);
}