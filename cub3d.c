/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjesberg <jjesberg@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:53:21 by ezpiro-m          #+#    #+#             */
/*   Updated: 2023/01/14 10:45:48 by nlouro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

/*
 * validate filename s ends with ".cub"
 * filename may include a dir: maps/42.cub
 */
int check_arg(char *s)
{
    int     i;
    int     len;

    len = ft_strlen(s);
    i = 0;
    if (len < 4)
        return (1);
    while (s[i])
    {
        i++;
        if (s[i] == '.' && s[i + 1])
        {
            i++;
            if (!ft_strncmp(s + i, "cub", 5))
                return (0);
        }
    }
    return (1);
}

/*
 * verify a single map filename is passed as parameter
 * initialise data from filename
 */
int main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || check_arg(argv[1]))
		return (cub_error(ARG_ERROR));
	data = init_data(argv);
	start_cub(data);
	free(data);
	write(1, "Exit cub3D\n", 11);
	return (0);
}
