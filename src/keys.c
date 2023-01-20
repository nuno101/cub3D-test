/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/20 15:34:39 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	resize_screen(int32_t x, int32_t y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	cub->s_width = x;
	cub->s_height = y;
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
	printf("key = %i\n", key.key);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
	{
		printf("cub_keys: Escape pressed!\n");
		//clean_mlx(cub);
		//free_data(cub->d);
		//free_cub(cub);
		mlx_terminate(cub->mlx);
	}
}
