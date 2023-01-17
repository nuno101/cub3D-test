/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:41:44 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/17 12:26:31 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	player_mid_surrounded(char *map, int j)
{
	int	count;

	count = 0;
	if (map[j - 1] == '0' || map[j - 1] == '1')
		count++;
	if (map[j + 1] == '0' || map[j + 1] == '1')
		count++;
	if (count != 2)
		return (0);
	return (1);
}

static int	player_bottop_surrounded(char *map, int j)
{
	int	count;

	count = 0;
	if (map[j - 1] == '0' || map[j - 1] == '1')
		count++;
	if (map[j + 1] == '0' || map[j + 1] == '1')
		count++;
	if (map[j] == '0' || map[j] == '1')
		count++;
	if (count != 3)
		return (0);
	return (1);
}

static int	player_surrounded(char **map, int i, int j)
{
	if (!player_bottop_surrounded(map[i - 1], j))
		return (1);
	if (!player_mid_surrounded(map[i], j))
		return (1);
	if (!player_bottop_surrounded(map[i + 1], j))
		return (1);
	return (0);
}

void	player_checks(t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (is_player(data->map[i][j]))
			{
				if (i == 0 || j == 0 || player_surrounded(data->map, i, j))
					exit(cub_error(P_SURROUNDED_ERROR));
				count++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (count != 1)
		exit(cub_error(PLAYER_ERROR));
}
