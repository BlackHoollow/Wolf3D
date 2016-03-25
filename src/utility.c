/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 17:26:51 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/25 16:20:38 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_exit(void)
{
	ft_putendl("ERREUR");
	exit(1);
}

void	draw_px(int x, int y, int color, t_param *param)
{
	get_data(param);
	*(int *)(unsigned long)(param->str_img + (param->size_line * y) +
			(x * param->bits / 8)) = color;
}
