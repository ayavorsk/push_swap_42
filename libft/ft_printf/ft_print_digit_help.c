/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:11:47 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/23 20:11:48 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_set_prec_2(t_param **pf, int *count, int n)
{
	if ((int)n < 0 && (*pf)->flags[1] == ZERO &&
	((*pf)->modifier == Z || (*pf)->modifier == LL) && (*pf)->width > (*count))
		(*count)++;
	if ((*count) >= (*pf)->width + (*pf)->precision)
		(*pf)->width = 0;
	if ((*pf)->width > (*count) &&
		(*pf)->precinit == 0 && (*pf)->flags[3] == ZERO)
	{
		(*count) = (*pf)->width - 1;
		(*pf)->width -= (*count);
	}
}

int			ft_set_prec(t_param **pf, int count, int n)
{
	if (count - 1 < (*pf)->precision)
	{
		count = (*pf)->precision;
		if ((*pf)->flags[2] == PLUS && (*pf)->precision > (*pf)->width)
			(*pf)->width -= (*pf)->precision - 1;
		else if ((*pf)->precision > (*pf)->width)
			(*pf)->width -= (*pf)->precision - 1;
		if (((*pf)->flags[1] == ZERO && n > 0)
			|| ((*pf)->flags[3] == ZERO && n < 0))
		{
			(*pf)->flags[1] = NOTHING;
			(*pf)->flags[3] = NOTHING;
		}
	}
	if ((*pf)->flags[1] == ZERO
		&& count < (*pf)->width - 1 && (*pf)->precinit == 0)
	{
		if (n < 0 || (*pf)->flags[2] == PLUS)
			count = (*pf)->width - 1;
		else
			count = (*pf)->width;
		(*pf)->width = 0;
	}
	return (count);
}

int			ft_integer_null(t_param pf, int nbr)
{
	if (pf.precision == 0 && nbr == 0 && pf.precinit == 0)
	{
		if (pf.flags[2] == SPACE && nbr == 0 && pf.width <= 1)
			return (ft_print_param(pf, ft_strdup(" 0")));
		if (pf.precinit == 1)
			return (ft_print_param(pf, ft_strdup(" ")));
		if (pf.flags[2] == PLUS)
		{
			pf.width -= 1;
			return (ft_print_param(pf, ft_strdup("+0")));
		}
		return (ft_print_param(pf, ft_strdup("0")));
	}
	if (pf.precision == 0 && nbr == 0 && pf.flags[1] == NOTHING
		&& pf.modifier == NOTHING && pf.flags[2] == NOTHING && pf.width < 1)
		return (ft_print_param(pf, ft_strdup("")));
	else if (pf.precision == 0 && nbr == 0 && pf.flags[1] == NOTHING
		&& pf.modifier == NOTHING && pf.flags[2] == NOTHING && pf.width > 1)
		return (ft_print_param(pf, ft_strdup(" ")));
	return (0);
}
