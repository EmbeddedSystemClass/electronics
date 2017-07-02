#ifndef LED_H
#define LED_H

/*Alert LED*/
#define RED_BIT  0x0004		//RB2
#define GRE_BIT  0x0008		//RB3
#define BLU_BIT  0x0020		//RB5
#define LED_BITS 0x002c		//all colors bits

#define LED_OFF 1000		//1sec @ 10MHz
#define LED_ON  100     	//1:10 sec

void    init_led(void);

#endif