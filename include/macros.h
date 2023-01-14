/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:02:43 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/14 23:37:29 by nlouro           ###   ########.fr       */
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
	FILE_ERROR,
	INVALID_MAP,
	MALLOC_ERROR,
	DIR_ERROR,
	COLOUR_ERROR,
	MAP_ERROR,
	MLX_ERROR,
	PNG_ERROR,
	TEX_PATH_ERROR,
	PLAYER_ERROR,
	P_SURROUNDED_ERROR,
	W_SURROUNDED_ERROR,
}	t_error;
#endif

/*
 * define cub3d texture codes starting at 1 
 * NO - North texture
 * SO - South texture
 * WE - West texture
 * EA - East texture
 */
#ifndef t_texture
# define t_error
enum	e_textures { NO, SO, WE, EA } t_texture;
#endif

#endif
