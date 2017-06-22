
#include "header.h"

/*	
 *	Usage:	led_alert(color);		
 *	Aim: Blink led with color choice
 *	Arguments: colors can be combined.
 *                 red   = RED_BIT
 *		   blue  = GRE_PIN
 *		   green = BLU_PIN
 *	No color stop led blinking as well as TMR3.
 */

uint16_t    led_color = 0x0000;
void    led_alert(uint16_t color_bits){
    if (color_bits == 0)
    {
        T3CONbits.ON = OFF;		//stop led timer if no color
    }
    else
    {
        T3CONbits.ON = ON;
    }
    led_color = color_bits &= LED_BITS;	//security mask
}

void    init_led(void)
{
/*GPIO*/
    TRISBCLR = LED_BITS;      //Output
    LATBSET  = LED_BITS;      //Low
    ODCBSET  = LED_BITS;      //Open drain
/*TIMER3*/
    T3CON = 0;
    T3CONbits.TCKPS = 0x7;    //1:256
    PR3 = LED_OFF;            //1sec
    TMR3 = 0;
    T3CONbits.ON = OFF;         //T3 OFF until calling led_alert()
/*INTERRUPT*/
    //T3 ? Timer3 14 12 IFS0<14> IEC0<14> IPC3<4:2> IPC3<1:0> No
    IFS0bits.T3IF = 0;
    IEC0bits.T3IE = 1;        
    IPC3bits.T3IP = 6;        //Priority = 2
    IPC3bits.T3IS = 0;        //Subpriority = 0
}

//T3 ? Timer3 14 12 IFS0<14> IEC0<14> IPC3<4:2> IPC3<1:0> No
void __attribute__ ((interrupt(IPL6AUTO), vector(12))) led_alert_interrupt(void)
{
	TMR3 = 0;
	LATBSET = LED_BITS;		//clear color
	if(PR3 == LED_OFF)		//if led is off
	{
		LATBCLR  = led_color;	//set as param color
		PR3 = LED_ON;
	}
	else
	{
		PR3 = LED_OFF;
	}
	IFS0bits.T3IF = 0;
}
