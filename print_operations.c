/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:59:55 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/07 15:59:57 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_operations(t_snake *stack_a, t_snake *stack_b)
{
	int		i;
	char	**str;

	i = 0;
	(void)stack_b;
	str = ft_strsplit(OPT_A, '\n');
	while (str[i] != 0)
	{
		if (str[i + 1] != 0 && ((ft_strstr(str[i], "sa")
			&& ft_strstr(str[i + 1], "sb"))
			|| (ft_strstr(str[i], "sb") && ft_strstr(str[i + 1], "sa"))))
		{
			printf("ss\n");
			i++;
		}
		else
			printf("%s\n", str[i]);
		i++;
	}
	ft_arr_free(str);
}
