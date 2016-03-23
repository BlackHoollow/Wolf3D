/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:40:58 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/11 16:50:03 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len1;
	int		len2;
	int		len3;
	char	*res;

	len1 = 0;
	len2 = ft_strlen(s);
	if (!s)
		return (NULL);
	while (s[len1] && (s[len1] == ' ' || s[len1] == '\n' || s[len1] == '\t'))
		len1++;
	if (len1 < len2)
		len2--;
	while ((s[len2] == ' ' || s[len2] == '\n' || s[len2] == '\t'))
		len2--;
	if (!(res = (char *)malloc(sizeof(char) * (len2 - len1 + 2))))
		return (NULL);
	len3 = 0;
	while (len1 <= len2)
		res[len3++] = s[len1++];
	res[len3] = '\0';
	return (res);
}
