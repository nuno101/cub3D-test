/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/05 05:26:03 by jjesberg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int main(int argc, char *argv[])
{
    t_data *data;
    int ret;

    if (argc < 2)
        return (error(ARG_ERROR));
    data = init_data(argc, argv);
    ret = save_param(data);
    if (ret != 0)
    {
        free_data(data);
        return (error(ret));
    }
	start_cub(data);
    print_map_param(data);
    free_data(data);
    return (error(ret));
}
