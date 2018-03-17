/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 20:22:20 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/27 20:22:22 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			revers_arr(t_snake *stack)
{
	int i;

	i = 0;
	while (i < TOP)
	{
		if (DATA[i] > DATA[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			sorted_arr(t_snake *stack)
{
	int i;

	i = TOP;
	while (i > 0)
	{
		if (DATA[i] > DATA[i - 1] && (i - 1) >= -1)
			return (0);
		i--;
	}
	return (1);
}
