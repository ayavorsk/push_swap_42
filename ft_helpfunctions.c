/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:12:33 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/11 16:12:33 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_arr_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int			count_len(char **av, t_snake *stack)
{
	int		i;
	int		j;
	char	**str;

	j = 0;
	i = (stack->flags == 0 ? 1 : 2);
	while (av[i] != 0)
	{
		str = ft_strsplit(av[i], ' ');
		while (str[j] != 0)
			j++;
		i++;
		ft_arr_free(str);
	}
	if (j < i)
		return (i - 2);
	else
		return (j);
}

int			count_len_v2(char **av)
{
	int		i;
	long	nbr;
	char	**str;

	i = 0;
	str = NULL;
	if (ft_strlen(av[1]) != 0)
		str = ft_strsplit(av[1], ' ');
	if (str == NULL)
		return (0);
	while (str[i] != 0)
		i++;
	nbr = ft_atoi(str[0]);
	if (nbr > MAX || nbr < MIN || check_digit(str) == 0)
		ft_exit("Error");
	if (i == 1 || i == 0)
		return (0);
	else
		return (1);
}

void		ft_print_usage(void)
{
	ft_printf("In order to see the number of operations: \n");
	ft_printf("\"push_swap\": ./push_swap unsorted numbers | wc -l\n");
	ft_printf("For test output : \n");
	ft_printf("./push_swap unsorted numbers | ./cheker same numbers\n");
	ft_printf("\"cheker\": ./cheker unsorted"
		" numbers and write operations following \\n\n");
	ft_printf("Operations: \n%s%s", SA_2, SA_2_2);
	ft_printf("(Do nothing if there is only one or no elements).\n");
	ft_printf("sb  : %s%s%s", SB_2, SB_2_2, SB_2_3);
	ft_printf("ss  : sa and sb at the same time.\n");
	ft_printf("pa  : %s%s%s", PA_2, PA_2_2, SB_2_3);
	ft_printf("pb  : %s%s%s", PB_2, PB_2_2, SB_2_3);
	ft_printf("ra  : %s%s", RA_2, RA_2_2);
	ft_printf("the last one.\n");
	ft_printf("rb  : %selements%s\n", RB_2, RB_2_2);
	ft_printf("rr  : ra and rb at the same time.\n");
	ft_printf("rra : %s%s%s", RRA_2, RRA_2_2, RRA_2_3);
	ft_printf("rrb : %s%s%s", RRB_2, RRB_2_2, RRB_2_3);
	ft_printf("rrr : rra and rrb at the same time.\n");
	ft_printf("Flags -v  : Visual\n");
	ft_printf("Flags -vc : Visual, color operations and result\n");
	ft_printf("Flags -c  : color result\n");
	exit(1);
}
