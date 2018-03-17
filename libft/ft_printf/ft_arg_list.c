/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:07:04 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/23 14:07:06 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t					ft_get_signed_nbr(t_param param, va_list list)
{
	intmax_t		nbr;

	if (param.modifier == J)
		nbr = va_arg(list, intmax_t);
	else if (param.modifier == Z)
		nbr = va_arg(list, ssize_t);
	else if (param.modifier == L)
		nbr = va_arg(list, long);
	else if (param.modifier == LL)
		nbr = va_arg(list, long long);
	else
		nbr = va_arg(list, int);
	if (param.modifier == H)
		nbr = (short)nbr;
	else if (param.modifier == HH)
		nbr = (char)nbr;
	return (nbr);
}

intmax_t					ft_get_unsigned_nbr(t_param param, va_list list)
{
	intmax_t n;

	if (param.modifier == L)
		n = va_arg(list, unsigned long);
	else if (param.modifier == LL)
		n = va_arg(list, unsigned long long);
	else if (param.modifier == J)
		n = va_arg(list, uintmax_t);
	else if (param.modifier == Z)
		n = va_arg(list, size_t);
	else
		n = va_arg(list, unsigned int);
	if (param.modifier == HH)
		n = (unsigned char)n;
	else if (param.modifier == H)
		n = (unsigned short)n;
	return (n);
}
