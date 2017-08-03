NAME = radio

SOURCES = 	gpio_driver.c\
		spi_driver.c\
		nrf24l01_driver.c\
		radio.c

CFLAGS = -Wall -Wextra -Werror -I./libft/include

all: $(NAME)

$(NAME):
	make -C ./libft/
	g++ -L ./libft -lft $(SOURCES) -I./libft/include/ -o $(NAME) -g 
clean:
	rm $(NAME)

fclean: clean

re: fclean all

