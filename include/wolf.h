/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 20:43:37 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/25 18:32:28 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

# define HAUTEUR 384
# define LARGEUR 512
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00

typedef struct	s_player
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_player;

typedef struct	s_map
{
	int			nb_col;
	int			nb_line;
	int			**tab;
}				t_map;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*str_img;
	int			bits;
	int			size_line;
	int			endian;
	t_map		map;
	t_player	player;
}				t_param;

/*
**	core.c
*/

int				my_key_func(int keycode, t_param *param);
int				repeat_key(int key, t_param *param);
void			get_data(t_param *param);
int				main(int argc, char **argv);

/*
**	utility.c
*/

void			ft_exit(void);
void			draw_px(int x, int y, int color, t_param *param);

/*
**	parse2.c
*/

t_map			*count_line_col(int fd, t_map *map);
t_map			*split_tab(t_map *map, int fd);
void			parsing(char *argv, t_map *map);

/*
**	wolf.c
*/

void			init_player(t_param *param);
void			raycasting(t_param *param, int key);

#endif
