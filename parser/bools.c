/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:39:05 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/17 11:29:56 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

bool	is_player(char c)
{
	if (c == 'E' || c == 'S' || c == 'N' || c == 'W')
		return (1);
	return (0);
}

bool	is_mapchar(char c)
{
	if (c != ' ' && c != '1' && c != '0' && !is_player(c))
		return (0);
	return (1);
}

static bool	map_wall(char c)
{
	if (c != '1' && c != ' ')
		return (0);
	return (1);
}

/*
 * checks one map line
 */
bool	check_map(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (!map_wall(row[i]))
			return (0);
		i++;
	}
	return (1);
}

bool	validate_mapchars(char **map)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (!is_mapchar(map[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
