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

void    init_led(void)
{
/*GPIO*/
    TRISBCLR = LED_BITS;      //Output
    LATBSET  = LED_BITS;      //Low
//  ODCBCLR  = LED_BITS;      //Open drain
}