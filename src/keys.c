/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/28 15:35:54 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*
 * FIXME 
 * image missing rendering , maybe with mlx_loop_hook(render_ray)
*/
void	resize_screen(int32_t x, int32_t y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	cub->s_width = x;
	cub->s_height = y;
	//mlx_loop_hook(cub->mlx, &render_ray, cub);
}

/*
 * print key atm (TODOO implement movement [W|A|S|D] or arrows or both
 * maybe Menu/Pause
 * 
*/
void	cub_keys(mlx_key_data_t key, void *param)
{
	t_cub	*cub;

	(void)key;
	cub = (t_cub *)param;
	if (key.key == 256)
	{
		mlx_close_window(cub->mlx);
		mlx_delete_image(cub->mlx, cub->image);
	}
	if (key.key == 87) 
	{
		if (cub->ray->wall_distance >= 1)
		{
			cub->ray->dir.y += (cub->direction == 'E') * 0.04;
			cub->ray->dir.x += (cub->direction == 'S') * 0.04;
		}
		cub->ray->dir.x -= (cub->direction == 'N') * 0.04;
		cub->ray->dir.y -= (cub->direction == 'W') * 0.04;
		//printf("dir x = %f\nray dir y = %f\n", cub->ray->dir.x, cub->ray->dir.y);
		printf("hit = %f\n", cub->ray->wall_distance);
	}
	else if (key.key == 83) 
	{
		cub->ray->dir.y -= (cub->direction == 'E') * 0.04;
		cub->ray->dir.x -= (cub->direction == 'S') * 0.04;
		if (cub->ray->wall_distance >= 1)
		{
			cub->ray->dir.x += (cub->direction == 'N') * 0.04;
			cub->ray->dir.y += (cub->direction == 'W') * 0.04;	
		}
		printf("hit = %f\n", cub->ray->wall_distance);
	}
	else if (key.key == 68)
	{
		if (cub->ray->wall_distance >= 1)
		{
			cub->ray->dir.y += (cub->direction == 'N') * 0.04;
			cub->ray->dir.x += (cub->direction == 'E') * 0.04;
		}
		cub->ray->dir.y -= (cub->direction == 'S') * 0.04;
		cub->ray->dir.x -= (cub->direction == 'W') * 0.04;
		printf("hit = %f\n", cub->ray->wall_distance);
	}
	else if (key.key == 65)
	{
		
		cub->ray->dir.y -= (cub->direction == 'N') * 0.04;
		cub->ray->dir.x -= (cub->direction == 'E') * 0.04;
		if (cub->ray->wall_distance >= 1)
		{
			cub->ray->dir.y += (cub->direction == 'S') * 0.04;
			cub->ray->dir.x += (cub->direction == 'W') * 0.04;
		}
		printf("hit = %f\n", cub->ray->wall_distance);
	}
	//printf("key = %i\n", key.key);
}
