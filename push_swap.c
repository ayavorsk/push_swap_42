/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:13:31 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/26 19:13:32 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		reverse_sort(t_snake *stack_a, t_snake *stack_b)
{
	while (TOP_A > 0)
	{
		reverse_rv(stack_a, "rra\n");
		push_ab(stack_a, stack_b, "pb\n");
	}
	swap_ab(stack_a, "sa\n");
	while (TOP_B >= 0)
		push_ab(stack_b, stack_a, "pa\n");
	return (1);
}

int				main(int ac, char **av)
{
	t_snake			*stack_a;
	t_snake			*stack_b;
	t_opt			opt;

	if (ft_check_av(ac, av) == 0)
		return (0);
	stack_a = stack_int(ac, av, 'a');
	stack_b = stack_int(ac, av, 'b');
	if (sorted_arr(stack_a) == 1)
		return (1);
	opt.str = ft_strdup("\0");
	stack_a->op = &opt;
	stack_b->op = &opt;
	if (TOP_A < 3)
		mini_sort(stack_a);
	else if (TOP_A < 6)
		sort_5_elem(stack_a, stack_b);
	else if (revers_arr(stack_a) == 1)
		reverse_sort(stack_a, stack_b);
	else
		quick_a(stack_a, stack_b, TOP_A + 1);
	print_operations(stack_a, stack_b);
	ft_all_free(stack_a, stack_b, opt);
	return (0);
}
