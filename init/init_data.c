/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:03:20 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/04 22:19:16 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static void	set_data(int argc, char **argv, t_data *data)
{
	data->argc = argc;
	data->argv = argv;
	data->_NO = NULL;
	data->_SO = NULL;
	data->_WE = NULL;
	data->_EA = NULL;
	data->_split_len = 0;
	data->map_values = NULL;
	data->map = malloc(sizeof(char *) * (80));
	if (!data->map)
		exit(error(MALLOC_ERROR));
}

/*save map in struct(data.map) via get_next_line*/
static int	init_map(int argc, char **argv, t_data *data)
{
	int	fd;
	int	i;
	int	count;

	set_data(argc, argv, data);
	count = 0;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		data->map[i] = get_next_line(fd);
		count += ft_strlen(data->map[i]);
		if (!data->map[i])
			break ;
		i++;
	}
	data->map[i] = NULL;
	close(fd);
	if (count <= 5)
		return (MAP_ERROR);
	return (0);
}

t_data	*init_data(int argc, char *argv[])
{
	t_data	*data;
	int		ret;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		exit(error(MALLOC_ERROR));
	ret = init_map(argc, argv, data);
	if (ret)
	{
		if (ret != MALLOC_ERROR)
			ft_cleansplit(data->map);
		else
			free(data->map);
		free(data);
		exit(error(ret));
	}
	return (data);
}
