/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:13:50 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/28 22:13:51 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*map;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	if ((map = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		map[i] = f(i, (char)s[i]);
		i++;
	}
	return (map);
}
