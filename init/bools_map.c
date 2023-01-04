/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:35:11 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/23 06:34:27 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	is_cardinal_direction(char c, char *s)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (c == 'N' && s[1] && s[1] == 'O')
			return (NO);
		if (c == 'S' && s[1] && s[1] == 'O')
			return (SO);
		if (c == 'W' && s[1] && s[1] == 'E')
			return (WE);
		if (c == 'E' && s[1] && s[1] == 'A')
			return (EA);
	}
	return (0);
}

bool	is_surrounded_num(int i, int j, t_data *data)
{
	int	rows;
	int	cols;

	cols = ft_splitlen(data->map_values);
	rows = ft_strlen(data->map_values[i]);
	if (i > 0 && data->map_values[i - 1][j + 1] != '1' && data->map_values[i - 1][j + 1] \
	!= '2' && data->map_values[i - 1][j + 1] != '0' && !is_player(data->map_values[i - 1][j + 1]))
		return (false);
	if (i > 0 && data->map_values[i - 1][j - 1] != '1' && data->map_values[i - 1][j - 1] \
	!= '2' && data->map_values[i - 1][j - 1] != '0' && !is_player(data->map_values[i - 1][j - 1]))
		return (false);
	if (i > 0 && data->map_values[i - 1][j] != '1' && data->map_values[i - 1][j] != '2' \
	&& data->map_values[i - 1][j] != '0' && !is_player(data->map_values[i - 1][j]))
		return (false);
	if (j < cols - 1 && data->map_values[i][j + 1] != '1' && data->map_values[i][j + 1] \
	!= '2' && data->map_values[i][j + 1] != '0' && !is_player(data->map_values[i][j + 1]))
		return (false);
	if (i < rows - 1 && data->map_values[i + 1][j] != '1' && data->map_values[i + 1][j] \
	!= '2' && data->map_values[i + 1][j] != '0' && !is_player(data->map_values[i + 1][j]))
		return (false);
	if (i < rows - 1 && data->map_values[i + 1][j + 1] != '1' && data->map_values[i + 1][j + 1] \
	!= '2' && data->map_values[i + 1][j + 1] != '0' && !is_player(data->map_values[i + 1][j + 1]))
		return (false);
	if (i < rows - 1 && data->map_values[i + 1][j - 1] != '1' && data->map_values[i + 1][j - 1] \
	!= '2' && data->map_values[i + 1][j - 1] != '0' && !is_player(data->map_values[i + 1][j - 1]))
		return (false);
	if (j > 0 && data->map_values[i][j - 1] != '1' && data->map_values[i][j - 1] != '2' \
	&& data->map_values[i][j - 1] != '0' && !is_player(data->map_values[i][j - 1]))
		return (false);
	return (true);
}

bool	is_surrounded(int i, int j, t_data *data)
{
	int	rows;
	int	cols;

	cols = data->_split_len;
	rows = ft_strlen(data->map_values[i]);
	if (i > 0 && data->map_values[i - 1][j] != '1' && data->map_values[i - 1][j] != '2' && data->map_values[i - 1][j] != '0')
		return (false);
	if (i > 0 && data->map_values[i - 1][j + 1] != '1' && data->map_values[i - 1][j + 1] != '2' && data->map_values[i - 1][j + 1] != '0')
		return (false);
	if (i > 0 && data->map_values[i - 1][j - 1] != '1' && data->map_values[i - 1][j - 1] != '2' && data->map_values[i - 1][j - 1] != '0')
		return (false);
	if (j < cols - 1 && data->map_values[i][j + 1] != '1' && data->map_values[i][j + 1] != '2' && data->map_values[i][j + 1] != '0')
		return (false);
	if (i < rows - 1 && data->map_values[i + 1][j] != '1' && data->map_values[i + 1][j] != '2' && data->map_values[i + 1][j] != '0')
		return (false);
	if (i < rows - 1 && data->map_values[i + 1][j + 1] != '1' && data->map_values[i + 1][j + 1] != '2' && data->map_values[i + 1][j + 1] != '0')
		return (false);
	if (i < rows - 1 && data->map_values[i + 1][j - 1] != '1' && data->map_values[i + 1][j - 1] != '2' && data->map_values[i + 1][j - 1] != '0')
		return (false);
	if (j > 0 && data->map_values[i][j - 1] != '1' && data->map_values[i][j - 1] != '2' && data->map_values[i][j - 1] != '0')
		return (false);
	return (true);
}

bool	is_player(char c)
{
	if (c == 'E' || c == 'S' || c == 'N' || c == 'W')
		return (1);
	return (0);
}

bool	check_surrounded_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_values[i])
	{
		while (data->map_values[i][j])
		{
			if (is_player(data->map_values[i][j]) \
			&& !is_surrounded(i, j, data))
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}
