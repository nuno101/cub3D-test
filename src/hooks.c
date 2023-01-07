/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:11:23 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/07 21:20:59 by jjesberg         ###   ########.fr       */
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

static t_ray	*init_ray(t_cub *m, float r_angle, t_coords pos)
{
	t_ray	*ray;

	(void)pos;
	(void)r_angle;
	(void)m;
	ray = malloc(sizeof(t_ray));

	return (ray);
}

float	ray_angle_fix(t_cub *m, int i)
{
	float	screen_halflen;
	float	seg_len;

	screen_halflen = tanf(m->fov / 2);
	seg_len = screen_halflen / (m->s_width / 2);
	return (atanf(seg_len * i - screen_halflen));
}

void	render_ray(void	*param)
{
	t_cub	*m;
	int		i;
	float	r_angle;

	m = (t_cub*)param;
	i = 0;
	m->ray = malloc(sizeof(t_ray) * (m->s_width + 1));
	if (!m->ray)
		exit(cub_error(MALLOC_ERROR));
	while (i < m->s_width)
	{
		r_angle = m->player_angle + ray_angle_fix(m, i);
		m->ray[i] = init_ray(m, r_angle, m->player_pos);
		i++;
	}
	m->ray[i] = NULL;
}

void	hooks(t_cub *m)
{
	mlx_key_hook(m->mlx, &cub_keys, m);
	mlx_resize_hook(m->mlx, &resize_screen, m);
	mlx_loop_hook(m->mlx, &render_ray, m);
	mlx_loop(m->mlx);
}