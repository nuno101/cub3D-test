/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:19:44 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/14 14:48:57 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	free_data(t_data *data)
{
	mlx_delete_texture(data->textures[0]);
	mlx_delete_texture(data->textures[1]);
	mlx_delete_texture(data->textures[2]);
	mlx_delete_texture(data->textures[3]);
	ft_cleansplit(data->map);
	ft_cleansplit(data->map_data);
	free(data);
}

void	free_cub(t_cub *cub)
{
	free(cub->ray);
	free(cub);
}