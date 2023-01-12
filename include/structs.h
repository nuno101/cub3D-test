/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:41 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/11 06:49:59 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_coords
{
	int		x;
	int		y;
}	t_coords;

typedef struct s_data
{
	t_coords		player_pos;
	char			*map_path; // map path
	char			**map_data; //map data
	char			**map; //map
	mlx_texture_t	*textures[4];
	uint32_t		f_colour;
	uint32_t		c_colour;
	int				tmp[4];
}	t_data;


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
	int32_t			s_width; //window width its dynamic
	int32_t			s_height; //window height its dynamic
	mlx_image_t		*image;
	uint32_t		f;
	uint32_t		c;
	float			player_angle;
	t_coords		player_pos; // player pos not set yet
	float			fov;
	t_ray			*ray;
}	t_cub;

#endif