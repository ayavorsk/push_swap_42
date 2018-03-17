/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:41:04 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/26 19:41:04 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *sour, size_t n)
{
	unsigned char	*s1;
	unsigned char	*d1;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)sour;
	d1 = (unsigned char *)dest;
	if (s1 < d1)
	{
		n--;
		while ((int)(n) >= 0)
		{
			d1[n] = s1[n];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			d1[i] = s1[i];
			i++;
		}
	}
	return (d1);
}
