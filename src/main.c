/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/27 17:18:12 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

/*
initalazing Map
*/
int	main(int argc, char *argv[])
{
	t_player	*pl;

	if (argc == 2)
	{
		pl = (t_player *)malloc(sizeof(t_player));
		check_extension(argv[1]);
		pl->data = parse_map(argv[1]);		//deficiencies will be completed.
		pl->mlx = init_mlx();				//deficiencies will be completed.
		init_player(pl);					//deficiencies will be completed.
		draw_screen(pl);//deficiencies will be completed.
		free_all(pl);				
	}
	else
		ft_putendl_fd("Error\nUsage example ./cub3D map.cub" STDERR);
	return (0);
}
