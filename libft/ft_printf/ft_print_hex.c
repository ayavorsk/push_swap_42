/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:43:32 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/22 22:43:33 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int					ft_hex_null(t_param pf)
{
	if (pf.conversion != 'o' || (pf.conversion == 'o'
		&& pf.flags[0] == HASH && pf.precinit == 0))
		pf.flags[0] = NOTHING;
	if (pf.precinit == 1 && pf.width > 1)
		return (ft_print_param(pf, ft_strdup(" ")));
	else if (pf.precinit == 1 && pf.conversion == 'o')
		return (ft_print_param(pf, ft_strdup("")));
	else if (pf.precinit == 1)
		return (ft_print_param(pf, ft_strdup("")));
	else if (pf.width > 1 && pf.conversion != 'p')
		return (ft_print_param(pf, ft_strdup(" ")));
	else
		return (ft_print_param(pf, ft_strdup("0")));
	return (0);
}

static int			ft_set_p(t_param **param, int count)
{
	if ((*param)->flags[1] == ZERO && (*param)->precision < count
		&& (*param)->flags[0] == HASH && (*param)->conversion != 'p')
	{
		count = (*param)->width - 2;
		(*param)->width = 0;
	}
	if ((*param)->precision <= count)
	{
		(*param)->width -= count - 1;
		(*param)->precision = 0;
	}
	if ((*param)->precision >= count)
	{
		count = (*param)->precision;
		(*param)->width -= (*param)->precision - 1;
	}
	if ((*param)->conversion == 'o' && (*param)->flags[0] == HASH)
		(*param)->width -= 1;
	else if ((*param)->flags[0] == HASH && (*param)->conversion != 'p')
		(*param)->width -= 2;
	return (count);
}

static char			*hex_itoa(uintmax_t n, unsigned int base,
						const char *dig, t_param *param)
{
	int			count;
	char		*str;

	count = base_count(n, base);
	if (param->conversion == 'o' && param->flags[0] == HASH
		&& param->precision > count)
	{
		param->flags[0] = NOTHING;
		param->conversion = 'x';
	}
	count = ft_set_p(&param, count);
	str = ft_memalloc(count + 1);
	if (str == NULL)
		return (NULL);
	while (count > 0)
	{
		str[count - 1] = dig[n % base];
		count--;
		n /= base;
	}
	return (str);
}

int					ft_print_hex(t_param pf, int base, uintmax_t n)
{
	char			*str;
	int				count;

	count = 0;
	str = ft_memalloc(1);
	if ((pf.precision == 0 && n == 0) || (n == 0 && pf.conversion == 'o'
				&& (pf.flags[0] == HASH)))
		str = NULL;
	else
		free(str);
	if (pf.conversion == 'X' && str != NULL)
		str = hex_itoa(n, base, BASE_16_UPPER, &pf);
	else if (str != NULL || (pf.conversion == 'p' && str != NULL))
		str = hex_itoa(n, base, BASE_16_LOWER, &pf);
	if (str != NULL)
		count += ft_print_param(pf, str);
	else
		count += ft_hex_null(pf);
	return (count);
}
