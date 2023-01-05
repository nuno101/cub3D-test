/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 04:47:49 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/05 05:22:49 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

void	skyline(t_cub *m)
{
	int32_t			i;

	i = 0;
	while (i < m->s_width * m->s_height)
	{
		if (i < m->s_width * (m->s_height / 2))
			mlx_put_pixel(m->image, i, 0, m->c);
		else if (i > m->s_width * (m->s_height / 2))
			mlx_put_pixel(m->image, i, 0, m->f);
		i++;
	}
}

void	render_map(void	*param)
{
	t_cub	*m;
	int		i;
	float	r_angle;

	(void)r_angle;
	m = (t_cub*)param;
	i = 0;
	while (i < m->s_width)
	{
		i++;
	}
}