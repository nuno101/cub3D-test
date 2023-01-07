/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:06:10 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/07 21:15:58 by jjesberg         ###   ########.fr       */
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

	i = 0;
	while (i < m->s_width * m->s_height)
	{
		if (i < m->s_width * (m->s_height / 2))
			mlx_put_pixel(m->image, i, 0, m->d->c_colour);
		else
			mlx_put_pixel(m->image, i, 0, m->d->f_colour);
		i++;
	}
}

static t_cub	*init_cub(t_data *data)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	cub->d = data;
	cub->mlx = mlx_init(100, 100, "MLX", true);
	screensize(cub);
	if (!cub->mlx)
		exit(cub_error(MLX_ERROR));
	cub->image = mlx_new_image(cub->mlx, cub->s_width, cub->s_height);
	if (!cub->image)
		exit(cub_error(MLX_ERROR));
	cub->player_angle = 11;
	cub->player_pos.x = 2;
	cub->player_pos.y = 2;
	cub->fov = 2 * atan(0.66 / 1.0);
	cub->ray = NULL;
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	return (cub);
}

void	start_cub(t_data *data)
{
	t_cub	*cub;

	cub = init_cub(data);
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) < 0)
		exit(cub_error(MLX_ERROR));
	skyline(cub);
	hooks(cub);
	clean_mlx(cub);
	exit(cub_error(EXIT_SUCCESS));
}
