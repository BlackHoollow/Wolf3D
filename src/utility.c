/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:26:51 by nromptea          #+#    #+#             */
/*   Updated: 2016/04/01 15:50:12 by nromptea         ###   ########.fr       */
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

void	ft_free(t_param *param)
{
	int		i;

	i = 0;
	while (i < param->map.nb_line)
	{
		free(param->map.tab[i]);
		i++;
	}
	exit(1);
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

t_param	*get_color(t_param *param)
{
	if (param->wich_color == 0)
	{
		param->color.color1 = RED;
		param->color.color2 = GREEN;
		param->color.color3 = ORANGE;
		param->color.color4 = BLUE;
	}
	if (param->wich_color == 1)
	{
		param->color.color1 = 0xFF0000;
		param->color.color2 = 0xFFFF00;
		param->color.color3 = 0x00FF00;
		param->color.color4 = 0x0000FF;
	}
	if (param->wich_color == 2)
	{
		param->color.color1 = 0xFF99FF;
		param->color.color2 = 0xFF33FF;
		param->color.color3 = 0xFF66FF;
		param->color.color4 = 0xFF00FF;
	}
	return (param);
}
