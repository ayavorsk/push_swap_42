/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:12:54 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/10 14:12:55 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_do_instruct_2(t_snake *stack_a, t_snake *stack_b, char *line)
{
	if (ft_strstr(line, "ra"))
		rotate_ab(stack_a, NULL);
	else if (ft_strstr(line, "rb"))
		rotate_ab(stack_b, NULL);
	if (ft_strstr(line, "rr"))
	{
		rotate_ab(stack_a, NULL);
		rotate_ab(stack_b, NULL);
	}
}

static void		ft_do_instruct_1(t_snake *stack_a, t_snake *stack_b, char *line)
{
	if (ft_strstr(line, "sa"))
		swap_ab(stack_a, NULL);
	else if (ft_strstr(line, "sb"))
		swap_ab(stack_b, NULL);
	else if (ft_strstr(line, "ss"))
	{
		swap_ab(stack_a, NULL);
		swap_ab(stack_b, NULL);
	}
	else if (ft_strstr(line, "pa"))
		push_ab(stack_b, stack_a, NULL);
	else if (ft_strstr(line, "pb"))
		push_ab(stack_a, stack_b, NULL);
	else if (ft_strstr(line, "rra"))
		reverse_rv(stack_a, NULL);
	else if (ft_strstr(line, "rrb"))
		reverse_rv(stack_b, NULL);
	else if (ft_strstr(line, "rrr"))
	{
		reverse_rv(stack_a, NULL);
		reverse_rv(stack_b, NULL);
	}
	else
		ft_do_instruct_2(stack_a, stack_b, line);
}

static int		ft_error_instruct(char *line)
{
	if (ft_strstr(line, "sa") || ft_strstr(line, "rr")
		|| ft_strstr(line, "rra") || ft_strstr(line, "rrb")
		|| ft_strstr(line, "rrr") || ft_strstr(line, "sb")
		|| ft_strstr(line, "ss") ||
		ft_strstr(line, "pa") || ft_strstr(line, "pb")
		|| ft_strstr(line, "ra") || ft_strstr(line, "rb"))
		return (1);
	else
		return (0);
}

static void		read_instruct(t_snake *stack_a, t_snake *stack_b)
{
	char	*line;

	if (stack_a->flags == VISUAL || stack_a->flags == VISUAL_COLOR)
		print_stacks(stack_a, stack_b);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_error_instruct(line) == 0)
		{
			free(line);
			break ;
		}
		else
			ft_do_instruct_1(stack_a, stack_b, line);
		if (stack_a->flags == VISUAL || stack_a->flags == VISUAL_COLOR)
			print_op(stack_a, stack_b, line);
		free(line);
	}
	ft_ok_ko(stack_a, stack_b);
}

int				main(int ac, char **av)
{
	t_snake			*stack_a;
	t_snake			*stack_b;
	t_opt			opt;

	if (ft_check_av(ac, av) == 0)
	{
		if (ac == 2)
			ft_printf("OK\n");
		return (0);
	}
	stack_a = stack_int(ac, av, 'a');
	stack_b = stack_int(ac, av, 'b');
	opt.str = ft_strdup("\0");
	read_instruct(stack_a, stack_b);
	ft_all_free(stack_a, stack_b, opt);
	return (0);
}
