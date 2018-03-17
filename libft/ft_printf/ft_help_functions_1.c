/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:40:02 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/22 22:40:03 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t					base_count(uintmax_t n, unsigned int base)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= base;
	}
	return (i);
}

inline int				ft_atoi_printf(const char *str, size_t *i)
{
	long	nbr;
	int		neg;

	neg = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			neg = -1;
		(*i)++;
	}
	nbr = 0;
	while (ft_isdigit(str[*i]))
	{
		nbr = nbr * 10 + (str[*i] - '0');
		(*i)++;
	}
	if (neg != 0)
		nbr *= neg;
	return (nbr);
}

int						check_corect(const char c)
{
	if ((ft_strchr("htljz", c)) != NULL)
		return (1);
	else
		return (0);
}

int						check_flag(char c)
{
	if (ft_strchr("#0-+' ", c) != NULL)
		return (1);
	else
		return (0);
}

int						ft_pf_write(const char *str, int start, int end)
{
	int len;

	len = 0;
	if (str[start] != '%')
	{
		while (str[start] != '\0' && start <= end)
		{
			write(1, &str[start], 1);
			start++;
			len++;
		}
	}
	return (len);
}
