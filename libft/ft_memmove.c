/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:09:35 by nromptea          #+#    #+#             */
/*   Updated: 2015/11/27 19:11:07 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmpdst;
	const unsigned char	*tmpsrc;

	tmpdst = (unsigned char *)dst;
	tmpsrc = (unsigned char *)src;
	if (tmpdst < tmpsrc)
		while (len-- != 0)
			*tmpdst++ = *tmpsrc++;
	else
	{
		tmpdst += len;
		tmpsrc += len;
		while (len-- > 0)
			*--tmpdst = *--tmpsrc;
	}
	return (dst);
}
