/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:56:26 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/25 19:56:27 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

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
