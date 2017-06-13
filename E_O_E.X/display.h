#ifndef DISPLAY_H
#define DISPLAY_H

static void	display_write(int charactere, int line, int index);
uint8_t	display_write_dec(int32_t nb, uint8_t line,uint8_t index);
void	display_write_str(char	*str, uint8_t line,uint8_t index);
void	display_update();
void	init_display();



#endif