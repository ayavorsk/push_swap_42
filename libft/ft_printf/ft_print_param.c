/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:42:56 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/23 13:42:56 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			write_hash(t_param *pf)
{
	int len;

	len = 0;
	if (pf->flags[0] != HASH && pf->conversion != 'p')
		return (len);
	if (pf->conversion == 'p')
	{
		len += ft_pf_write("0x", 0, 5);
		pf->conversion = NOTHING;
	}
	if (pf->conversion == 'x' || pf->conversion == 'X'
	|| pf->conversion == 'd' || (pf->conversion == '0' && pf->flags[0] == HASH))
	{
		if (pf->conversion == 'X')
			len += ft_pf_write("0X", 0, 2);
		else
			len += ft_pf_write("0x", 0, 2);
	}
	if (pf->conversion == 'o')
	{
		pf->conversion = NOTHING;
		len += ft_pf_write("0", 0, 1);
	}
	return (len);
}

int					ft_print_str(t_param pf, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(pf.fd_pf, &str[i], 1);
		i++;
	}
	if (str != NULL)
		free((void*)str);
	return (i);
}

static int			write_width(char c, t_param pf, char *str)
{
	int i;
	int len;

	i = 1;
	len = 0;
	if ((pf.conversion == 'p' && str[0] == '0')
		&& pf.flags[1] != MINUS && pf.flags[1] == ZERO)
		len += write_hash(&pf);
	if (pf.width > 0)
	{
		while (i < pf.width)
		{
			write(pf.fd_pf, &c, 1);
			i++;
			len++;
		}
	}
	if ((pf.conversion == 'p' || pf.flags[0] == HASH) && pf.flags[1] != MINUS)
		len += write_hash(&pf);
	return (len);
}

int					ft_print_param(t_param pf, char *str)
{
	int	len;

	len = 0;
	if ((pf.flags[1] == ZERO) && (pf.width > 1))
		len += write_width('0', pf, str);
	else if (pf.flags[1] != ZERO && pf.width > 1 && pf.flags[1] != MINUS)
		len += write_width(' ', pf, str);
	else if (pf.flags[1] == ZERO
		&& pf.flags[1] != MINUS && pf.width > pf.precision)
		len += write_width(' ', pf, str);
	if ((pf.conversion == 'p' || pf.flags[0] == HASH) && pf.width < 1)
		len += write_hash(&pf);
	if ((pf.conversion == 'p' ||
		pf.flags[0] == HASH) && (pf.flags[1] == MINUS || pf.width == 0))
		len += write_hash(&pf);
	if (str != NULL)
		len += ft_print_str(pf, str);
	if ((pf.flags[1] == MINUS) && pf.width > 1)
		len += write_width(' ', pf, str);
	return (len);
}
