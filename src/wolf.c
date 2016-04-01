/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:58:35 by nromptea          #+#    #+#             */
/*   Updated: 2016/04/01 15:18:35 by nromptea         ###   ########.fr       */
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
	param->mv_speed = 0.3;
	param->rot_speed = 0.2;
	param->wich_color = 0;
	param = get_color(param);
	param->player = player;
}

void	ft_one(t_raycast *ray, t_param *param, int x)
{
	ray->camerax = 2 * x / (double)(LARGEUR) - 1;
	ray->rayposx = param->player.posx;
	ray->rayposy = param->player.posy;
	ray->raydirx = param->player.dirx + param->player.planex * ray->camerax;
	ray->raydiry = param->player.diry + param->player.planey * ray->camerax;
}

void	ft_two(t_raycast *r)
{
	r->mapx = (int)(r->rayposx);
	r->mapy = (int)(r->rayposy);
	r->deltadistx = sqrt(1 + (r->raydiry * r->raydiry) / (r->raydirx *
				r->raydirx));
	r->deltadisty = sqrt(1 + (r->raydirx * r->raydirx) / (r->raydiry *
				r->raydiry));
	r->hit = 0;
}

void	ft_three(t_raycast *r)
{
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (r->rayposx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - r->rayposx) * r->deltadistx;
	}
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (r->rayposy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - r->rayposy) * r->deltadisty;
	}
}

void	raycasting(t_param *param)
{
	int			x;
	t_raycast	r;

	x = 0;
	while (x < LARGEUR)
	{
		ft_one(&r, param, x);
		ft_two(&r);
		ft_three(&r);
		ft_four(&r, param);
		ft_five(&r);
		ft_six(&r);
		ft_seven(&r, param, x);
		x++;
	}
}

/*
**	if (param->map.tab[mapx][mapy] == 1)
**		color = RED;
**	else if (param->map.tab[mapx][mapy] == 2)
**		color = GREEN;
**	else if (param->map.tab[mapx][mapy] == 3)
**		color = BLUE;
**	else if (param->map.tab[mapx][mapy] == 4)
**		color = PURPLE;
**	else
**		color = YELLOW;
**	if (side == 1)
**		color = color / 2;
*/
