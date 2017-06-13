#ifndef LEVEL_H
#define LEVEL_H

/*Level sensor*/
//PORTA
#define LEVEL_1_PIN	0x01
#define LEVEL_2_PIN	0x02
#define LEVEL_3_PIN	0x04
#define LEVEL_4_PIN	0x08
#define LEVEL_5_PIN	0x10
#define LEVEL_ALL_PINS 0x1f

uint8_t	get_level(void);
void    init_level();

#endif