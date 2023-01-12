/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:27:46 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/12 14:57:06 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	cub_error(int err)
{
	if (err == ARG_ERROR)
		return (write(STDERR_FILENO, "ERROR ARGS\n", 11));
	if (err == FILE_ERROR)
		return (write(2, "ERROR FILE invalid\n", 11));
	if (err == MALLOC_ERROR)
		return (write(2, "ERROR Malloc\n", 13));
	if (err == INVALID_MAP)
		return (write(2, "ERROR MAP broken\n", 17));
	if (err == DIR_ERROR)
		return (write(2, "ERROR Path not valid\n", 21));
	if (err == COLOUR_ERROR)
		return (write(2, "ERROR Colour not valid\n", 23));
	if (err == MAP_ERROR)
		return (write(2, "ERROR Map not valid\n", 20));
	if (err == MLX_ERROR)
		return (write(2, "ERROR MLX Malloc\n", 10));
	if (err == TEX_PATH_ERROR)
		return (write(2, "ERROR put ONE of each path NO/SO/EA/WE ./path\n", 46));
	if (err == PLAYER_ERROR)
		return (write(2, "ERROR Player\n", 13));
	if (err == PNG_ERROR)
		return (write(2, "ERROR PNG path not valid \
	| MLX malloc\n", 38));
	if (err == EXIT_SUCCESS)
		return (write(2, "Exit cub3D\n", 11));
	return (0);
}
