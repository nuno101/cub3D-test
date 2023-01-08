/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:26:29 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/08 03:28:14 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	find_map(t_data *data)
{
	int		i;
	int		j;
	int		flag;
	int		len;

	j = 0;
	flag = 0;
	i = 0;
	while (data->map_data[i])
	{
		len = ft_strlen(data->map_data[i]);
		while (data->map_data[i][j] && check_map(data->map_data[i]) && len > 2)
		{
			flag = 1;
			if (data->map_data[i][j] != '1' && data->map_data[i][j] != ' ' && data->map_data[i][j] != 9)
				exit(cub_error(INVALID_MAP));
			j++;
		}
		if (flag == 1)
		{
			data->map = data->map_data + i;
			break ;
		}
		j = 0;
		i++;
	}
}

static void	save_param(t_data *data)
{
	int		i;
	int		ret;

	i = 0;
	if (check_text(data->map_data, data->tmp))
		exit(cub_error(TEX_PATH_ERROR));
	while (data->map_data[i])
	{
		ret = find_path_type(data->map_data[i]);
		if (ret)
			init_texture(data, data->map_data[i], ret);
		else if (ft_haschar(data->map_data[i], 'F') || ft_haschar(data->map_data[i], 'C')) //not save! to use ft_haschar strncmp is stronger
			check_colours(data, data->map_data[i]);
		i++;
	}
	if (data->c_colour == 0 || data->f_colour == 0)
		exit(cub_error(COLOUR_ERROR));
	find_map(data);
}

static void	map_data(t_data *data)
{
	if (!ft_ispath(data->map_path))
		exit(cub_error(DIR_ERROR));
	data->map_data = get_map(data->map_path);
	save_param(data);
	if (ft_splitlen(data->map) < 3 || validate_mapchars(data->map))
		exit(cub_error(MAP_ERROR));
	//map need still validation for corners/walls...
}

static char	*get_path(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] <= 32)
		i++;
	return (s + i);
}

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		exit(cub_error(MALLOC_ERROR));
	data->map_path = get_path(argv[1]);
	data->map_data = NULL;
	data->map = NULL;
	data->textures[0] = NULL;
	data->textures[1] = NULL;
	data->textures[2] = NULL;
	data->textures[3] = NULL;
	data->tmp[0] = 0;
	data->tmp[1] = 0;
	data->tmp[2] = 0;
	data->tmp[3] = 0;
	data->f_colour = 0;
	data->c_colour = 0;
	map_data(data);
	return (data);
}