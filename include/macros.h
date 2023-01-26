/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <j.jesberger@heilbronn.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:02:43 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/26 17:20:23 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
 * define cub3d specific errors
 * start at 256 to not overwrite OS error codes
 * need include guard for compiling in linux, because multiple definition if not.
 */
#ifndef t_error
# define t_error
enum	e_cub3d_errors
{
	ARG_ERROR = 256,
	ARG_FILENAME_ERROR,
	EMPTY_FILE_ERROR,
	FILE_ERROR,
	FILE_TOO_SHORT_ERROR,
	INVALID_MAP,
	MALLOC_ERROR,
	DIR_ERROR,
	COLOUR_ERROR,
	MAP_ERROR,
	MLX_ERROR,
	PNG_ERROR,
	TEX_PRESENCE_ERROR,
	TEX_PATH_ERROR,
	TEX_MLX_LOAD_PNG_ERROR,
	PLAYER_ERROR,
	P_SURROUNDED_ERROR,
	W_SURROUNDED_ERROR,
}	t_error;
#endif
/*
 * define cub3d texture codes starting at 1 
 * NONE - not a texture
 * NO - North texture
 * SO - South texture
 * WE - West texture
 * EA - East texture
 */
#ifndef t_texture
# define t_texture
enum	e_textures { NONE = -1, NO, SO, WE, EA } t_texture;
#endif

#ifndef ray_direction_consts
#define ray_direction_consts
static	const int RAY_DIR_X[] = {-1, 0, 1, 0};
static	const int RAY_DIR_Y[] = {0, 1, 0, -1};
static	const double PLANE_X[] = {0, 0.66, 0, -0.66};
static	const double PLANE_Y[] = {0.66, 0, -0.66, 0};
#endif

#endif
