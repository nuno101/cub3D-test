/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:03:13 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 12:40:50 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static int	wall_mid_surrounded(char *map, int j)
{
	int	count;

	count = 0;
	if (map[j - 1] == '0' || map[j - 1] == '1' || is_player(map[j - 1]))
		count++;
	if (map[j + 1] == '0' || map[j + 1] == '1' || is_player(map[j + 1]))
		count++;
	if (count != 2)
		return (0);
	return (1);
}

static int	wall_bottop_surrounded(char *map, int j)
{
	int	count;

	count = 0;
	if (map[j - 1] == '0' || map[j - 1] == '1' || is_player(map[j - 1]))
		count++;
	if (map[j + 1] == '0' || map[j + 1] == '1' || is_player(map[j + 1]))
		count++;
	if (map[j] == '0' || map[j] == '1' || is_player(map[j]))
		count++;
	if (count != 3)
		return (0);
	return (1);
}

static int	wall_surrounded(char **map, int i, int j)
{
	if (!wall_bottop_surrounded(map[i - 1], j))
		return (1);
	if (!wall_mid_surrounded(map[i], j))
		return (1);
	if (!wall_bottop_surrounded(map[i + 1], j))
		return (1);
	return (0);
}

void	wall_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if (i == 0 || j == 0 || wall_surrounded(data->map, i, j))
					exit(cub_error(W_SURROUNDED_ERROR));
			}
			j++;
		}
		j = 0;
		i++;
	}
}
