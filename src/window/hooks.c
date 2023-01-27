/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 21:11:23 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 12:37:53 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	hooks(t_cub *cub)
{
	mlx_loop_hook(cub->mlx, &render_ray, cub);
	mlx_key_hook(cub->mlx, &cub_keys, cub);
	mlx_resize_hook(cub->mlx, &resize_screen, cub);
	mlx_loop(cub->mlx);
}
