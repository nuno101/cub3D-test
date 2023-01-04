/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/04 22:03:50 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

/*
hex = (r << 24 | g << 16 | b << 8 | t);
*/

int main(int argc, char *argv[])
{
    t_data *data;
    int ret;

	ret = 105;
    if (argc < 2)
        return (error(ARG_ERROR));
    data = init_data(argc, argv);
    ret = save_param(data);
    if (ret != 0)
    {
        free_data(data);
        return (error(ret));
    }
	ret = start_cub(data);
    
    print_map_param(data);
    free_data(data);
    return (error(ret));
}
