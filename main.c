/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/12/19 13:15:21 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	int		ret;

	if (argc < 2)
		return (ARG_ERROR);
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
	ret = save_param(data);
	if (ret != 0)
	{
		free_data(data);
		return (error(ret));
	}
	print_map_param(data);
	free_data(data);
	return (error(0));
}
