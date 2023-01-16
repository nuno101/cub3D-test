/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:19:44 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/15 00:44:04 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	free_data(t_data *data)
{
	ft_cleansplit(data->map);
	ft_cleansplit(data->raw_data);
	free(data);
}

void	clean_mlx(t_cub *m)
{
	mlx_delete_image(m->mlx, m->image);
	mlx_delete_texture(m->d->textures[0]);
	mlx_delete_texture(m->d->textures[1]);
	mlx_delete_texture(m->d->textures[2]);
	mlx_delete_texture(m->d->textures[3]);
	mlx_terminate(m->mlx);
}

void	free_cub(t_cub *cub)
{
	free(cub->ray);
	free(cub);
}
