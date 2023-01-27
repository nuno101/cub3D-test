/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:16:33 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 12:36:11 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * glaobal variables defined in macros.h must be prefixed with g_ and
 * contain only lowercase chars to comply with norm
 */
t_cub	*ray_direction(t_cub *cub)
{
	int	dir_index;

	dir_index = 0;
	if (cub->direction == 'N')
		dir_index = 0;
	else if (cub->direction == 'E')
		dir_index = 1;
	else if (cub->direction == 'S')
		dir_index = 2;
	else if (cub->direction == 'W')
		dir_index = 3;
	cub->ray->dir.x = g_ray_dir_x[dir_index];
	cub->ray->dir.y = g_ray_dir_y[dir_index];
	cub->ray->plane.x = g_plane_x[dir_index];
	cub->ray->plane.y = g_plane_y[dir_index];
	return (cub);
}

static t_cub	*init_ray(t_cub *cub)
{
	cub->ray->camera = 0;
	cub->ray->dir.y = 0;
	cub->ray->hit = 0;
	cub->ray->map.x = 0;
	cub->ray->map.y = 0;
	cub->ray->wall_distance = 0;
	cub->ray->plane.x = 0;
	cub->ray->pos.x = (float)(cub->player_pos.y + 0.5);
	cub->ray->pos.y = (float)(cub->player_pos.x + 0.5);
	cub->ray->ray_dir.x = 0;
	cub->ray->ray_dir.y = 0;
	cub->ray->side = 0;
	cub = ray_direction(cub);
	return (cub);
}

static void	screensize(t_cub *cub)
{
	if (!cub->mlx)
		exit(cub_error(MLX_ERROR));
	mlx_get_monitor_size(0, &cub->s_width, &cub->s_height);
	mlx_terminate(cub->mlx);
	cub->mlx = mlx_init(cub->s_width, cub->s_height, "Cub3D", true);
}

/*
 * initialise window
 */
t_cub	*init_cub(t_cub *cub, t_data *data)
{
	cub->d = data;
	cub->c = data->c_colour;
	cub->f = data->f_colour;
	player_pos(cub, data);
	if (!cub->player_pos.x || !cub->player_pos.y)
		exit(cub_error(P_SURROUNDED_ERROR));
	cub->mlx = mlx_init(100, 100, "MLX", true);
	screensize(cub);
	if (!cub->mlx)
		exit(cub_error(MLX_ERROR));
	cub->image = mlx_new_image(cub->mlx, cub->s_width, cub->s_height);
	if (!cub->image)
		exit(cub_error(MLX_ERROR));
	cub->ray = malloc(sizeof(t_ray));
	if (!cub->ray)
		exit (cub_error(MALLOC_ERROR));
	cub = init_ray(cub);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
	return (cub);
}

/*
 * initialise cub struct
 * start window
 * set window hooks
 * clean up before exiting
 */
void	start_cub(t_data *data)
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (!cub)
		exit(cub_error(MALLOC_ERROR));
	init_cub(cub, data);
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) < 0)
		exit(cub_error(MLX_ERROR));
	hooks(cub);
	clean_mlx(cub);
	free_cub(cub);
}
