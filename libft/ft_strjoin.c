/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:41:45 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/29 18:41:45 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if ((char*)s1 == NULL || (char*)s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strcat(ft_strcpy(str, s1), s2);
	str[len] = '\0';
	return (str);
}
