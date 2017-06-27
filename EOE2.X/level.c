
#include "header.h"

/*	
 *	Usage:	get_level();
 * 	
 *	Aim: get witchs water level probes are sub_water
 *
 * 	Arguments: None 
 *
 * 	Return:	top under water probe number
 */

uint8_t GPIO_EXP_PORTA = 0;
uint8_t test_defval = 0;

uint8_t	get_level(void)
{
	GPIO_EXP_PORTA = gpio_exp_read_byte_from_reg(REG_GPIOA);
	gpio_exp_write_byte_to_reg(REG_DEFVALA, GPIO_EXP_PORTA);
	test_defval = gpio_exp_read_byte_from_reg(REG_DEFVALA);
	delay_micro(10000);
	gpio_exp_read_byte_from_reg(REG_GPIOA);
		
	if(GPIO_EXP_PORTA & LEVEL_5_PIN){return(5);}	//FULL
	if(GPIO_EXP_PORTA & LEVEL_4_PIN){return(4);}
	if(GPIO_EXP_PORTA & LEVEL_3_PIN){return(3);}
	if(GPIO_EXP_PORTA & LEVEL_2_PIN){return(2);}
	if(GPIO_EXP_PORTA & LEVEL_1_PIN){return(1);}
	return(0);					//EMPTY
}

void    init_level()
{
	/*INTA PIN on PIC32*/
	LATBCLR  = 0x0080;
	TRISBSET = 0x0080;

	gpio_exp_write_byte_to_reg(REG_IODIRA, 0x1f);	//set port A pins 0 to 4 as INPUT
	
	gpio_exp_write_byte_to_reg(REG_IOCONA, 0b00110010);		//0x01 = 0 Unimplemented
									//0x02 = 1 Interruption output polarity set to Active_high
									//0x04 = 0 Interruption output open drain disabled
									//0x08 = 0 Hardware address disabled
									//0x10 = 1 Slew rate disabled
									//0x20 = 1 Address pointer++ disabled
									//0x40 = 0 INTA, INTB disassociated
									//0x80 = 0 Registers(A, B) in the same bank
}

/*
 * Check how much level probes are under water.
 * and show it on the lcd and bargraph.
 */
extern uint8_t level;
uint8_t prev_lvl = 0xff;
void check_level(void)
{
	if ((level = get_level()) == prev_lvl){return;}
	prev_lvl = level;

	switch (level)
	{
		case 0:
			bargraph_write(0x00000);
			lcd_frimousse_0();
			break;
		case 1:
			bargraph_write(0x00005);
			lcd_frimousse_1();
			break;
		case 2:
			bargraph_write(0x000ff);
			lcd_frimousse_2();
			break;
		case 3:
			bargraph_write(0x00aaa);
			lcd_frimousse_3();
			break;
		case 4:
			bargraph_write(0x0aaaa);
			lcd_frimousse_4();
			break;
		case 5:
			bargraph_write(0xaaaaa);
			lcd_frimousse_5();
	}
}