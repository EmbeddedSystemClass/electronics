
#include "gpio_driver.h"
#include "spi_driver.h"
#include "nrf24l01_driver.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define payload_size 24

/*	REGISTERS CONFIG
	config		0x3b
	en_aa		0x3f
	en_rxaddr	0x03
	setup_aw	0x03
	setup_retr	0x03
	rf_ch		0x01
	rf_setup	0x07
	status		0x07
	observe_tx	0x00
	cd		0x00
	rx_addr_p0	0x3131313131
	rx_addr_p1	0x3232323232
	rx_addr_p2	0xc3
	rx_addr_p3	0xc4
	rx_addr_p5	0xc5
	rx_addr_p6	0xc6	
	tx_addr		0x3131313131
	rx_pw_p0	0x04
	rx_pw_p1	0x04
	rx_pw_p2	0x00
	rx_pw_p3	0x00
	rx_pw_p4	0x00
	rx_pw_p5	0x00
	fifo_status	0x11
	dynpd		0x00
	feature		0x00
 */

typedef struct s_save
{
	unsigned char	time_s;		//secondes
	unsigned char	time_m;		//minutes
	unsigned char	time_h;		//heures
	unsigned char	time_d;		//jours
	unsigned char	time_M;		//mois
	unsigned char	time_y;		//annees
	unsigned int	bat;		//niveau batterie (%)
	unsigned short	lum;		//luminosity (lux)
	unsigned short	hum;		//humiditee (%)
	short		temp;		//temperature (degres celcius)
	unsigned char	lvl;		//niveau d'eau
}			t_save;

void	radio_config(void)
{
	radio_write_reg(CONFIG_REG,	0x0b, 1);
	radio_write_reg(EN_AA_REG,	0x3f, 1);
	radio_write_reg(EN_RXADDR_REG,	0x03, 1);
	radio_write_reg(SETUP_AW_REG,	0x03, 1);
	radio_write_reg(SETUP_RETR_REG,	0x03, 1);
	radio_write_reg(RF_CH_REG,	0x01, 1);
	radio_write_reg(RF_SETUP_REG,	0x0f, 1);
	radio_write_reg(STATUS_REG,	0x70, 1);
	radio_write_reg(OBSERVE_TX_REG,	0x00, 1);
	radio_write_reg(CD_REG,		0x00, 1);
	radio_write_reg(RX_ADDR_P0_REG,	0x3131313131, 5);
	radio_write_reg(RX_ADDR_P1_REG,	0x3232323232, 5);
	radio_write_reg(RX_ADDR_P2_REG,	0xc3, 1);
	radio_write_reg(RX_ADDR_P3_REG,	0xc4, 1);
	radio_write_reg(RX_ADDR_P4_REG,	0xc5, 1);
	radio_write_reg(RX_ADDR_P5_REG,	0xc6, 1);
	radio_write_reg(TX_ADDR_REG,	0x3131313131, 5);
	radio_write_reg(RX_PW_P0_REG,	payload_size, 1);
	radio_write_reg(RX_PW_P1_REG,	payload_size, 1);
	radio_write_reg(RX_PW_P2_REG,	0x00, 1);
	radio_write_reg(RX_PW_P3_REG,	0x00, 1);
	radio_write_reg(RX_PW_P4_REG,	0x00, 1);
	radio_write_reg(RX_PW_P5_REG,	0x00, 1);
	radio_write_reg(FIFO_STATUS_REG,0x11, 1);
	radio_write_reg(DYNPD_REG,	0x00, 1);
	radio_write_reg(FEATURE_REG,	0x00, 1);
}


int main(void)
{
	unsigned char	*rx_buff;
	char		path[] = "/home/pi/plot_test";
	int		data_fd = 0;
	t_save		save;
	char		buff[666];
	int		count = 0;

	radio_init();
	radio_config();		//configure registers
	print_registers();	//print config
	printf("~~~~~~~~~~~~~~~~~\n");

	/*File*/
	data_fd = open(path, O_RDWR);
	if (data_fd < 0)
	{
		printf("Cant open %s\n", path);
		exit(-1);
	}

	/*	RECEPTION	*/
	while (1)
	{
		rx_buff = radio_recieve(payload_size);

		save.time_s = rx_buff[1];
		save.time_m = rx_buff[2];
		save.time_h = rx_buff[3];
		save.time_d = rx_buff[5];
		save.time_M = rx_buff[6];
		save.time_y = rx_buff[7];

		save.bat = rx_buff[8];
		save.lum = rx_buff[12] + (rx_buff[13] << 8);
		save.hum = rx_buff[14] + (rx_buff[15] << 8);
		save.temp = rx_buff[16] + (rx_buff[17] << 8);
		save.lvl = rx_buff[18];

		printf("%u%u/%u%u/%u%u, ", (save.time_y & 0xf0) >> 4, save.time_y & 0x0f, (save.time_M & 0xf0) >> 4, save.time_M & 0x0f, (save.time_d & 0xf0) >> 4, save.time_d & 0x0f);
		printf("%u%u:%u%u:%u%u", (save.time_h & 0xf0) >> 4, save.time_h & 0x0f, (save.time_m & 0xf0) >> 4, save.time_m & 0x0f, (save.time_s & 0xf0) >> 4, save.time_s & 0x0f);

		printf("	count = %d", ++count);
		printf("	bat = %3u", save.bat);
		printf("	lum = %4u", save.lum);
		printf("	hum = %3u", save.hum);
		printf("	temp = %2d,%d", save.temp / 10, save.temp % 10);
		printf("	lvl = %1u\n", save.lvl);

		sprintf(buff, "%d%d/%d%d %d%d:%d%d:%d%d\t%d\t%d\t%d\t%d.%d\t%d\n",\
		(save.time_M & 0xf0) >> 4, save.time_M & 0x0f,\
		(save.time_d & 0xf0) >> 4, save.time_d & 0x0f,\
		(save.time_h & 0xf0) >> 4, save.time_h & 0x0f,\
		(save.time_m & 0xf0) >> 4, save.time_m & 0x0f,\
		(save.time_s & 0xf0) >> 4, save.time_s & 0x0f,\
		save.bat,\
		save.lum,\
		save.hum,\
		save.temp/10,\
		save.temp%10,\
		save.lvl);

		write(data_fd, buff, strlen(buff));	// write to the data file
		//system("sh ~/Bureau/plot.sh"); // generation auto graphique gnuplot !! changer les path ici et dans le script
	}

			/*	EMISSION
				while (1)
				{
				buff[0] = 66u;
				printf("sending %d\n", buff[0]);
				radio_send(buff, 4);
				printf("\n");
				sleep(1);
				}
			 */

			//	radio_purge();		//release gpio and spi
	radio_purge();
	close(data_fd);
	return(0);
}

