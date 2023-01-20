/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:16:33 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/20 11:15:48 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*
 * initializing all the fields of 't_cub' to zero.
 * FIXME TODOO 25lines
*/
static t_cub	*init_ray(t_cub *cub)
{
	cub->ray->camera = 0;
	cub->ray->delta_dist.x = 0;
	cub->ray->delta_dist.y = 0;
	cub->ray->dir.x = 0;
	cub->ray->dir.y = 0;
	cub->ray->hit = 0;
	cub->ray->map.x = 0;
	cub->ray->map.y = 0;
	cub->ray->old_dir.x = 0;
	cub->ray->old_dir.y = 0;
	cub->ray->old_plane.x = 0;
	cub->ray->old_plane.y = 0;
	cub->ray->perp_wall_dist = 0;
	cub->ray->plane.x = 0;
	cub->ray->plane.y = 0.66;
	cub->ray->pos.x = (float)(cub->player_pos.y + 0.5);
	cub->ray->pos.y = (float)(cub->player_pos.x + 0.5);
	cub->ray->ray_dir.x = -1;
	cub->ray->ray_dir.y = 0;
	cub->ray->side = 0;
	cub->ray->side_dist.x = 0;
	cub->ray->side_dist.y = 0;
	cub->ray->step.x = 0;
	cub->ray->step.y = 0;
	if (cub->direction == 'S')
	{
		cub->ray->dir.x = 1;
		cub->ray->plane.y = -0.66;
	}
	else if (cub->direction == 'W')
	{
		cub->ray->ray_dir.x = 0;
		cub->ray->ray_dir.y = -1;
		cub->ray->plane.x = -0.66;
		cub->ray->plane.y = 0;
	}
	else if (cub->direction == 'E')
	{
		cub->ray->dir.x = 0;
		cub->ray->dir.y = 1;
		cub->ray->plane.x = 0.66;
		cub->ray->plane.y = 0;
	}
	return (cub);
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
