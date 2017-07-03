#include "header.h"

#define lum_threshold   30          //Sensibility threshold
#define seeker          500//32768       //Occurency for TMR1 Interrupt

extern uint8_t      I_can_check_sensors;             //global monitor sleeping
extern uint8_t      I_can_display;                   //To display or not to display...
extern uint8_t      g_mon_sleep;                     //global monitor sleeping
extern int16_t      lum_sleep;                       //Global keeping luminosity when sleep
extern uint16_t     lum_manual;     //luminosity value
extern uint8_t      SLEEPON;

void        init_tmr1()
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

void        init_tmr2()
{
	/*TIMER 2*/
	T2CONbits.TCKPS = 0x07;		//1:256 postscaler
	PR2 = 39062;		//39062 for 1sec @ PBCLK = 10MHz
	T2CONbits.ON = 1;		//disable timer2

	/*TMR2 INTERUPTS*/
	IPC2bits.T2IP = 3;		//Prio = 5
	IPC2bits.T2IS = 0;		//Sub-prio = 0
	IFS0bits.T2IF = 0;		//Flag down
	IEC0bits.T2IE = 1;		//Enable on
}

void __attribute__ ((interrupt(IPL6AUTO), vector(4)))   tmr1_interrupt(void)
{

}

void __attribute__ ((interrupt(IPL3AUTO), vector(8)))	shut_down_display(void)
{
    static uint8_t  sec;

    IFS0bits.T2IF = 0;
    if (sec == 10)                      //skip second
    {
        T2CONbits.ON = 0;
        lcd_backlight_inv();
        I_can_display = 0;
        g_mon_sleep = 1;
        sec = 0;
    }
    sec++;
    TMR2 = 0;
}