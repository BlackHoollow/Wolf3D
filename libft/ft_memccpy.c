/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:38:38 by nromptea          #+#    #+#             */
/*   Updated: 2015/11/27 23:49:51 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	f;
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;
	size_t			i;

	i = 0;
	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	f = (unsigned char)c;
	while (i < n)
	{
		if (*tmpsrc == f)
		{
			*tmpdst = *tmpsrc;
			tmpdst++;
			return (tmpdst);
		}
		*tmpdst = *tmpsrc;
		tmpsrc++;
		tmpdst++;
		i++;
	}
	return (NULL);
}
