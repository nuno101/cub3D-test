/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:41 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/05 05:15:15 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**map;
	char	**map_values;
	int		_split_len;
	char	*_NO;
	char	*_SO;
	char	*_WE;
	char	*_EA;
	int		F[3];
	int		C[3];
}	t_data;

typedef struct s_cub
{
	t_data			*d;
	mlx_t			*mlx;
	int32_t			s_width;
	int32_t			s_height;
	mlx_image_t		*image;
	mlx_texture_t	*_NO;
	mlx_texture_t	*_SO;
	mlx_texture_t	*_WE;
	mlx_texture_t	*_EA;
	uint32_t		f;
	uint32_t		c;
	float			player_angle;
}	t_cub;

#endif