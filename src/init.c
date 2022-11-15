/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:06:45 by ezpiro-m          #+#    #+#             */
/*   Updated: 2022/11/15 21:07:26 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub.h"

int	init_map(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		return (ARG_ERROR);
	data = malloc(sizeof(t_data));
	if (!data)
		return (MALLOC_ERROR);
	data->argc = argc;
	data->argv = argv;
	data->map = NULL; // 
	if (data->map == NULL)
		return (INVALID_MAP);
	return (0);
}
