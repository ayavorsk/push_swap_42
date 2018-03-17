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

NAME = push_swap

NAME_2 = checker

HEAD = include/

DIR = src

SRC = med.c \
		ft_check_av.c \
		ft_stack_int.c \
		operations.c \
		quick_a.c \
		quick_b.c \
		sorted.c \
		mini_sort.c \
		ft_next.c \
		print_operations.c \
		get_next_line.c\
		visual.c\
		ft_helpfunctions.c\
		ft_all_free.c\
		sort_5_elem.c\
		print_op_color.c

SRC_1 = $(SRC) push_swap.c

SRC_2 = $(SRC) checker.c

LIBFT = libft/

OBJ_1 = $(SRC_1:.c=.o)

OBJ_2 = $(SRC_2:.c=.o)

FLAGS = -Wall -Werror -Wextra 

CC = gcc

all: $(NAME) $(NAME_2)

$(NAME): $(OBJ_1)
	make -C $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(SRC_1) -I $(HEAD) -L $(LIBFT) -lft

$(NAME_2): $(OBJ_2)
	$(CC) $(FLAGS) -o $(NAME_2) $(SRC_2) -I $(HEAD) -L $(LIBFT) -lft

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -I $(HEAD) -c $<

clean:
	rm -f $(SRC:.c=.o) push_swap.o  checker.o
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME) $(NAME_2) 
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: re all clean fclean

