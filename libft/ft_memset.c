/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:58:50 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/26 14:58:50 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *memptr, int val, size_t num)
{
	size_t			i;
	unsigned char	*str;

	str = memptr;
	i = 0;
	while (i < num)
	{
		str[i] = val;
		i++;
	}
	return (memptr);
}
