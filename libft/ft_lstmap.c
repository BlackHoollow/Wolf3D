/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 21:36:17 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/04 18:16:44 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*list;
	t_list	*begin;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	begin = new;
	if (new && lst && (*f))
	{
		new = (*f)(lst);
		begin = new;
		while (lst->next)
		{
			list = (t_list*)malloc(sizeof(t_list));
			lst = lst->next;
			if (!list)
				return (NULL);
			list = (*f)(lst);
			new->next = list;
			new = new->next;
		}
	}
	return (begin);
}
