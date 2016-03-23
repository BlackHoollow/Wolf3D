/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:11:33 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/02 19:22:02 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *begin, int nb)
{
	int	i;

	i = 0;
	if (begin == NULL || nb <= 0)
		return (NULL);
	else
		while (i < nb && begin->next != NULL)
		{
			begin = begin->next;
			i++;
		}
	return (begin);
}
