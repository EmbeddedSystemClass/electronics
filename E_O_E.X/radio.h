#ifndef NRF24L01_H      /* Guard against multiple inclusion */
#define NRF24L01_H

#define CE_PIN		0x0040	//RB6
#define IRQ_PIN		0x0002	//RB1

#define CSN_PIN 0x8000

/*              RADIO COMMANDS                */
#define R_REGISTER(addr)        (0b00000000 | addr)     //0b000A AAAA (A = address) (1 to 5, LSByte first)
#define W_REGISTER(addr)        (0b00100000 | addr)     //0b001A AAAA (A = address) (1 to 5, LSByte first)
#define R_RX_PAYLOAD             0b01100001             //Read payload  (1 to 32, LSByte first)
#define W_TX_PAYLOAD             0b10100000             //Write payload (1 to 32, LSByte first)
#define FLUSH_TX                 0b11100001             //Flush TX      (0 byte)
#define FLUSH_RX                 0b11100010             //FLush RX      (0 byte)
#define REUSE_TX_PL              0b11100011             //              (0 byte)
#define ACTIVATE                 0b01010000             //              (1 byte)
#define R_RX_PL_WID              0b01100000             //              
#define W_ACK_PAYLOAD(pipe)     (0b10101000 | pipe)     //P = Pipe      (1 to 32, LSByte first)
#define W_TX_PAYLOAD_NO_ACK      0b10110000             //              (1 to 32, LSByte first)
#define NOP                      0b11111111             //NOP           (0 byte)

typedef enum	e_radio_reg
{
	CONFIG_REG,         //1byte
	EN_AA_REG,          //1
	EN_RXADDR_REG,      //1
	SETUP_AW_REG,       //1
	SETUP_RETR_REG,     //1
	RF_CH_REG,          //1
	RF_SETUP_REG,       //1
	STATUS_REG,         //1
	OBSERVE_TX_REG,     //1
	CD_REG,             //1
	RX_ADDR_P0_REG,     //5     //0x0a
	RX_ADDR_P1_REG,     //5
	RX_ADDR_P2_REG,     //1
	RX_ADDR_P3_REG,     //1
	RX_ADDR_P4_REG,     //1
	RX_ADDR_P5_REG,     //1
	TX_ADDR_REG,        //5     //0x10
	RX_PW_P0_REG,       //1
	RX_PW_P1_REG,       //1
	RX_PW_P2_REG,       //1
	RX_PW_P3_REG,       //1
	RX_PW_P4_REG,       //1
	RX_PW_P5_REG,       //1
	FIFO_STATUS_REG,    //1
	NONE0,              //
	NONE1,              //
	NONE2,              //
	NONE3,              //
	DYNPD_REG,          //1
	FEATURE_REG         //1
}               t_radio_reg;


void	init_radio(uint8_t reg_addr);
int64_t	radio_command(int8_t command, int64_t data, int8_t data_len);
int64_t	radio_read_reg(int8_t reg_addr);
void	radio_write_reg(int8_t reg_addr, int64_t data);
void	radio_read_payload();
void	radio_write_payload();
void	radio_flush_tx();
void	radio_flush_rx();
void	radio_reuse_payload();
void	radio_activate();
void	radio_read_payload_wid();
void	radio_w_ack_payload(int8_t pipe);
void	radio_write_payload_no_ack();
void	radio_nop();


#endif /* NRF24L01_H */