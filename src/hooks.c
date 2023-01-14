/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:11:23 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/14 14:46:59 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	screensize(t_cub *m)
{
	if (!m->mlx)
		exit(cub_error(MLX_ERROR));
	mlx_get_monitor_size(0, &m->s_width, &m->s_height);
	mlx_terminate(m->mlx);
	m->mlx = mlx_init(m->s_width, m->s_height, "Cub3D", true);
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

void	hooks(t_cub *m)
{
	mlx_loop_hook(m->mlx, &render_ray, m);
	mlx_key_hook(m->mlx, &cub_keys, m);
	mlx_resize_hook(m->mlx, &resize_screen, m);
	mlx_loop(m->mlx);
}
