/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:56:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/30 18:51:31 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_param	*straf_left(t_param *param)
{
	if (param->map.tab[(int)(param->player.posx - param->player.planex *
				MVSPEED)][(int)(param->player.posy)] == 0)
		param->player.posx -= param->player.planex * MVSPEED;
	if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy -
				param->player.planey * MVSPEED)] == 0)
		param->player.posy -= param->player.planey * MVSPEED;
	return (param);
}

int		repeat_key(int key, t_param *param)
{
	if (key == 53)
		exit(1);
	if (key == KEY_W)
		param = key_up(param);
	if (key == KEY_S)
		param = key_down(param);
	if (key == KEY_RIGHT)
		param = key_right(param);
	if (key == KEY_LEFT)
		param = key_left(param);
	if (key == KEY_D)
		param = straf_right(param);
	if (key == KEY_A)
		param = straf_left(param);
	raycasting(param);
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
	parsing(argv[1], &map, &param);
	param.map = map;
	param.win = mlx_new_window(param.mlx, LARGEUR, HAUTEUR, "wolf");
	param.img = mlx_new_image(param.mlx, LARGEUR, HAUTEUR);
	init_player(&param);
	raycasting(&param);
	mlx_put_image_to_window(param.mlx, param.win, param.img, 0, 0);
	mlx_hook(param.win, 2, 3, repeat_key, &param);
	mlx_loop(param.mlx);
}
