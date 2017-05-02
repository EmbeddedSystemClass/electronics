
#include <xc.h>
#include "header.h"

void	init_I2C(void)
{
/*GPIO*/
//	TRISBSET = SCL_PIN | SDA_PIN;
/*Timer5*/
	//Used in slave ack timeout
	PR5 = 0xffff;		//No timer5 interrupt 
	T5CON =0x0070;		//ON = 0, TCKPS @ 1:256
/*I2C*/
	I2C1CON = 0;		//CLR conf reg
	I2C1STAT = 0;		//CLR stat reg
	I2C1BRG = 0x62;		//Baud rate generator @ 100kHz
	I2C1CONbits.SCLREL = 1;	//Release clock
	I2C1CONbits.DISSLW = 1;	//DIsable slew mode (slew mode is used at 400KHz)
	I2C1CONbits.ON = 1;	//Enable I2C

}

void    gpio_exp_is_iddle(void)	//Wait while I2C bus is busy
{
	while((I2C1CON & 0x001f) || (I2C1STAT & 0x4000));
}

void    gpio_exp_start(void)	//Start sequence
{
	I2C1CONbits.SEN = 1;
	gpio_exp_is_iddle();
}

void    gpio_exp_restart(void)	//Restart sequence	(useless, restart sequence is a start without a stop before)
{
	I2C1CONbits.RSEN = 1;
	gpio_exp_is_iddle();
}

void    gpio_exp_stop(void)	//Stop sequence
{
	I2C1CONbits.PEN = 1;
	gpio_exp_is_iddle();
}

void    gpio_exp_ack_master(uint8_t ack_data_bit)	//Send an (N)ACK to the slave
{
	I2C1CONbits.ACKDT = ack_data_bit;	//1 = NACK; 0 = ACK
	I2C1CONbits.ACKEN = 1;			//start ack sequence
	gpio_exp_is_iddle();
}

#define ACK_TIME_OUT 195		//calc value
uint8_t    gpio_exp_ack_slave(void)			//Wait slave ACK. may timeout then return NACK
{
	TMR5 = 0;
	T5CONbits.ON = 1;
	while(I2C1STATbits.ACKSTAT)	//wait for slave ack
	{
	    if (TMR5 == ACK_TIME_OUT)	//check timeout
	    {
		T5CONbits.ON = 0;
		return(1);		//return error
	    }
	}
	T5CONbits.ON = 0;
	gpio_exp_is_iddle();
	return(0);			//return ok
}

uint8_t	gpio_exp_write_byte(uint8_t data_byte)		//send a single byte to the slave
{
	I2C1TRN = data_byte;
	gpio_exp_is_iddle();
	return(gpio_exp_ack_slave());
}

// !! add timeout? //
uint8_t	gpio_exp_read_byte(void)			//return the recieved byte
{
	I2C1CONbits.RCEN = 1;
	while(I2C1CONbits.RCEN);
	gpio_exp_is_iddle();
	return(I2C1RCV);
}
