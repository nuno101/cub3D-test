/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:27:46 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/14 23:00:52 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*
 * global error handling
 * print an error message according to err
 * return err value to be re-used as program exiting value
 * FIXME too many lines atm!!
*/
int	cub_error(int err)
{
	printf("Error\n");
	if (err == ARG_ERROR)
		printf("ARGS\n");
	else if (err == FILE_ERROR)
		printf("FILE invalid\n");
	else if (err == INVALID_MAP)
		printf("MAP broken\n");
	else if (err == MALLOC_ERROR)
		printf("Malloc\n");
	else if (err == DIR_ERROR)
		printf("Path not valid\n");
	else if (err == COLOUR_ERROR)
		printf("Colour not valid\n");
	else if (err == MAP_ERROR)
		printf("Map not valid\n");
	else if (err == MLX_ERROR)
		printf("MLX Malloc\n");
	else if (err == PNG_ERROR)
		printf("PNG path not valid | MLX malloc\n");
	else if (err == TEX_PATH_ERROR)
		printf("Put ONE of each path NO/SO/EA/WE ./path\n");
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
