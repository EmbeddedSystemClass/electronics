# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alngo <alngo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/25 21:33:03 by alngo             #+#    #+#              #
#    Updated: 2017/07/26 13:14:43 by alngo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = src

SRC_NAME =	ft_abs.c\
			ft_atoi.c\
			ft_atol.c\
			ft_bzero.c\
			ft_chachange.c\
			ft_div.c\
			ft_foreach.c\
			ft_foreachar.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_islower.c\
			ft_isprint.c\
			ft_isspace.c\
			ft_isupper.c\
			ft_iterative_factorial.c\
			ft_labs.c\
			ft_ldiv.c\
			ft_litob.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memrealloc.c\
			ft_memset.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putinttab.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putnchar.c\
			ft_putnstr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_putstrtab.c\
			ft_putwchar.c\
			ft_putwchar_fd.c\
			ft_sqrt.c\
			ft_strcasestr.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strlenchr.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strrenew.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c\
			get_next_line.c\
			miniprintf.c\

OBJ_PATH = obj

INCLUDE_PATH = -I include

LIBFT_A = -lft

CC = g++

CFLAGS = -Wall -Wextra -Werror

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

GREEN=\033[0;32m
NC=\033[0m

$(NAME): $(OBJ_PATH) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "${GREEN}Done !${NC}"

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -o $@ -c $^

clean:
	$(RM) -r $(OBJ)

fclean:	clean
	$(RM) -r $(NAME)

re:	fclean all
