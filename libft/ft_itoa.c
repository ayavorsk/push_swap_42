/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:06:53 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/30 17:06:53 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_len(int n)
{
	size_t		i;

	i = 1;
	if (n < 0)
		i++;
	n /= 10;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char		*str;
	long int	nbr;
	size_t		len;

	len = get_len(n);
	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	str[--len] = (nbr % 10) + '0';
	while (nbr > 0)
	{
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
