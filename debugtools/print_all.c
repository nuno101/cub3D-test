/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 06:59:32 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 07:03:01 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

void	print_map_param(t_data *data)
{
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
}