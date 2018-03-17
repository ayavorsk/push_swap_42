/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:56:53 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/07 15:56:55 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		*ft_next(char *s1, char *s2)
{
	char	*str;
	char	*tmp;
	size_t	len;

	tmp = s1;
	if ((char*)s1 == NULL || (char*)s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(len + 1);
	if (str == NULL)
		return (NULL);
	ft_strcat(ft_strcpy(str, s1), s2);
	str[len] = '\0';
	free(tmp);
	return (str);
}
