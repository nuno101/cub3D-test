/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:18 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 12:40:28 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	player_pos(t_cub *cub, t_data *data)
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
	cub->player_pos.x = 0;
	cub->player_pos.y = 0;
}
