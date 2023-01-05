/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:03:20 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/05 05:22:04 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static	void	init_colour(t_cub *m)
{
	m->f = (m->d->F[0] << 24 | m->d->F[1] << 16 | m->d->F[2] << 8 | 255);
	m->c = (m->d->C[0] << 24 | m->d->C[1] << 16 | m->d->C[2] << 8 | 255);
}

static void	load_textures(t_cub *m)
{
	m->_NO = mlx_load_png(m->d->_NO);
	if (!m->_NO)
		exit(error(PNG_ERROR));
	m->_SO = mlx_load_png(m->d->_SO);
	if (!m->_SO)
		exit(error(PNG_ERROR));
	m->_WE = mlx_load_png(m->d->_WE);
	if (!m->_WE)
		exit(error(PNG_ERROR));
	m->_EA = mlx_load_png(m->d->_EA);
	if (!m->_EA)
		exit(error(PNG_ERROR));
}

t_cub	*init_cub(t_data *data)
{
	t_cub	*m;

	m = malloc(sizeof(t_cub));
	m->d = data;
	m->mlx = mlx_init(100, 100, "MLX", true);
	if (!m->mlx)
		exit(error(MLX_ERROR));
	screensize(m);
	if (!m->mlx)
		exit(error(MLX_ERROR));
	load_textures(m);
	m->image = mlx_new_image(m->mlx, m->s_width, m->s_height);
	if (!m->image)
		exit(error(MLX_ERROR));
	mlx_set_cursor_mode(m->mlx, MLX_MOUSE_HIDDEN);
	if (mlx_image_to_window(m->mlx, m->image, 0, 0) < 0)
		exit(error(MLX_ERROR));
	init_colour(m);
	return (m);
}

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
