/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:53 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/21 15:28:03 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "error.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 1024;
# define HEIGHT 780;
# define MINIMAP_W 300;

# ifdef __APPLE__

enum e_keys {
	IS_MAC = 90,
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	LEFT = 123,
	RIGHT = 124,
	// UP = 126,
	// DOWN = 125,
};

#endif

# ifdef __linux__

enum e_keys {
	IS_MAC = 91,
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	LEFT = 65361,
	RIGHT = 65363,
	// UP = 65362,
	// DOWN = 65364,
};

#endif

enum e_err
{
	FILE_ERROR,
	// MALLOC_ERROR,
	// ARG_ERROR,
	RGB_ERROR,
	RGB_OUT_OF_BONUS,
	RGB_TOO_MANY,
	RGB_TOO_FEW,
	MAP_DUP_ERROR,
	MAP_EXCESS_CHAR,
	MAP_NOT_CLOSED,
	EXT_ERR,
	MAP_ERR,
};

enum e_general
{
	ON_DESTROY = 17,
	ON_MOUSEMOVE = 6,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	// COLOR 0X000000FF,
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
};

enum e_flag
{
	WALL_BEFORE_EMPTY_NO_EXIST,
	WALL_AFTER_EMPTY_EXIST,
	EMPTY_AFTER_WALL_EXIST,
	FLOOR_NOT_CHANGED,
	FLOOR_CHANGED,
	CEIL_NOT_CHANGED,
	CEIL_CHANGED,
};

typedef struct s_map
{
	char	*line;
	int		len;
}				t_map;

typedef struct s_point
{
	float	x;
	float	y;
	int		i;
	int		j;
	float	angle;
}				t_point;

typedef struct s_flag
{
	int	empty_line;
	int	dup_ceil;
	int	dup_floor;
};			t_flag;

typedef	struct	s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_clr;
	int		ceil_clr;
	char	**map;
	t_list	head;
	int		map_h;
	int		map_w;
	int		max_w;
	int		zoom;
	int		shift_x;
	int		shift_y;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_xpm
{
	t_img	tx_img;
	char	*path;
	int		img_w;
	int		img_h;
}			t_xpm;

typedef struct s_ray
{
	t_point	pos;
	float	step_x;
	float	step_y;
	float	side_x;
	float	side_y;
	float	dir_x;
	float	dir_y;
	float	dist;
	float	shade;
	int		dx;
	int		dy;
	int		side;
}				t_ray;

typedef struct s_tex
{
	int		x;
	int		y;
	float	pos;
	float	step;
	int		clr;
}			t_tex;

typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**map;
}				t_data;

typedef	struct	s_player
{
	t_map	*data;
	struct	s_mlx	*mlx;
	t_point	pos;
	t_point	dir;
	int		tex_flag;
	int		rend_dist;
	float	fov;
}				t_player;

typedef struct s_cub
{
	t_data			data;
	t_player		player;
	struct s_mlx	*mlx;
	struct s_cub	*cub;
	int				**map;
	// int			map_width;
	// int			map_height;
	// int			map_width_max;
	// int			map_height_max;
	// int			map_width_min;
	// int			map_height_min;
	int				pos_x;
	int				pos_y;
	int				dir_x;
	int				dir_y;
	int				plane_x;
	int				plane_y;
	int				move_speed;
	int				key;
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_left;
	int				key_right;
	int				key_esc;
	struct s_cub	rot_speed;
}				t_cub;

typedef	struct	s_map
{
	char	*es;
	char	*no;
	char	*so;
	char	*we;
	int		floor;
	int		ceiling;
	char	**map;
	t_list	*__head;
	int		map_height;
	int		map_weight;
	int		max_weight;
	int		shift_x;
	int		shift_y;
	int		zoom;
	mlx_t	*mlx;
}				t_map;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
	int		esc;
}				t_keys;

//src/init.c
int	init_map(int argc, char **argv, t_data *data);

//src/map_reader.c
int	map_reader(t_data *data);

#endif