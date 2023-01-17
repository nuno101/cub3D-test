/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/14 15:25:27 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	resize_screen(int32_t x, int32_t y, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	cub->s_width = x;
	cub->s_height = y;
	skyline(cub);
}

void	cub_keys(mlx_key_data_t key, void *param)
{
	t_cub	*cub;

	(void)key;
	cub = (t_cub *)param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
	{
		clean_mlx(cub); 
		free_cub(cub);
		write(1, "Exit cub3D\n", 11);
		exit (0);
	}
}
