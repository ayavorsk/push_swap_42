/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:56:05 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/01/27 16:56:06 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack		*stack_data(int ac, char **av, t_snake *stack)
{
	t_stack		*st;
	long		nbr;
	int			i;

	if ((st = (t_stack*)malloc(sizeof(t_stack) * 1)) == NULL)
		ft_exit("Error");
	if ((st->data = (int*)malloc(sizeof(int) * (ac))) == NULL)
		ft_exit("Error");
	i = (stack->flags == 0 ? 1 : 2);
	st->top = ac - 2;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		if (nbr > MAX || nbr < MIN)
			ft_exit("Error");
		st->data[--ac - 1] = nbr;
		i++;
	}
	same_nbr(st->top, st->data);
	return (st);
}

static t_stack		*stack_data_2(int ac, char **av)
{
	t_stack		*st;
	long		nbr;
	int			i;

	if ((st = (t_stack*)malloc(sizeof(t_stack) * 1)) == NULL)
		ft_exit("Error");
	if ((st->data = (int*)malloc(sizeof(int) * (ac))) == NULL)
		ft_exit("Error");
	i = 0;
	st->top = ac - 2;
	while (av[i])
	{
		nbr = ft_atoi(av[i]);
		if (nbr > MAX || nbr < MIN)
			ft_exit("Error");
		st->data[--ac - 1] = nbr;
		i++;
	}
	same_nbr(st->top, st->data);
	return (st);
}

static t_stack		*stack_null(int ac, char **av)
{
	t_stack		*st;
	int			i;

	if ((st = (t_stack*)malloc(sizeof(t_stack) * 1)) == NULL)
		ft_exit("Error");
	if ((st->data = (int*)malloc(sizeof(int) * ac - 2)) == NULL)
		ft_exit("Error");
	i = 1;
	st->top = EMPTY;
	while (av[i] != 0)
	{
		st->data[--ac - 1] = 0;
		i++;
	}
	return (st);
}

t_snake				*stack_int(int ac, char **av, char c)
{
	t_snake	*stack;

	if ((stack = (t_snake*)malloc(sizeof(t_snake) * 1)) == NULL)
		ft_exit("Error");
	stack->str = NULL;
	if (c == 'a')
	{
		check_flags(&ac, av, stack);
		if ((ac == 2 || (count_len(av, stack) >= 2 && ac == 3)))
			stack->st = stack_data_2(count_len(av, stack) + 1,
				ft_strsplit((stack->flags == 0 ? av[1] : av[2]), ' '));
		else
			stack->st = stack_data(ac, av, stack);
	}
	else
	{
		check_flags(&ac, av, stack);
		if (ac == 2)
			stack->st = stack_null(count_len(av, stack),
				ft_strsplit((stack->flags == 0 ? av[1] : av[2]), ' '));
		else
			stack->st = stack_null(ac, av);
	}
	return (stack);
}
