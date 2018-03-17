/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:40:49 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/23 17:40:57 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_set_modifier(t_param *param, const char *str, size_t *i)
{
	while (check_corect(str[*i]) != 0)
	{
		if (str[*i] == 'h' && param->modifier == NOTHING)
		{
			param->modifier = H;
			if (str[*i + 1] == 'h')
			{
				param->modifier = HH;
				(*i)++;
			}
		}
		else if (str[*i] == 'j')
			param->modifier = J;
		else if (str[*i] == 'z')
			param->modifier = Z;
		else if (str[*i] == 'l' || str[*i] == 't')
		{
			if (str[*i + 1] == 'l')
				++(*i);
			param->modifier = L;
		}
		(*i)++;
	}
	return (0);
}

int				ft_set_width(t_param *param, const char *str,
				size_t *i, va_list list)
{
	if (str[*i] == '*')
	{
		param->width = va_arg(list, int);
		if (param->width <= 0)
		{
			param->width *= -1;
			param->flags[1] = MINUS;
			param->star = 1;
		}
		(*i)++;
		return (0);
	}
	param->width = ft_atoi_printf(str, i);
	if (param->star == 1)
		param->flags[1] = NOTHING;
	return (0);
}

static void		ft_set_space(t_param **pf)
{
	if ((*pf)->flags[0] != NOTHING)
		(*pf)->flags[0] = NOTHING;
	if ((*pf)->flags[1] == ZERO)
		(*pf)->flags[1] = NOTHING;
	(*pf)->flags[2] = SPACE;
}

int				ft_set_flags(t_param *pf, const char *str, size_t *i)
{
	char c;

	while ((*i) < pf->length)
	{
		c = str[*i];
		if (check_flag(c))
		{
			if (c == '#' && pf->flags[2] != SPACE)
				pf->flags[0] = HASH;
			if (c == '0' && pf->flags[1] != MINUS && pf->flags[2] != SPACE)
				pf->flags[1] = ZERO;
			if (c == '-')
				pf->flags[1] = MINUS;
			if (c == ' ' && pf->flags[2] == NOTHING)
				ft_set_space(&pf);
			if (c == '+')
				pf->flags[2] = PLUS;
			if (c == '0' && pf->flags[2] == SPACE)
				pf->flags[3] = ZERO;
		}
		else
			return (0);
		(*i)++;
	}
	return (1);
}
