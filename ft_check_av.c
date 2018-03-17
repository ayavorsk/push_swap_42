/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_av.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 19:44:31 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/26 19:44:33 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_exit(char *error)
{
	ft_dprintf(2, "%s\n", error);
	exit(1);
}

void		same_nbr(int j, int *tab)
{
	int i;
	int i_2;
	int nbr;

	i = j;
	nbr = 0;
	while (i >= 0)
	{
		i_2 = i - 1;
		nbr = tab[i];
		while (i_2 >= 0)
		{
			if (nbr == tab[i_2])
				ft_exit("Error");
			i_2--;
		}
		i--;
	}
}

int			check_digit(char **str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] != 0)
	{
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				j++;
			if (ft_isdigit(str[i][j]) == 0)
			{
				ft_arr_free(str);
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_arr_free(str);
	return (1);
}

static int	what_flag(char **av)
{
	if (ft_strstr(av[1], "-vc"))
		return (1);
	else if (ft_strstr(av[1], "-v"))
		return (1);
	else if (ft_strstr(av[1], "-c"))
		return (1);
	else if (ft_strstr(av[1], "-u"))
		ft_print_usage();
	else
		return (0);
	return (0);
}

int			ft_check_av(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		what_flag(av);
		if (count_len_v2(av) == 0)
			return (0);
	}
	if (what_flag(av) == 1)
		i++;
	while (i < ac)
	{
		if (check_digit(ft_strsplit(av[i], ' ')) == 0)
			ft_exit("Error");
		i++;
	}
	return (1);
}
