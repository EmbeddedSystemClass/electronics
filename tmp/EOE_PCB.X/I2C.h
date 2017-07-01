#ifndef I2C_H
#define I2C_H

#define INTA_PIN 0x0080		//RB7
#define SCL_PIN  0x0200		//RB8
#define SDA_PIN  0x0100		//RB9

void    init_I2C(void);
uint8_t	gpio_exp_write_byte(uint8_t data_byte);
uint8_t	gpio_exp_read_byte(void);

void    gpio_exp_is_iddle(void);


#endif