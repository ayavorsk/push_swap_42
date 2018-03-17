/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:18:58 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/26 15:18:59 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)destination;
	s2 = (unsigned char *)source;
	if (n == 0 || s1 == s2)
		return (destination);
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (destination);
}
