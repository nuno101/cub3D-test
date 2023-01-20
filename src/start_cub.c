/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:06:10 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/20 17:55:50 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	start_cub(t_data *data)
{
	t_cub	*cub;

	cub = init_cub(data);
	if (mlx_image_to_window(cub->mlx, cub->image, 0, 0) < 0)
		exit(cub_error(MLX_ERROR));
	hooks(cub);
	clean_mlx(cub);
	free_cub(cub);
}
