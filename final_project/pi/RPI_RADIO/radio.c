#include "gpio_driver.h"
#include "spi_driver.h"
#include "nrf24l01_driver.h"
#include "libft.h"
#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <errno.h>

#define payload_size 24
#define mesures_per_plot 10
#define SEND_RETRIES 3
#define DEFAULT_PATH "./default.txt"	//file storing thresholds
#define buff_size 512	//gnl buffer

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

int16_t	new_default[16];
int16_t	old_default[16];

void	radio_config(void)
{
	radio_write_reg(CONFIG_REG,		0x0b, 1);
	radio_write_reg(EN_AA_REG,		0x3f, 1);
	radio_write_reg(EN_RXADDR_REG,		0x03, 1);
	radio_write_reg(SETUP_AW_REG,		0x03, 1);
	radio_write_reg(SETUP_RETR_REG,		0x03, 1);
	radio_write_reg(RF_CH_REG,		0x01, 1);
	radio_write_reg(RF_SETUP_REG,		0x0f, 1);
	radio_write_reg(STATUS_REG,		0x70, 1);
	radio_write_reg(OBSERVE_TX_REG,		0x00, 1);
	radio_write_reg(CD_REG,			0x00, 1);
	radio_write_reg(RX_ADDR_P0_REG,		0x3131313131, 5);
	radio_write_reg(RX_ADDR_P1_REG,		0x3232323232, 5);
	radio_write_reg(RX_ADDR_P2_REG,		0xc3, 1);
	radio_write_reg(RX_ADDR_P3_REG,		0xc4, 1);
	radio_write_reg(RX_ADDR_P4_REG,		0xc5, 1);
	radio_write_reg(RX_ADDR_P5_REG,		0xc6, 1);
	radio_write_reg(TX_ADDR_REG,		0x3131313131, 5);
	radio_write_reg(RX_PW_P0_REG,		payload_size, 1);
	radio_write_reg(RX_PW_P1_REG,		payload_size, 1);
	radio_write_reg(RX_PW_P2_REG,		0x00, 1);
	radio_write_reg(RX_PW_P3_REG,		0x00, 1);
	radio_write_reg(RX_PW_P4_REG,		0x00, 1);
	radio_write_reg(RX_PW_P5_REG,		0x00, 1);
	radio_write_reg(FIFO_STATUS_REG,	0x11, 1);
	radio_write_reg(DYNPD_REG,		0x00, 1);
	radio_write_reg(FEATURE_REG,		0x00, 1);
}

/*
void	get_default_value(int fd, int16_t tab[11])
{
	int	ret;
	int	i;
	char	*line;

	i = 0;
	ret = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
			return ;
		if (line[0] != '#')
		{
			tab[i] = (int16_t)atoi(line);
			i++;
		}
		free(line);
	}
}

void	show_default_value(int16_t tab[11])
{
	int	i;

	i = 0;
	while (i < 11)
	{
		printf("Tab[%d] = %d\n", i, tab[i]);
		i++;
	}
}

void	check_default_value(const char *value, int16_t tab[11])
{
	int	value_fd = 0;

	value_fd = open(value, O_RDWR);
	if (value_fd < 0)
		printf("Cant open %s, %s\n", value, strerror(errno));
	get_default_value(value_fd, tab);
	//	show_default_value(tab);
	close(value_fd);
}

int	compare_default_value(const char *value, int16_t tab[11], int16_t tmptab[11])
{
	int	i;

	i = 0;
	check_default_value(value, tmptab);
	while (i < 11)
	{
		if (tab[i] != tmptab[i])
			return (i);
		i++;
	}
	return (0);
}
*/

//	retrieve current limites config in default tab
void	get_config(int16_t defaut[16])
{
	int fd;
	char *buff;

	buff = ft_strnew(BUFF_SIZE);
	if ((fd = open(DEFAULT_PATH, O_RDWR)) < 0)
	{
		printf("Cant open %s: %s\n", DEFAULT_PATH, strerror(errno));
		exit(-1);
	}
	int index = 0;
	while (get_next_line(fd, (char **)&buff))
	{
		if (*(buff + 0) != '#')
		{
			*(defaut + index) = (int16_t)ft_atoi(buff);
			index++;
		}
	}
	close(fd);
	ft_memdel((void**)&buff);
}

//	has default.txt changed?
int	has_config_changed(void)
{
	int index = 0;

	while (index < 11)
	{
		if (*(old_default + index) != *(new_default + index))	
		{
			return(1);
		}
		index++;
	}
	return(0);
}

#define DEF_VAL_NB 11
void	cp_default(int16_t dst[16], int16_t src[16])
{
	int index = 0;

	while (index < DEF_VAL_NB)
	{
		*(dst + index) = *(src + index);
		index++;
	}
}

void	print_config(int16_t defaut[16])
{
	int	index = 0;
	char	value_name[][128] = {
			"battery_threshold",
			"level_threshold",
			"pump_threshold",
			"bottom_lum_threshold",
			"top_lum_threshold",
			"bottom_temp_threshold",
			"top_temp_threshold",
			"bottom_offet_bat",
			"top_offset_bat",
			"freqency",
			"amask"
		};

	while(index < 11)
	{
		printf("%s = %d\n", *(value_name + index), *(defaut + index));
		index++;
	}
}

int8_t		radio_ack()
{
	int	i = 0;
	int	stat = 0;

	while (i < 100)	//1000
	{
		stat = *radio_read_reg(STATUS_REG, 1);	//get radio status
		if (stat & 0x20)	//if acked
		{
			radio_write_reg(STATUS_REG, 0x20, 1); //clr status rx ack flag
			return (1);	//ok
		}
		i++;
		usleep(1000);
		//add usleep?
	}
	return (0);	//err
}

int main(void)
{
	unsigned char	*rx_buff;
	unsigned char	command[4];
	char		path[] = "/home/pi/data.dat";
	char		value[] = "/home/pi/default";
	int		data_fd = 0;
	int		value_fd = 0;
	int16_t		tab[11] = {0};
	int16_t		tmptab[11] = {0};
	int		ret;
	t_save		save;
	char		*buff;
	int		count = 0;
	int		index = 1;
	time_t		t;
	struct tm 	tm;

	/*	INIT	*/
	radio_init();
	radio_config();		//configure registers
	print_registers();	//print registers config
	printf("~~~~~~~~~~~~~~~~~\n");

	/*Open data.dat file*/
	data_fd = open(path, O_RDWR);
	if (data_fd < 0)
	{
		printf("Cant open %s, %s\n", path, strerror(errno));
		exit(-1);
	}

	//get default.txt config
		get_config(old_default);
		print_config(old_default);
	/*	__INIT	*/


	/*	LOOP	*/
	while (1)
	{
		/*	RECEPTION	*/
		//recieve payload
		rx_buff = radio_recieve(payload_size);

		//get current time
		t = time(NULL);
		tm = *localtime(&t);

		//fill values struct
		save.bat = rx_buff[8];
		save.lum = rx_buff[12] + (rx_buff[13] << 8);
		save.hum = rx_buff[14] + (rx_buff[15] << 8);
		save.temp = rx_buff[16] + (rx_buff[17] << 8);
		save.lvl = rx_buff[18];

		//print data in stdout
		printf("%02u/%02u/%02u, ", tm.tm_year - 100, tm.tm_mon + 1, tm.tm_mday, save.time_M);
		printf("%02u:%02u:%02u", tm.tm_hour, tm.tm_min, tm.tm_sec);
		printf("	count = %d", ++count);
		printf("	bat = %3u", save.bat);
		printf("	lum = %4u", save.lum);
		printf("	hum = %3u", save.hum);
		printf("	temp = %2d,%d", save.temp / 10, save.temp % 10);
		printf("	lvl = %1u\n", save.lvl);

		//format & write data to data.dat
		dprintf(data_fd, "%02d/%02d %02d:%02d:%02d\t%d\t%d\t%d\t%d.%d\t%d\n",\
				tm.tm_mday,\
				tm.tm_mon + 1,\
				tm.tm_hour,\
				tm.tm_min,\
				tm.tm_sec,\
				save.bat,\
				save.lum,\
				save.hum,\
				save.temp/10,\
				save.temp%10,\
				save.lvl * 20);
		/*	__RECEPTION	*/

		/*	VALUES CHANGED? */
		get_config(new_default);	//re read threshold conf file
		if (has_config_changed() != 0)	//compare old vs new threshold confs
		{
			printf("Config changed>\n");
			printf("sending new thresholds...\n");

/////////////////radio send efface le buffer, penser le recopier a chaque reenvoi//////////////////

			int	limit = SEND_RETRIES;	//nb de re-envois
			int16_t tmp_thres_conf[16];
			cp_default(tmp_thres_conf, new_default);
			while (limit > 0)
			{
//				command[3] = 42;			//MSB | LSB ?
//				command[2] = ret;
//				command[1] = (tmptab[ret] >> 8);
//				command[0] = (tmptab[ret] & 0x00ff);

//				int test_index = 0;
//				while (test_index < 22)
//				{
//					printf(">>>\t%x\t", *((uint8_t*)new_default + test_index));
//
//					if ((test_index % 2) != 0)
//						printf("\n");
//						
//					test_index++;
//				}
//				printf("\n");

				//remive below
				cp_default(old_default, new_default);	//cp new_default to old_default

				radio_send((uint8_t *)tmp_thres_conf, 22);
				if (radio_ack())
				{
					printf("Sent\n");
					cp_default(old_default, new_default);	//cp new_default to old_default
					break;
				}
				limit--;
				command_flush_tx();
			}
			printf("New threshold config:\n");
			print_config(old_default);
		}
		



		//check_default_value(value, tab);
		/*	__VALUES CHANGED? */

		/*	PLOT	*/
		if (index == mesures_per_plot)	//Enough mesures. It's time to plot.
		{
			//close data.dat file
			close(data_fd);

			//append data to data.dat//
			/*Open data.dat file*/
			data_fd = open(path, O_RDWR);
			if (data_fd < 0)
			{
				printf("Cant open %s, %s\n", path, strerror(errno));
				exit(-1);
			}

			// generation auto graphique gnuplot !! changer les path ici et dans le script
			system("sh /home/pi/plot.sh");
			index = 0;	//remise a zero du nombre de mesure par plot

/*
			int		limit = 4;	//nb de re-envois
			while ((ret = compare_default_value(value, tab, tmptab)) && limit)
			{
				int status = 0;

				command[3] = 42;
				command[2] = ret;
				command[1] = (tmptab[ret] >> 8);
				command[0] = (tmptab[ret] & 0x00ff);
				//	printf("%d\n" , tmptab[ret]);
				//	printf("%hd %hd %hd %hd\n", command[3], command[2], command[1], command[0]);
				printf("sending...\n");
				radio_send(command, 4);
				if (!radio_ack())
				{
					printf("Sent\n");
					tab[ret] = tmptab[ret];
				}
				limit--;
				command_flush_tx();
			}
*/
		}
		index++;	//compteur de mesure par plot
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

	/*	CLOSE	*/
	//	radio_purge();		//release gpio and spi
	radio_purge();
	close(data_fd);
	close(value_fd);
	/*	__CLOSE	*/

	return(0);
}

