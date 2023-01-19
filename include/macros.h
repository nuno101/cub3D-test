/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:02:43 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/19 10:46:57 by nlouro           ###   ########.fr       */
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
	FILE_ERROR,
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

/*
 * define cub3d texture codes starting at 1 
 * NONE - not a texture
 * NO - North texture
 * SO - South texture
 * WE - West texture
 * EA - East texture
 */
enum	e_textures { NONE = -1, NO, SO, WE, EA } t_texture;

#endif
