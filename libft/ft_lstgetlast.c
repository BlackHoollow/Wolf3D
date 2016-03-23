/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:17:56 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/01 23:21:02 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetlast(t_list *lst)
{
	t_list	*swp;

	swp = lst;
	if (!lst)
		return (NULL);
	while (swp->next)
		swp = swp->next;
	return (swp);
}
