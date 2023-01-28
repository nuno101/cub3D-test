/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:41 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 16:03:42 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	char			**map;
	mlx_texture_t	*textures[4];
	uint32_t		f_colour;
	uint32_t		c_colour;
}	t_data;

typedef struct i_coords
{
	int		x;
	int		y;
}	t_i_coords;

typedef struct f_coords
{
	double	x;
	double	y;
}	t_f_coords;

typedef struct s_ray
{
	t_f_coords	pos;
	t_f_coords	dir;
	t_f_coords	plane;
	t_f_coords	ray_dir;
	double		camera;
	double		wall_distance;
	t_f_coords	side_dist;
	t_f_coords	delta_dist;
	t_i_coords	map;
	t_i_coords	step;
	int			hit;
	int			side;
}	t_ray;

typedef struct s_cub
{
	t_data			*d;
	mlx_t			*mlx;
	int32_t			s_width;
	int32_t			s_height;
	mlx_image_t		*image;
	uint32_t		f_colour;
	uint32_t		c_colour;
	t_i_coords		player_pos;
	char			direction;
	t_ray			*ray;
}	t_cub;

#endif
