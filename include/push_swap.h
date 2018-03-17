/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:57:57 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/26 18:58:00 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "get_next_line.h"

# define MAX			2147483647
# define MIN			-2147483648
# define DATA			stack->st->data
# define TOP			stack->st->top
# define DATA_A			stack_a->st->data
# define TOP_A			stack_a->st->top
# define DATA_B			stack_b->st->data
# define TOP_B			stack_b->st->top
# define OPT			stack->op->str
# define OPT_A			stack_a->op->str
# define SA				"sa\n"
# define SB 			"sb\n"
# define SS 			"ss\n"
# define PA 			"pa\n"
# define PB 			"pb\n"
# define RA 			"ra\n"
# define RB 			"rb\n"
# define RR 			"rr\n"
# define RRA 			"rra\n"
# define RRB 			"rrb\n"
# define RRR 			"rrr\n"
# define VISUAL 		1
# define VISUAL_COLOR 	2
# define COLOR 			3
# define NOTHING		0
# define EMPTY 			-1
# define SA_2 "sa  : swap a - swap the "
# define SA_2_2	"first 2 elements at the top of stack a. "
# define SB_2 "swap b - swap the first 2 elements "
# define SB_2_2	"at the top of stack b. "
# define SB_2_3	"(Do nothing if there is only one or no elements).\n"
# define PA_2 "push a - take the first "
# define PA_2_2	"element at the top of b and put it at the top of a. "
# define PB_2 "push b - take the first "
# define PB_2_2	"element at the top of a and put it at the top of b. "
# define RA_2 "rotate a - shift up all "
# define RA_2_2 "elements of stack a by 1. The first element becomes "
# define RB_2 	"rotate b - shift up all "
# define RB_2_2	" of stack b by 1. The first element becomes the last one."
# define RRA_2	"reverse rotate a - shift "
# define RRA_2_2 "down all elements of stack a by 1. "
# define RRA_2_3 "The flast element becomes the first one.\n"
# define RRB_2 "reverse rotate b - shift "
# define RRB_2_2 "down all elements of stack b by 1. "
# define RRB_2_3 "The flast element becomes the first one.\n"

typedef struct	s_opt
{
	char		*str;
}				t_opt;

typedef struct	s_stack
{
	int			*data;
	int			top;
}				t_stack;

typedef struct	s_snake
{
	char		*str;
	t_stack		*st;
	t_opt		*op;
	int			flags;
}				t_snake;

t_snake			*stack_int(int ac, char **av, char c);
int				ft_check_av(int ac, char **av);
int				sorted_arr(t_snake *stack);
int				revers_arr(t_snake *stack);
int				count_len(char **av, t_snake *stack);
int				quick_a(t_snake *stack_a, t_snake *stack_b, int i);
int				quick_b(t_snake *stack_a, t_snake *stack_b, int nb);
int				check_median(t_snake *stack_a, int med, int nb);
int				check_med(t_snake *stack_a, int nbelem);
int				mini_sort(t_snake *stack_a);
int				count_len_v2(char **str);
int				check_digit(char **str);
int				sort_5_elem(t_snake *stack_a, t_snake *stack_b);

void			print_op_color(t_snake *stack_a,
				t_snake *stack_b, char *op);
void			same_nbr(int j, int *tab);
void			ft_exit(char *error);
void			ft_arr_free(char **str);
void			swap_ab(t_snake *stack, char *str);
void			push_ab(t_snake *stack_a,
				t_snake *stack_b, char *str);
void			rotate_ab(t_snake *stack, char *str);
void			reverse_rv(t_snake *stack, char *str);
void			print_stacks(t_snake *stack_a, t_snake *stack_b);
void			print_op(t_snake *stack_a, t_snake *stack_b, char *line);
void			check_flags(int *ac, char **av, t_snake *stack_a);
void			sort_pile(t_snake *stack_a, t_snake *stack_b);
void			print_operations(t_snake *stack_a, t_snake *stack_b);
void			ft_arr_free(char **str);
void			ft_all_free(t_snake *stack_a, t_snake *stack_b, t_opt	opt);
void			ft_ok_ko(t_snake *stack_a, t_snake *stack_b);
char			*ft_next(char *s1, char *s2);
void			ft_print_usage(void);

#endif
