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
    LATBSET  = SCL_PIN | SDA_PIN;   //OD OFF, bus = high (1)
//    LATBCLR  = SCL_PIN | SDA_PIN;   //OD off
    ODCBSET  = SCL_PIN | SDA_PIN;   //ODC = 1  enable OPENDRAIN (1)
//    LATBCLR  = SCL_PIN | SDA_PIN;   //OD on, bus = low
    /*Timer5*/
//Used in slave ack timeout
//	PR5 = 0xffff;		//No timer5 interrupt
//	T5CON =0x0070;		//ON = 0, TCKPS @ 1:256
}

void    scl_pulse_high(void)
{
    SCL_LAT = 1;               //open drain on
    delay_micro(5);
}
void    scl_pulse_low(void)
{
    SCL_LAT = 0;               //open drain off
    delay_micro(5);
}

void    sda_pulse_hight(void)
{
    SDA_LAT = 1;
    delay_micro(5);
}

void    sda_pulse_low(void)
{
    SDA_LAT = 0;
    delay_micro(5);
}

void    gpio_exp_start_soft(void)
{
    scl_pulse_low();
    sda_pulse_hight();
    scl_pulse_high();
    sda_pulse_low();
    scl_pulse_low();
//    SDA_LAT = 0;
//   delay_micro(5);
//    SCL_LAT = 0;               //open drain off
//    //__asm("nop");
//    delay_micro(5);

}

void    gpio_exp_stop_soft(void)
{
    scl_pulse_low();
    sda_pulse_low();
    scl_pulse_high();
    sda_pulse_hight();
//    SDA_LAT = 1;
//   delay_micro(5);
//    SCL_LAT = 1;               //open drain on
//   // __asm("nop");
//    delay_micro(5);

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
        scl_pulse_high();
        scl_pulse_low();
        index--;
    }
}

uint8_t	gpio_exp_read_byte_soft(void)			//return the recieved byte
{
    uint8_t data = 0;
    uint8_t masque = 1;

    //Reconfig  SDA
    LATBCLR  = SDA_PIN;      //LOW
    TRISBSET = SDA_PIN;      //INPUT
    ODCBCLR  = SDA_PIN;      //disable OPENDRAIN
    
    int8_t index = 7;
    while (index >= 0)
    {
        scl_pulse_high();
//        if (PORTBbits.RB9)
//            data = (data | masque);
//        masque = masque << 1;
//
        if (PORTBbits.RB9)
            data = data | (1 << index);
        index--;
        scl_pulse_low();
    }
    return(data);
}