/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:27:46 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/08 16:26:09 by nlouro           ###   ########.fr       */
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
	if (err == ARG_ERROR)
		write(2, "ERROR ARGS\n", 11);
	else if (err == FILE_ERROR)
		write(2, "ERROR FILE invalid\n", 11);
	else if (err == MALLOC_ERROR)
		write(2, "ERROR Malloc\n", 13);
	else if (err == INVALID_MAP)
		write(2, "ERROR MAP broken\n", 17);
	else if (err == DIR_ERROR)
		write(2, "ERROR Path not valid\n", 21);
	else if (err == COLOUR_ERROR)
		write(2, "ERROR Colour not valid\n", 23);
	else if (err == MAP_ERROR)
		write(2, "ERROR Map not valid\n", 20);
	else if (err == MLX_ERROR)
		write(2, "ERROR MLX Malloc\n", 10);
	else if (err == TEX_PATH_ERROR)
		write(2, "ERROR put ONE of each path NO/SO/EA/WE ./path\n", 46);
	else if (err == PNG_ERROR)
		write(2, "ERROR PNG path not valid \
	| MLX malloc\n", 38);
	else
		write(2, "ERROR FIXME - unsupported error\n", 32);
	return (err);
}
