/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 22:32:41 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/26 22:32:41 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;
	size_t l;

	i = 0;
	if (*s2 == '\0')
		return ((char*)s1);
	l = ft_strlen(s2);
	while (s1[i] != '\0' && (i + l) <= len)
	{
		j = 0;
		while (s2[j] == s1[i + j] && i < len)
		{
			if (s2[j + 1] == '\0')
				return ((char*)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
