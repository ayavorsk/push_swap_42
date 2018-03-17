/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:50:45 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/07 14:50:46 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			mini_sort_part_2(t_snake *stack_a)
{
	if (DATA_A[TOP_A] > DATA_A[TOP_A - 1]
		&& DATA_A[TOP_A - 1] < DATA_A[0] && DATA_A[TOP_A] > DATA_A[0])
	{
		rotate_ab(stack_a, "ra\n");
		return (1);
	}
	else if (DATA_A[TOP_A] < DATA_A[TOP_A - 1]
		&& DATA_A[TOP_A - 1] > DATA_A[0] && DATA_A[0] > DATA_A[TOP_A])
	{
		swap_ab(stack_a, "sa\n");
		rotate_ab(stack_a, "ra\n");
		return (1);
	}
	else if (DATA_A[TOP_A] < DATA_A[TOP_A - 1] && DATA_A[TOP_A] > DATA_A[0])
	{
		reverse_rv(stack_a, "rra\n");
		return (1);
	}
	return (0);
}

int					mini_sort(t_snake *stack_a)
{
	if (TOP_A == 1)
	{
		swap_ab(stack_a, "sa\n");
		return (1);
	}
	if (DATA_A[TOP_A] > DATA_A[TOP_A - 1]
		&& DATA_A[TOP_A - 1] < DATA_A[0] && DATA_A[TOP_A] < DATA_A[0])
	{
		swap_ab(stack_a, "sa\n");
		return (1);
	}
	else if (DATA_A[TOP_A] > DATA_A[TOP_A - 1]
		&& DATA_A[TOP_A - 1] > DATA_A[0])
	{
		swap_ab(stack_a, "sa\n");
		reverse_rv(stack_a, "rra\n");
		return (1);
	}
	return (mini_sort_part_2(stack_a));
}
