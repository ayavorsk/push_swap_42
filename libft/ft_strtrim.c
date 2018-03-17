/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:02:56 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/29 19:02:56 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_space(const char *str)
{
	if (*str == '\n' || *str == '\t' || *str == ' ')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((is_space(&s[i])) == 1)
		i++;
	if (s[i] == '\0')
	{
		str = ft_strdup("");
		return (str);
	}
	len = ft_strlen(s) - 1;
	while (is_space(&s[len]) == 1)
		len--;
	len -= i;
	str = ft_strsub(s, i, len + 1);
	return (str);
}
