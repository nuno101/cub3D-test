/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:18:59 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 07:49:41 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub.h"

static int	check_valid_path(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd >= 0)
		close(fd);
	else
		return 0;
	return 1;
}

static int	check_colour(t_data *data)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (data->C[i] < 0 || data->C[i] > 255 || data->F[i] < 0 || data->F[i] > 255)
			return (1);
		i++;
	}
	return (0);
}

static int	check_map(t_data *data)
{
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