/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:45:39 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/30 18:04:20 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_four(t_raycast *r, t_param *param)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->side = 1;
		}
		if (param->map.tab[r->mapx][r->mapy] > 0)
			r->hit = 1;
	}
}

void	ft_five(t_raycast *r)
{
	if (r->side == 0)
		r->perpwalldist = (r->mapx - r->rayposx + (1 -
					r->stepx) / 2) / r->raydirx;
	else
		r->perpwalldist = (r->mapy - r->rayposy + (1 -
					r->stepy) / 2) / r->raydiry;
}

void	ft_six(t_raycast *r)
{
	r->lineheight = (int)(HAUTEUR / r->perpwalldist);
	r->drawstart = -r->lineheight / 2 + HAUTEUR / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->lineheight / 2 + HAUTEUR / 2;
	if (r->drawend >= HAUTEUR)
		r->drawend = HAUTEUR - 1;
}

void	ft_seven(t_raycast *r, t_param *param, int x)
{
	if (r->side == 0)
		r->color = r->mapx > param->player.posx ? RED : GREEN;
	else
		r->color = r->mapy > param->player.posy ? ORANGE : BLUE;
	r->tmp = 0;
	while (r->tmp < r->drawstart)
	{
		draw_px(x, r->tmp, CYAN, param);
		r->tmp++;
	}
	while (r->tmp < r->drawend)
	{
		draw_px(x, r->tmp, r->color, param);
		r->tmp++;
	}
	while (r->tmp < HAUTEUR)
	{
		draw_px(x, r->tmp, 0xFFFFCC, param);
		r->tmp++;
	}
}
