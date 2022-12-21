/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:38:29 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/21 08:49:30 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	skip_to_path(char *s, int *j)
{
	while (s[*j] && !(s[*j] <= 32))
		(*j)++;
}

void	save_cardinal_direction(t_data *data, int i, int j, int dir)
{
	char	**dest;

	skip_to_path(data->map[i] + j, &j);
	if (dir == NO)
		dest = &(data->_NO);
	else if (dir == SO)
		dest = &(data->_SO);
	else if (dir == WE)
		dest = &(data->_WE);
	else if (dir == EA)
		dest = &(data->_EA);
	else
		return ;
	while (data->map[i][j] && !ft_isalpha(data->map[i][j]) \
	&& data->map[i][j] != '.')
		j++;
	*dest = ft_strdup(data->map[i] + j);
}

int check_length(char **s)
{
    int i;
    int j;
    int valid_lines;

	i = 0;
	valid_lines = 0;
    while (s[i] != NULL)
	{
        j = 0;
        while (s[i][j] != '\0')
		{
            if (j == 2)
			{
                if (s[i][j] > 33)
				{
                    valid_lines++;
                    break;
                }
            }
            j++;
        }
        i++;
    }
    if (valid_lines < 3)
		return 1;
	return 0;
}

static int	save_map_val(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = find_map(data->map[i]);
	while (j < 0)
	{
		i++;
		j = find_map(data->map[i]);
	}
	if (check_length(data->map + i))
		return (1);
	data->map_start[0] = i;
	data->map_start[1] = j;
	data->map_values = ft_splitdup(data->map + i);
	return (0);
}

int	save_param(t_data *data)
{
	int		i;
	int		j;
	int		ret;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			ret = is_cardinal_direction(data->map[i][j], data->map[i] + j);
			if (ret)
				save_cardinal_direction(data, i, j, ret);
			else if (data->map[i][j] == 'F' || data->map[i][j] == 'C')
				ret = save_colours(data->map[i] + j, data);
			if (ret == COLOUR_ERROR)
				return (ret);
			j++;
		}
		i++;
	}
	if (save_map_val(data))
		return (MAP_ERROR);
	return (check_params(data));
}
