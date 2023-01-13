/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:41 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/13 17:49:44 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	char			*map_path;
	char			**map_data;
	char			**map;
	mlx_texture_t	*textures[4];
	uint32_t		f_colour;
	uint32_t		c_colour;
	int				tmp[4];
}	t_data;

typedef struct s_coords
{
	int		x;
	int		y;
}	t_coords;

typedef	struct s_ray
{
	float		cam;
	int			hit;
	int			side;
	float		wall;
	t_coords	c_ray;
	t_coords	c_map;
	t_coords	c_side;
	t_coords	c_delta;
	t_coords	c_step;
	t_coords	c_p;
	t_coords	c_d;
	t_coords	c_w;
}	t_ray;

typedef struct s_cub
{
	t_data			*d;
	mlx_t			*mlx;
	int32_t			s_width;
	int32_t			s_height;
	mlx_image_t		*image;
	uint32_t		f;
	uint32_t		c;
	float			player_angle;
	t_coords		player_pos;
	float			fov;
	t_ray			*ray;
}	t_cub;

#endif