/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/12/19 03:22:18 by jjesberg         ###   ########.fr       */
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
	free_data(data);
	return (error(0));
}
