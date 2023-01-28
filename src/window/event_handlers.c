/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/28 21:31:47 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

/*
 * update sreen sixe in cub struct
 */
void	handle_screen_resize(int32_t x, int32_t y, void *param)
{
	t_cub	*cub;
	static	int i;

	cub = (t_cub *)param;
	if (VERBOSE > 0)
	{
		if (i >= 0)
			i++;
		else
			i = 0;
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
 * TODO implement look to left and right [arrows]
 * ESC - exit
 * movement [W|A|S|D]
 * ignore key release and key repeat (hold)
 */
void	handle_keypress(mlx_key_data_t kd, void *param)
{
	t_cub	*cub;
	t_ray	*ray;
	static	int i;

	if (kd.action != MLX_PRESS)
		return;
	cub = (t_cub *)param;
	if (kd.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(cub->mlx);
		mlx_delete_image(cub->mlx, cub->image);
		return ;
	}
	ray = cub->ray;
	if (kd.key == MLX_KEY_W) 
	{
		if (ray->wall_distance >= 1)
		{
			ray->dir.y += (cub->direction == 'E') * 0.04;
			ray->dir.x += (cub->direction == 'S') * 0.04;
		}
		ray->dir.x -= (cub->direction == 'N') * 0.04;
		ray->dir.y -= (cub->direction == 'W') * 0.04;
		//printf("dir x = %f\nray dir y = %f\n", ray->dir.x, ray->dir.y);
	}
	else if (kd.key == MLX_KEY_S)
	{
		ray->dir.y -= (cub->direction == 'E') * 0.04;
		ray->dir.x -= (cub->direction == 'S') * 0.04;
		if (ray->wall_distance >= 1)
		{
			ray->dir.x += (cub->direction == 'N') * 0.04;
			ray->dir.y += (cub->direction == 'W') * 0.04;	
		}
	}
	else if (kd.key == MLX_KEY_D)
	{
		if (ray->wall_distance >= 1)
		{
			ray->dir.y += (cub->direction == 'N') * 0.04;
			ray->dir.x += (cub->direction == 'E') * 0.04;
		}
		ray->dir.y -= (cub->direction == 'S') * 0.04;
		ray->dir.x -= (cub->direction == 'W') * 0.04;
	}
	else if (kd.key == MLX_KEY_A)
	{
		
		ray->dir.y -= (cub->direction == 'N') * 0.04;
		ray->dir.x -= (cub->direction == 'E') * 0.04;
		if (ray->wall_distance >= 1)
		{
			ray->dir.y += (cub->direction == 'S') * 0.04;
			ray->dir.x += (cub->direction == 'W') * 0.04;
		}
	}
	else if (kd.key == MLX_KEY_LEFT)
	{
		printf("FIXME: look left\n");
		return ;
	}
	else if (kd.key == MLX_KEY_RIGHT)
	{
		printf("FIXME: look right\n");
		return ;
	}
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
