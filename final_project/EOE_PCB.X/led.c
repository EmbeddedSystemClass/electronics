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

void    led_alert(uint16_t color_bits)
{
    led_color = color_bits & LED_BITS;	//security mask
    //alert = color_bits == 0 ? 0 : 1;
    if (color_bits == 0)
    {
        LATBCLR = LED_BITS;
        alert = 0;
//        T1CONbits.ON = OFF;		//stop led timer if no color
    }
    else
    {
        alert = 1;
//        T1CONbits.ON = ON;
    }
}

void    init_led(void)
{
/*GPIO*/
    TRISBCLR = LED_BITS;      //Output
    LATBCLR  = LED_BITS;      //Low
}

//T3 ? Timer3 14 12 IFS0<14> IEC0<14> IPC3<4:2> IPC3<1:0> No
//void __attribute__ ((interrupt(IPL6AUTO), vector(12))) led_alert_interrupt(void)
//{
//	TMR3 = 0;
//	LATBCLR = LED_BITS;		//clear color
//	if(PR3 == LED_OFF)		//if led is off
//	{
//		LATBSET  = led_color;	//set as param color
//		PR3 = LED_ON;
//	}
//	else
//	{
//		PR3 = LED_OFF;
//	}
//	IFS0bits.T3IF = 0;
//}
