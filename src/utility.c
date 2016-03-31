/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:26:51 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/31 19:26:27 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_exit(void)
{
	ft_putendl("ERREUR");
	exit(1);
}

void	draw_px(int x, int y, int color, t_param *param)
{
	get_data(param);
	*(int *)(unsigned long)(param->str_img + (param->size_line * y) +
			(x * param->bits / 8)) = color;
}

t_map	*count_bis(t_map *map, char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
	{
		ft_strdel(&split[i]);
		i++;
	}
	map->nb_line = map->nb_line + 1;
	if (i != map->nb_col)
		ft_exit();
	ft_strdel(&line);
	return (map);
}
