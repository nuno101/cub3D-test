/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:18 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/12 12:50:01 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	player_pos(t_data *data)
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
				data->player_pos.x = i;
				data->player_pos.y = j;
				return (0);
			}
			j += write(1, &data->map[i][j], 1);
		}
		j = 0;
		i++;
	}
	return (INVALID_MAP);
}
