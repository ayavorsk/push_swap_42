/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:49:19 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/22 22:49:21 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char					*str_null(char *str, t_param *param)
{
	if (((wchar_t*)str == NULL || str[0] == '(') && param->conversion == 'S')
	{
		param->conversion = 's';
		return ("(null)");
	}
	if (param->precstar == 1)
		return ("");
	if (param->precstar == 1 || str == NULL)
		return ("(null)");
	if (str == NULL && param->width > 1)
		return ("0");
	else
		return (str);
}

int						ft_print_arg(t_param param, va_list list)
{
	if (param.conversion == 's' || param.conversion == 'S')
		return (ft_print_string(param, str_null(va_arg(list, char *), &param)));
	else if (param.conversion == 'c' || param.conversion == 'C')
		return (ft_p_char(param, list));
	else if (param.conversion == '%')
		return (ft_p_char(param, list));
	else if (param.conversion == 'x' || param.conversion == 'X')
		return (ft_print_hex(param, 16, ft_get_unsigned_nbr(param, list)));
	else if (param.conversion == 'o')
		return (ft_print_hex(param, 8, ft_get_unsigned_nbr(param, list)));
	else if (param.conversion == 'U' || param.conversion == 'u')
		return (ft_print_hex(param, 10, ft_get_unsigned_nbr(param, list)));
	else if (param.conversion == 'p')
		return (ft_print_hex(param, 16, (uintmax_t)va_arg(list, void*)));
	else if (param.conversion == 'd' || param.conversion == 'D')
		return (ft_print_integer(param, ft_get_signed_nbr(param, list)));
	return (0);
}

static int				ft_parse_argument(const char *str, va_list l)
{
	size_t			i;
	size_t			ptr;
	int				result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		ptr = i;
		if (str[i] == '%')
		{
			i++;
			if (ft_is_valid(str, &i))
				result += ft_print_arg(ft_get_arg(str + ptr, i - ptr, l), l);
			else
				result += ft_p_char(ft_get_arg(str + ptr, i - ptr, l), l);
		}
		else
		{
			while (str[i] != '\0' && str[i] != '%')
				i++;
			result += ft_pf_write(str, ptr, i - 1);
		}
	}
	return (result);
}

int						ft_printf(const char *format, ...)
{
	va_list	list;
	int		result;

	result = 0;
	if (format != NULL)
	{
		va_start(list, format);
		result = ft_parse_argument(format, list);
		va_end(list);
	}
	return (result);
}
