/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:59:09 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/22 22:59:10 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t					count_wchar(wchar_t *wstr, t_param param, int what)
{
	size_t			i;
	int				count;
	int				add;

	i = 0;
	add = 0;
	count = 0;
	while (wstr[i] != '\0')
	{
		if (wstr[i] <= 0x7F)
			add = 1;
		else if (wstr[i] <= 0x7FF)
			add = 2;
		else if (wstr[i] <= 0xFFFF)
			add = 3;
		else if (wstr[i] <= 0x10FFFF)
			add = 4;
		if ((count + add) > param.precision
			&& param.precinit == 1)
			break ;
		count += add;
		i++;
	}
	return ((what == 1 ? count : i));
}

static char				ft_putwstr(t_param pf, wchar_t w_char)
{
	unsigned char	ch_w[4];

	ft_bzero(ch_w, 4);
	if (w_char >= 0 && w_char <= 0x7F)
	{
		ft_put_wchar(pf, (unsigned char *)&w_char, 1);
		return (1);
	}
	else if (w_char > 0x7F && w_char < 0x10FFFF)
		return (ft_print_wchar(ch_w, w_char, pf));
	return (0);
}

int						ft_wchar_str(wchar_t *wstr, t_param pf)
{
	int i;
	int size;

	size = count_wchar(wstr, pf, 0);
	i = 0;
	while (wstr[i] != '\0' && i < size)
	{
		ft_putwstr(pf, wstr[i]);
		i++;
	}
	return (count_wchar(wstr, pf, 1));
}
