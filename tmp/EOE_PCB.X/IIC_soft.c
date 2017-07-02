#include "header.h"

/*write on slave*/
//start_sequence function
//send i2c adress of the slave (with R/W bit low)
//send slave internal register adress you want to write
// send data byte
// stop_sequence function
/*read from slave*/
//start_sequence
//send i2c adress of the slave (with R/W bit low)
//send slave internal register adress
//send start_sequence
//send i2c adress of the slave (with R/W bit high
//read data byte
//stop sequence function

//ACK slave function


void	init_I2C_soft(void)
{
    /*GPIO*/
    TRISBCLR = SCL_PIN | SDA_PIN;   //OUTPUT (0)
    LATBSET  = SCL_PIN | SDA_PIN;   //OD OFF, bus = high
//    LATBCLR  = SCL_PIN | SDA_PIN;   //OD off
    ODCBSET  = SCL_PIN | SDA_PIN;   //ODC = 1  hight??
//    LATBCLR  = SCL_PIN | SDA_PIN;   //OD on, bus = low
    /*Timer5*/
//Used in slave ack timeout
//	PR5 = 0xffff;		//No timer5 interrupt
//	T5CON =0x0070;		//ON = 0, TCKPS @ 1:256
}

void    scl_pulse(void)
{
    SCL_LAT = 1;               //open drain on
    __asm("nop");
    SCL_LAT = 0;               //open drain off
}

void    gpio_exp_start_soft(void)
{
    SDA_LAT = 0;
    __asm("nop");
    SCL_LAT = 0;               //open drain on
    __asm("nop");
}

void    gpio_exp_stop_soft(void)
{
    SDA_LAT = 1;
    __asm("nop");
    SCL_LAT = 1;               //open drain on
    __asm("nop");
}

uint8_t	gpio_exp_write_byte_soft(uint8_t data_byte)		//send a single byte to the slave
{
    //Reconfig SDA
    TRISBCLR = SDA_PIN;       //OUTPUT
    LATBCLR  = SDA_PIN;       //LOW
    ODCBSET  = SDA_PIN;       //enable OPENDRAIN
    //Send data
//    data_byte ^= 0xff;      //inv all bits for open drain
    int8_t index = 7;
    while (index >= 0)
    {
        SDA_LAT = (data_byte >> index) & 1u;
        scl_pulse();
        index--;
    }
}

uint8_t	gpio_exp_read_byte_soft(void)			//return the recieved byte
{
    uint8_t data = 0;

    //Reconfig  SDA
    LATBCLR  = SDA_PIN;      //LOW
    TRISBSET = SDA_PIN;      //INPUT
    ODCBCLR  = SDA_PIN;      //disable OPENDRAIN
    
    int8_t index = 7;
    while (index >= 0)
    {
        scl_pulse();
        data = PORTBbits.RB9;
        data <<= 1;
        index--;
    }
    return(data);
}