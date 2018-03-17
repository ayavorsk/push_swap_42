/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:00:21 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/27 17:00:22 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			swap_ab(t_snake *stack, char *str)
{
	int		tmp;

	if (TOP > 0)
	{
		tmp = DATA[TOP];
		DATA[TOP] = DATA[TOP - 1];
		DATA[TOP - 1] = tmp;
		if (str != NULL)
			OPT = ft_next(OPT, str);
	}
}

void			push_ab(t_snake *stack_a, t_snake *stack_b, char *str)
{
	if (TOP_A != EMPTY)
	{
		DATA_B[(TOP_B++) + 1] = DATA_A[TOP_A--];
		if (str != NULL)
			OPT_A = ft_next(OPT_A, str);
	}
}

void			rotate_ab(t_snake *stack, char *str)
{
	int		save;
	int		i;

	if (TOP <= 0)
		return ;
	i = TOP;
	save = DATA[TOP];
	while (i > 0)
	{
		DATA[i] = DATA[i - 1];
		i--;
	}
	DATA[0] = save;
	if (str != NULL)
		OPT = ft_next(OPT, str);
}

void			reverse_rv(t_snake *stack, char *str)
{
	int		i;
	int		save;

	if (DATA == NULL || TOP <= 0)
		return ;
	i = 0;
	save = DATA[0];
	while (i <= TOP)
	{
		DATA[i] = DATA[i + 1];
		i++;
	}
	DATA[TOP] = save;
	if (str != NULL)
		OPT = ft_next(OPT, str);
}
