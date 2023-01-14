/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/14 11:29:45 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

/*
 * validate filename ends with ".cub"
 * filename may include a dir: maps/42.cub
 */
int validate_map_filename(char *filename)
{
    int     i;
    int     len;

    len = ft_strlen(filename);
    i = 0;
    if (len < 4)
        return (1);
    while (filename[i])
    {
        i++;
        if (filename[i] == '.' && filename[i + 1])
        {
            i++;
            if (!ft_strncmp(filename + i, "cub", 5))
                return (0);
        }
    }
    return (1);
}

/*
 * verify a single map filename is passed as parameter
 * validate map filename is valid by checking open returns a valid fd
 * initialise data from filename
 */
int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || validate_map_filename(argv[1]))
		return (cub_error(ARG_ERROR));
	if (!ft_ispath(argv[1]))
		exit(cub_error(DIR_ERROR));
	data = init_data(argv[1]);
	start_cub(data);
	free(data);
	write(1, "Exit cub3D\n", 11);
	return (0);
}
