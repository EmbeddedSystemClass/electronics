

NAME = radio
SOURCES = gpio_driver.c\
		  spi_driver.c\
		  nrf24l01_driver.c\
		radio.c


all: $(NAME)

$(NAME):
		g++ $(SOURCES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

