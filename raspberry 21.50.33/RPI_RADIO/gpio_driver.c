/*
 * GPIO driver
 */

#include "gpio_driver.h"


//Export GPIO and open it.
//Return its files descriptors.
t_gpio	*gpio_export(int gpio)
{
	int	export_fd = 0;
	char	gpio_pin[128];
	t_gpio	*gpio_FDs = NULL;

	//check pin number
	if (gpio > 28)
	{
		perror("There are no more than 28 pins.\n");
		return(gpio_FDs);
	}

	//malloc struct
	if((gpio_FDs = (t_gpio *)malloc(sizeof(*gpio_FDs))) == NULL)
	{
		perror("Malloc error.\n");
		return(gpio_FDs);
	}
	(*gpio_FDs).value = 0;

	//export gpio pin
	if ((export_fd = open("/sys/class/gpio/export", O_RDWR)) == -1)	//open export file
	{
		perror("Can't open export.\n");
		return(gpio_FDs);
	}
	sprintf(gpio_pin, "%d", gpio);						//gpio pin number to str
	write(export_fd, gpio_pin, strlen(gpio_pin));				//export gpio pin number
	close(export_fd);							//close export file
	usleep(100000);								// wait exporting

	//open gpio files
	(*gpio_FDs).pinNb = gpio;
	sprintf(gpio_pin, "/sys/class/gpio/gpio%d/value", gpio);		//gpio value path
	(*gpio_FDs).value = open(gpio_pin, O_RDWR);
	sprintf(gpio_pin, "/sys/class/gpio/gpio%d/direction", gpio);		//gpio direction path
	(*gpio_FDs).direction = open(gpio_pin, O_RDWR);
	return(gpio_FDs);
}

//release gpio
int	gpio_unexport(t_gpio *gpio_FDs)
{
	int	unexport_fd = 0;
	char	gpio_pin[128];

	//close gpio files
	if ((close((*gpio_FDs).value)) == -1)					//close gpio value file
	{
		perror("Can't close fd.\n");
		return(-1);
	}
	if ((close((*gpio_FDs).direction)) == -1)				//close gpio direction file
	{
		perror("Can't close fd.\n");
		return(-1);
	}

	//unexport gpio pin
	if ((unexport_fd = open("/sys/class/gpio/unexport", O_WRONLY)) == -1)	//open export file
		return(-1);							//error
	sprintf(gpio_pin, "%d", (*gpio_FDs).pinNb);				//gpio pin number to str
	write(unexport_fd, gpio_pin, strlen(gpio_pin));				//export gpio pin number
	close(unexport_fd);							//close unexport file

	//free(gpio_fd);
	return(0);
}

//set GPIO as input or OUTPUT	
void	gpio_direction(t_gpio *gpio_FDs, int direction)
{
	if (direction == D_OUT)
		write((*gpio_FDs).direction, "out", 3);				//set gpio pin as output
	if (direction == D_IN)
		write((*gpio_FDs).direction, "in", 2);				//set gpio pin as input
}

//write a digital value
void	gpio_write(t_gpio *gpio_FDs, int value)
{
	if (value == D_LOW)
		write((*gpio_FDs).value, "0", 1);				//set gpio pin low
	if (value == D_HIGH)
		write((*gpio_FDs).value, "1", 1);				//set gpio pin high
}

//read a digital value (untested)
int	gpio_read(t_gpio *gpio_FDs)
{
	int	value;
	char	buffer[1];

	read((*gpio_FDs).value, buffer, 1);					//read value from gpio value file
	value = atoi(buffer);
	return(value);
}

/*Set gpio as OUTPUT HIGH for 5 sec, then LOW for 5 sec*/
int     gpio_test(int pin)
{
        t_gpio *gpio;   //struct holding gpio FDs

        printf("**Export gpio**\n");
        gpio = gpio_export(pin);
        if (gpio == NULL || (*gpio).value == -1 || (*gpio).direction == -1) 
        {   
                perror("Failes exporting gpio.\n");
                return(-1);
        }   

        printf("val_FD = %d\ndir_FD = %d\n", (*gpio).value, (*gpio).direction);
        sleep(1);

        printf("Set gpio as output.\n");
        gpio_direction(gpio, D_OUT);
        sleep(1);

        printf("Set gpio high.\n");
        gpio_write(gpio, D_HIGH);
        sleep(5);

        printf("Set gpio low.\n");
        gpio_write(gpio, D_LOW);
        sleep(5);

        printf("**Unexport gpio.**\n");
        if (gpio_unexport(gpio) == -1) 
        {
                perror("Failed unexporting gpio");
                return(-1);
        }
        return(0);
}

