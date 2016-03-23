/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:47:55 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/11 15:36:30 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *tmps;

	tmps = (unsigned char *)s;
	while (n--)
	{
		if (*tmps != (unsigned char)c)
			tmps++;
		else
			return (tmps);
	}
	return (NULL);
}
