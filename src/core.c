/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:56:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/29 16:28:12 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		repeat_key(int key, t_param *param)
{
	if (key == 53)
		exit(1);
	if (key == KEY_UP)
	{
		if (param->map.tab[(int)(param->player.posx + param->player.dirx * MVSPEED)][(int)(param->player.posy)] == 0)
			param->player.posx += param->player.dirx * MVSPEED;
		if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy + param->player.diry * MVSPEED)] == 0)
			param->player.posy += param->player.diry * MVSPEED;
	}
	else if (key == KEY_DOWN)
	{
		if (param->map.tab[(int)(param->player.posx - param->player.dirx * MVSPEED)][(int)(param->player.posy)] == 0)
			param->player.posx -= param->player.dirx * MVSPEED;
		if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy - param->player.diry * MVSPEED)] == 0)
			param->player.posy -= param->player.diry * MVSPEED;
	}
	if (key == KEY_RIGHT)
	{
		param->player.olddirx = param->player.dirx;
		param->player.dirx = param->player.dirx * cos(-ROTSPEED) - param->player.diry * sin(-ROTSPEED);
		param->player.diry = param->player.olddirx * sin(-ROTSPEED) + param->player.diry * cos(-ROTSPEED);
		param->player.oldplanex = param->player.planex;
		param->player.planex = param->player.planex * cos(-ROTSPEED) - param->player.planey * sin(-ROTSPEED);
		param->player.planey = param->player.oldplanex * sin(-ROTSPEED) + param->player.planey * cos(-ROTSPEED);
	}
	else if (key == KEY_LEFT)
	{
		param->player.olddirx = param->player.dirx;
		param->player.dirx = param->player.dirx * cos(ROTSPEED) - param->player.diry * sin(ROTSPEED);
		param->player.diry = param->player.olddirx * sin(ROTSPEED) + param->player.diry * cos(ROTSPEED);
		param->player.oldplanex = param->player.planex;
		param->player.planex = param->player.planex * cos(ROTSPEED) - param->player.planey * sin(ROTSPEED);
		param->player.planey = param->player.oldplanex * sin(ROTSPEED) + param->player.planey * cos(ROTSPEED);
	}
	raycasting(param, key);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	return (0);
}

void	get_data(t_param *param)
{
	param->str_img = mlx_get_data_addr(param->img, &param->bits,
			&param->size_line, &param->endian);
}

int		main(int argc, char **argv)
{
	t_param		param;
	t_map		map;

	argc = argc + 0;
	param.mlx = mlx_init();
	parsing(argv[1], &map);
	param.map = map;
	param.win = mlx_new_window(param.mlx, LARGEUR, HAUTEUR, "wolf");
	param.img = mlx_new_image(param.mlx, LARGEUR, HAUTEUR);
	init_player(&param);
	raycasting(&param, 1);
	mlx_put_image_to_window(param.mlx, param.win, param.img, 0, 0);
	mlx_hook(param.win, 2, 3, repeat_key, &param);
	mlx_loop(param.mlx);
}
