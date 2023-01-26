/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:16:33 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/26 17:22:28 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*
 * constant variables used here are defined in macros.h
 */
t_cub	*ray_direction(t_cub *cub)
{
	int dir_index;

	dir_index = 0;
	if (cub->direction == 'N')
		dir_index = 0;
	else if (cub->direction == 'E')
		dir_index = 1;
	else if (cub->direction == 'S')
		dir_index = 2;
	else if (cub->direction == 'W')
		dir_index = 3;
	cub->ray->dir.x = RAY_DIR_X[dir_index];
	cub->ray->dir.y = RAY_DIR_Y[dir_index];
	cub->ray->plane.x = PLANE_X[dir_index];
	cub->ray->plane.y = PLANE_Y[dir_index];
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

t_cub	*init_cub(t_data *data)
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
