/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 10:42:58 by nlouro           ###   ########.fr       */
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
	else if (key.key == 87)
		move_fwd();
	printf("DEBUG: key code: %i\n", key.key);
}
