/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:03:33 by nromptea          #+#    #+#             */
/*   Updated: 2015/11/27 19:17:56 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*str;
	char	*swipe;
	size_t	len;

	str = (char *)ft_memchr(dst, '\0', size);
	if (str == NULL)
		return (size + ft_strlen(src));
	swipe = (char *)src;
	len = (size_t)(str - dst) + ft_strlen(swipe);
	while ((size_t)(str - dst) < size - 1 && *swipe != '\0')
	{
		*str = *swipe;
		str++;
		swipe++;
	}
	*str = '\0';
	return (len);
}
