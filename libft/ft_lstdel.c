/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 20:48:55 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/31 20:48:56 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *list;
	t_list *save;

	list = *alst;
	if (alst != NULL && del != NULL)
	{
		while (list != NULL)
		{
			save = list->next;
			del(list, list->content_size);
			list = save;
		}
		*alst = NULL;
	}
}
