/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:18:59 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/23 06:27:55 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	dl_nl(char **path)
{
	int		i;
	int		len;

	len = ft_strlen(*path);
	if (len < 5)
		return ;
	i = 0;
	while ((*path)[i] != '\0')
	{
		if ((*path)[i] == ' ' || (*path)[i] == '\t' || (*path)[i] == '\n')
        	break;
		i++;
	}
	ft_memset((*path) + i, '\0', len - (i));
}

static int	check_valid_path(char *path)
{
	int	fd;

	dl_nl(&path);
	fd = open(path, O_RDONLY);
	if (fd >= 0)
		close(fd);
	else
		return (0);
	return (1);
}

static int	check_colour(t_data *data)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (data->C[i] < 0 || data->C[i] > 255 \
		|| data->F[i] < 0 || data->F[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

static int	is_valid_mapchar(char c)
{
	if (c > ' ' && c != '0' && c != '1' && c != 'N' \
	&& c != 'S' && c != 'E' && c != 'W' && c != '2')
		return (1);
	return (0);
}

static int	check_map(t_data *data)
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

static bool check_surrounded_tiles(t_data *data)
{
    int i;
    int j;

	i = 0;
	j = 0;
    while (data->map_values[i]) 
    {
		while (data->map_values[i][j])
		{
			if ((data->map_values[i][j] == '0' || data->map_values[i][j] == '2') && !is_surrounded_num(i, j, data)) 
			{

				return false;
			}
			j++;
		}
		i++;
		j = 0;
    }
    return true;
}

int	check_params(t_data *data)
{
	if (!check_valid_path(data->_EA) || !check_valid_path(data->_NO) \
	|| !check_valid_path(data->_SO) || !check_valid_path(data->_WE))
		return (DIR_ERROR);
	if (check_colour(data))
		return (COLOUR_ERROR);
	if (check_map(data))
		return (MAP_ERROR);
	if (!check_surrounded_player(data))
		return (MAP_ERROR);
	if (!check_surrounded_tiles(data))
		return (MAP_ERROR);
	return (0);
}
