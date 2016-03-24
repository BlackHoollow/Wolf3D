/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:24:10 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/24 17:35:27 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	*count(int fd, t_map *map)
{
	char	*line;
	char	**split;
	int		i;

	if (get_next_line(fd, &line
}

int		**init_map(char *argv, t_map *map)
{
	int		fd;
	map->nb_line = 0;
	map->nb_col = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_exit();
	map = count(fd, map);
}
