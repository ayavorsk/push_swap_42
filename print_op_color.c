/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 20:15:05 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/13 20:15:05 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_color_a(t_snake *stack, char *op, int i)
{
	if (ft_strstr(op, "sa"))
	{
		ft_printf("\x1B[31m%d ", DATA[i--]);
		ft_printf("\x1B[32m%d \x1B[0m", DATA[i--]);
		while (i >= 0)
			ft_printf("%d \x1B[0m", DATA[i--]);
	}
	else if (ft_strstr(op, "rra"))
	{
		ft_printf("\x1B[32m%d ", DATA[i--]);
		while (i >= 0)
			ft_printf("\x1B[31m%d \x1B[0m", DATA[i--]);
	}
	else if (ft_strstr(op, "ra"))
	{
		ft_printf("\x1B[32m%d ", DATA[0]);
		while (i > 0)
			ft_printf("\x1B[31m%d \x1B[0m", DATA[i--]);
	}
	else
		while (i >= 0)
			ft_printf("\x1B[0m%d ", DATA[i--]);
}

static void		print_color_b(t_snake *stack, char *op, int i)
{
	if (ft_strstr(op, "sb"))
	{
		ft_printf("\x1B[31m%d ", DATA[i--]);
		ft_printf("\x1B[32m%d \x1B[0m", DATA[i--]);
		while (i >= 0)
			ft_printf("%d ", DATA[i--]);
	}
	else if (ft_strstr(op, "rrb"))
	{
		ft_printf("\x1B[31m%d ", DATA[i--]);
		while (i >= 0)
			ft_printf("\x1B[31m%d \x1B[0m", DATA[i--]);
	}
	else if (ft_strstr(op, "rb"))
	{
		ft_printf("\x1B[32m%d ", DATA[0]);
		while (i > 0)
			ft_printf("\x1B[31m%d \x1B[0m", DATA[i--]);
	}
	else
		while (i >= 0)
			ft_printf("\x1B[0m%d ", DATA[i--]);
}

void			print_op_color(t_snake *stack_a, t_snake *stack_b, char *op)
{
	int i;
	int j;

	i = TOP_A;
	j = TOP_B;
	ft_printf("STACK_A[ \x1B[0m");
	if (ft_strstr(op, "pa") && i >= 0)
	{
		ft_printf("\x1B[31m%d \x1B[0m", DATA_A[i--]);
		while (i >= 0)
			ft_printf("\x1B[32m%d \x1B[0m", DATA_A[i--]);
	}
	else if (i >= 0)
		print_color_a(stack_a, op, i);
	ft_printf("]\x1B[0m\n");
	ft_printf("STACK_B[ \x1B[0m");
	if (ft_strstr(op, "pb") && j >= 0)
	{
		ft_printf("\x1B[31m%d \x1B[0m", DATA_B[j--]);
		while (j >= 0)
			ft_printf("\x1B[32m%d ", DATA_B[j--]);
	}
	else if (j >= 0)
		print_color_b(stack_b, op, j);
	ft_printf("]\x1B[0m\n");
}
