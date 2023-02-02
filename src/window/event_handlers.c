/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/02/02 13:32:30 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * update sreen sixe in cub struct
 * TODOO CHECK:
 * In Linux "DEBUG: Resizing screen..." is
 * always printed, so 'i' should be higher then 1, maybe in MAc too??
 */
void	handle_screen_resize(int32_t x, int32_t y, void *param)
{
	t_cub		*cub;
	static int	i;

	cub = (t_cub *)param;
	if (VERBOSE > 0)
	{
		if (i >= 0)
			i++;
		else
			i = 0;
		if (i != 1)
			printf("DEBUG: Resizing screen... %i \n", i);
	}
	cub->s_width = x;
	cub->s_height = y;
}

/*
 * TODO: prepare image for display in new position
 * may need several images to reach the new postion in smal steps
 */
void	move_fwd(void)
{
	if (VERBOSE > 0)
		printf("TODO: move forward");
}
/*
 * xval & yval are +- operators which came from movement
 * because moving forward is increasing instead moving backwards will decrease
 * will check the char in the map array 
 * if there is a wall
 */
int	wall_hit(t_ray *ray, t_cub *cub, int x_val, int y_val)
{
	double	x;
    double	y;
	double	i;

	i = 1.0;
	while (i < 5)
	{
		y = ray->pos.y + (ray->dir.y) * y_val * i * MOVE;
  		x = ray->pos.x + (ray->dir.x) * x_val * i * MOVE;
		if (x < 1.2|| y < 1.2 || x + 1.2 > (double)cub->d->map_height)
			return (0);
		if (cub->d->map[(int)(x)][(int)ray->pos.y] == '1' \
		|| cub->d->map[(int)(ray->pos.x)][(int)(y)] == '1')
			return (0);
		i += 1.0;
	}
    return (1);
}

void	wasd(t_cub *cub, t_ray *ray, int key)
{
	double	move;

	move = MOVE;
	if (key == MLX_KEY_W && wall_hit(ray, cub, 1, 1))
	{
		ray->pos.x += ray->dir.x * move;
		ray->pos.y += ray->dir.y * move;
	}
	else if (key == MLX_KEY_S && wall_hit(ray, cub, -1, -1))
	{
		ray->pos.x -= ray->dir.x * move;
		ray->pos.y -= ray->dir.y * move;
	}
	else if (key == MLX_KEY_D && wall_hit(ray, cub, 1, -1))
	{
		ray->pos.x += ray->dir.y * move;
		ray->pos.y -= ray->dir.x * move;
	}
	else if (key == MLX_KEY_A && wall_hit(ray, cub, -1, 1))
	{
		ray->pos.x -= ray->dir.y * move;
		ray->pos.y += ray->dir.x * move;
	}
}

void	arrows(t_ray *ray, int key)
{
	double	val;
	double	cos_val;
	double	sin_val;
	double	delta_dir_x;
	double	delta_plane_x;

	val = -0.05;
	if (key == MLX_KEY_LEFT)
		val = 0.05;
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
 * TODO implement look to left and right [arrows]
 * ESC - exit
 * movement [W|A|S|D]
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
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT) || mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
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
