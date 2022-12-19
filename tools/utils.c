/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 03:16:21 by jjesberg          #+#    #+#             */
/*   Updated: 2022/12/19 03:16:39 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

void	free_data(t_data *data)
{
	int i = 0;
	while (data->map[i])
	{
		printf("[%i]%s = \n", i, data->map[i]);
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
}
