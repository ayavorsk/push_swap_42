/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 22:38:52 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/22 22:38:53 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_check_valid(const char c)
{
	if (ft_strchr(" ", c))
		return (1);
	if (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL)
		return (2);
	else if (ft_strchr("hltjz", c) != NULL)
		return (1);
	else if (ft_strchr("#0-+' ", c) != NULL)
		return (1);
	else if (ft_strchr("$*.", c) != NULL)
		return (1);
	else if (ft_isdigit(c))
		return (1);
	else
		return (0);
}

int				ft_is_valid(const char *str, size_t *i)
{
	if (str[*i] == '\0')
		return (0);
	while (((str[*i] != '\0') && (ft_check_valid(str[*i]) == 1)
			&& (ft_check_valid(str[*i]) != 2)))
		(*i)++;
	if (ft_strchr("dDioOuUxXeEfFgGaAcCsSpn%",
		str[*i]) != NULL && str[*i] != '\0')
	{
		(*i)++;
		return (1);
	}
	else
	{
		if (str[*i] == '\0')
			return (2);
		(*i)++;
		return (0);
	}
}
