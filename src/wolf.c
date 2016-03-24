/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:58:35 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/24 19:58:21 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_player(t_param *param)
{
	t_player	player;

	player.posx = 22;
	player.posy = 12;
	player.dirx = -1;
	player.diry = 0;
	player.planex = 0;
	player.planey = 0.66;
	player.time = 0;
	player.old_time = 0;
}

void	raycasting(t_param *param)
{
	int		x;
	double	camerax;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;

	init_player(param);
	x = 0;
	while (x < param->map.nb_col)
	{
		//1
		camerax = 2 * x / double(param->map.nb_col) - 1;
		rayposx = param->player.posx;
		rayposy = param->player.posy;
		raydirx = param->player.dirx + param->player.planex * camerax;
		raydiry = param->player.diry + param->player.planey * camerax;
		//2
		mapx = int(rayposx);
		mapy = int(rayposy);
		deltadistx = ft_sqrt(1 + (raydiry * raydiry) / (raydirx * raydirx));
		deltadisty = ft_sqrt(1 + (raydirx * raydirx) / (raydiry * raydiry));
		hit = 0;
		//3
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (rayposx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - rayposx) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (raypoy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - rayposy) * deltadisty;
		}
		//4

		x++;
	}
}
