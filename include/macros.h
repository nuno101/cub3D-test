/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:02:43 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/14 10:41:39 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "cub.h"

/*
 * define cub3d specific errors
 * start at 256 to not overwrite OS error codes
 */
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

#define NO 101
#define SO 102
#define WE 103
#define EA 104

#endif
