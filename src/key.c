/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:40 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/30 19:38:02 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_param		*key_up(t_param *param)
{
	if (param->map.tab[(int)(param->player.posx + param->player.dirx *
				param->mv_speed)][(int)(param->player.posy)] == 0)
		param->player.posx += param->player.dirx * param->mv_speed;
	if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy +
				param->player.diry * param->mv_speed)] == 0)
		param->player.posy += param->player.diry * param->mv_speed;
	return (param);
}

t_param		*key_down(t_param *param)
{
	if (param->map.tab[(int)(param->player.posx - param->player.dirx *
				param->mv_speed)][(int)(param->player.posy)] == 0)
		param->player.posx -= param->player.dirx * param->mv_speed;
	if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy -
				param->player.diry * param->mv_speed)] == 0)
		param->player.posy -= param->player.diry * param->mv_speed;
	return (param);
}

t_param		*key_left(t_param *param)
{
	param->player.olddirx = param->player.dirx;
	param->player.dirx = param->player.dirx * cos(param->rot_speed) -
		param->player.diry * sin(param->rot_speed);
	param->player.diry = param->player.olddirx * sin(param->rot_speed) +
		param->player.diry * cos(param->rot_speed);
	param->player.oldplanex = param->player.planex;
	param->player.planex = param->player.planex * cos(param->rot_speed) -
		param->player.planey * sin(param->rot_speed);
	param->player.planey = param->player.oldplanex * sin(param->rot_speed) +
		param->player.planey * cos(param->rot_speed);
	return (param);
}

t_param		*key_right(t_param *param)
{
	param->player.olddirx = param->player.dirx;
	param->player.dirx = param->player.dirx * cos(-param->rot_speed) -
		param->player.diry * sin(-param->rot_speed);
	param->player.diry = param->player.olddirx * sin(-param->rot_speed) +
		param->player.diry * cos(-param->rot_speed);
	param->player.oldplanex = param->player.planex;
	param->player.planex = param->player.planex * cos(-param->rot_speed) -
		param->player.planey * sin(-param->rot_speed);
	param->player.planey = param->player.oldplanex * sin(-param->rot_speed) +
		param->player.planey * cos(-param->rot_speed);
	return (param);
}

t_param		*straf_right(t_param *param)
{
	if (param->map.tab[(int)(param->player.posx + param->player.planex *
				param->mv_speed)][(int)(param->player.posy)] == 0)
		param->player.posx += param->player.planex * param->mv_speed;
	if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy +
				param->player.planey * param->mv_speed)] == 0)
		param->player.posy += param->player.planey * param->mv_speed;
	return (param);
}
