/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 22:26:36 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/28 22:26:37 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_median_1(t_snake *stack_a, int med, int top)
{
	int	i;

	i = TOP_A - top - 1;
	while (i < TOP_A + 1)
	{
		if (DATA_A[i] < med)
			return (1);
		i++;
	}
	return (0);
}

static void		quick_sort_1_1(t_snake *stack_a, int top, int j)
{
	while (j > 0)
	{
		if ((top / 2 + top % 2) == TOP_A + 1)
			break ;
		reverse_rv(stack_a, "rra\n");
		j--;
	}
}

static void		quick_sort_1(t_snake *stack_a, t_snake *stack_b, int top)
{
	int	i;
	int	j;
	int	med;

	med = check_med(stack_a, top);
	i = 0;
	j = 0;
	while (i < top)
	{
		if (check_median_1(stack_a, med, top) == 0)
			break ;
		if (DATA_A[TOP_A] >= med)
		{
			rotate_ab(stack_a, "ra\n");
			j++;
		}
		else
			push_ab(stack_a, stack_b, "pb\n");
		i++;
	}
	quick_sort_1_1(stack_a, top, j);
}

int				quick_a(t_snake *stack_a, t_snake *stack_b, int top)
{
	if (top > 2)
	{
		quick_sort_1(stack_a, stack_b, top);
		quick_a(stack_a, stack_b, top / 2 + (top % 2));
		quick_b(stack_a, stack_b, top / 2);
		return (0);
	}
	if (top <= 2)
	{
		if (top == 2 && DATA_A[TOP_A] > DATA_A[TOP_A - 1])
			swap_ab(stack_a, "sa\n");
		return (1);
	}
	return (0);
}
