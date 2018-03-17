/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:46:14 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/29 19:46:15 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_ch(char *str, char c)
{
	size_t tab;
	size_t i;

	tab = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			if (str[i + 1] != c)
				tab++;
		}
		i++;
	}
	return (tab);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**wd;
	size_t		i;
	size_t		j;
	size_t		word;

	if (s == NULL)
		return (NULL);
	if ((wd = (char**)malloc(sizeof(char*) * (ft_ch((char*)s, c) + 2))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
		if (s[i] == c)
			i++;
		else
		{
			word = 0;
			while (s[i + word] != '\0' && (s[i + word] != c))
				word++;
			wd[j++] = ft_strsub(s, i, word);
			i = i + word;
		}
	wd[j] = NULL;
	return (wd);
}
