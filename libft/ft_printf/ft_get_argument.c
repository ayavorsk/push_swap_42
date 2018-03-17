/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:45 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/24 13:14:46 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_set_conversion(t_param *p, const char *str, size_t *i)
{
	if (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", str[*i]) != NULL)
	{
		p->conversion = str[*i];
		(*i)++;
	}
	else
	{
		p->error = 1;
		p->conversion = str[*i];
		(*i)++;
	}
	if (p->precision > p->width && p->conversion == 'S')
		p->width = 0;
	if (p->precstar == 3 && p->conversion == 'S' && p->precision > p->width)
		p->width -= 1;
}

static t_param	ft_upper_conversions(t_param param)
{
	if (param.conversion == 'O')
		param.modifier = LL;
	if (param.conversion == 'O')
		param.conversion = 'o';
	if (param.conversion == 'i')
		param.conversion = 'd';
	if (param.modifier == L)
		param.modifier = LL;
	if (param.conversion == 'U')
		param.modifier = LL;
	if (param.conversion == 'D')
		param.modifier = LL;
	if ((param.conversion == 'd' || param.conversion == 'D')
		&& param.flags[0] == HASH)
		param.flags[0] = NOTHING;
	if (param.conversion == 'p')
		param.width -= 2;
	return (param);
}

static t_param	ft_set_handles(t_param param, const char *str,
					size_t i, va_list list)
{
	char c;

	while (str[i] != '\0')
	{
		c = str[i];
		if (check_flag(c))
			ft_set_flags(&param, str, &i);
		else if (ft_isdigit(c) || str[i] == '*')
			ft_set_width(&param, str, &i, list);
		else if (str[i] == '.')
			ft_set_precision(&param, str, &i, list);
		else if (check_corect((char)c))
			ft_set_modifier(&param, str, &i);
		else
		{
			ft_set_conversion(&param, str, &i);
			break ;
		}
	}
	return (ft_upper_conversions(param));
}

t_param			ft_get_arg(const char *str, size_t len, va_list list)
{
	t_param			param;
	size_t			i;
	size_t			pos;

	i = 0;
	pos = 0;
	param.str = str;
	param.length = len;
	param.flags[0] = NOTHING;
	param.flags[1] = NOTHING;
	param.flags[2] = NOTHING;
	param.flags[3] = NOTHING;
	param.width = NOTHING;
	param.precision = NOTHING;
	param.modifier = NOTHING;
	param.conversion = 0;
	param.precinit = 0;
	param.error = 0;
	param.star = 0;
	param.precstar = 0;
	param.fd_pf = 1;
	param = ft_set_handles(param, str + 1, pos, list);
	return (param);
}

t_param			ft_fd_arg(const char *str, size_t len, va_list list, int fd)
{
	t_param			param;
	size_t			pos;

	pos = 0;
	param.str = str;
	param.length = len;
	param.flags[0] = NOTHING;
	param.flags[1] = NOTHING;
	param.flags[2] = NOTHING;
	param.flags[3] = NOTHING;
	param.width = NOTHING;
	param.precision = NOTHING;
	param.modifier = NOTHING;
	param.conversion = 0;
	param.precinit = 0;
	param.error = 0;
	param.star = 0;
	param.precstar = 0;
	param.fd_pf = fd;
	param = ft_set_handles(param, str + 1, pos, list);
	return (param);
}
