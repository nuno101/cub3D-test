/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:53:59 by jjesberg          #+#    #+#             */
/*   Updated: 2023/02/04 12:36:36 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
 * define cub3d specific errors
 * start at 256 to not overwrite OS error codes
 * need include guard for compiling in linux, because multiple definition if not.
 */
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
	COLOUR_PRESENCE_ERROR,
	MAP_ERROR,
	MLX_ERROR,
	PNG_ERROR,
	TEX_PRESENCE_ERROR,
	TEX_PATH_ERROR,
	TEX_MLX_LOAD_PNG_ERROR,
	PLAYER_ERROR,
	P_SURROUNDED_ERROR,
	W_SURROUNDED_ERROR,
	PLAYER_NOT_FOUND_ERROR,
}	t_error;

/*
 * define cub3d texture codes starting at 1 
 * NONE - not a texture
 * NO - North texture
 * SO - South texture
 * WE - West texture
 * EA - East texture
 */
enum	e_textures { NONE = -1, NO, SO, WE, EA } t_texture;

/*
 * define reasonable global constants for ray directions calculations
 */
static const int	g_ray_dir_x[] = {-1, 0, 1, 0};
static const int	g_ray_dir_y[] = {0, 1, 0, -1};
static const double	g_plane_x[] = {0, 0.66, 0, -0.66};
static const double	g_plane_y[] = {0.66, 0, -0.66, 0};

/*
 * player move step
 */
# define MOVE 0.1

#endif
