/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:04 by jjesberg          #+#    #+#             */
/*   Updated: 2022/11/29 00:22:06 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/error.h"

int	error(int err)
{
	if (err == ARG_ERROR)
		return (write(2, "ERROR ARGS\n", 11));
	if (err == MALLOC_ERROR)
		return (write(2, "ERROR MALLOC\n", 13));
	if (err == INVALID_MAP)
		return (write(2, "ERROR MAP broken\n", 17));
	return (0);
}
