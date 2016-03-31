/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 19:14:01 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/31 15:17:47 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_param		*mv_speed_up(t_param *param)
{
	if (param->mv_speed <= 0.9)
		param->mv_speed = param->mv_speed + 0.1;
	return (param);
}

t_param		*mv_speed_down(t_param *param)
{
	if (param->mv_speed > 0.2)
		param->mv_speed = param->mv_speed - 0.1;
	return (param);
}

t_param		*rot_speed_up(t_param *param)
{
	if (param->rot_speed <= 1.4)
		param->rot_speed = param->rot_speed + 0.1;
	return (param);
}

t_param		*rot_speed_down(t_param *param)
{
	if (param->rot_speed > 0.2)
		param->rot_speed = param->rot_speed - 0.1;
	return (param);
}
