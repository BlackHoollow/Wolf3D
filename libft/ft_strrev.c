/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:58:54 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/09 19:00:01 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	int		i;
	int		len;
	char	*rev;

	i = 0;
	len = ft_strlen(s);
	if (!(rev = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s[len] == '\0')
		len--;
	while (len >= 0)
	{
		rev[i] = s[len];
		i++;
		len--;
	}
	return (rev);
}
