/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/13 19:40:03 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

/*
 * verify a single map filename is passed as parameter
 * initialise data from filename
 */
int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || check_arg(argv[1]))
		return (cub_error(ARG_ERROR));
	data = init_data(argv);
	start_cub(data);
	free(data);
	write(1, "Exit cub3D\n", 11);
	return (0);
}
