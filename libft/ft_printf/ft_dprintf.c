/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:29:12 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/25 15:29:33 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_fd_write(const char *str, int start, int end, int fd)
{
	int len;

	len = 0;
	if (str[start] != '%')
	{
		while (str[start] != '\0' && start <= end)
		{
			write(fd, &str[start], 1);
			start++;
			len++;
		}
	}
	return (len);
}

static int		ft_parse_fd(const char *str, va_list l, int fd)
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
				result += ft_print_arg(ft_fd_arg(str + ptr, i - ptr, l, fd), l);
			else
				result += ft_p_char(ft_fd_arg(str + ptr, i - ptr, l, fd), l);
		}
		else
		{
			while (str[i] != '\0' && str[i] != '%')
				i++;
			result += ft_fd_write(str, ptr, i - 1, fd);
		}
	}
	return (result);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list	list;
	int		result;

	result = 0;
	if (format != NULL)
	{
		va_start(list, format);
		result = ft_parse_fd(format, list, fd);
		va_end(list);
	}
	return (result);
}
