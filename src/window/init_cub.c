/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:16:33 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 16:30:26 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * global variables defined in macros.h must be prefixed with g_ and
 * contain only lowercase chars to comply with norm
 */
static void	set_ray_direction(t_cub *cub)
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
}

static void	init_ray(t_cub *cub)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		exit (cub_error(MALLOC_ERROR));
	ray->camera = 0;
	ray->dir.y = 0;
	ray->hit = 0;
	ray->map.x = 0;
	ray->map.y = 0;
	ray->wall_distance = 0;
	ray->plane.x = 0;
	ray->pos.x = (float)(cub->player_pos.y + 0.5);
	ray->pos.y = (float)(cub->player_pos.x + 0.5);
	ray->ray_dir.x = 0;
	ray->ray_dir.y = 0;
	ray->side = 0;
	cub->ray = ray;
	set_ray_direction(cub);
}

/*
 * initialise a MLX window instance to get the current screensize
 * width and height and terminate it
 */
static void	get_screensize(t_cub *cub)
{
	cub->mlx = mlx_init(100, 100, "dummy", true);
	if (!cub->mlx)
		exit(cub_error(MLX_ERROR));
	mlx_get_monitor_size(0, &cub->s_width, &cub->s_height);
	mlx_terminate(cub->mlx);
}

/*
 * initialise struct parameters, get current screen size
 * initialise MLX window
 */
static void	init_cub(t_cub *cub, t_data *data)
{
	cub->d = data;
	cub->c_colour = data->c_colour;
	cub->f_colour = data->f_colour;
	player_pos(cub, data);
	if (!cub->player_pos.x || !cub->player_pos.y)
		exit(cub_error(P_SURROUNDED_ERROR));
	get_screensize(cub);
	cub->mlx = mlx_init(cub->s_width, cub->s_height, "Cub3D", true);
	if (!cub->mlx)
		exit(cub_error(MLX_ERROR));
	cub->image = mlx_new_image(cub->mlx, cub->s_width, cub->s_height);
	if (!cub->image)
		exit(cub_error(MLX_ERROR));
	init_ray(cub);
	mlx_set_cursor_mode(cub->mlx, MLX_MOUSE_HIDDEN);
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
