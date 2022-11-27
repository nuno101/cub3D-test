/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:06:45 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/27 17:14:13 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

t_map	*init_map(void)
{
	t_map	*data;

	data = (t_map *)malloc(sizeof(t_map));
	data->head = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->map_h = 0;
	data->map_w = 0;
	data->map_w = INT_MIN;
	data -> ceil_clr = 0x000000;		// Adjustments may be needed here
	data -> floor_clr = 0x000000;	    // Adjustments may be needed here
	data->shift_x = 0;
	data->shift_y = 0;
	data->zoom = 0;
	return (data);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!mlx)
		error(MALLOC_ERR);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Cub3D");
	mlx->img.img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,// bits_per_pixel = bpp :)
			&mlx->img.line_len, &mlx->img.endian);
	return (mlx);
}

void	init_xpm(t_player *pl)
{
	pl->pos = find_pos(pl->data->map);
	idx2tile(pl->data, pl->pos);
	pl->dir = find_dir(pl->data->map, pl->pos);
	pl->dir->i = pl->pos->i;
	pl->dir->j = pl->pos->j;
	pl->rend_dist = pl->data->max_w * pl->data->zoom;
	pl->fov = 60;
	init_xpm(pl);
}

void	init_flag(t_flag *flag)
{
	flag->empty_line = WALL_BEFORE_EMPTY_NOT_EXIST;
	flag->dup_floor = FLOOR_NOT_CHANGED;
	flag->dup_ceil = CEIL_NOT_CHANGED;
}
