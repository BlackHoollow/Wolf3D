/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 20:48:46 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/04 17:39:45 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**tmp;

	tmp = alst;
	if (!alst || !del)
		return ;
	while ((*tmp) != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*tmp);
		(*tmp) = (*tmp)->next;
	}
	*alst = NULL;
}
