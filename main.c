/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/15 21:20:53 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

/*
initalazing Map
*/
int	main(int argc, char *argv[])
{
	t_data	*data;
	int		ret;

	data = NULL;
	ret = init_map(argc, argv, data);
	if (ret != 0)
	{
		if (data)
			free(data);
		system("leaks cub3D");
		return (error(ret));
	}
	ret = map_reader(data);
	if (ret != 0)
	{
		free(data);
		system("leaks cub3D");
		return (error(ret));
	}
	free(data);
	system("leaks cub3D");
	return (error(0));
}
