/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 15:10:15 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/25 15:10:15 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_arrlen(char **array)
{
	size_t i;

	i = 0;
	if (array != NULL && *array != NULL)
	{
		while (array[i] != NULL)
			i++;
		return (i);
	}
	return (0);
}
