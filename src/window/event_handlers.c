/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/02/03 15:32:04 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * xval & yval are +- operators which came from movement
 * because moving forward is increasing instead moving backwards will decrease
 * will check the char in the map array 
 * if there is a wall
 */
static int	wall_hit_ad(t_ray *ray, t_cub *cub, int x_val, int y_val)
{
	int	x_check;
	int	y_check;
	int	i;

	i = 1;
	while (i < 5)
	{
		x_check = (int)(ray->pos.x + ray->dir.y * MOVE * x_val * i);
		y_check = (int)(ray->pos.y + ray->dir.x * MOVE * y_val * i);
		if (cub->d->map[x_check][(int)ray->pos.y] == '1' || \
			cub->d->map[(int)ray->pos.x][y_check] == '1')
			return (0);
		i++;
	}
	return (1);
}

static int	wall_hit_ws(t_ray *ray, t_cub *cub, int x_val, int y_val)
{
	int	x_check;
	int	y_check;
	int	i;

	i = 1;
	while (i < 5)
	{
		x_check = (int)(ray->pos.x + ray->dir.x * MOVE * x_val * i);
		y_check = (int)(ray->pos.y + ray->dir.y * MOVE * y_val * i);
		if (cub->d->map[x_check][(int)ray->pos.y] == '1' || \
			cub->d->map[(int)ray->pos.x][y_check] == '1')
			return (0);
		i++;
	}
	return (1);
}

/*
 * handle WASD key events which simulate the player
 * movement by changing the POV
 */
static void	wasd(t_cub *cub, t_ray *ray, int key)
{
	double	move;

	move = MOVE;
	if (key == MLX_KEY_W && wall_hit_ws(ray, cub, 1, 1))
	{
		ray->pos.x += ray->dir.x * move;
		ray->pos.y += ray->dir.y * move;
	}
	else if (key == MLX_KEY_S && wall_hit_ws(ray, cub, -1, -1))
	{
		ray->pos.x -= ray->dir.x * move;
		ray->pos.y -= ray->dir.y * move;
	}
	else if (key == MLX_KEY_D && wall_hit_ad(ray, cub, 1, -1))
	{
		ray->pos.x += ray->dir.y * move;
		ray->pos.y -= ray->dir.x * move;
	}
	else if (key == MLX_KEY_A && wall_hit_ad(ray, cub, -1, 1))
	{
		ray->pos.x -= ray->dir.y * move;
		ray->pos.y += ray->dir.x * move;
	}
}

static void	arrows(t_ray *ray, int key)
{
	double	val;
	double	cos_val;
	double	sin_val;
	double	delta_dir_x;
	double	delta_plane_x;

	val = -MOVE;
	if (key == MLX_KEY_LEFT)
		val = MOVE;
	cos_val = cos(val);
	sin_val = sin(val);
	delta_dir_x = ray->dir.x;
	ray->dir.x = ray->dir.x * cos_val - ray->dir.y * sin_val;
	ray->dir.y = delta_dir_x * sin_val + ray->dir.y * cos_val;
	delta_plane_x = ray->plane.x;
	ray->plane.x = ray->plane.x * cos_val - ray->plane.y * sin_val;
	ray->plane.y = delta_plane_x * sin_val + ray->plane.y * cos_val;
}

/*
 * ESC - exit
 * movement [W|A|S|D]
 * arrows	[<-|->]
 * ignore key release and key repeat (hold)
 */
void	handle_keypress(mlx_key_data_t kd, void *param)
{
	t_cub		*cub;
	t_ray		*ray;
	static int	i;

	cub = (t_cub *)param;
	if (kd.key == MLX_KEY_ESCAPE)
	{
		mlx_delete_image(cub->mlx, cub->image);
		mlx_close_window(cub->mlx);
		return ;
	}
	ray = cub->ray;
	wasd(cub, ray, kd.key);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT) || \
		mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		arrows(ray, kd.key);
	if (VERBOSE > 2)
	{
		if (i >= 0)
			i++;
		else
			i = 0;
		printf("DEBUG: hit = %f\n", ray->wall_distance);
		printf("DEBUG: i = %i, pos x: %f y: %f\n", i, ray->dir.x, ray->dir.y);
	}
}
