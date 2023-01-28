/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:27:46 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/27 12:01:19 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*
 * global error handling
 * print an error message according to err
 * return err value to be re-used as program exiting value
*/
int	cub_error(int err)
{
	printf("Error\n");
	if (err >= PNG_ERROR)
		return (cub_error_2(err));
	else if (err == ARG_ERROR)
		printf("Wrong arguments. Use: ./cub3D <path to map filename>\n");
	else if (err == ARG_FILENAME_ERROR)
		printf("Invalid map filename. Only *.cub format is accepted\n");
	else if (err == EMPTY_FILE_ERROR)
		printf("File appears to be empty\n");
	else if (err == FILE_ERROR)
		printf("File invalid.\n");
	else if (err == FILE_TOO_SHORT_ERROR)
		printf("File invalid. Check all required definitions are included.\n");
	else if (err == INVALID_MAP)
		printf("MAP broken\n");
	else if (err == MALLOC_ERROR)
		printf("Malloc failed\n");
	else if (err == DIR_ERROR)
		printf("Path not valid\n");
	else if (err == COLOUR_ERROR)
		printf("Colour not valid\n");
	else
		printf("ERROR FIXME - unsupported error\n");
	return (err);
}

/*
 * continuation of cub_error for norminette compliance
 */
int	cub_error_2(int err)
{
	if (err == MAP_ERROR)
		printf("Map not valid\n");
	else if (err == MLX_ERROR)
		printf("MLX Malloc\n");
	else if (err == PNG_ERROR)
		printf("PNG path not valid | MLX malloc\n");
	else if (err == TEX_PRESENCE_ERROR)
	{
		printf("Specify exactly ONE texture file for each direction as:\n");
		printf("NO/SO/EA/WE ./filename\n");
	}
	else if (err == TEX_PATH_ERROR)
		printf("TEX_PATH_ERROR\n");
	else if (err == TEX_MLX_LOAD_PNG_ERROR)
		printf("TEX_MLX_LOAD_PNG_ERROR\n");
	else if (err == PLAYER_ERROR)
		printf("Only one Player needed\n");
	else if (err == P_SURROUNDED_ERROR)
		printf("Player not surrounded\n");
	else if (err == W_SURROUNDED_ERROR)
		printf("Wall not surrounded\n");
	else
		printf("ERROR FIXME - unsupported error\n");
	return (err);
}
