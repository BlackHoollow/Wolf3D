/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:33:20 by nromptea          #+#    #+#             */
/*   Updated: 2015/12/09 18:52:24 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_rec(long long n, char *res, int base)
{
	if (n > 9)
		res = itoa_rec(n / base, res, base);
	*res = "0123456789ABCDEF"[n % base];
	*(res + 1) = '\0';
	return (res + 1);
}

char		*ft_itoa_base(int n, int base)
{
	char		*res;
	int			nb;
	int			nbch;
	long long	tmp;
	int			i;

	nb = n;
	nbch = 1;
	i = 0;
	tmp = n;
	while (nb >= 10)
	{
		nb = nb / 10;
		nbch++;
	}
	if (!(res = (char *)malloc(sizeof(char) * nbch + 1)))
		return (NULL);
	if (tmp < 0)
	{
		res[i] = '-';
		i++;
		tmp = -tmp;
	}
	itoa_rec(tmp, res + i, base);
	return (res);
}
