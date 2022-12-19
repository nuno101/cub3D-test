/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 06:59:32 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 09:09:38 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

void	print_map_param(t_data *data)
{
	printf("_NO =%s\n", data->_NO);
	printf("_SO =%s\n", data->_SO);
	printf("_WE =%s\n", data->_WE);
	printf("_EA =%s\n", data->_EA);
	printf("F[1] (R) = %i\n", data->F[0]);
	printf("F[2] (B) = %i\n", data->F[1]);
	printf("F[3] (G) = %i\n", data->F[2]);
	printf("C[1] (R) = %i\n", data->C[0]);
	printf("C[2] (B) = %i\n", data->C[1]);
	printf("C[3] (G) = %i\n", data->C[2]);
	int i = 0;
	while (data->map_values[i])
		printf("map val = %s\n", data->map_values[i++]);
}