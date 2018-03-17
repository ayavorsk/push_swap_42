/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:38:57 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/24 13:38:58 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

int		ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}

void	*ft_memalloc(size_t size)
{
	void *lloc;

	lloc = malloc(size);
	if (lloc == NULL)
		return (NULL);
	ft_bzero(lloc, size);
	return (lloc);
}

char	*ft_strchr(const char *string, int symbol)
{
	size_t		i;

	i = 0;
	while (string[i] != (char)symbol && string[i] != '\0')
		i++;
	if (string[i] == (char)symbol)
		return ((char*)&string[i]);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	size_t		i;
	size_t		len;
	char		*dup;

	len = ft_strlen(str);
	dup = (char*)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
