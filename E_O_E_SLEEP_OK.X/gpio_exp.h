#ifndef GPIO_EXP_H
#define  GPIO_EXP_H

/*GPIO_exp*/
#define REG_IODIRA      0x00
#define REG_IPOLA       0x02
#define REG_GPINTENA	0x04
#define REG_DEFVALA     0x06
#define REG_INTCONA     0x08
#define REG_IOCONA      0x0a
#define REG_GPPUA       0x0c
#define REG_INTFA       0x0e
#define REG_INTCAPA     0x10
#define REG_GPIOA       0x12
#define REG_OLATA       0x14

#define REG_IODIRB      0x01
#define REG_IPOLB       0x03
#define REG_GPINTENB    0x05
#define REG_DEFVALB     0x07
#define REG_INTCONB     0x09
#define REG_IOCONB      0x0b
#define REG_GPPUB       0x0d
#define REG_INTFB       0x0f
#define REG_INTCAPB     0x11
#define REG_GPIOB       0x13
#define REG_OLATB       0x15

uint8_t	gpio_exp_write_byte(uint8_t data_byte);		//send a single byte to the slave
uint8_t	gpio_exp_read_byte(void);                   //return the recieved byte
void	gpio_exp_write_byte_to_reg(uint8_t register_addr, uint8_t data);
uint8_t	gpio_exp_read_byte_from_reg(uint8_t reg_addr);
void    init_gpio_exp(void);
void    gpio_exp_is_iddle(void);
void    gpio_exp_start();

#endif