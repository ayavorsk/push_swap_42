/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:53:31 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/25 19:53:32 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		t;

	k = ft_strlen(s1);
	j = ft_strlen(s2);
	i = 0;
	t = 0;
	if (len <= k)
		return (j + len);
	while (i < (len - 1) && s1[i] != '\0')
		i++;
	while (s2[t] != '\0' && i < (len - 1))
	{
		s1[i] = s2[t];
		i++;
		t++;
	}
	s1[i] = '\0';
	return (j + k);
}
