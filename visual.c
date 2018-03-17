/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:23:42 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/10 15:23:43 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_flags(int *ac, char **av, t_snake *stack_a)
{
	if (ft_strstr(av[1], "-vc"))
	{
		(*ac)--;
		stack_a->flags = VISUAL_COLOR;
	}
	else if (ft_strstr(av[1], "-v"))
	{
		(*ac)--;
		stack_a->flags = VISUAL;
	}
	else if (ft_strstr(av[1], "-c"))
	{
		(*ac)--;
		stack_a->flags = COLOR;
	}
	else
		stack_a->flags = NOTHING;
}

void		print_stacks(t_snake *stack_a, t_snake *stack_b)
{
	int i;
	int j;

	i = TOP_A;
	j = TOP_B;
	ft_printf("STACK_A[ ");
	while (i >= 0)
		ft_printf("%d ", DATA_A[i--]);
	ft_printf("]\n");
	ft_printf("STACK_B[ ");
	while (j >= 0)
		ft_printf("%d ", DATA_B[j--]);
	ft_printf("]\n");
}

void		print_op(t_snake *stack_a, t_snake *stack_b, char *op)
{
	int i;
	int j;

	i = TOP_A;
	j = TOP_B;
	if (stack_a->flags == 0 || stack_a->flags == 1)
	{
		ft_printf("%s\n", op);
		ft_printf("STACK_A[ ");
		while (i >= 0)
			ft_printf("%d ", DATA_A[i--]);
		ft_printf("]\n");
		ft_printf("STACK_B[ ");
		while (j >= 0)
			ft_printf("%d ", DATA_B[j--]);
		ft_printf("]\n");
	}
	else
	{
		ft_printf("\x1B[34m%s\n\x1B[0m", op);
		print_op_color(stack_a, stack_b, op);
	}
}

void		ft_ok_ko(t_snake *stack_a, t_snake *stack_b)
{
	if (stack_a->flags == 0 || stack_a->flags == 1)
	{
		if (sorted_arr(stack_a) == 1 && TOP_B == EMPTY)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
	{
		if (sorted_arr(stack_a) == 1 && TOP_B == EMPTY)
			ft_printf("\x1B[32mOK\n");
		else
			ft_printf("\x1B[31mKO\n");
	}
}
