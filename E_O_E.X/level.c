
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
	
#ifndef level_on_interrupt	
	gpio_exp_write_byte_to_reg(REG_IOCONA, 0b00110010);		//0x01 = 0 Unimplemented
									//0x02 = 1 Interruption output polarity set to Active_high
									//0x04 = 0 Interruption output open drain disabled
									//0x08 = 0 Hardware address disabled
									//0x10 = 1 Slew rate disabled
									//0x20 = 1 Address pointer++ disabled
									//0x40 = 0 INTA, INTB disassociated
									//0x80 = 0 Registers(A, B) in the same bank

#else	
	/* EXT0 Interrupt */	//>>>change to CN interrupt (rising edge only)
	//INT0 ? External Interrupt 3 3 IFS0<3> IEC0<3> IPC0<28:26> IPC0<25:24> No
	IPC0bits.INT0IP = 7;		//Priority = 5
	IPC0bits.INT0IS = 1;		//Sub-priority = 1
	INTCONbits.INT0EP = 1;		//Rising edge polarity
	IFS0bits.INT0IF = 0;		//CLR flag
	IEC0bits.INT0IE = 1;		//ENable ext0 interrupt

	/* GPIOA, pins 0 to 5, interrupt on change. */
	gpio_exp_write_byte_to_reg(REG_IOCONA, 0b00110010);		//0x01 = 0 Unimplemented
									//0x02 = 1 Interruption output polarity set to Active_high
									//0x04 = 0 Interruption output open drain disabled
									//0x08 = 0 Hardware address disabled
									//0x10 = 1 Slew rate disabled
									//0x20 = 1 Address pointer++ disabled
									//0x40 = 0 INTA, INTB disassociated
									//0x80 = 0 Registers(A, B) in the same bank

	gpio_exp_write_byte_to_reg(REG_INTCONA, 0x1f);			//IO pin compared against DEFVAL.
	gpio_exp_write_byte_to_reg(REG_DEFVALA, 0x00);			//GPIOs comparison values.
	gpio_exp_read_byte_from_reg(REG_INTCAPA);			//Clear gpio_exp int flag.
	gpio_exp_read_byte_from_reg(REG_GPIOA);				//Clear gpio_exp int flag.
	gpio_exp_write_byte_to_reg(REG_GPINTENA, LEVEL_ALL_PINS);	//ENable interrupt on change on level sensor pins
#endif
}

//add level_int flag & recheck level code
#ifdef level_on_interrupt
//NT0 ? External Interrupt 3 3 IFS0<3> IEC0<3> IPC0<28:26> IPC0<25:24> No
void	__attribute__ ((interrupt(IPL7AUTO), vector(3) )) level_change_interrupt()
{	
	IFS0bits.INT0IF = 0;		//CLR ext int0 flag
	I_can_check_level = 1;		//Check how much is the water level (implicite clear gpio-exp int flag while reading ports).
}
#endif