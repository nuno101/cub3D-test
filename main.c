/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/12/19 06:55:20 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		ret;

	data = malloc(sizeof(t_data));
	if (!data)
		return (MALLOC_ERROR);
	ret = init_map(argc, argv, data);
	if (ret != 0)
	{
		if (data)
			free(data);
		return (error(ret));
	}
	ret = map_reader(data);
	if (ret != 0)
	{
		free_data(data);
		return (error(ret));
	}
	printf("_NO =%s\n", data->_NO);
	printf("_SO =%s\n", data->_SO);
	printf("_WE =%s\n", data->_WE);
	printf("_EA =%s\n", data->_EA);
	printf("F1 = %i\n", data->F[0]);
	printf("F2 = %i\n", data->F[1]);
	printf("F3 = %i\n", data->F[2]);
	printf("C1 = %i\n", data->C[0]);
	printf("C2 = %i\n", data->C[1]);
	printf("C3 = %i\n", data->C[2]);
	free_data(data);
	return (error(0));
}
