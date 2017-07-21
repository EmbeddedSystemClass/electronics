#include "header.h"

//	Delay of (uint) micro seconds
//	Designed for low precision delays


void	init_delay(void)
{
    	/*TIMER4 (micro sec measurement)*/
	T4CONbits.ON    = 0x00;		//Disable
	T4CONbits.TCKPS = 0x00;		//1:1
	PR4 = 10;			//1us			

	/*TIMER4*/
	IPC4bits.T4IP = 7;	//prio = 3		(dont care if interrupted, low prec time measurement)
	IPC4bits.T4IS = 0;	//sub-prio = 0
	IFS0bits.T4IF = 0;	//flag down
	IEC0bits.T4IE = 1;	//enable on

}

uint32_t g_time_count = 0;
//T4 ? Timer4 19 16 IFS0<19> IEC0<19> IPC4<4:2> IPC4<1:0> No
void	__attribute__ ((interrupt(IPL7AUTO), vector(16)))	delay_interrupt(void)
{
    IFS0bits.T4IF = 0;	//CLR flag
    TMR4 = 0;		//RST timer
    g_time_count++;	//Count +1 micro second
}

void	delay_micro(uint32_t time_ms)
{
	g_time_count = 0;	//init counter
	TMR4 = 0;		//init timer
	T4CONbits.ON = 1;	//EN timer
	while(g_time_count < time_ms);	//Wait (uint32 micro sec)
	T4CONbits.ON = 0;
}
