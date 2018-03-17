/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:57:39 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/22 22:57:41 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			width_string_3(char c, t_param pf, int len, int i)
{
	int l;

	l = 0;
	while (i < pf.width - len)
	{
		write(pf.fd_pf, &c, 1);
		i++;
		l++;
	}
	return (l);
}

void		ft_put_wchar(t_param pf, unsigned char *ch_w, int size)
{
	int i;

	i = 0;
	while (i != size)
	{
		write(pf.fd_pf, &ch_w[i], 1);
		i++;
	}
}

char		ft_print_wchar(unsigned char *ch_w, wchar_t w_char, t_param pf)
{
	if (w_char < 0x07FF)
	{
		ch_w[0] = (((w_char & 0x07c0) >> 6) + 0xC0);
		ch_w[1] = (((w_char & 0x003F)) + 0x80);
		ft_put_wchar(pf, ch_w, 2);
		return (2);
	}
	else if (w_char < 0xFFFF)
	{
		ch_w[0] = (((w_char & 0xF000) >> 12) + 0xE0);
		ch_w[1] = (((w_char & 0x0FC0) >> 6) + 0x80);
		ch_w[2] = (((w_char & 0x003F)) + 0x80);
		ft_put_wchar(pf, ch_w, 3);
		return (3);
	}
	else
	{
		ch_w[0] = (((w_char & 0x1C0000) >> 18) + 0xF0);
		ch_w[1] = (((w_char & 0x03F000) >> 12) + 0x80);
		ch_w[2] = (((w_char & 0x0FC0) >> 6) + 0x80);
		ch_w[3] = (((w_char & 0x003F)) + 0x80);
		ft_put_wchar(pf, ch_w, 4);
		return (4);
	}
}

char		ft_putwchar(t_param pf, wchar_t w_char)
{
	unsigned char	ch_w[4];

	ft_bzero(ch_w, 4);
	if (w_char >= 0 && w_char <= 255)
	{
		write(pf.fd_pf, &w_char, 1);
		return (1);
	}
	else if (w_char > 255 && w_char < 0x10FFFF)
		return (ft_print_wchar(ch_w, w_char, pf));
	return (1);
}
