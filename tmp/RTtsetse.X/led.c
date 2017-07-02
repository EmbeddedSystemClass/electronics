#include "header.h"

/*	
 *	Usage:	led_alert(color);		
 *	Aim: Blink led with color choice
 *	Arguments: colors can be combined.
 *          red   = RED_BIT
 *		   blue  = GRE_PIN
 *		   green = BLU_PIN
 *	No color stop led blinking as well as TMR3.
 */

uint16_t    led_color = 0x0000;
void    led_alert(uint16_t color_bits){
    if (color_bits == 0)
    {
        T1CONbits.ON = OFF;		//stop led timer if no color
    }
    else
    {
        T1CONbits.ON = ON;
    }
    led_color = color_bits &= LED_BITS;	//security mask
}

void    init_led(void)
{
/*GPIO*/
    TRISBCLR = LED_BITS;      //Output
    LATBCLR  = LED_BITS;      //Low
//  ODCBSET  = LED_BITS;      //Open drain (not any more)
}

//T3 ? Timer3 14 12 IFS0<14> IEC0<14> IPC3<4:2> IPC3<1:0> No
