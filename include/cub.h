/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:53 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/15 21:11:56 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
# include "error.h"
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct s_data
{
	int		argc;
	char	**argv;
	char	**map;
}				t_data;

typedef	struct s_player
{
	int		x;
	int		y;
	int		orientation;
}				t_player;
			
typedef struct s_cub
{
	t_data			data;
	t_player		player;
	struct t_mlx	*mlx;
}				t_cub;

typedef	struct s_map
{
	char	*es;
	char	*no;
	char	*so;
	char	*we;
	int		floor;
	int		ceiling;
	char 	**map;
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