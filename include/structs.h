/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:41 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/12 12:47:15 by ezpiro-m         ###   ########.fr       */
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
	t_coords	pos;
	t_coords	wall_pos;
	float		len;
	float		eye_len;
	char		wall_face;
	float		pos_on_wall;
	char		wall_type;
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
	t_ray			**ray;
}	t_cub;

#endif