/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:11:23 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/14 15:24:57 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	screensize(t_cub *cub)
{
	if (!cub->mlx)
		exit(cub_error(MLX_ERROR));
	mlx_get_monitor_size(0, &cub->s_width, &cub->s_height);
	mlx_terminate(cub->mlx);
	cub->mlx = mlx_init(cub->s_width, cub->s_height, "Cub3D", true);
}

void	init_ray(t_ray *ray, int x, t_cub *cub)
{

	ray->cam = 2 * x / cub->s_width - 1;
}

void	render_ray(void	*param)
{
	t_cub	*cub;
	int		x;

	x = 0;
	cub = (t_cub *)param;
	skyline(cub);
	while (x < cub->s_width)
	{
		init_ray(cub->ray, x, cub);
		x++;
	}	
}

void	hooks(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, &render_ray, cub);
	mlx_key_hook(cub->mlx, &cub_keys, cub);
	mlx_resize_hook(cub->mlx, &resize_screen, cub);
	mlx_loop(cub->mlx);
}
