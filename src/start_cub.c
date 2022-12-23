/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 06:37:19 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/23 07:02:09 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"


static int	screensize(t_cub *m)
{
	int width, height;

	mlx_get_monitor_size(0, &m->s_width, &m->s_height);
	return 0;
}

int	start_cub(t_data *data)
{
	t_cub	*m;

	m = malloc(sizeof(t_cub));
	m->d = data;
	m->mlx = mlx_init(10, 10, "MLX", true);
	if (!m->mlx)
		return (MALLOC_ERROR);
	screensize(m);
	m->mlx = mlx_init(m->s_width, m->s_height, "MLX", true);
	if (!m->mlx)
		return (MALLOC_ERROR);
	mlx_loop(m->mlx);
	return (0);
}