#include <stdio.h>
#include "gpio_driver.h"
#include "spi_driver.h"
#include "nrf24l01_driver.h"

/***GLOBALS***/
t_gpio	*ce_gpio;			//FDs struct
t_gpio	*csn_gpio;			//FDs struct

unsigned char buffer[32] = {0,0,0,0,0,0,0,0,\
			    0,0,0,0,0,0,0,0,\
			    0,0,0,0,0,0,0,0,\
			    0,0,0,0,0,0,0,0};

void	clr_buffer(void)
{
	memset(buffer, '\0', 32);
}

void	radio_init(void)
{
	int spi = 0;				//spi status ret value

	/***	INIT GPIOs	***/
	ce_gpio = gpio_export(CE_PIN);		//export
	csn_gpio = gpio_export(CSN_PIN);	//export
	gpio_direction(ce_gpio, D_OUT);		//CE as OUTPUT
	gpio_direction(csn_gpio, D_OUT);	//CSN as OUTPUT
	gpio_write(ce_gpio, D_LOW);		//active high
	gpio_write(csn_gpio, D_HIGH);		//active low

	/***	INIT SPI	***/
	spi = SpiOpenPort(0);		//spi port 0, slave select 0
	if (spi < 0)
	{
		perror("Spirror\n");
		exit(-1);
	}
}

void	radio_purge(void)
{
	int spi = 0;				//spi status ret value

	/***	UNEXPORT GPIOs	***/
	gpio_unexport(ce_gpio);
	gpio_unexport(csn_gpio);

	/***	SPI CLOSE PORT	***/
	spi = SpiClosePort(0);
	if (spi < 0)
	{
		perror("Spirror\n");
		exit(-1);
	}
}

//read 1 or 5 bytes to buffer
unsigned char	*radio_read_reg(unsigned char reg, unsigned int size)
{
	clr_buffer();				//destruction!!!
	memcpy(buffer, &reg, size);		//put reg in the buffer of doom
	gpio_write(csn_gpio, D_LOW);		//nrf24 is listening out of space
	SpiWriteAndRead(0, buffer, 1);		//send the name of the unnameable register
	SpiWriteAndRead(0, buffer, size);	//send the blind data to Cthulhu
	gpio_write(csn_gpio, D_HIGH);
	return(buffer);				//return data to ashes
}

//write 1 or 5 bytes to reg
void	radio_write_reg(unsigned char reg, unsigned long long data, unsigned int size)
{
	unsigned char	tmp_reg[1];

	reg = W_REGISTER(reg);		//or with write command
	memcpy(tmp_reg, &reg, 1);	//cpy data in buffer
	clr_buffer();
	memcpy(buffer, &data, size);
	gpio_write(csn_gpio, D_LOW);	//slave listening
	SpiWriteAndRead(0, tmp_reg, 1);
	SpiWriteAndRead(0, buffer, size);
	gpio_write(csn_gpio, D_HIGH);	//slave !listening
}

void	radio_ce_pulse()
{
	gpio_write(ce_gpio, 1);
	usleep(10);	//10micro sec
	gpio_write(ce_gpio, 0);
}

void	radio_tx_mode()
{
	radio_write_reg(CONFIG_REG, 0x0c, 1);
}

void	radio_rx_mode()
{
	radio_write_reg(CONFIG_REG, 0x0b, 1);
}

void	radio_send(unsigned char *payload, unsigned int size)
{
	unsigned char	tmp_reg[1];

	*tmp_reg = (unsigned char)W_TX_PAYLOAD;
	//memcpy(tmp_reg, &W_TX_PAYLOAD, 1);	//cpy data in buffer
	radio_tx_mode();
	//ra
	SpiWriteAndRead(0, tmp_reg, 1);		//send write payload command
	SpiWriteAndRead(0, buffer, size);	//write payload in pipe
	radio_ce_pulse();			//send payload
	radio_write_reg(STATUS_REG, 0x70, 1);	//clear status
}

//la flemme, a finir.
unsigned char	*radio_recieve(unsigned int size)
{
	char	status[1] = {0};

	clr_buffer();
	radio_rx_mode();
	gpio_write(ce_gpio, D_HIGH);
	usleep(10);
	do while ((status & 0x40) == 0)
	{
		status = radio_read_reg(STATUS_REG, 1);
	}


	gpio_write(ce_gpio, D_LOW);


	return(buffer);
}

void	print_registers(void)
{
	printf("CONFIG		= 0x%02x\n", *radio_read_reg(CONFIG_REG, 1));
	printf("EN_AA		= 0x%02x\n", *radio_read_reg(EN_AA_REG, 1));
	printf("EN_RXADDR	= 0x%02x\n", *radio_read_reg(EN_RXADDR_REG, 1));
	printf("SETUP_AW	= 0x%02x\n", *radio_read_reg(SETUP_AW_REG, 1));
	printf("SETUP_RETR	= 0x%02x\n", *radio_read_reg(SETUP_RETR_REG, 1));
	printf("RF_CH		= 0x%02x\n", *radio_read_reg(RF_CH_REG, 1));
	printf("RF_SETUP	= 0x%02x\n", *radio_read_reg(RF_SETUP_REG, 1));
	printf("STATUS		= 0x%02x\n", *radio_read_reg(STATUS_REG, 1));
	printf("OBSERVE_TX	= 0x%02x\n", *radio_read_reg(OBSERVE_TX_REG, 1));
	printf("CD		= 0x%02x\n", *radio_read_reg(CD_REG, 1));
	printf("RX_ADDR_P0	= 0x%02x\n", *radio_read_reg(RX_ADDR_P0_REG, 1));
	printf("RX_ADDR_P1	= 0x%02x\n", *radio_read_reg(RX_ADDR_P1_REG, 1));
	printf("RX_ADDR_P2	= 0x%02x\n", *radio_read_reg(RX_ADDR_P2_REG, 1));
	printf("RX_ADDR_P3	= 0x%02x\n", *radio_read_reg(RX_ADDR_P3_REG, 1));
	printf("RX_ADDR_P4	= 0x%02x\n", *radio_read_reg(RX_ADDR_P4_REG, 1));
	printf("RX_ADDR_P5	= 0x%02x\n", *radio_read_reg(RX_ADDR_P5_REG, 1));
	printf("TX_ADDR		= 0x%02x\n", *radio_read_reg(TX_ADDR_REG, 1));
	printf("RX_PW_P0	= 0x%02x\n", *radio_read_reg(RX_PW_P0_REG, 1));
	printf("RX_PW_P1	= 0x%02x\n", *radio_read_reg(RX_PW_P1_REG, 1));
	printf("RX_PW_P2	= 0x%02x\n", *radio_read_reg(RX_PW_P2_REG, 1));
	printf("RX_PW_P3	= 0x%02x\n", *radio_read_reg(RX_PW_P3_REG, 1));
	printf("RX_PW_P4	= 0x%02x\n", *radio_read_reg(RX_PW_P4_REG, 1));
	printf("RX_PW_P5	= 0x%02x\n", *radio_read_reg(RX_PW_P5_REG, 1));
	printf("FIFO_STATUS	= 0x%02x\n", *radio_read_reg(FIFO_STATUS_REG, 1));
	printf("DYNPD		= 0x%02x\n", *radio_read_reg(DYNPD_REG, 1));
	printf("FEATURE		= 0x%02x\n", *radio_read_reg(FEATURE_REG, 1));
}

int main(void)
{

	radio_init();
	print_registers();
	radio_write_reg(EN_AA_REG, 0x3f, 1);
	printf("~~~~~~~~~~~~~~~~~\n");
	print_registers();
	radio_purge();


	/*
	int status = 0;

	unsigned char config[1] = {R_REGISTER(CONFIG_REG)};
	gpio_write(csn_gpio, D_LOW);
	status = SpiWriteAndRead(0, config, 1);		//command
	status = SpiWriteAndRead(0, config, 1);		//command
	gpio_write(csn_gpio, D_HIGH);
	printf("status = %d\n", status);
	printf("reg = 0x%x\n", *config);

	unsigned char en_aa[1] = {R_REGISTER(EN_AA_REG)};
	gpio_write(csn_gpio, D_LOW);
	status = SpiWriteAndRead(0, en_aa, 1);		//command
	status = SpiWriteAndRead(0, en_aa, 1);		//command
	gpio_write(csn_gpio, D_HIGH);
	printf("status = %d\n", status);
	printf("reg = 0x%x\n", *en_aa);

	unsigned char rf_setup[1] = {R_REGISTER(EN_RXADDR_REG)};
	gpio_write(csn_gpio, D_LOW);
	status = SpiWriteAndRead(0, rf_setup, 1);		//command
	status = SpiWriteAndRead(0, rf_setup, 1);		//command
	gpio_write(csn_gpio, D_HIGH);
	printf("status = %d\n", status);
	printf("reg = 0x%x\n", *rf_setup);
	*/

	/*
	printf("CONFIG = %d\n", radio_read_reg(CONFIG_REG));
	printf("EN_AA  = %d\n", radio_read_reg(EN_AA_REG));
	*/

	return(0);
}


unsigned long long fillon(void)
{
	unsigned long long the_million = 0xffffffffffffffff;
	return(the_million);
}
