/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:26:50 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/02 20:30:22 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_char(const char *s, char c)
{
	if (*s && *s != c)
		return (ft_strlen_char(s + 1, c) + 1);
	return (0);
}

static int	ft_tablen_word(const char *s, char c)
{
	if (!*s)
		return (1);
	if (*s != c)
		return (ft_tablen_word(s + 1, c));
	while (*s && *s == c)
		s++;
	return (ft_tablen_word(s, c) + 1);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	size = ft_tablen_word(s, c) + 1;
	if (!(tab = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			size = ft_strlen_char(s, c);
			tab[i++] = ft_strsub(s, 0, size);
			s += size;
		}
		else
			++s;
	}
	tab[i] = NULL;
	return (tab);
}
