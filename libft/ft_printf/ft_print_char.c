/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:42:07 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/22 22:42:08 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			write_width(char c, int width)
{
	int i;

	i = 0;
	while (i < width)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int					ft_p_char(t_param param, va_list list)
{
	int		len;

	len = 0;
	if (param.conversion == 0)
		return (len);
	if ((param.flags[1] == ZERO) && (param.width > 1))
		len += write_width('0', param.width - 1);
	else if ((param.flags[1] != ZERO) && (param.width > 1)
			&& (param.flags[1] != MINUS))
		len += write_width(' ', param.width - 1);
	if (param.error == 1)
		len += write_width(param.conversion, 1);
	else if (param.conversion == '%')
		len += write_width('%', 1);
	else if (param.modifier == LL || param.conversion == 'C')
	{
		len += ft_putwchar(param, va_arg(list, wchar_t));
	}
	else
		len += write_width(va_arg(list, int), 1);
	if ((param.flags[1] == MINUS) && param.width > 1)
		len += write_width(' ', param.width - 1);
	return (len);
}
