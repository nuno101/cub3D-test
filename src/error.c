/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:04 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 09:22:33 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/error.h"

int	error(int err)
{
	if (err == ARG_ERROR)
		return (write(2, "ERROR ARGS\n", 11));
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
	return (0);
}
