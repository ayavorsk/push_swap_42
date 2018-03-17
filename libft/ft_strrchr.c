/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:13:06 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/25 20:15:54 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int symbol)
{
	int		i;

	i = ft_strlen((char*)string);
	while (string[i] != (char)symbol && 0 != i)
		i--;
	if (string[i] == (char)symbol)
		return ((char*)&string[i]);
	return (NULL);
}
