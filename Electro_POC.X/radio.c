
#include <xc.h>
#include "header.h"
#include "radio.h"

uint8_t	status = 0;	//hold last status register (updated each time sending command)
int8_t rx_buffer[32];	//Buffer holding data to be send or get with a command
int8_t tx_buffer[32];	//Buffer holding data to be send or get with a command

int64_t test = 0;

void	init_radio(uint8_t reg_addr)
{
	radio_write_reg(CONFIG_REG, 0x0f);
	radio_write_reg(EN_AA_REG, 0x3f);
	radio_write_reg(EN_RXADDR_REG, 0x02);
	radio_write_reg(SETUP_AW_REG, 0x03);
	radio_write_reg(SETUP_RETR_REG, 0x5f);
	radio_write_reg(RF_CH_REG, 0x6c);
	radio_write_reg(RF_SETUP_REG, 0x3);
//	radio_write_reg(STATUS_REG, 0x0e);
	radio_write_reg(OBSERVE_TX_REG, 0x00);
	radio_write_reg(CD_REG, 0x00);

	radio_write_reg(RX_ADDR_P0_REG, 0x3232323232);
	radio_write_reg(RX_ADDR_P1_REG, 0x3131313131);
	radio_write_reg(RX_ADDR_P2_REG, 0xc3);
	radio_write_reg(RX_ADDR_P3_REG, 0xc4);
	radio_write_reg(RX_ADDR_P4_REG, 0xc5);
	radio_write_reg(RX_ADDR_P5_REG, 0xc6);
	radio_write_reg(TX_ADDR_REG, 0x3232323232);
	radio_write_reg(RX_PW_P0_REG, 0x20);
	radio_write_reg(RX_PW_P0_REG, 0x20);
	radio_write_reg(RX_PW_P0_REG, 0x00);
	radio_write_reg(RX_PW_P0_REG, 0x00);
	radio_write_reg(RX_PW_P0_REG, 0x00);
	radio_write_reg(RX_PW_P0_REG, 0x00);
	radio_write_reg(FIFO_STATUS_REG, 0x11);

	radio_write_reg(FEATURE_REG, 0x00);		//disable all features
	radio_write_reg(DYNPD_REG, 0x00);			//disable
	
	radio_flush_tx();
	radio_flush_rx();


	
}

////Read data from a 1 byte long register.
//int8_t	radio_read_short_reg(uint8_t reg_addr)
//{
//	uint8_t	ret;
//
//	LATBCLR = CSN_PIN;			//SS high
//	spi_transfer(R_REGISTER(reg_addr));	//Send read command with a register address
//	ret = spi_transfer(0x00);		//Dummy byte
//	LATBSET = CSN_PIN;			//SS low
//	return(ret);
//}
//
////Read data from a 5 bytes long register.
//int64_t	radio_read_long_reg(uint8_t reg_addr)
//{
//	int8_t		count;
//	uint64_t	ret;
//	uint64_t	test;	
//	
//	ret = 0l;
//	LATBCLR = CSN_PIN;			//SS high
//	spi_transfer(R_REGISTER(reg_addr));	//Send read command with a register address
//	
//	for(count = 0; count <= 32; count += 8)
//	{
//		test = ((uint64_t)spi_transfer(0x00) << count);
//		ret += test;				//Dummy byte
//	}
//
//	LATBSET = CSN_PIN;			//SS low
//	return(ret);
//}
//
////Write data to a 1 byte long register.
//void	radio_write_short_reg(uint8_t reg_addr, int8_t data)
//{
//	LATBCLR = CSN_PIN;			//SS high
//	spi_transfer(W_REGISTER(reg_addr));	//Send write command with a register address
//	spi_transfer(data);			//Data
//	LATBSET = CSN_PIN;			//SS low
//}
//
////Write data to a 5 bytes long register.
//void	radio_write_long_reg(uint8_t reg_addr, int64_t data)
//{
//	int8_t count;
//	uint64_t test;
//	
//	test = 0;
//	LATBCLR = CSN_PIN;					//SS high
//	spi_transfer(W_REGISTER(reg_addr));			//Send write command with a register address
//
//	for(count = 0; count <= 32; count += 8)			//MSB to LSB?
//	{
//		test = ((data >> count) & 0x00000000000000ffll);
//		spi_transfer(test);
//	}
//
//	LATBSET = CSN_PIN;					// SS low
////}

///** BUFFERS **/
//int64_t	buffer_to_ll(void)
//{
//	int64_t ret = 0;
//	int8_t count;	
//	
//	for(count = 0; count < 5; count++)			//LSB to MSB?
//	{
//		ret += (rx_buffer[count] & 0x00000000000000ffll) << (count * 8);
//	}
//	return(ret);
//}
//
//void	ll_to_buffer(int64_t val)
//{
//	int8_t count;
//	
//	for(count = 0; count < 5; count++)			//LSB to MSB?
//	{
//		tx_buffer[count] = (val >> (count * 8)) & 0x000000ffll;
//	}	
//}
//
//void	radio_clear_buffers(void)
//{
//	uint8_t		count;
//	uint64_t	*tmp_rx_buffer;
//	uint64_t	*tmp_tx_buffer;
//	
//	tmp_rx_buffer = rx_buffer;
//	tmp_tx_buffer = tx_buffer;
//	for(count = 0; count < 4 ; count += 1)		//clear buffer 8 bytes by 8 bytes
//	{
//		*(tmp_tx_buffer + count) = 0x00ll;
//		*(tmp_rx_buffer + count) = 0x00ll;
//	}
//}

int64_t	radio_command(int8_t command, int64_t data, int8_t data_len)
{
	int32_t		count;
	int64_t		ret = 0;
	
	LATBCLR = CSN_PIN;						//SS high
	status = spi_transfer(command);					//Send command and get STATUS_REG
	for(count = 0; count < data_len * 8; count += 8)		//LSB to MSB?
	{
		ret += (int64_t)spi_transfer(data >> count) << count;		//Send or get data
	}
	LATBSET = CSN_PIN;						// SS low
	return(ret);
}

/** COMMANDS **/
int64_t	radio_read_reg(int8_t reg_addr)
{
	int64_t	ret = 0;
	
	if (reg_addr == RX_ADDR_P0_REG | reg_addr == RX_ADDR_P1_REG | reg_addr == TX_ADDR_REG)	//if 5 bytes data
	{
		ret = radio_command(R_REGISTER(reg_addr), 0x00ll, 5);
	}
	else											//else 1 byte data
	{
		ret = radio_command(R_REGISTER(reg_addr), 0x00ll, 1);						
	}
	return(ret);
}

void	radio_write_reg(int8_t reg_addr, int64_t data)
{
	if (reg_addr == RX_ADDR_P0_REG | reg_addr == RX_ADDR_P1_REG | reg_addr == TX_ADDR_REG)
	{
		radio_command(W_REGISTER(reg_addr), data, 5);
	}
	else
	{
		radio_command(W_REGISTER(reg_addr), data, 1);
	}
}

void	radio_read_payload()
{
	radio_command(R_RX_PAYLOAD, 0x00ll, 32);
}

void	radio_write_payload()
{
	radio_command(W_TX_PAYLOAD, 0x00ll, 32);
}

void	radio_flush_tx()
{
	radio_command(FLUSH_TX, 0x00ll, 0);
}

void	radio_flush_rx()
{
	radio_command(FLUSH_RX, 0x00ll, 0);
}

void	radio_reuse_payload()
{
	radio_command(REUSE_TX_PL, 0x00ll, 0);
}

void	radio_activate()
{
	radio_command(ACTIVATE, 0x00ll, 1);
}

void	radio_read_payload_wid()
{
	radio_command(R_RX_PL_WID, 0x00ll, 1);
}

void	radio_w_ack_payload(int8_t pipe)
{
	radio_command(W_ACK_PAYLOAD(pipe), 0x00ll, 32);
}

void	radio_write_payload_no_ack()
{
	radio_command(W_TX_PAYLOAD_NO_ACK, 0x00ll, 32);
}

void	radio_nop()
{
	radio_command(NOP, 0x00ll, 0);
}

//int32_t	radio_get_payload(void)
//{
//	int32_t payload;
//	int8_t count;
//	
//	spi_transfer(R_RX_PAYLOAD);				//Read rx register command
//	for(count = 0; count < 32; count += 8)
//	{
//		payload += (spi_transfer(0x00) << count);	//Send dummy bytes
//	}
//	return(payload);
//}
//
//void	radio_send_payload(int32_t payload)
//{
//	int32_t count;
//	
//	spi_transfer(W_TX_PAYLOAD);
//	for(count = 0; count < 32; count += 8)
//	{	
//		spi_transfer((payload >> count) | 0x000000ff);
//	}
//}

/** send and recieve **/

void	radio_send(int32_t payload)
{
	int test;
	//set PWR_UP, clr PRIM_RX
	radio_write_reg(CONFIG_REG, 0x0e);	//PWR_UP
	test = radio_read_reg(CONFIG_REG);
	
	//payload in TX FIFO
	radio_write_reg(TX_ADDR_REG, 0x0000003232323232);	//tx addr = ""
	radio_command(R_RX_PAYLOAD, payload, 8);
	
	//CE_PIN HIGH (10us pulse)
	LATBSET = CE_PIN;
	delay_micro(10);
	LATBCLR = CE_PIN;
}

int32_t	radio_recieve(void)
{
	int64_t	ret = 0;
	
	//set PWR_US, set PRIM_RX
	test = radio_read_reg(CONFIG_REG);
	radio_write_reg(CONFIG_REG, 0x0f);	//PWR_UP | PRIM_RX
	test = radio_read_reg(CONFIG_REG);

	//CE_PIN HIGH
	LATBSET = CE_PIN;
	
	//wait for a payload in RX FIFO
	while((status & 0x0e) == 0x0e)
	{
		radio_nop();
	}
	
	//get_payload
	ret = radio_command(R_RX_PAYLOAD, 0x00ll, 8);

	//CE_PIN LOW
	LATBCLR = CE_PIN;
	
	return(ret);
}

/** TESTS **/

void	spi_test(void)
{
	int64_t val = 0;
	int reg = RX_ADDR_P0_REG;

	val = radio_read_reg(reg);
	radio_write_reg(reg, 0xeeddccbbaa);
	val = radio_read_reg(reg);
}

void		ping_raspberry(void)
{
	int val = 0;
	
	radio_send(0x2a);
//	val = radio_recieve();
}
