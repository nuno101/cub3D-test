/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 06:37:19 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/05 04:55:28 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

static void	resize_screen(int32_t x, int32_t y, void *param)
{
	t_cub 			*m;

	m = (t_cub*)param;
	m->s_width = x;
	m->s_height = y;
	skyline(m); //maybe leaks because we overwrite old images
}

static void	hooks(t_cub *m)
{
	mlx_key_hook(m->mlx, &cub_keys, m);
	mlx_resize_hook(m->mlx, &resize_screen, m);
	mlx_loop_hook(m->mlx, &render_map, m);
	mlx_loop(m->mlx);
}

void	start_cub(t_data *data)
{
	t_cub	*m;

	m = init_cub(data);
	skyline(m);
	hooks(m);
	clean_mlx(m);
	exit(error(EXIT_SUCCESS));
}
