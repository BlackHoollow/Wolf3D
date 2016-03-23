/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:50:47 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/15 20:13:48 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		k;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (i < n && s1[i] != '\0')
	{
		k = 0;
		while (s1[i + k] == s2[k] && (s1[i + k] != '\0') && (i + k) < n)
		{
			if (s2[k + 1] == '\0')
			{
				s1 = s1 + i;
				return ((char *)s1);
			}
			k++;
		}
		i++;
	}
	return (NULL);
}
