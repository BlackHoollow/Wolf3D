/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 20:43:37 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/30 19:44:45 by nromptea         ###   ########.fr       */
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

# define HAUTEUR 1000
# define LARGEUR 1000
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define RED 0xFF9999
# define GREEN 0xCCFF99
# define BLUE 0x9999FF
# define ORANGE 0xFFCC99
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF99
# define PURPLE 0x800080
# define CYAN 0x66FFFF
# define BLACK 0x000000

typedef struct	s_player
{
	double		posx;
	double		posy;
	double		olddirx;
	double		dirx;
	double		diry;
	double		oldplanex;
	double		planex;
	double		planey;
}				t_player;

typedef struct	s_raycast
{
	double		camerax;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
	int			tmp;
}				t_raycast;

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
	double		startx;
	double		starty;
	int			endian;
	t_map		map;
	t_player	player;
	double		mv_speed;
	double		rot_speed;
}				t_param;

/*
**	core.c
*/

t_param			*straf_left(t_param *param);
int				repeat_key(int key, t_param *param);
int				repeat_key_two(int key, t_param *param);
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
void			define_start(t_param *param, t_map *map);
void			parsing(char *argv, t_map *map, t_param *param);

/*
**	wolf.c
*/

void			init_player(t_param *param);
void			ft_one(t_raycast *ray, t_param *param, int x);
void			ft_two(t_raycast *r);
void			ft_three(t_raycast *r);
void			raycasting(t_param *param);

/*
**	key.c
*/

t_param			*key_up(t_param *param);
t_param			*key_down(t_param *param);
t_param			*key_left(t_param *param);
t_param			*key_right(t_param *param);
t_param			*straf_right(t_param *param);

/*
**	raycasting.c
*/

void			ft_four(t_raycast *r, t_param *param);
void			ft_five(t_raycast *r);
void			ft_six(t_raycast *r);
void			ft_seven(t_raycast *r, t_param *param, int x);

/*
**	hook.c
*/

t_param			*mv_speed_up(t_param *param);
t_param			*mv_speed_down(t_param *param);
t_param			*rot_speed_up(t_param *param);
t_param			*rot_speed_down(t_param *param);

#endif
