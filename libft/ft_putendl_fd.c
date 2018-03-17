/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:50:11 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/27 20:50:11 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			write(fd, s++, 1);
		write(fd, "\n", 1);
	}
}
