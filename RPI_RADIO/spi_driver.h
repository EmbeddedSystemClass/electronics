#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include <fcntl.h>              //Needed for SPI port
#include <sys/ioctl.h>          //Needed for SPI port
#include <linux/spi/spidev.h>   //Needed for SPI port
#include <unistd.h>             //Needed for SPI port
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <cstring>

/*FUNCTIONS*/
int SpiOpenPort (int spi_device);
int SpiClosePort (int spi_device);
int SpiWriteAndRead (int spi_device, unsigned char *data, int length);

#endif
