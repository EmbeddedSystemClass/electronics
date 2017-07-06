
#include "header.h"
/*
 * 
 * VERIFY MASTER ACK!!!
 * 
 */

/*
 *	usage:	gpio_exp_write_byte_to_reg(uint8_t register_addr, uint8_t data)
 *		gpio_exp_read_byte_from_reg(uint8_t reg_addr)
 * 
 *	aim: write or read any MCP23017 register
 *	
 *	arguments:
 *		register_addr(u8): see below registers list
 *		data(u8): the data send to the chip
 * 
 *	return:
 *		data(u8): the data read from the chip
 * 
 *	error sources: dont interrupt data transfer.
 */

void	gpio_exp_write_byte_to_reg(uint8_t register_addr, uint8_t data)
{
	gpio_exp_start();			//start sequence
	if(gpio_exp_write_byte(EN_PIN))
           led_alert(0xe000);		//slave address
	if(gpio_exp_write_byte(register_addr))
            led_alert(0xe000);	//register to write
	if(gpio_exp_write_byte(data))
            led_alert(0xe000);		//data to write
	gpio_exp_stop();			//start sequence	
}

uint8_t	gpio_exp_read_byte_from_reg(uint8_t reg_addr)
{
	uint8_t data = 0;

	gpio_exp_start();			//start sequence
	if(gpio_exp_write_byte(EN_PIN))
            led_alert(0xe000);		//slave address
	gpio_exp_ack_slave();
	if(gpio_exp_write_byte(reg_addr))
            led_alert(0xe000);		//slave address
	gpio_exp_start();			//start sequence
	if(gpio_exp_write_byte(0x41))
            led_alert(0xe000);		//slave address
	gpio_exp_ack_slave();
	data = gpio_exp_read_byte();		//data to write
	//gpio_exp_ack_master(0);
	gpio_exp_stop();			//start sequence	
	return(data);
}

void    init_gpio_exp(void)
{
/*EXP_GPIO*/
	gpio_exp_write_byte_to_reg(REG_OLATA, 0x00);	//SET LATA LOW
	gpio_exp_write_byte_to_reg(REG_OLATB, 0x00);	//SET LATB LOW
}
