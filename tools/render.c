/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:47:49 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/05 08:49:05 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

static t_ray	*init_ray(t_cub *m, float r_angle, t_coords pos)
{
	t_ray	*ray;

	(void)pos;
	(void)r_angle;
	(void)m;
	ray = malloc(sizeof(t_ray) * 2);

	return (ray);
}

void	skyline(t_cub *m)
{
	int32_t			i;

	i = 0;
	while (i < m->s_width * m->s_height)
	{
		if (i < m->s_width * (m->s_height / 2))
			mlx_put_pixel(m->image, i, 0, m->c);
		else
			mlx_put_pixel(m->image, i, 0, m->f);
		i++;
	}
}

float	ray_angle_fix(t_cub *m, int i)
{
	float	screen_halflen;
	float	seg_len;

	screen_halflen = tanf(m->fov / 2);
	seg_len = screen_halflen / (m->s_width / 2);
	return (atanf(seg_len * i - screen_halflen));
}

void	render_map(void	*param)
{
	t_cub	*m;
	int		i;
	float	r_angle;

	m = (t_cub*)param;
	i = 0;
	m->ray = malloc(sizeof(t_ray) * (m->s_width + 1));
	if (!m->ray)
		exit(error(MALLOC_ERROR));
	while (i < m->s_width)
	{
		r_angle = m->player_angle + ray_angle_fix(m, i);
		m->ray[i] = init_ray(m, r_angle, m->player_pos);
		i++;
	}
	m->ray[i] = NULL;
}
