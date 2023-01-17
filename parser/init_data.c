/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:26:29 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/17 17:21:51 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*
 * walk through the raw_data lines
 * find top border of map and then walk through following rows
 * to check only spaces or 1's are present 
 * sets data->map as beginning of map
 */
static void	find_map(t_data *data, char **raw_data)
{
	int		i;
	int		j;
	int		flag;
	int		len;

	j = 0;
	flag = 0;
	i = 0;
	while (raw_data[i] && flag != 1)
	{
		len = ft_strlen(raw_data[i]);
		while (raw_data[i][j] && valid_map_border(raw_data[i]) && len > 2)
		{
			flag = 1;
			if (raw_data[i][j] != '1' && raw_data[i][j] != ' ')
				exit(cub_error(INVALID_MAP));
			j++;
		}
		if (flag == 1)
			data->map = raw_data + i;
		j = 0;
		i++;
	}
}

/*
 * textures and colours may be defined in any order but before the map
 * validates presence and store texture filenames
 * validate presence of Floor and Ceiling colours
 * calls find_map() -  map must be specified last in the file
 */
static void	save_param(t_data *data, char **raw_data)
{
	int		i;
	int		tex_code;
	int		tex_code_sum;

	i = 0;
	tex_code_sum = 0;
	while (raw_data[i])
	{
		tex_code = find_path_type(raw_data[i]);
		if (tex_code != NONE)
		{
			if (tex_code == NO)
				tex_code_sum += 4;
			else
				tex_code_sum += tex_code;
			data->textures[tex_code] = save_texture(raw_data[i]);
		}
		else if (ft_strchr(raw_data[i], 'F') != NULL \
		|| ft_strchr(raw_data[i], 'C') != NULL)
			check_colours(data, raw_data[i]);
		if (data->c_colour > 0 && data->f_colour > 0 && tex_code_sum == 10)
			break;
		i++;
	}
	if (tex_code_sum != 10)
		exit(cub_error(TEX_PRESENCE_ERROR));
	if (data->c_colour == 0 || data->f_colour == 0)
		exit(cub_error(COLOUR_ERROR));
	find_map(data, raw_data);
}

/*
 * TODO
 * Check edgecases of map validation
 * raw_data stores the full content of the filename
 */
void	map_data(char *map_path, t_data *data)
{
	char	**raw_data;

	raw_data = get_map(map_path);
	save_param(data, raw_data);
	if (ft_splitlen(data->map) < 3 || validate_mapchars(data->map))
		exit(cub_error(MAP_ERROR));
	player_checks(data);
	wall_check(data);
	free(raw_data);
}

