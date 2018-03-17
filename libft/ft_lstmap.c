/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayavorsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:22:41 by ayavorsk          #+#    #+#             */
/*   Updated: 2017/10/31 22:22:41 by ayavorsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*buff;

	if (lst == NULL || f == NULL)
		return (NULL);
	buff = f(lst);
	if ((new = ft_lstnew(buff->content, buff->content_size)) != NULL)
	{
		tmp = new;
		lst = lst->next;
		while (lst != NULL)
		{
			buff = f(lst);
			if ((tmp->next = ft_lstnew(buff->content,
				buff->content_size)) == NULL)
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new);
}
