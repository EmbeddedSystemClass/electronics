#ifndef NRF24L01_H
#define NRF24L01_H

/*
 *      Radio pinout
 *
 *         Radio                        RPI
 *      1       GND             GND             25
 *      2       VCC             +3v             17
 *      3       CE              GPIO24          18
 *      4       CSN             GPIO25          22
 *      5       SCK             SPI0 SCLK       23
 *      6       MOSI            SPI0 MOSI       19
 *      7       MISO            SPI0 MISO       21
 *      8       IRQ             UNUSED
 */

/***RADIO PINS***/
#define CE_PIN  24
#define CSN_PIN 25

/***COMMANDS***/
#define R_REGISTER(addr)	(0b00000000 | addr)
#define W_REGISTER(addr)	(0b00100000 | addr)
#define R_RX_PAYLOAD		 0b01100001
#define W_TX_PAYLOAD		 0b10100000
#define FLUSH_TX		 0b11100001
#define FLUSH_RX		 0b11100010
#define REUSE_TX_PL		 0b11100011
#define ACTIVATE		 0b01010000
#define R_RX_PL_WID		 0b01100000
#define W_ACK_PAYLOAD(pipe)	(0b10101000 | pipe)
#define W_TX_PAYLOAD_NO_ACK	 0b10110000
#define NOP 			 0b11111111

/***RADIO REGISTERS***/
typedef enum e_radio_reg
{
	CONFIG_REG,
	EN_AA_REG,
	EN_RXADDR_REG,
	SETUP_AW_REG,
	SETUP_RETR_REG,
	RF_CH_REG,
	RF_SETUP_REG,
	STATUS_REG,
	OBSERVE_TX_REG,
	CD_REG,
	RX_ADDR_P0_REG,
	RX_ADDR_P1_REG,
	RX_ADDR_P2_REG,
	RX_ADDR_P3_REG,
	RX_ADDR_P4_REG,
	RX_ADDR_P5_REG,
	TX_ADDR_REG,
	RX_PW_P0_REG,
	RX_PW_P1_REG,
	RX_PW_P2_REG,
	RX_PW_P3_REG,
	RX_PW_P4_REG,
	RX_PW_P5_REG,
	FIFO_STATUS_REG,
	NONE0_REG,
	NONE1_REG,
	NONE2_REG,
	NONE3_REG,
	DYNPD_REG,
	FEATURE_REG
}t_radio_reg;

/***FUNCTHIONS***/
void		clr_buffer(void);
void		radio_ce_pulse();
void		radio_tx_mode();
void		radio_rx_mode();
void		radio_nop();
void		command_flush_rx(void);

void		radio_init(void);
void		radio_purge(void);
void		print_registers(void);
unsigned char	*radio_read_reg(unsigned char reg, unsigned int size);
void		radio_write_reg(unsigned char reg, unsigned long long data, unsigned int size);
void		radio_send(unsigned char *payload, unsigned int size);
unsigned char	*radio_recieve(unsigned int size);

#endif
