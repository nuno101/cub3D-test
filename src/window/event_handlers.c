/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/31 02:39:08 by jjesberg         ###   ########.fr       */
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

/* TODOO 
 * Check if player would hit wall after that move 
 * segerror if
 * atm we stuck in wall before entering segfaults
 */
int	wall_hit(t_ray *ray, t_cub *cub)
{
	(void)cub;
	(void)ray;
	int x = ray->pos.x + ray->dir.x * 0.05;
	int y = ray->pos.y + ray->dir.y * 0.05;
	if (x > 0 && y > 0 && y < cub->d->map_height && cub->d->map[y][x] == '0')
		return (0);
	return (1);
}

void	wasd(t_cub *cub, t_ray *ray, int key)
{
	if (key == MLX_KEY_W && !wall_hit(ray, cub))
	{
		ray->pos.x += ray->dir.x * 0.05;
		ray->pos.y += ray->dir.y * 0.05;
	}
	else if (key == MLX_KEY_S && !wall_hit(ray, cub))
	{
		ray->pos.x -= ray->dir.x * 0.05;
		ray->pos.y -= ray->dir.y * 0.05;
	}
	else if (key == MLX_KEY_D && !wall_hit(ray, cub))
	{
		ray->pos.x += ray->dir.y * 0.05;
		ray->pos.y -= ray->dir.x * 0.05;
	}
	else if (key == MLX_KEY_A && !wall_hit(ray, cub))
	{
		ray->pos.x -= ray->dir.y * 0.05;
		ray->pos.y += ray->dir.x * 0.05;
	}
}

void	arrows(t_cub *cub, t_ray *ray, int key)
{
	(void)ray;
	(void)cub;
	if (key == MLX_KEY_LEFT)
	{
		printf("FIXME: look left\n");
		return ;
	}
	else if (key == MLX_KEY_RIGHT)
	{
		printf("FIXME: look right\n");
		return ;
	}
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
