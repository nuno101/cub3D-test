/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:06:10 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/12 15:10:41 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	clean_mlx(t_cub *m)
{
	mlx_delete_image(m->mlx, m->image);
	mlx_terminate(m->mlx);
	free(m);
}

void	skyline(t_cub *m)
{
	int32_t			i;
	int32_t			j;

	i = 0;
	while (i < m->s_height)
	{
		j = 0;
		while (j < m->s_width)
		{
			if (i < m->s_height / 2)
				mlx_put_pixel(m->image, j, i, m->d->c_colour);
			else
				mlx_put_pixel(m->image, j, i, m->d->f_colour);
			j++;
		}
		i++;
	}
}

static t_cub	*init_cub(t_data *data)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		exit(cub_error(MALLOC_ERROR));
	cub->d = data;
	cub->c = data->c_colour;
	cub->f = data->f_colour;
	player_pos(cub, data);
	if (!cub->player_pos.x || !cub->player_pos.y)
		exit(cub_error(PLAYER_ERROR));
	cub->mlx = mlx_init(100, 100, "MLX", true);
	screensize(cub);
	if (!cub->mlx)
		exit(cub_error(MLX_ERROR));
	cub->image = mlx_new_image(cub->mlx, cub->s_width, cub->s_height);
	if (!cub->image)
		exit(cub_error(MLX_ERROR));
	cub->player_angle = 11;	
	cub->fov = 2 * atan(0.66 / 1.0);
	cub->ray = NULL;
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	//print_cub(cub);
	return (cub);
}

void	start_cub(t_data *data)
{
	t_cub	*cub;

	cub = init_cub(data);
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) < 0)
		exit(cub_error(MLX_ERROR));
	hooks(cub);
	clean_mlx(cub);
	exit(cub_error(EXIT_SUCCESS));
}
