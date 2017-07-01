#include "header.h"


extern uint8_t     I_can_check_sensors;            //global monitor sleeping
extern uint8_t     g_mon_sleep;            //global monitor sleeping

void init_sleep(void)
{
	/*TIMER 2*/
	T2CONbits.TCKPS = 0x07;		//1:256 postscaler
	PR2 = 39062;		//39062 for 1sec @ PBCLK = 10MHz
	T2CONbits.ON = 0;		//Enable timer2

	/*TMR2 INTERUPTS*/
	IPC2bits.T2IP = 5;		//Prio = 5
	IPC2bits.T2IS = 0;		//Sub-prio = 0
	IFS0bits.T2IF = 0;		//Flag down
	IEC0bits.T2IE = 1;		//Enable on
}

void __attribute__ ((interrupt(IPL5AUTO), vector(8)))	go_to_sleep(void)
{
    static uint8_t  ski;

    IFS0bits.T2IF = 0;
    ski++;
    if (ski == 20)                      //skip second
    {
        I_can_check_sensors = 0;
        g_mon_sleep = 1;
        lcd_backlight_inv();
        T2CONbits.ON = 0;
        ski = 0;
        init_auto_adc();
    }
    TMR2 = 0;
}
