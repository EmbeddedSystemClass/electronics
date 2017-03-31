/*
 TP4 :
 * DIM de la LED (a.k.a pour-les-vrais-qui-en-ont-dans-le-slip-ou-le-string)

Votre code fait toujours la même chose, mais sur un appui long (>2s) la led passe en mode DIM, en 5s son intensité passe de 0 à 100% puis de 100% à 0% (et ainsi de suite)

Pour cela vous coderez en firmware un PWM sur la GPIO qui contrôle la LED.
 */

#include <sys/attribs.h>
#include "exo4.h"
#include <xc.h>

/*
 * RF1 LED
 * RD8  BUTTON
 */
#define LOW 0
#define HIGH 1


void    init()
{
//GPIO
   TRISF = 0b00;
   TRISDbits.TRISD8 = 1;
 //timer 1
   T1CON = 0;
   T1CONbits.ON = 1;
   T1CONbits.TCKPS = 0b10;
   TMR1 = 0;
   PR1 = 15625;
 //timer 2
   T2CON = 0;
   T2CONbits.ON = 0;
   T2CONbits.TCKPS = 0b111;
   TMR2 = 0;
   PR2 = 0xffff;
//INTERRUPT
   //BUTTON
   IPC1bits.INT1IP = 3;     //priority
   IFS0bits.INT1IF = 0; //set flag = no flag
   INTCONbits.INT1EP = 0; // Set polarity control to Falling edge
   IEC0bits.INT1IE = 1; // enable interupt

   //TIMER 1
  IPC1bits.T1IP = 2;
  IFS0bits.T1IF = 0;
  IEC0bits.T1IE = 1;

    //TIMER 2
  IPC2bits.T2IP = 5;
  IFS0bits.T2IF = 0;
  IEC0bits.T2IE = 1;

   //INTCONSET = _INTCON_MVEC_MASK; //set interrupt controller for multi vector
 //  INTCONbits.MVEC = 1;
 //  __builtin_enable_interrupts(); //set CP0 IE on or global interrupt on
}

u8 dim = 0;
//Interupt Service Routine
void	__ISR(_TIMER_1_VECTOR, IPL2) Timer_1_Interrupt(void)
{
    LATFINV = 0x02; // LED ON/OFF
    IFS0bits.T1IF = LOW;
}

void	__ISR(_TIMER_2_VECTOR, IPL5) Timer_2_Interrupt(void)
{
    TMR2 = 7812;
IFS0bits.T2IF = 0;
}

void    __ISR(_EXTERNAL_1_VECTOR, IPL3) Button_Interrupt(void)
{
    INTCONINV = 0x02;
    if (INTCONbits.INT1EP)
    {
	T2CONbits.ON = 1;
	TMR2 = 0;
    }
    else
    {
	if (TMR2 >= 7812)
	{
	    dim ^= 1;
	    if (dim == 1)
	    {
		T1CONbits.ON = 0;
		T3CONbits.ON = 1;
		T4CONbits.ON = 1;
		TMR3 = 0;
		TMR4 = 0;
	    }
	    else
	    {
		T1CONbits.ON = 1;
		T4CONbits.ON = 0;
		T3CONbits.ON = 0;
	    }
	}
	    else
	{
		if (PR1 > 977)
			PR1 /= 2;
		else
			PR1 = 15625;
		TMR1 = 0;
	}
	T2CONbits.ON = 0;
    }
    IFS0bits.INT1IF = 0; //clear flag
}

//<^-^>

int     main()
{
    init();
    init_2();
    while (1);
    {
         WDTCONSET = 0x0001;     //reset watchdog
   }
    return (0);
}

