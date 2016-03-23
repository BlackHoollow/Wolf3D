/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:04:26 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/04 18:09:00 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **list)
{
	t_list *rev;
	t_list *cur;
	t_list *nxt;
	t_list *prev;

	cur = *list;
	nxt = NULL;
	rev = NULL;
	while (cur != NULL)
	{
		prev = cur;
		cur = cur->next;
		prev->next = rev;
		rev = prev;
	}
	*list = rev;
}
