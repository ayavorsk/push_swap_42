/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 20:04:49 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/28 20:04:50 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			check_med_2(int nb, int nbr, int *med)
{
	if (nb != nbr)
	{
		if (nbr > nb)
			(*med)++;
		else
			(*med)--;
	}
}

static int			check(int med, int nbelem)
{
	int elem;

	elem = nbelem % 2;
	if (elem == 0)
	{
		if (med == -1)
			return (1);
		return (0);
	}
	else if (med == 0)
		return (1);
	else
		return (0);
}

int					check_med(t_snake *stack_a, int nbelem)
{
	int	i;
	int	j;
	int	nb;
	int	med;

	j = TOP_A - nbelem + 1;
	while (j < TOP_A + 1)
	{
		med = 0;
		i = TOP_A - nbelem + 1;
		nb = DATA_A[j];
		while (i < TOP_A + 1)
		{
			check_med_2(nb, DATA_A[i], &med);
			i++;
		}
		if (check(med, nbelem) == 1)
			return (DATA_A[j]);
		j++;
	}
	return (0);
}
