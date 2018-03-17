#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 16:01:22 by ayavorsk          #+#    #+#              #
#    Updated: 2017/10/24 16:01:22 by ayavorsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= libft.a

INC = libft.h\

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_putstr_fd.c \
		ft_putstr.c \
		ft_putnbr_fd.c \
		ft_putnbr.c \
		ft_putendl_fd.c \
		ft_putendl.c \
		ft_putchar_fd.c \
		ft_putchar.c \
		ft_memcpy.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_swap_ch.c \
		ft_arrstr.c \
		ft_swap_int.c \
		ft_sqrt.c \
		ft_arrlen.c \

CC = gcc

FLAGS = -Wall -Werror -Wextra -I

PRINTF = ft_printf/

OBJ = $(SRC:.c=.o)


all: $(NAME)

%.o%.c:
	$(CC) -c $(FLAGS) $(INC) $< -o $@

$(NAME): $(OBJ)
	make -C $(PRINTF)
	cp ft_printf/libftprintf.a ./$(NAME)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	make clean -C $(PRINTF)

fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(PRINTF)

re: fclean all

.PHONY: re all clean fclean