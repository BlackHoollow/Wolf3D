/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:58:35 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/29 18:23:06 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_player(t_param *param)
{
	t_player	player;

	player.posx = param->startx;
	player.posy = param->starty;
	player.dirx = -1;
	player.diry = 0;
	player.planex = 0;
	player.planey = 0.66;
	param->player = player;
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

	int		lineheight;
	int		drawstart;
	int		drawend;

	int		color;
	int		tmp;

	x = 0;
	while (x < LARGEUR)
	{
		//1
		camerax = 2 * x / (double)(LARGEUR) - 1;
		rayposx = param->player.posx;
		rayposy = param->player.posy;
		raydirx = param->player.dirx + param->player.planex * camerax;
		raydiry = param->player.diry + param->player.planey * camerax;
		//2
		mapx = (int)(rayposx);
		mapy = (int)(rayposy);
		deltadistx = sqrt(1 + (raydiry * raydiry) / (raydirx * raydirx));
		deltadisty = sqrt(1 + (raydirx * raydirx) / (raydiry * raydiry));
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
			sidedisty = (rayposy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - rayposy) * deltadisty;
		}
		//4
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (param->map.tab[mapx][mapy] > 0)
				hit = 1;
		}
		//5
		if (side == 0)
			perpwalldist = (mapx - rayposx + (1 - stepx) / 2) / raydirx;
		else	
			perpwalldist = (mapy - rayposy + (1 - stepy) / 2) / raydiry;
		//6
		lineheight = (int)(HAUTEUR / perpwalldist);
		drawstart = -lineheight / 2 + HAUTEUR / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + HAUTEUR / 2;
		if (drawend >= HAUTEUR)
			drawend = HAUTEUR - 1;
		//7
		if (param->map.tab[mapx][mapy] == 1)
			color = RED;
		else if (param->map.tab[mapx][mapy] == 2)
			color = GREEN;
		else if (param->map.tab[mapx][mapy] == 3)
			color = BLUE;
		else if (param->map.tab[mapx][mapy] == 4)
			color = PURPLE;
		else
			color = YELLOW;
		if (side == 1)
			color = color / 2;
		tmp = 0;
		while (tmp < drawstart)
		{
			draw_px(x, tmp, CYAN, param);
			tmp++;
		}
		while (tmp < drawend)
		{
			draw_px(x, tmp, color, param);
			tmp++;
		}
		while (tmp < HAUTEUR)
		{
			draw_px(x, tmp, 0x000000, param);
			tmp++;
		}	
		x++;
	}
}
