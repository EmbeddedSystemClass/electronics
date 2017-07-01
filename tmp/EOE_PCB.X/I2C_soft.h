#ifndef I2C_H
#define I2C_H

#define SCL_PIN  0x0200		//RB8
#define SDA_PIN  0x0100		//RB9
#define SCL_LAT  LATBbits.LATB8		//RB8
#define SDA_LAT  LATBbits.LATB9		//RB9

void    init_I2C_soft(void);
void    gpio_exp_start_soft(void);
void    gpio_exp_stop_soft(void);

uint8_t	gpio_exp_write_byte_soft(uint8_t data_byte);
uint8_t	gpio_exp_read_byte_soft(void);
void    gpio_exp_is_iddle_soft(void);

#endif