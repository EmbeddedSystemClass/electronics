/*
 * PWM
 */

#include <sys/attribs.h>
#include "exo4.h"
#include <xc.h>

void	init_2()
{
   //GPIO
   TRISF = 0b00;	//RF1 OUTPUT
   PORTFCLR = 0x02;	//LED OFF

   //timer 3 PWM
   T3CON = 0;
   T3CONbits.ON = 0;		//ENABLE TIMER3
   T3CONbits.TCKPS = 0b110;   //Postscaler 1:64 (15625Hz)
   TMR3 = 0;
   PR3 = 156;		// = 1 cycle

   //timer 4 5sec
   T4CON = 0;
   T4CONbits.ON = 0;
   T4CONbits.TCKPS = 0b111;	 //Postscaler 1:256 (3906Hz)
   TMR4 = 0;
   PR4 = 19531;

   /* INTERRUPT */

   // INTERRUPT - TIMER 3
   IPC3bits.T3IP = 5;		// Priority 5
   IFS0bits.T3IF = 0;		//flag clr
   IEC0bits.T3IE = 1;		//enable 1

   // INTERRUPT - TIMER 4
   IPC4bits.T4IP = 6;
   IFS0bits.T4IF = 0;
   IEC0bits.T4IE = 1;

  INTCONSET = 0x1000;	//Enable multi vector 0b0001000000000000;
//  INTCONbits.MVEC = 1;
   __asm ("ei");
}

unsigned long long TMP_PR3 = 0;
int pwm_flag = 0; //0 = duty, 1 = !duty
void	__ISR(_TIMER_3_VECTOR, IPL5AUTO) Timer_3_Interrupt(void) //cycle de modulation de largeur d'impultion
{
    if (pwm_flag)	//switch duty or not
    {
	TMP_PR3 = (156 - (TMR4 * 155) / 19531) + 1;	//PR3 = duty_cycle; //
	PR3 = (u16)TMP_PR3;
    }
    else
    {
	TMP_PR3 = ((TMR4 * 155) / 19531 ) + 1;
	PR3 = (u16)TMP_PR3;
    }
    LATFINV = 0x02; //LED toggle
    pwm_flag ^= 1;
    IFS0bits.T3IF = 0;
    TMR3 = 0;	//reset
}

void	__ISR(_TIMER_4_VECTOR, IPL6AUTO) Timer_4_Interrupt(void) //cycle de gradation lumineux
{
    pwm_flag ^= 1;
    TMR4 = 0;
    TMR3 = 0;	//reset
    IFS0bits.T4IF = 0;
}