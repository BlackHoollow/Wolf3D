/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:29:35 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/02 20:49:48 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	size;

	if (!s)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(*res) * (len + 1))))
		return (NULL);
	size = 0;
	while (size < len)
	{
		res[size] = s[start + size];
		size++;
	}
	res[size] = '\0';
	return (res);
}
