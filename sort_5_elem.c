/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 16:08:31 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/13 16:08:33 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_min(t_snake *stack)
{
	int		i;
	int		nbr;
	int		j;

	i = TOP;
	nbr = DATA[TOP];
	j = i;
	while (i >= 0)
	{
		if (nbr > DATA[i])
		{
			nbr = DATA[i];
			j = i;
		}
		i--;
	}
	return (j);
}

static void		fimd_min_v_2(t_snake *stack_a, t_snake *stack_b)
{
	if (find_min(stack_a) < (TOP_A / 2))
		reverse_rv(stack_a, "rra\n");
	else if (find_min(stack_a) > (TOP_A / 2))
		rotate_ab(stack_a, "ra\n");
	else
	{
		while (find_min(stack_a) != TOP_A)
			rotate_ab(stack_a, "ra\n");
		if (sorted_arr(stack_a) != 1)
			push_ab(stack_a, stack_b, "pb\n");
	}
}

int				sort_5_elem(t_snake *stack_a, t_snake *stack_b)
{
	while (TOP_A != 2 && sorted_arr(stack_a) == 0)
	{
		if (find_min(stack_a) == TOP_A)
			push_ab(stack_a, stack_b, "pb\n");
		else if (find_min(stack_a) == 0)
		{
			reverse_rv(stack_a, "rra\n");
			push_ab(stack_a, stack_b, "pb\n");
		}
		else if (find_min(stack_a) == TOP_A - 1)
		{
			swap_ab(stack_a, "sa\n");
			push_ab(stack_a, stack_b, "pb\n");
		}
		else
			fimd_min_v_2(stack_a, stack_b);
	}
	mini_sort(stack_a);
	while (TOP_B >= 0)
		push_ab(stack_b, stack_a, "pa\n");
	return (1);
}
