/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:41 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/20 15:40:58 by jjesberg         ###   ########.fr       */
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
	int				tmp[4];
}	t_data;

typedef struct i_coords
{
	int		x;
	int		y;
}	i_coords;

typedef struct f_coords
{
	double		x;
	double		y;
}	f_coords;

typedef struct s_ray
{
	f_coords	pos;
	f_coords	dir;
	f_coords	old_dir;
	f_coords	plane;
	f_coords	old_plane;
	f_coords	ray_dir;
	double		camera;
	
	double		perp_wall_dist;
	f_coords	side_dist;
	f_coords	delta_dist;
	i_coords	map;
	i_coords	step;
	int			hit;
	int			side;
}	t_ray;

typedef struct s_cub
{
	bool			exit;
	t_data			*d;
	mlx_t			*mlx;
	int32_t			s_width;
	int32_t			s_height;
	mlx_image_t		*image;
	uint32_t		f;
	uint32_t		c;
	i_coords		player_pos;
	char			direction;
	t_ray			*ray;
}	t_cub;

#endif
