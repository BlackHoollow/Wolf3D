/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:40:58 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/01 18:29:12 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	int		len1;
	int		len2;
	int		len3;
	char	*res;

	len1 = 0;
	len2 = ft_strlen(s);
	while (s[len1] && s[len1] == c)
		len1++;
	if (len1 < len2)
		len2--;
	while (s[len2] == c)
		len2--;
	if (!(res = (char *)malloc(sizeof(char) * (len2 - len1 + 1))))
		return (NULL);
	len3 = 0;
	while (len1 <= len2)
		res[len3++] = s[len1++];
	res[len3] = '\0';
	return (res);
}
