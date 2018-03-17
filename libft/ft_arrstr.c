/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:52:59 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/04 12:53:00 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	ft_arrstr(char **str)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (str != NULL && *str != NULL)
	{
		while (str[i] != NULL)
		{
			j = 0;
			while (str[i][j] != '\0')
			{
				write(1, &str[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}
