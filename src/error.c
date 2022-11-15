/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:01:45 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/15 21:03:57 by ezpiro-m         ###   ########.fr       */
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
