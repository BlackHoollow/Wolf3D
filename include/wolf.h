/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 20:43:37 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/23 21:02:24 by nromptea         ###   ########.fr       */
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
# define KEY_UP 126
# define KEY_DOWN 125

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*str_img;
	int			bits;
	int			size_line;
	int			endian;
}				t_param;

/*
**	core.c
*/

int				my_key_func(int keycode, t_param *param);
void			get_data(t_param *param);
int				main(void);

/*
**	utility.c
*/

void			ft_exit(void);
void			draw_px(int x, int y, int color, t_param *param);

#endif
