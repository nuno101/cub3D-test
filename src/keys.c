/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:16:40 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/13 17:54:20 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	resize_screen(int32_t x, int32_t y, void *param)
{
	t_cub	*m;

	m = (t_cub *)param;
	m->s_width = x;
	m->s_height = y;
	skyline(m);
}

void	cub_keys(mlx_key_data_t key, void *param)
{
	t_cub	*tmp;

	(void)key;
	tmp = (t_cub *)param;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_ESCAPE))
	{
		clean_mlx(tmp); 
		write(1, "Exit cub3D\n", 11);
		exit (0);
	}
}
