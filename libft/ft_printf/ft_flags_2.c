/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:30:48 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/23 17:30:49 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_set_prec_star(t_param **pf, char c, va_list list)
{
	if (c == '*')
	{
		(*pf)->precision = va_arg(list, int);
		if ((*pf)->precision == 0)
			(*pf)->precstar = 1;
		if ((*pf)->precision < 0)
		{
			(*pf)->precstar = 2;
			(*pf)->precision = (*pf)->width;
		}
	}
	else if ((*pf)->precision < 0)
	{
		(*pf)->flags[1] = MINUS;
		(*pf)->width = ABS((*pf)->precision);
		(*pf)->precision = 0;
		(*pf)->precstar = 3;
	}
	return (1);
}

int				ft_set_precision(t_param *pf,
							const char *str, size_t *i, va_list list)
{
	int precision;

	precision = -2;
	if (str[*i] == '.')
	{
		pf->precinit = 1;
		(*i)++;
	}
	else
	{
		pf->precision = precision;
		return (0);
	}
	pf->precision = 0;
	if (str[*i] == '*')
	{
		(*i)++;
		return (ft_set_prec_star(&pf, '*', list));
	}
	if ((precision = ft_atoi_printf(str, i)) == 0)
		return (0);
	else
		pf->precision = precision;
	return (ft_set_prec_star(&pf, ' ', list));
}
