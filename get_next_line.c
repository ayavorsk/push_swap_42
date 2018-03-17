/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <ayavorsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:15:56 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/11/16 22:16:28 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

static int		ft_read(const int fd, char **next)
{
	char	buff[BUFF_SIZE + 1];
	int		fr;

	while ((fr = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[fr] = '\0';
		if ((next[fd] = ft_next(next[fd], buff)) == NULL)
			return (-1);
		if (buff[fr - 1] == '\n')
			break ;
	}
	return (fr);
}

static	int		ft_check_error(const int fd, char **line)
{
	if (fd < 0 || fd > MAX_FD)
		return (-1);
	if (BUFF_SIZE <= 0)
		return (-1);
	if (line == NULL)
		return (-1);
	return (1);
}

static int		ft_in_line(const int fd, char **next, char **line)
{
	int		i;
	char	*save;

	i = 0;
	while (next[fd][i] != '\n' && next[fd][i] != '\0')
		i++;
	if (((*line) = ft_strsub(next[fd], 0, i)) == NULL)
	{
		free(next[fd]);
		return (-1);
	}
	if ((save = ft_strdup(&next[fd][i + 1])) == NULL)
	{
		free(next[fd]);
		return (-1);
	}
	ft_bzero(next[fd], ft_strlen(next[fd]) + 1);
	if ((next[fd] = ft_next(next[fd], save)) == NULL)
	{
		free(save);
		return (-1);
	}
	free(save);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char *next[MAX_FD];

	if (ft_check_error(fd, line) == -1)
		return (-1);
	if (next[fd] == NULL)
		if (((next[fd] = ft_strnew(BUFF_SIZE))) == NULL)
			return (-1);
	if ((ft_read(fd, next)) < 0)
		return (-1);
	if (next[fd][0] == '\0')
	{
		(*line) = NULL;
		return (0);
	}
	if ((ft_in_line(fd, next, line)) == -1)
		return (-1);
	return (1);
}
