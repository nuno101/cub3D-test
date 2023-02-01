/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:02:43 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/28 19:44:49 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//FIXME: comply with norminette before submission. Required changes make 
// compilation in Linux fail so do not change now.
#ifndef MACROS_H
# define MACROS_H

#define MOVE 0.05
#define HIT_BOX 0.4

/*
 * define cub3d specific errors
 * start at 256 to not overwrite OS error codes
 * need include guard for compiling in linux, because multiple definition if not.
 */
#ifndef E_ERRORS
# define E_ERRORS

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
	PLAYER_NOT_FOUND_ERROR,
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
#ifndef E_TEXTURES
# define E_TEXTURES

enum	e_textures { NONE = -1, NO, SO, WE, EA } t_texture;
#endif

/*
 * constants for ray directions calculations
 */
#ifndef RAY_DIRECTION_CONSTS
#define RAY_DIRECTION_CONSTS

static const int	g_ray_dir_x[] = {-1, 0, 1, 0};
static const int	g_ray_dir_y[] = {0, 1, 0, -1};
static const double	g_plane_x[] = {0, 0.66, 0, -0.66};
static const double	g_plane_y[] = {0.66, 0, -0.66, 0};
#endif

#endif
