/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 21:10:43 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/23 21:10:45 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char			*ft_digit_str(int count, char sign, char neg, uintmax_t v)
{
	char		*str;
	char		*dig;

	dig = BASE_10;
	str = ft_memalloc(count + 1);
	str[count + 1] = '\0';
	if (sign != '/')
		str[0] = sign;
	while (count > 0)
	{
		str[count + neg - 1] = dig[v % 10];
		count--;
		v /= 10;
	}
	return (str);
}

char				*ft_digit(intmax_t n, t_param *pf, char sign)
{
	int			count;
	uintmax_t	nbr;
	char		neg;

	count = 0;
	nbr = ABS(n);
	neg = (n < 0 || sign != '/' ? 1 : 0);
	if ((pf)->precinit == 1 && ((pf)->width - (pf)->precision) < count
		&& (pf)->width > (pf)->precision && (pf)->precision < count)
	{
		count = base_count(nbr, 10);
		(pf)->width = (count > (pf)->width ? count : (pf)->width);
	}
	else
		count = ft_set_prec(&pf, base_count(nbr, 10), n);
	ft_set_prec_2(&pf, &count, n);
	if (n < 0)
	{
		if ((pf)->precstar == 2)
			count--;
		sign = '-';
	}
	return (ft_digit_str(count, sign, neg, nbr));
}

int					ft_print_integer(t_param pf, intmax_t nbr)
{
	char			*str;
	int				count;

	count = 0;
	if (pf.precision == 0 && nbr == 0 && (pf.width < 1
		|| (pf.precision == 0 && pf.precinit == 1)))
		return (ft_integer_null(pf, nbr));
	if (pf.flags[2] == PLUS)
		str = ft_digit(nbr, &pf, '+');
	else if (pf.flags[2] == SPACE)
		str = ft_digit(nbr, &pf, ' ');
	else
		str = ft_digit(nbr, &pf, '/');
	if (ft_strlen(str) >= pf.precision && pf.precinit == 1 && pf.flags[1] != 9)
		pf.flags[1] = NOTHING;
	if (pf.width >= ft_strlen(str))
		pf.width -= ft_strlen(str) - 1;
	else if (pf.width <= ft_strlen(str))
		pf.width -= ft_strlen(str) - 1;
	if (pf.flags[1] == ZERO && (pf.precision == 0 || pf.precision == -1))
	{
		pf.flags[1] = NOTHING;
		return (ft_print_param(pf, str));
	}
	return (ft_print_param(pf, str));
}
