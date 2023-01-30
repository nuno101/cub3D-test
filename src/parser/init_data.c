/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:26:29 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/29 20:58:04 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * walk through the raw_data lines
 * find top border of map and then walk through following rows
 * to check only spaces or 1's are present 
 * sets data->map as beginning of map
 * free raw_data
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
			data->map = ft_splitdup(raw_data + i);
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
static void	parse_raw_data(t_data *data, char **raw)
{
	int		i;
	int		tex_code;
	int		tex_code_sum;

	i = 0;
	tex_code_sum = 0;
	while (raw[i])
	{
		tex_code = get_texture_code(raw[i]);
		tex_code_sum += add_tex_code(tex_code);
		if (tex_code != NONE)
			data->textures[tex_code] = save_texture(raw[i]);
		else if (ft_strchr(raw[i], 'F') != NULL || \
			ft_strchr(raw[i], 'C') != NULL)
			check_colours(data, raw[i]);
		if (data->c_colour > 0 && data->f_colour > 0 && tex_code_sum == 10)
			break ;
		i++;
	}
	if (tex_code_sum != 10)
		exit(cub_error(TEX_PRESENCE_ERROR));
	if (data->c_colour == 0 || data->f_colour == 0)
		exit(cub_error(COLOUR_ERROR));
	find_map(data, raw);
}

/*
 * return number of lines of filename path
 */
static int	count_lines(char *path)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd, 1);
	if (line == NULL)
		exit(cub_error(FILE_ERROR));
	while (line)
	{
		free(line);
		line = get_next_line(fd, 0);
		if (line)
			count++;
	}
	close(fd);
	if (count == 0)
		exit(cub_error(EMPTY_FILE_ERROR));
	else if (count < 9)
		exit(cub_error(FILE_TOO_SHORT_ERROR));
	return (count);
}

/*
 * read the user filename and return an array of strings representing 
 * each line of the file
 */
static char	**get_map(char *path)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;
	int		len;

	map = malloc(sizeof(char *) * (count_lines(path) + 2));
	if (!map)
		exit(cub_error(MALLOC_ERROR));
	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd, 1);
	while (line)
	{
		len = ft_strlen(line) - 1;
		if (len > 0 && line[len] == '\n')
			line[len] = '\0';
		map[i] = line;
		i++;
		line = get_next_line(fd, 0);
	}
	map[i++] = NULL;
	close(fd);
	return (map);
}

/*
 * TODO
 * Check edgecases of map validation
 * raw_data stores the full content of the filename
 */
void	parse_map_data(char *map_path, t_data *data)
{
	char	**raw_data;

	raw_data = get_map(map_path);
	parse_raw_data(data, raw_data);
	ft_cleansplit(raw_data);
	if (ft_splitlen(data->map) < 3 || validate_mapchars(data->map))
		exit(cub_error(MAP_ERROR));
	player_checks(data);
	wall_check(data);
}
