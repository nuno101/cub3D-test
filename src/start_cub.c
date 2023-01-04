/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 06:37:19 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/04 18:09:17 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

static void	screensize(t_cub *m)
{
	mlx_get_monitor_size(0, &m->s_width, &m->s_height);
	mlx_terminate(m->mlx);
	m->mlx = mlx_init(m->s_width, m->s_height, "Cub3D", true);
}

static void	clean_mlx(t_cub *m)
{
	free_data(m->d);
	mlx_delete_image(m->mlx, m->image);
	mlx_delete_texture(m->texture);
	mlx_terminate(m->mlx);
	free(m);
}

void	key_press(mlx_key_data_t key, void *param)
{
	t_cub	*tmp;

	if (key.key == MLX_KEY_ESCAPE)
	{
		tmp = (t_cub*)param;
		clean_mlx(tmp);
		system("leaks cub3D");
		exit(0);
	}
}

int	start_cub(t_data *data)
{
	t_cub	*m;

	m = malloc(sizeof(t_cub));
	m->d = data;
	m->mlx = mlx_init(100, 100, "MLX", true);
	if (!m->mlx)
		return (MALLOC_ERROR);
	screensize(m);
	if (!m->mlx)
		return (MALLOC_ERROR);
	m->texture = mlx_load_png("./png_textures/lava_1024.png");
	if (!m->texture)
		return (DIR_ERROR);
	m->image = mlx_texture_to_image(m->mlx, m->texture);
	if (!m->image)
		return (MALLOC_ERROR);
	if (mlx_image_to_window(m->mlx, m->image, 0, 0) < 0)
        return (MALLOC_ERROR);
	mlx_key_hook(m->mlx, &key_press, m);
	mlx_loop(m->mlx);
	clean_mlx(m);
	return (0);
}
