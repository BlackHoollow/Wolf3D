/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:10:34 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/31 19:44:14 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_map	*count_line_col(int fd, t_map *map)
{
	char	*line;
	char	**split;
	int		i;

	if (get_next_line(fd, &line) == 1)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i] != NULL)
		{
			ft_strdel(&split[i]);
			i++;
		}
		map->nb_line = 1;
		map->nb_col = i;
		ft_strdel(&line);
	}
	while (get_next_line(fd, &line) == 1)
	{
		map = count_bis(map, line);
	}
	return (map);
}

t_map	*split_tab(t_map *map, int fd)
{
	char	**split;
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		map->tab[i] = (int *)malloc(sizeof(int *) * (map->nb_col));
		split = ft_strsplit(line, ' ');
		while (split[j] != NULL)
		{
			map->tab[i][j] = ft_atoi(split[j]);
			ft_strdel(&split[j]);
			j++;
		}
		ft_strdel(&line);
		i++;
	}
	return (map);
}

void	define_start(t_param *param, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			if (map->tab[i][j] == 0)
			{
				param->startx = i + 0.5;
				param->starty = j + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
	ft_exit();
}

void	check_border(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->nb_col)
	{
		if (map->tab[0][i] == 0)
			ft_exit();
		i++;
	}
	i = 0;
	while (i < map->nb_col)
	{
		if (map->tab[map->nb_line - 1][i] == 0)
			ft_exit();
		i++;
	}
	i = 0;
	while (i < map->nb_line)
		map->tab[i][0] == 0 ? ft_exit() : i++;
	i = 0;
	while (i < map->nb_line)
		map->tab[i][map->nb_col - 1] == 0 ? ft_exit() : i++;
}

void	parsing(char *argv, t_map *map, t_param *param)
{
	int		fd;

	map->nb_line = 0;
	map->nb_col = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_exit();
	map = count_line_col(fd, map);
	map->tab = (int **)malloc(sizeof(int *) * (map->nb_line));
	map->tab[map->nb_line] = NULL;
	close(fd);
	fd = open(argv, O_RDONLY);
	map = split_tab(map, fd);
	define_start(param, map);
	check_border(map);
	close(fd);
}
