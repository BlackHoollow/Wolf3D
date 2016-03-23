/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 00:26:44 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/02 20:47:10 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(res = ft_strdup((char const*)s)))
		return (NULL);
	while (res[i] != '\0')
	{
		res[i] = f(res[i]);
		i++;
	}
	return (res);
}
