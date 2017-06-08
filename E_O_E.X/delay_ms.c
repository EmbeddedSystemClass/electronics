//
//#include <xc.h>
//#include "header.h"
//
//void	init_delay(void)
//{
//    	/*TIMER4 (chech_sensors)*/
//	T4CONbits.TCKPS = 0x07;		//1:256
//	PR4 = 0x78;			
//	T4CONbits.ON = 0;
//
//
//	/*TIMER4*/
//	IPC4bits.T4IP = 6;    //prio = 5
//	IPC4bits.T4IS = 0;    //sub-prio = 0
//	IFS0bits.T4IF = 0;    //flag down
//	IEC0bits.T4IE = 1;    //enable on
//
//}
//
//uint32_t g_time_count = 0;
////T4 ? Timer4 19 16 IFS0<19> IEC0<19> IPC4<4:2> IPC4<1:0> No
//void	__attribute__ ((interrupt(IPL6AUTO), vector(16)))	delay_interrupt(void)
//{
//    TMR4 = 0;
//    g_time_count++;
//    IFS0bits.T4IF = 0;
//}
//
//void	delay_ms(uint32_t time_ms)
//{
//	g_time_count = 0;
//	TMR4 = 0;
//	T4CONbits.ON = 1;
//	while(g_time_count < time_ms);
//	T4CONbits.ON = 0;
//}
