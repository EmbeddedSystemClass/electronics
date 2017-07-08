
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
extern uint8_t level;

void	get_level(void)
{
	GPIO_EXP_PORTA = gpio_exp_read_byte_from_reg(REG_GPIOA);
	if(GPIO_EXP_PORTA & LEVEL_5_PIN)
        {
            level = 5;
            return;
        }	//FULL
	if(GPIO_EXP_PORTA & LEVEL_4_PIN)
        {
            level = 4;
            return;
        }
	if(GPIO_EXP_PORTA & LEVEL_3_PIN)
        {
            level = 3;
            return;
        }
	if(GPIO_EXP_PORTA & LEVEL_2_PIN)
        {
            level = 2;
            return;
        }
	if(GPIO_EXP_PORTA & LEVEL_1_PIN)
        {
            level = 1;
            return;
        }
	level = 0;					//EMPTY
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
