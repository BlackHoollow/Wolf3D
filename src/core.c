/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 16:56:58 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/24 17:47:23 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		my_key_func(int keycode, t_param *param)
{
	param = param + 0;
	if (keycode == 53)
		exit(1);
	return (0);
}

int		repeat_key(int key, t_param *param)
{
	ft_putnbr(key);
	ft_putchar('\n');
	param = param + 0;
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
	param.win = mlx_new_window(param.mlx, LARGEUR, HAUTEUR, "wolf");
	param.img = mlx_new_image(param.mlx, LARGEUR, HAUTEUR);
	mlx_key_hook(param.win, my_key_func, &param);
	mlx_hook(param.win, 2, 3, repeat_key, &param);
	mlx_loop(param.mlx);
}
