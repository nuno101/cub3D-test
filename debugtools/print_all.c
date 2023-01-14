/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 06:59:32 by jjesberg          #+#    #+#             */
/*   Updated: 2023/01/14 11:02:38 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	print_data(t_data *data)
{
	printf("f_colour = %x\n", data->f_colour);
	printf("c_colour = %x\nthe whole file:\n", data->c_colour);
	ft_print_split(data->map_data);
	printf("\n");
}

void	print_cub(t_cub *cub)
{
	printf("c colour = %x\n", cub->c);
	printf("f colour = %x\n", cub->f);
	printf("player_pos = x(%i)y(%i)\n", cub->player_pos.x, cub->player_pos.y);
}
