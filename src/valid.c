/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:18:59 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/21 08:49:09 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	dl_nl(char **path)
{
	int		j;
	int		i;

	if (ft_strlen(*path) < 5)
		return ;
	i = 0;
	while ((*path)[i] != '\0')
	{
		if ((*path)[i] == 'x' && (*path)[i + 1] == 'p' && (*path)[i + 2] == 'm')
		{
			j = i + 3;
			while ((*path)[j] != '\0')
			{
				if ((*path)[j] != ' ' && (*path)[j] != \
				'\n' && (*path)[j] != '\t')
					return ;
				j++;
			}
			ft_memset((*path) + i + 3, '\0', ft_strlen(*path) - (i + 3));
			return ;
		}
		i++;
	}
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

bool is_surrounded(int i, int j, t_data *data)
{
    int rows;
    int cols;

	cols = data->_split_len;
	rows = ft_strlen(data->map_values[i]);
    if (i > 0 && data->map_values[i - 1][j] != '1' && data->map_values[i - 1][j] != '2' && data->map_values[i - 1][j] != '0')
    {
		return (false);
	}
    if (j < cols - 1 && data->map_values[i][j + 1] != '1' && data->map_values[i][j + 1] != '2' && data->map_values[i - 1][j] != '0')
    {
		return (false);
	}
    if (i < rows - 1 && data->map_values[i + 1][j] != '1' && data->map_values[i + 1][j] != '2' && data->map_values[i - 1][j] != '0')
    {
		return (false);
	}
    if (j > 0 && data->map_values[i][j - 1] != '1' && data->map_values[i][j - 1] != '2' && data->map_values[i][j - 1] != '0')
    {
		return (false);
	}
    return true;
}

bool	is_player(char c)
{
	if (c == 'E' || c == 'S' || c == 'N' || c == 'W')
		return (1);
	return (0);
}

bool is_surrounded_num(int i, int j, t_data *data)
{
    int rows;
    int cols;

	cols = ft_splitlen(data->map_values);
	rows = ft_strlen(data->map_values[i]);
    if (i > 0 && data->map_values[i - 1][j] != '1' && data->map_values[i - 1][j] != '2' && data->map_values[i - 1][j] != '0' && !is_player(data->map_values[i - 1][j]))
    {
		printf("1hi \n");

		return (false);
	}
    if (j < cols - 1 && data->map_values[i][j + 1] != '1' && data->map_values[i][j + 1] != '2' && data->map_values[i - 1][j] != '0' && !is_player(data->map_values[i - 1][j]))
    {
		printf("2hi \n");
		return (false);
	}
    if (i < rows - 1 && data->map_values[i + 1][j] != '1' && data->map_values[i + 1][j] != '2' && data->map_values[i - 1][j] != '0' && !is_player(data->map_values[i - 1][j]))
    {
		printf("3hi \n");

		return (false);
	}
    if (j > 0 && data->map_values[i][j - 1] != '1' && data->map_values[i][j - 1] != '2' && data->map_values[i][j - 1] != '0' && !is_player(data->map_values[i][j - 1]))
    {
		printf("4hi \n");

		return (false);
	}
    return true;
}

bool check_surrounded_tiles(t_data *data)
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

bool check_surrounded_player(t_data *data)
{
    int i;
    int j;

	i = 0;
	j = 0;
    while (data->map_values[i]) 
    {
		while (data->map_values[i][j])
		{
			if (is_player(data->map_values[i][j]) && !is_surrounded(i, j, data)) 
				return false;
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
