/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:18 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/28 19:49:05 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * exit should never be called as the map was previously validated 
 * to make sure a player was present
 */
void	set_player_pos(t_cub *cub, t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (is_player(data->map[i][j]))
			{
				cub->direction = data->map[i][j];
				data->map[i][j] = '0';
				cub->player_pos.x = j;
				cub->player_pos.y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	exit(cub_error(PLAYER_NOT_FOUND_ERROR));
}
