/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:05:13 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/28 18:05:14 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *ptr;

	if ((ptr = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	ft_memset(ptr, '\0', size + 1);
	return (ptr);
}
