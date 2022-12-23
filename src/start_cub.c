/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 06:37:19 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/23 07:38:01 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"


static int	screensize(t_cub *m)
{
	mlx_get_monitor_size(0, &m->s_width, &m->s_height);
	return 0;
}

void	x_button(void *param)
{
	t_cub	*tmp;

	tmp = (t_cub*)param;

}

int	start_cub(t_data *data)
{
	t_cub	*m;

	m = malloc(sizeof(t_cub));
	m->d = data;
	m->mlx = mlx_init(100, 100, "MLX", true);
	if (!m->mlx)
		return (MALLOC_ERROR);
	screensize(m);
	mlx_loop(m->mlx);
	mlx_terminate(m->mlx);
	free(m);
	return (0);
}