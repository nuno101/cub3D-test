/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/02/01 15:49:01 by jjesberg         ###   ########.fr       */
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
 * 0.4 is like a hitbox
 * xval & yval are +- operators which came from movement
 * because moving forward is increasing instead moving backwards will decrease
 * will check the char in the map array 
 * if there is a wall
 */
int	wall_hit(t_ray *ray, t_cub *cub, int x_val, int y_val)
{
	double x;
    double y;

    y = ray->pos.y + (ray->dir.y) * MOVE;
    x = ray->pos.x + (ray->dir.x) * MOVE;
    if (cub->d->map[(int)(x + HIT_BOX * x_val)][(int)ray->pos.y] == '1' || \
    cub->d->map[(int)(ray->pos.x)][(int)(y + HIT_BOX * y_val)] == '1')
        return 0;
    return 1;
}

void	wasd(t_cub *cub, t_ray *ray, int key)
{
	if (key == MLX_KEY_W && wall_hit(ray, cub, 1, 1))
	{
		ray->pos.x += ray->dir.x * MOVE;
		ray->pos.y += ray->dir.y * MOVE;
	}
	else if (key == MLX_KEY_S && wall_hit(ray, cub, -1, -1))
	{
		ray->pos.x -= ray->dir.x * MOVE;
		ray->pos.y -= ray->dir.y * MOVE;
	}
	else if (key == MLX_KEY_D && wall_hit(ray, cub, 1, -1))
	{
		ray->pos.x += ray->dir.y * MOVE;
		ray->pos.y -= ray->dir.x * MOVE;
	}
	else if (key == MLX_KEY_A && wall_hit(ray, cub, -1, 1))
	{
		ray->pos.x -= ray->dir.y * MOVE;
		ray->pos.y += ray->dir.x * MOVE;
	}
}

void	arrows(t_cub *cub, t_ray *ray, int key)
{
	(void)ray;
	(void)cub;
	double	val;

	val = -0.05;
	if (key == MLX_KEY_LEFT)
		val = 0.05;
	ray->delta_dir.x = ray->dir.x;
	ray->dir.x = ray->dir.x * cos(val) - ray->dir.y * sin(val);
	ray->dir.y = ray->delta_dir.x * sin(val) + ray->dir.y * cos(val);
	ray->delta_plane.x = ray->plane.x;
	ray->plane.x = ray->plane.x * cos(val) - ray->plane.y * sin(val);
	ray->plane.y = ray->delta_plane.x * sin(val) + ray->plane.y * cos(val);
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
		arrows(cub, ray, kd.key);
	if (VERBOSE > 0)
	{
		if (i >= 0)
			i++;
		else
			i = 0;
		printf("DEBUG: hit = %f\n", ray->wall_distance);
		printf("DEBUG: i = %i, pos x: %f y: %f\n", i, ray->dir.x, ray->dir.y);
	}
}
