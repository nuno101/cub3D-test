/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:06:10 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/20 16:12:25 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	skyline(t_cub *cub)
{
	uint32_t			i;
	uint32_t			j;

	i = 0;
	while (i < (uint32_t)cub->s_height)
	{
		j = 0;
		while (j < (uint32_t)cub->s_width)
		{
			if (i < (uint32_t)cub->s_height / 2)
				mlx_put_pixel(cub->image, j, i, cub->d->c_colour);
			else
				mlx_put_pixel(cub->image, j, i, cub->d->f_colour);
			j++;
		}
		i++;
	}
}

void	start_cub(t_data *data)
{
	t_cub	*cub;

	cub = init_cub(data);
	cub->exit = false;
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) < 0)
		exit(cub_error(MLX_ERROR));
	hooks(cub);
	clean_mlx(cub);
	free_cub(cub);
}
