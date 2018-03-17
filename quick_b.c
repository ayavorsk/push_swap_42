/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 22:26:44 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/28 22:26:46 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_median_2(t_snake *stack_a, int med, int top)
{
	int	i;

	i = TOP_A - top - 1;
	while (i < TOP_A + 1)
	{
		if (DATA_A[i] >= med)
			return (1);
		i++;
	}
	return (0);
}

static void		quick_sort_2_2(t_snake *stack_b, int top, int j)
{
	while (j > 0)
	{
		if (top / 2 == TOP_B + 1)
			break ;
		reverse_rv(stack_b, "rrb\n");
		j--;
	}
}

static void		quick_sort_2(t_snake *stack_a, t_snake *stack_b, int top)
{
	int	i;
	int	j;
	int	med;

	med = check_med(stack_b, top);
	i = 0;
	j = 0;
	while (i <= top)
	{
		if (check_median_2(stack_b, med, top) == 0)
			break ;
		if (DATA_B[TOP_B] < med)
		{
			rotate_ab(stack_b, "rb\n");
			j++;
		}
		if (DATA_B[TOP_B] >= med)
			push_ab(stack_b, stack_a, "pa\n");
		i++;
	}
	quick_sort_2_2(stack_b, top, j);
}

int				quick_b(t_snake *stack_a, t_snake *stack_b, int top)
{
	if (top > 2)
	{
		quick_sort_2(stack_a, stack_b, top);
		quick_a(stack_a, stack_b, top / 2 + (top % 2));
		quick_b(stack_a, stack_b, top / 2);
	}
	if (top <= 2)
	{
		if (top == 2 && DATA_B[TOP_B] < DATA_B[TOP_B - 1])
			swap_ab(stack_b, "sb\n");
		while (top > 0)
		{
			top--;
			push_ab(stack_b, stack_a, "pa\n");
		}
		return (1);
	}
	return (0);
}
