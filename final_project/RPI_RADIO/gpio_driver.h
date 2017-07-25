#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define D_OUT	0
#define D_IN	1
#define D_LOW	0
#define D_HIGH	1

typedef struct	s_gpio
{
	int	pinNb;
	int	value;
	int	direction;
}		t_gpio;

/***FUNCTIONS***/
t_gpio	*gpio_export(int gpio);
int	gpio_unexport(t_gpio *gpio_FDs);
void	gpio_direction(t_gpio *gpio_FDs, int direction);
void	gpio_write(t_gpio *gpio_FDs, int value);
int	gpio_read(t_gpio *gpio_FDs);
int     gpio_test(int pin);

#endif
