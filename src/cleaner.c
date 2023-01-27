/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:19:44 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 16:38:08 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	clean_mlx(t_cub *m)
{
	mlx_delete_image(m->mlx, m->image);
	mlx_delete_texture(m->d->textures[0]);
	mlx_delete_texture(m->d->textures[1]);
	mlx_delete_texture(m->d->textures[2]);
	mlx_delete_texture(m->d->textures[3]);
	mlx_terminate(m->mlx);
}
