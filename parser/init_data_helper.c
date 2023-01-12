/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:51:23 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/12 14:30:20 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	count_lines(char *path)
{
	int		count;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	count = 1;
	line = get_next_line(fd, 1);
	if (!line)
		exit(cub_error(FILE_ERROR));
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd, 0);
	}
	close(fd);
	return (count);
}

char	**get_map(char *path)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	map = malloc(sizeof(char *) * (count_lines(path)));
	if (!map)
		exit(cub_error(MALLOC_ERROR));
	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd, 1);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd, 0);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
