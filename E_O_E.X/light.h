#ifndef LIGHT_H
#define LIGHT_H

#define LIGHT_PIN 0
#define THRESHOLD 100

void    	check_light();
uint8_t		uchar_to_hex(uint8_t val);
void      init_auto_adc(void);
void      init_manual_adc(void);
uint32_t	get_light_manual(void)

#endif
