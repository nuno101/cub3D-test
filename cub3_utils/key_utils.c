/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:00:20 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/27 14:26:58 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	move_forward_backward(t_player *pl, int sign)
{
	t_point	tmp;

	tmp.x = pl->pos->x + sign * pl->dir->x * 3;
	tmp.y = pl->pos->y + sign * pl->dir->y * 3;
	tile2idx(pl->data, &tmp);
	if (pl->data->map[tmp.j][tmp.i] != '1')
	{
		pl->pos->x = tmp.x;
		pl->pos->y = tmp.y;
		tile2idx(pl->data, &pl->pos);
	}
}

void	move_left_right(t_player *pl, int sign)
{
	t_point	tmp;

	tmp.angle = fl_mod_deg(pl->dir.angle + 90);
	tmp.x = pl->pos->x + sign * cos(ft_deg2rad(tmp.angle)) * 3;
	tmp.y = pl->pos->y - sign * sin(ft_deg2rad(tmp.angle)) * 3;
	tile2idx(pl->data, &tmp);
	if (pl->data->map[tmp.j][tmp.i] != '1')
	{
		pl->pos->x = tmp.x;
		pl->pos->y = tmp.y;
		tile2idx(pl->data, &pl->pos);
	}
}

void	rotate(t_player *pl, int sign)
{
	pl->dir->angle = fl_mod_deg(pl->dir->angle + sign * 2);
	pl->dir->x = cos(ft_deg2rad(pl->dir->angle));
	pl->dir->y = sin(ft_deg2rad(pl->dir->angle));
}
