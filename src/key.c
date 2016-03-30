/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:40 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/30 18:12:39 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_param		*key_up(t_param *param)
{
	if (param->map.tab[(int)(param->player.posx + param->player.dirx *
				MVSPEED)][(int)(param->player.posy)] == 0)
		param->player.posx += param->player.dirx * MVSPEED;
	if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy +
				param->player.diry * MVSPEED)] == 0)
		param->player.posy += param->player.diry * MVSPEED;
	return (param);
}

t_param		*key_down(t_param *param)
{
	if (param->map.tab[(int)(param->player.posx - param->player.dirx *
				MVSPEED)][(int)(param->player.posy)] == 0)
		param->player.posx -= param->player.dirx * MVSPEED;
	if (param->map.tab[(int)(param->player.posx)][(int)(param->player.posy -
				param->player.diry * MVSPEED)] == 0)
		param->player.posy -= param->player.diry * MVSPEED;
	return (param);
}

t_param		*key_left(t_param *param)
{
	param->player.olddirx = param->player.dirx;
	param->player.dirx = param->player.dirx * cos(ROTSPEED) -
		param->player.diry * sin(ROTSPEED);
	param->player.diry = param->player.olddirx * sin(ROTSPEED) +
		param->player.diry * cos(ROTSPEED);
	param->player.oldplanex = param->player.planex;
	param->player.planex = param->player.planex * cos(ROTSPEED) -
		param->player.planey * sin(ROTSPEED);
	param->player.planey = param->player.oldplanex * sin(ROTSPEED) +
		param->player.planey * cos(ROTSPEED);
	return (param);
}

t_param		*key_right(t_param *param)
{
	param->player.olddirx = param->player.dirx;
	param->player.dirx = param->player.dirx * cos(-ROTSPEED) -
		param->player.diry * sin(-ROTSPEED);
	param->player.diry = param->player.olddirx * sin(-ROTSPEED) +
		param->player.diry * cos(-ROTSPEED);
	param->player.oldplanex = param->player.planex;
	param->player.planex = param->player.planex * cos(-ROTSPEED) -
		param->player.planey * sin(-ROTSPEED);
	param->player.planey = param->player.oldplanex * sin(-ROTSPEED) +
		param->player.planey * cos(-ROTSPEED);
	return (param);
}
