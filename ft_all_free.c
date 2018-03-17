/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:04:31 by ayavorsk          #+#    #+#             */
/*   Updated: 2018/02/11 19:04:32 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_all_free(t_snake *stack_a, t_snake *stack_b, t_opt opt)
{
	free(opt.str);
	free(DATA_A);
	free(DATA_B);
	free(stack_a->st);
	free(stack_b->st);
	free(stack_a);
	free(stack_b);
}
