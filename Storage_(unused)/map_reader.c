/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 00:22:18 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 23:17:15 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	map_reader(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			j += write(1, &data->map[i][j], 1);
		}
		j = 0;
		i++;
	}
	return (INVALID_MAP);
	return (0);
}
