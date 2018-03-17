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

NAME		= libftprintf.a
INC = libftprintf.h

SRC = ft_printf.c\
	ft_is_valid.c\
	ft_get_argument.c\
	ft_flags_2.c\
	ft_flags_1.c\
	ft_arg_list.c\
	ft_print_char.c\
	ft_print_hex.c\
	ft_print_param.c\
	ft_print_digit.c\
	ft_print_digit_help.c\
	ft_print_string.c\
	ft_help_functions_1.c\
	ft_help_functions_2.c\
	ft_wchar_str.c\
	ft_wchar.c\
	ft_strlen.c\
	ft_dprintf.c\


LIBFT = libft

CC = gcc

FLAGS = -Wall -Werror -Wextra -I 

OBJ = $(SRC:.c=.o)

all: $(NAME)


%.o%.c:
	$(CC) -c $(FLAGS) $(INC) $< -o $@ 

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(LB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
.NOTPARALLEL: all ($NAME) $(MK_LIB) re