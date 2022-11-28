/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:00:53 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/22 14:12:11 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "structs.h"
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


/*
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
};*/

//src/init.c
int	init_map(int argc, char **argv, t_data *data);

//src/map_reader.c
int	map_reader(t_data *data);

#endif