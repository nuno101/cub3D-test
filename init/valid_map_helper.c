/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:47:33 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/04 22:48:42 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	is_valid_mapchar(char c)
{
	if (c > ' ' && c != '0' && c != '1' && c != 'N' \
	&& c != 'S' && c != 'E' && c != 'W' && c != '2')
		return (1);
	return (0);
}

int	check_map(t_data *data)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	data->_split_len = ft_splitlen(data->map_values);
	while (data->map_values[i])
	{
		j = 0;
		while (data->map_values[i][j])
		{
			if (is_valid_mapchar(data->map_values[i][j]))
				return (-1);
			if (data->map_values[i][j] == 'N' || data->map_values[i][j] == 'S' \
			|| data->map_values[i][j] == 'E' || data->map_values[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (!player || player > 1)
		return (-1);
	return (0);
}
