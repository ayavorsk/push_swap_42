/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:47:18 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/22 22:47:20 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			width_string_2(char c, t_param pf, int i)
{
	int l;

	l = 0;
	while (i < (pf.conversion == 'S'
		? pf.width - (pf.precision - 1) : pf.width - pf.precision))
	{
		write(pf.fd_pf, &c, 1);
		i++;
		l++;
	}
	return (l);
}

static int			width_string(char c, t_param pf, int len, int i)
{
	int l;

	l = 0;
	if (pf.conversion == 'S' && pf.width > 1
		&& pf.precision == 0 && pf.precinit == 1 && pf.flags[1] != ZERO)
		i--;
	if (pf.width > 1 && pf.conversion == 'S' && len == 1)
		len -= 1;
	if (pf.precision == 0 && pf.precinit == 1 && pf.width > 1)
		pf.width += len;
	if (pf.precision > 1 && (pf.precision < len
		|| (pf.conversion == 'S' && pf.precision < pf.width)))
		return (width_string_2(c, pf, i));
	else
		while ((i + (pf.conversion == 's' || (pf.conversion == 'S'
		&& ((pf.flags[1] == ZERO && pf.precision < 1)
			|| pf.flags[1] == MINUS)) ? 0 : 1)) < pf.width - len)
		{
			write(pf.fd_pf, &c, 1);
			i++;
			l++;
		}
	return (l);
}

static int			write_width(char c, t_param param, char *str)
{
	if (param.conversion == 'S' && (param.flags[1] == MINUS
		|| param.precinit == 0))
		return (width_string_3(c, param,
			count_wchar((wchar_t*)str, param, 1), 0));
	else if (param.conversion == 'S')
		return (width_string(c, param,
			count_wchar((wchar_t*)str, param, 0), 0));
	else
		return (width_string(c, param, ft_strlen(str), 0));
}

static int			ft_print_str(char *str,
			int end, int prec, t_param pf)
{
	int i;

	i = 0;
	if (pf.precision == 0 && pf.precinit == 1 && pf.width > 1)
		return (i);
	if ((pf.conversion == 'S' || (pf.conversion == 's'
	&& pf.modifier == LL)))
		return (ft_wchar_str((wchar_t*)str, pf));
	while (str[i] != '\0' && i <= end && i < prec)
	{
		write(pf.fd_pf, &str[i], 1);
		i++;
	}
	return (i);
}

int					ft_print_string(t_param pf, char *str)
{
	int		len;

	len = 0;
	if ((pf.flags[1] == ZERO) && (pf.width > 1))
		len += write_width('0', pf, str);
	else if (pf.flags[1] != ZERO && pf.width > 1 && pf.flags[1] != MINUS)
		len += write_width(' ', pf, str);
	else if (pf.flags[1] == ZERO &&
		pf.flags[1] != MINUS && pf.width > pf.precision)
		len += write_width(' ', pf, str);
	if (pf.precision > 0)
		len += ft_print_str(str, ft_strlen(str), pf.precision, pf);
	else
		len += ft_print_str(str, ft_strlen(str), ft_strlen(str), pf);
	if ((pf.flags[1] == MINUS) && pf.width > 1)
		len += write_width(' ', pf, str);
	return (len);
}
