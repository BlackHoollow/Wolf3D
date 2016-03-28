/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:58:35 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/28 15:45:13 by nromptea         ###   ########.fr       */
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
	param->player = player;
}
		#include <stdio.h>
// oui

void	raycasting(t_param *param, int key)
{
	key = key + 0;
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

	init_player(param);
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
			color = WHITE;
		else
			color = YELLOW;
		if (side == 1)
			color = color / 2;
		tmp = drawstart;
		while (tmp < drawend)
		{
			draw_px(x, tmp, color, param);
			tmp++;
		}
		x++;
	}
	//8 time et frametime non faite
	//9
/*	if (key == KEY_UP)
	{
		if (param->map.tab[(int)(param->player.posx + param->player.dirx)][(int)(param->player.posy)] == 0)
			param->player.posx += param->player.dirx;
		if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy + param->player.diry)] == 0)
			param->player.posy += param->player.diry;
	}
	else if (key == KEY_DOWN)
	{
		if (param->map.tab[(int)(param->player.posx - param->player.dirx)][(int)(param->player.posy)] == 0)
			param->player.posx -= param->player.dirx;
		if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy - param->player.diry)] == 0)
			param->player.posy -= param->player.diry;
	}
	if (key == KEY_RIGHT)
	{
		olddirx = param->player.dirx;
		param->player.dirx = param->player.dirx - param->player.diry;
		param->player.diry = olddirx + param->player.diry;
		oldplanex = param->player.planex;
		param->player.planex = param->player.planex - param->player.planey;
		param->player.planey = oldplanex + param->player.planey;
	}
	else if (key == KEY_LEFT)
	{
		olddirx = param->player.dirx;
		param->player.dirx = param->player.dirx - param->player.diry;
		param->player.diry = olddirx + param->player.diry;
		oldplanex = param->player.planex;
		param->player.planex = param->player.planex - param->player.planey;
		param->player.planey = oldplanex + param->player.planey;
	}*/
}
