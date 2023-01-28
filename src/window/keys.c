/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
<<<<<<< HEAD:src/keys.c
/*   Updated: 2023/01/28 15:35:54 by jjesberg         ###   ########.fr       */
=======
/*   Updated: 2023/01/27 12:38:03 by nlouro           ###   ########.fr       */
>>>>>>> ad49248bab4489fe8af04a9903de9ee233ccb502:src/window/keys.c
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

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
 * TODO: prepare image for display in new position
 * may need several images to reach the new postion in smal steps
 */
void	move_fwd(void)
{
	printf("TODO: move forward");
}

/*
 * TODO implement movement [W|A|S|D] and look to side [arrows]
 * key codes:
 * ESC 256
 * W 87 - move forward
 * A 65 - move left
 * S 83 - move back
 * D 68 - move right
 * Left-arrow 263 - look left
 * Right-arrow 262
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
<<<<<<< HEAD:src/keys.c
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
=======
	else if (key.key == 87)
		move_fwd();
	printf("DEBUG: key code: %i\n", key.key);
>>>>>>> ad49248bab4489fe8af04a9903de9ee233ccb502:src/window/keys.c
}
