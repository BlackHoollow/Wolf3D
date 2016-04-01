/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:56:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/04/01 15:56:54 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_param	*straf_left(t_param *param)
{
	if (param->map.tab[(int)(param->player.posx - param->player.planex *
				param->mv_speed)][(int)(param->player.posy)] == 0)
		param->player.posx -= param->player.planex * param->mv_speed;
	if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy -
				param->player.planey * param->mv_speed)] == 0)
		param->player.posy -= param->player.planey * param->mv_speed;
	return (param);
}

int		repeat_key(int key, t_param *param)
{
	if (key == 53)
		ft_free(param);
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
	if (key == 69)
		param = mv_speed_up(param);
	if (key == 78)
		param = mv_speed_down(param);
	if (key == 24)
		param = rot_speed_up(param);
	if (key == 27)
		param = rot_speed_down(param);
	return (repeat_key_two(key, param));
}

int		repeat_key_two(int key, t_param *param)
{
	if (key == 82)
		init_player(param);
	if (key == 65)
	{
		if (param->wich_color == 0)
			param->wich_color = 1;
		else if (param->wich_color == 1)
			param->wich_color = 2;
		else if (param->wich_color == 2)
			param->wich_color = 0;
		param = get_color(param);
	}
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

	if (argc != 2)
		ft_exit();
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
