/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:14:01 by nromptea          #+#    #+#             */
/*   Updated: 2015/11/27 23:48:57 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*tp;

	tp = (char*)s + ft_strlen(s);
	while (*tp != c)
	{
		if (*tp == *s)
			return (NULL);
		tp--;
	}
	return (tp);
}
