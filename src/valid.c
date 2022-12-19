/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:18:59 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 12:44:47 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void dl_nl(char **path)
{
    int len = strlen(*path);
    if (len < 4) {
        return;
    }

    int i = 0;
    while ((*path)[i] != '\0') {
        if ((*path)[i] == 'x' && (*path)[i + 1] == 'p' && (*path)[i + 2] == 'm') {
            int j = i + 3;
            while ((*path)[j] != '\0') {
                if ((*path)[j] != ' ' && (*path)[j] != '\n' && (*path)[j] != '\t') {
                    return;
                }
                j++;
            }
            ft_memset((*path) + i + 3, '\0', len - (i + 3));
            return;
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

static int	check_map(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (data->map[i])
	{
		i++;
	}
	return (0);
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
	return (0);
}
