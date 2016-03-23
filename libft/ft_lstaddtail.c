/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 22:26:17 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/02 00:33:03 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddtail(t_list *begin_list, void *content, size_t content_size)
{
	t_list	*end;
	t_list	*save;
	t_list	*swp;

	save = begin_list;
	swp = begin_list;
	if (!(end = ft_lstnew(content, content_size)))
		return (save);
	if (swp == NULL)
		return (end);
	while (swp && swp->next != NULL)
		swp = swp->next;
	swp->next = end;
	return (save);
}
