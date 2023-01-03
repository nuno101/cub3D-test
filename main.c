/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezpiro-m <ezpiro-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/03 17:17:29 by ezpiro-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

static t_data	*init_data(int argc, char *argv[])
{
    t_data *data = malloc(sizeof(t_data));
	if(data == NULL)
	{
		error(MALLOC_ERROR);
		return (NULL);
	}
    int ret = init_map(argc, argv, data);
    if (ret != 0)
    {
        if (ret != MALLOC_ERROR)
            ft_cleansplit(data->map);
        else
            free(data->map);
        free(data);
		error(ret);
        return (NULL);
    }
    return (data);
}

int main(int argc, char *argv[])
{
    t_data *data;
    int ret;

	ret = 105;
    if (argc < 2)
        return (error(ARG_ERROR));
    data = init_data(argc, argv);
    if (!data)
		return (1);
    ret = save_param(data);
    if (ret != 0)
    {
        free_data(data);
        return (error(ret));
    }
	ret = start_cub(data);
    print_map_param(data);
    free_data(data);
    system("leaks cub3D");
    return (error(ret));
}
